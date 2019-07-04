#ifndef _MYGL_H_
#define _MYGL_H_

#include <iostream>
#include "definitions.h"
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
struct Color {
    int R;
    int G;
    int B;
    int A;
};
Color yellow = {255,255,0,255};
Color red = {255,0,0,255};
Color green = {0,255,0,255};
Color blue = {0,0,255,255};
struct Line {
    int x0;
    int y0;
    Color color0;
    int x1;
    int y1;
    Color color1;
};

void PutPixel(int X ,int Y ,Color color){
    FBptr[X*4+Y*IMAGE_WIDTH*4] = color.R; // componente R
    FBptr[X*4+1+Y*IMAGE_WIDTH*4] = color.G; // componente G
    FBptr[X*4+2+Y*IMAGE_WIDTH*4] = color.B; // componente B
    FBptr[X*4+3+Y*IMAGE_WIDTH*4] = color.A; // componente A
}
void troca(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}

Color colorFunc(int x,int y,Line linha){
    Color retorno;
    double tamtotal=pow((pow((linha.x1 - linha.x0), 2) + pow((linha.y1 - linha.y0), 2.0)), 0.5);
    double tamatual = pow((pow((x - linha.x0), 2) + pow((y - linha.y0), 2.0)), 0.5);
    double t =tamatual/tamtotal;
    retorno.R=linha.color0.R*(1 - t) + linha.color1.R*t;
    retorno.G=linha.color0.G*(1 - t) + linha.color1.G*t;
    retorno.B=linha.color0.B*(1 - t) + linha.color1.B*t;
    retorno.A=linha.color0.A*(1 - t) + linha.color1.A*t;
    return retorno;
}

void DrawLine(int x0,int y0,Color color0,int x1,int y1,Color color1){
if(x0==x1 && y0==y1){
    PutPixel(x0,y0,color0);
    return;
}
Line linha={x0,y0,color0,x1,y1,color1};
if((x0-x1) * (y0-y1) < 0){
    int changeaxis =0;
    int dx=abs(x0-x1);
    int dy=abs(y0-y1);
    if(x0>x1){
        troca(&x0,&x1);
        troca(&y0,&y1);
    }
    if(dy>=dx){
        troca(&x0,&y0);
        troca(&x1,&y1);
        troca(&dx,&dy);
        changeaxis=1;

    }


    int d = 2* dy-dx;
    int incr_e = 2*dy;
    int incr_ne = 2*(dy-dx);
    int x=x0;
    int y=y0;
    if(y0>y1 && dy<dx){
    }
    if(!changeaxis){

			PutPixel(x,y,colorFunc(x,y,linha));
			while (x < x1) {

				if (d <= 0) {
					d += incr_e;
					x++;
				} else {
					d += incr_ne;
					x++;
					y--;
				}
				PutPixel(x,y,colorFunc(x,y,linha));
			}
		}
		else{

		PutPixel(y,x,colorFunc(x,y,linha));
			while (x1 < x) {
				if (d <= 0) {
					d += incr_e;
					x--;
				} else {
					d += incr_ne;
					x--;
					y++;
				}
				PutPixel(y,x,colorFunc(x,y,linha));
			}
		}
}
else{
    int changeaxis =0;
    int dx=abs(x0-x1);
    int dy=abs(y0-y1);
    if(dy>=dx){
        troca(&x0,&y0);
        troca(&x1,&y1);
        troca(&dx,&dy);
        changeaxis=1;

    }
    if(x0>x1){
        troca(&x0,&x1);
        troca(&y0,&y1);
    }
    int d = 2* dy-dx;
    int incr_e = 2*dy;
    int incr_ne = 2*(dy-dx);
    int x=x0;
    int y=y0;
    while(x<x1){
        if(changeaxis){PutPixel(y,x,colorFunc(x,y,linha));}
        else{PutPixel(x,y,colorFunc(x,y,linha));}
        if(d<=0){d+=incr_e;}
        else{
            d +=incr_ne;
            y++;
        }
        x++;

    }
}
return;
}

void DrawRandomLines(){
    srand(time(NULL));
	DrawLine(250,250,{rand()%255,rand()%255,rand()%255,255},rand()%500,rand()%500,{rand()%255,rand()%255,rand()%255,255});
}

void DrawAxis(){


    DrawLine(250,250,yellow,500,500,yellow);
    DrawLine(250,250,yellow,0,0,yellow);
    DrawLine(250,250,yellow,250,0,yellow);
    DrawLine(250,250,yellow,0,500,yellow);
    DrawLine(250,250,yellow,500,0,yellow);
    DrawLine(250,250,yellow,250,500,yellow);
    DrawLine(200,250,yellow,500,250,yellow);
    DrawLine(250,250,yellow,0,250,yellow);
    DrawLine(250,250,green,300,500,green);
    DrawLine(250,250,green,500,300,green);
    DrawLine(250,250,green,0,200,green);
    DrawLine(250,250,green,200,0,green);
    DrawLine(250,250,green,300,0,green);
    DrawLine(250,250,green,200,500,green);
    DrawLine(250,250,green,500,200,green);
    DrawLine(250,250,green,0,300,green);
}

bool edgeFunction(int x0,int y0,int x1,int y1,int x2,int y2)  {
     return ((x2 - x0) * (y1 - y0) - (y2- y0) * (x1 - x0) >= 0);  }

void DrawTriangle(int x0,int y0,Color color0,int x1,int y1,Color color1,int x2,int y2,Color color2,bool fill,Color fillcolor){
    DrawLine(x0,y0,color0,x1,y1,color1);
    DrawLine(x0,y0,color0,x2,y2,color2);
    DrawLine(x1,y1,color1,x2,y2,color2);
    if(fill){
        int xmin=std::min(x0,std::min(x1,x2));
        int xmax=std::max(x0,std::max(x1,x2));
        int ymin=std::min(y0,std::min(y1,y2));
        int ymax=std::max(y0,std::max(y1,y2));

        for(int xf=xmin;xf<xmax;xf++){
            for(int yf=ymin;yf<ymax;yf++){
                bool inside = true;
                inside &= edgeFunction(x0,y0,x1,y1,xf,yf);
                inside &= edgeFunction(x1,y1,x2,y2,xf,yf);
                inside &= edgeFunction(x2,y2,x0,y0,xf,yf);
                if (inside == true) {
                    PutPixel(xf,yf,fillcolor);
                }
            }
        }
    }
}

void DrawTriangle(int x0,int y0,Color color0,int x1,int y1,Color color1,int x2,int y2,Color color2,bool fill){
    DrawLine(x0,y0,color0,x1,y1,color1);
    DrawLine(x0,y0,color0,x2,y2,color2);
    DrawLine(x1,y1,color1,x2,y2,color2);
    if(fill){
        int xmin=std::min(x0,std::min(x1,x2));
        int xmax=std::max(x0,std::max(x1,x2));
        int ymin=std::min(y0,std::min(y1,y2));
        int ymax=std::max(y0,std::max(y1,y2));
        for(int xf=xmin;xf<xmax;xf++){
            for(int yf=ymin;yf<ymax;yf++){
                bool inside = true;
                inside &= edgeFunction(x0,y0,x1,y1,xf,yf);
                inside &= edgeFunction(x1,y1,x2,y2,xf,yf);
                inside &= edgeFunction(x2,y2,x0,y0,xf,yf);
                if (inside == true) {
                    PutPixel(xf,yf,blue);
                }
            }
        }
    }
}

#endif // _MYGL_H_
/*void fill(int x0,int y0,Color color0,int x1,int y1,Color color1,int x2,int y2,Color color2){
    int xmin=std::min(x0,std::min(x1,x2));
    Color corobj,corenc;
    int x,y;
    if(xmin==x0){
        corobj=color0;
        corenc=color0;
        corenc.A--;
        for(;corobj.R!=corenc.R&&corobj.G!=corenc.G&&corobj.B!=corenc.B&&corobj.A!=corenc.A;x++){
            for(;corobj.R!=corenc.R&&corobj.G!=corenc.G&&corobj.B!=corenc.B&&corobj.A!=corenc.A;y++){
                PutPixel(x,y-1,corobj);
                corenc.R=FBptr[x*4+y*IMAGE_WIDTH*4]; // componente R
                corenc.G=FBptr[x*4+1+y*IMAGE_WIDTH*4]; // componente G
                corenc.B=FBptr[x*4+2+y*IMAGE_WIDTH*4]; // componente B
                corenc.A=FBptr[x*4+3+y*IMAGE_WIDTH*4]; // componente A
            }
        }
    }
    if(xmin==x1){
        corobj=color1;
        corenc=color1;
        corenc.A--;
        for(;corobj.R!=corenc.R&&corobj.G!=corenc.G&&corobj.B!=corenc.B&&corobj.A!=corenc.A;x++){
            for(;corobj.R!=corenc.R&&corobj.G!=corenc.G&&corobj.B!=corenc.B&&corobj.A!=corenc.A;y++){
                PutPixel(x,y-1,corobj);
                corenc.R=FBptr[x*4+y*IMAGE_WIDTH*4]; // componente R
                corenc.G=FBptr[x*4+1+y*IMAGE_WIDTH*4]; // componente G
                corenc.B=FBptr[x*4+2+y*IMAGE_WIDTH*4]; // componente B
                corenc.A=FBptr[x*4+3+y*IMAGE_WIDTH*4]; // componente A
            }
        }
    }
    if(xmin==x2){
        corobj=color2;
        corenc=color2;
        corenc.A--;
        for(;corobj.R!=corenc.R&&corobj.G!=corenc.G&&corobj.B!=corenc.B&&corobj.A!=corenc.A;x++){
            for(;corobj.R!=corenc.R&&corobj.G!=corenc.G&&corobj.B!=corenc.B&&corobj.A!=corenc.A;y++){
                PutPixel(x,y-1,corobj);
                corenc.R=FBptr[x*4+y*IMAGE_WIDTH*4]; // componente R
                corenc.G=FBptr[x*4+1+y*IMAGE_WIDTH*4]; // componente G
                corenc.B=FBptr[x*4+2+y*IMAGE_WIDTH*4]; // componente B
                corenc.A=FBptr[x*4+3+y*IMAGE_WIDTH*4]; // componente A
            }
        }
    }
}*/

