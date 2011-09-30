#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>

int main () 
{
    int fp=0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long screensize=0;
    char *fbp = 0;
    int x = 0, y = 0;
    int i;
    long location = 0;
    fp = open ("/dev/fb0",O_RDWR);

    if (fp < 0){
        printf("Error : Can not open framebuffer device\n");
        exit(1);
    }

    if (ioctl(fp,FBIOGET_FSCREENINFO,&finfo)){
        printf("Error reading fixed information\n");
        exit(2);
    }

    if (ioctl(fp,FBIOGET_VSCREENINFO,&vinfo)){
        printf("Error reading variable information\n");
        exit(3);
    }

    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
    /*这就是把fp所指的文件中从开始到screensize大小的内容给映射出来，得到一个指向这块空间的指针*/
    fbp =(char *) mmap (0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fp,0);
    if ((int) fbp == -1)
    {
        printf ("Error: failed to map framebuffer device to memory.\n");
        exit (4);
    }

    for(i=0; i<100; i++)
    {
        /*这是你想画的点的位置坐标,(0，0)点在屏幕左上角*/
        x = 100;
        y = 100+i;
        location = x * (vinfo.bits_per_pixel / 8) + y * finfo.line_length;

        *(fbp + location) = 255;        /* 蓝色的色深 */        /*直接赋值来改变屏幕上某点的颜色*/
        *(fbp + location + 1) = 0;    /* 绿色的色深*/
        *(fbp + location + 2) = 0;    /* 红色的色深*/        
        *(fbp + location + 3) = 0;        /* 是否透明*/        
    }
    munmap (fbp, screensize);    /*解除映射*/
    close (fp);                /*关闭文件*/
    return 0;

}
