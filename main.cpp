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
    srand(time(NULL));
    Color cor ={rand()%255,rand()%255,rand()%255,rand()%255};
    DrawTriangle(250,0,cor,125,500,cor,250,250,cor,true,cor);
    DrawTriangle(250,0,cor,375,500,cor,250,250,cor,true,cor);
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

