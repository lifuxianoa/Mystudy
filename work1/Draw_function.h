#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <math.h>
#include <sys/mman.h>
#include "ziku.h"

#define row 9
#define col 10

struct fbdev
{
	int fp;
	unsigned long screensize;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	char *fbp;
}screen;

void fb_open()
{
	if((screen.fp = open("/dev/fb0", O_RDWR)) == -1)
	{ 
		printf("Error:Can not open /dev/fb0\n");
		exit(1);
	}
	if(ioctl(screen.fp,FBIOGET_VSCREENINFO,&screen.vinfo) == -1)
	{
		printf("Error:reading variable information\n");
		exit(2);
	}
	if(ioctl(screen.fp,FBIOGET_FSCREENINFO,&screen.finfo) == -1)
	{
		printf("Error:reading fixed information\n");
		exit(3);
	}
	screen.screensize = screen.vinfo.xres * screen.vinfo.yres * screen.vinfo.bits_per_pixel * 4/8;
	screen.fbp = (char *)mmap(0,screen.screensize,PROT_READ|PROT_WRITE,MAP_SHARED,screen.fp,0);
	getchar();
	if((int) screen.fbp == -1)
	{
		printf("Error:failed to map framebuffer device to memory.\n");
		exit(4); 
	}
}

void Draw_Point(int x, int y, int color)
{
	int fbp_offset = 0;	
	fbp_offset = x * (screen.vinfo.bits_per_pixel * 4  / 8) + y * screen.vinfo.xres * (screen.vinfo.bits_per_pixel * 4 / 8);
	*(screen.fbp + fbp_offset) = color & 0xff;
	*(screen.fbp + fbp_offset + 1) = (color >> 8) & 0xff;
	*(screen.fbp + fbp_offset + 2) = (color >> 16) & 0xff;
	*(screen.fbp + fbp_offset + 3) = 0;
}

void Set_screen(int color)
{
	int i , j ; 	
	for( i = 0 ; i < 800 ; i ++)
		for( j = 0 ; j < 600 ; j ++)
			Draw_Point(i, j , color);
}

void Draw_vline(int start_x, int start_y, int end_y, int color)
{
	int tmp ;	
	int i = 0;
	if(start_y > end_y)
	{
		start_y = start_y + end_y;
		end_y = start_y - end_y;
		start_y = start_y - end_y;
	}
	tmp = end_y - start_y;
	for( i = 0; i <= tmp ;  ++i)
	{
		Draw_Point(start_x, start_y + i, color);
	}
}
void Draw_hline(int start_x, int end_x, int start_y, int color)
{
	int tmp ;	
	int i = 0;
	if(start_x > end_x)
	{
		start_x = start_x + end_x;
		end_x = start_x - end_x;
		start_x = start_x - end_x;
	}
	tmp = end_x - start_x;
	for( i = 0; i <= tmp ;  ++i)
	{
		Draw_Point(start_x + i, start_y, color);
	}
}
void Draw_rectangle(int start_x,int start_y, int end_x, int end_y , int color)
{
	Draw_hline(start_x, end_x , start_y ,color);
	Draw_hline(start_x, end_x , end_y ,color);
	Draw_vline(start_x, start_y , end_y ,color);
	Draw_vline(end_x, start_y , end_y ,color);

}

void Draw_full_rectangle(int start_x,int start_y, int end_x, int end_y , int color)
{
	int i = 0;
	int tmp = 0;
	tmp = end_x - start_x;
	for(i = 0; i < tmp; i ++)
		Draw_vline(start_x + i , start_y, end_y, color);
}

void write_en(int x, int y, unsigned char *codes, int color)
{
	int i = 0;
	for(i = 0; i < 16; ++ i)
	{
		int j = 0; 
		x += 8;
		for(j = 0; j < 8; ++j)
		{
			--x;
			if((codes[i] >> j) & 0x1)
			{
				Draw_Point(x , y, color);
			}
		}
		++y;
	}
}

void write_cn(int x, int y, unsigned char *codes, int color)
{
	int i;
	for( i = 0; i < 16; i ++)
	{
		int j = 0; 	
		for( j = 0; j < 2; j ++)
		{
			int k = 0;
			x += 8 * (j + 1);
			for( k = 0; k < 8; k ++)
			{
				-- x;
				if((codes[2 * i + j] >> k) & 0x1)
					Draw_Point(x, y, color);
			}
		}
	}
	x -= 8;
	++ y;
}

void Display_string(int x, int y, char * str,int color)
{
	unsigned char *ptr;
	unsigned int ch;
	unsigned int cl;
	unsigned int offset;
	while(*str)
	{
		ch = (unsigned int )str[0];		
		cl = (unsigned int )str[1];
		if(( ch >= 0xa1) && (ch < 0xf8) && (cl >= 0xa1) && (cl < 0xff))
		{
			offset = ((ch - 0xa1) * 94 + (cl - 0xal)) * 32;
			ptr = __ASCII8X16__ + offset;
			write_cn(x, y, ptr,color);
			x += 16;
			str += 2;
		}
		else
		{
			ptr = __ASCII8X16__ + 16*ch;
			write_en(x, y + 4, ptr, color);
			x += 8; 
			str += 1;
		}

	}
}
void Draw_rectangle_wave(int x0, int y0, int t, int g, int color)
{
	int i;
	for(i = 0; i < 800; i += t)
	{
		Draw_hline(x0, x0 + t/2, y0,color);
		Draw_vline(x0 + t/2, y0 - g, y0, color);
		Draw_hline(x0 + t/2,  x0 + t, y0 - g, color);
		Draw_vline(x0 + t, y0 - g, y0, color);
		x0 = x0 + t;
	}
}

void Draw_wave(int start_x, int start_y, int t, int g, int color)
{
	int i = 0, j = 0; 
	int *screen_buffer = NULL;
	if((screen_buffer = (int *)malloc(screen.screensize)) == NULL)
	{
		printf("malloc error!\n");
	}
	memcpy(screen_buffer, screen.fbp, screen.screensize);
	while(1)
	{
		for(i = 0 ; i <= t/2; i ++ , start_x ++)
		{
			memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_full_rectangle(start_x + 1,240, start_x + 10, 360, 0x0000);
			//memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_Point(start_x, start_y, color);
			memcpy(screen_buffer, screen.fbp, screen.screensize);
			sleep(0.001);
		}
		for(j =0; j <= g; j ++,start_y --)
		{
			memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_full_rectangle(start_x + 1,240, start_x + 10, 360, 0x0000);
			//memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_Point(start_x, start_y, color);
			memcpy(screen_buffer, screen.fbp, screen.screensize);
			sleep(0.001);
		}		
		for(i = 0; i <= t/2; i ++, start_x ++)
		{
			memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_full_rectangle(start_x + 1,240, start_x + 10, 360, 0x0000);
			//memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_Point(start_x, start_y, color);
			memcpy(screen_buffer, screen.fbp, screen.screensize);
			sleep(0.001);
		}
		for(j = 0; j <= g; j ++ , start_y ++)
		{
			memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_full_rectangle(start_x + 1,240, start_x + 10, 360, 0x0000);
			//memcpy(screen.fbp, screen_buffer,screen.screensize);
			Draw_Point(start_x, start_y, color);
			memcpy(screen_buffer, screen.fbp, screen.screensize);
			sleep(0.001);
		}
	if(start_x >= 800)
		start_x = 0;
	}
}
