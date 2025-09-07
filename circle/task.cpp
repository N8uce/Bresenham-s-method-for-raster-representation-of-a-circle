#include "task.h"
#include "time.h"
#include <math.h>
#include "graphics.h"
#include <iostream>

void draw_circle(int x1, int y1, int R)
{
   int color=getcolor();
   int x0=0;
   int y0=R;
   int p=3-2*R;
   while(x0<= y0)
   {
       putpixel(x1 + x0, y1 + y0,color);
       putpixel(x1 + x0, y1 - y0,color);
       putpixel(x1 - x0, y1 + y0,color);
       putpixel(x1 - x0, y1 - y0,color);
       putpixel(x1 + y0, y1 + x0,color);
       putpixel(x1 + y0, y1 - x0,color);
       putpixel(x1 - y0, y1 + x0,color);
       putpixel(x1 - y0, y1 - x0,color);
       p+=p>0 ? 4*(++x0 - --y0)+10:4*++x0+6;
   }
}

void paintOver(int x0,int y0)
{
   int color = getcolor();
   int x,y,x1,y1;
   double theta1=PI/6;
   double theta2=PI/12;
   srand(time(0));
   int col_rand[3];
   int R1[3]= {30,180,280};
   int R2[4]= {30,110,160,250};

   for (int i=0,k = 0; i<3, k < 4 ; i++, k++) 
      {
      for (int j=0; j<12; j++) 
         {
            col_rand[i]=rand()%WHITE;
            setfillstyle(SOLID_FILL,col_rand[i]);
            x=x0+R1[i]*cos(j*theta1);
            y=y0+R1[i]*sin(j*theta1);
            floodfill(x,y,color);
            x1=x0+R2[k]*cos(j*theta1+theta2);
            y1=y0+R2[k]*sin(j*theta1+theta2);
            floodfill(x1,y1,color);
         }
      }
}
   
int done;
void draw_manycircles(int x0, int y0, int R)
{
   done = 1;
   draw_circle(x0,y0,R);
   for(int i=0;i <12;i++)
   draw_circle( x0+R*cos((PI/6)*i), y0+R*sin((PI/6)*i), R);
}

void paint(int width, int height)
{
   if(done == 1)
   paintOver(width/2,(height-100)/2);
}


void save()
{
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}

