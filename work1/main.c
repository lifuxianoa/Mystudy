#include "Draw_function.h"
#include <stdlib.h>

int main()
{
    //	int color = 0x00000000;
    int color = 0xffffff;
    //	int screen_buffer[400][5000];
    int *screen_buffer0;
    fb_open();
    if(( screen_buffer0 = (int *)malloc(screen.screensize)) == NULL)	
        printf("error: malloc fail!\n");

    memcpy(screen_buffer0,screen.fbp,screen.screensize);
    Set_screen(color);
    //	Draw_hline(0,800,300,0x00ffffff);
    //Draw_hline(0,800,420,0x00ffffff);
    Draw_hline(0,800,420,0x00);
    //	Display_string(370,380,"Aanlyzing",0xffffff);
    Display_string(370,380,"Aanlyzing",0xfff);
    //Draw_hline(0,800,560,0x00ffffff);
    Draw_hline(0,800,560,0x00);

    //Draw_full_rectangle(0,0,266,150,0x00537ae3);
    Draw_full_rectangle(0,0,266,150,0x0037ae3);
    Display_string(50, 40,"NIBP    120",0xffffff);
    Display_string(50, 60,"Alarm   ----  100 ",0xffffff);
    Display_string(50, 80,"         80       ",0xffffff);

    Draw_full_rectangle(266,0,534,150,0xfff);
    //Draw_full_rectangle(266,0,534,150,0x00000000);
    Display_string(310, 40,"HR               BPM",0xff0000);
    Display_string(310, 60,"Alarm     78     ECG ",0xff0000);
    Display_string(310, 80,"Lead II           x1",0xff0000);

    //Draw_full_rectangle(534,0,800,150,0x004a8f30);
    Draw_full_rectangle(534,0,800,150,0x00f30);
    Display_string(545, 10,"SPO2 ",0xffffff);
    Display_string(550, 60,"Alarm           98 ",0xffffff);
    Display_string(640, 90,"Signal OK ",0xffffff);

    Draw_full_rectangle(0,420,190,560,0x00f8000);
    //Draw_full_rectangle(0,420,190,560,0x00ff8000);
    Display_string(50, 460,"Pacer Stop ",0x000000);
    Display_string(45, 480,"Demand Mode ",0x000000);
    Display_string(50, 500,"70ppm 30mA ",0x000000);

    //Draw_full_rectangle(610,420,800,560,0x00ffff80);
    Draw_full_rectangle(610,420,800,560,0x00ffff0);
    Display_string(690, 460,"114J ",0x000000);
    Display_string(680, 480,"Shock:0 ",0x000000);
    Display_string(680, 500,"00:15:02 ",0x000000);

    Draw_rectangle(190,420,380,460,0x00ff);
    //Draw_rectangle(190,420,380,460,0x00ffffff);
    Display_string(210,435,"Alarm    Temperature ",0x00);
    //Display_string(210,435,"Alarm    Temperature ",0xffffff);

    Draw_rectangle(420,420,610,460,0x00);
    //Draw_rectangle(420,420,610,460,0x00ffffff);
    Display_string(430,435,"Alarm    Breach ",0x00);
    //Display_string(430,435,"Alarm    Breach ",0xffffff);

    Draw_vline(190,560,600,0x00);
    //Draw_vline(190,560,600,0x00ffffff);
    Display_string(210,570,"Stop ",0x00);
    //Display_string(210,570,"Stop ",0xffffff);

    Draw_vline(265,560,600,0x00);
    //Draw_vline(265,560,600,0x00ffffff);
    Display_string(285,570,"Alarm ",0x00);
    //Display_string(285,570,"Alarm ",0xffffff);

    //Draw_vline(340,560,600,0x00ffffff);
    Draw_vline(340,560,600,0x00);
    //Display_string(360,570,"Sign ",0xffffff);
    Display_string(360,570,"Sign ",0x00);

    Draw_vline(415,560,600,0x00);
    //Draw_vline(415,560,600,0x00ffffff);
    //Draw_vline(490,560,600,0x00ffffff);
    Draw_vline(490,560,600,0x00);

    Display_string(503,570,"Choouse ",0x00);
    //Display_string(503,570,"Choouse ",0xffffff);
    Draw_vline(565,560,600,0x00);
    //Draw_vline(565,560,600,0x00ffffff);
    Draw_vline(640,560,600,0x00);
    //Draw_vline(640,560,600,0x00ffffff);

    //	memcpy(screen_buffer,screen.fbp,screen.screensize);

    //	int time = 0, count = 0;
    //	int hight = 0;
    /*	while(1)
        {
    //srandom(100);
    Draw_rectangle_wave(time,350,15,100,0x33ffff);
    sleep(1);
    memcpy(screen.fbp,screen_buffer,screen.screensize);
    time = time + 5;
    if(time > 800)
    {
    time = 0;
    count += 1;
    }
    if(count == 1)
    break;
    }*/
    //	sleep(10);
    //Draw_wave(200, 350, 50, 150, 0xff0000);
    //	memcpy(screen.fbp,screen_buffer0,screen.screensize);
    free(screen_buffer0);
    return 0;
}
