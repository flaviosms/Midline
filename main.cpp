#include "main.h"

//-----------------------------------------------------------------------------

void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	//DrawLine(1,10,red,256,256,green);
	//DrawRandomLines();
    //DrawAxis();
    //srand(time(NULL));
    //Color cor ={rand()%255,rand()%255,rand()%255,rand()%255};
    //DrawTriangle(rand()%512,rand()%512,cor,rand()%512,rand()%512,cor,rand()%512,rand()%512,cor,true,cor);
    //DrawRandomCircles();
    //DrawCircle(250,250,51,100,blue);
    //DrawRandomTriangles();
    DrawTriangle(0,0,blue,0,256,blue,256,0,blue,true,blue);
    DrawTriangle(511,0,red,511,256,red,256,0,red,true,red);
    DrawCircle(256,256,200,100,yellow);
    DrawCircle(256,406,50,green);
    DrawTriangle(0,256,red,256,0,green,511,256,blue,false);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

