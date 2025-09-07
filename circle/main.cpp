#include "graphics.h"
#include "control.h"
#include "task.h"



int main()
{
   int left = 0, top = 0, width = 800, height = 800;
   initwindow(width,height);
   create_control(BACKGROUND,  0,0, "bg.bmp");
   create_control(DRAW_MANYC,   0, height -50, "create.bmp");
   create_control(PAINT,  200,height -50, "paint.bmp");
   create_control(SAVE,   400, height -50, "save.bmp");
   create_control(EXIT,    600, height -50, "exit.bmp");
   
   while (1)
   {
      while (mousebuttons() != 1);
      switch (select_control())
      {
      case NONE:break;
      case DRAW_MANYC:draw_manycircles(width/2,
                     (height-100)/2,150);break;
      case PAINT:paint(width, height);break;
      case SAVE:save();break;
      case EXIT:closegraph();return 0;
      }
   }
}