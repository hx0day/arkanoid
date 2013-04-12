#ifndef _MAIN_H
#define _MAIN_H
 
// Хидеры, необходимые для работы программы
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <avo\Timer.h>
#include "3dmath.h"

// Обьявим глобальные переменные, ширину, высоту и глубину цвета экрана
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_DEPTH 16
 using avo::Timer;
// Глобальные параметры окна; будут доступны из других файлов:
extern HWND  g_hWnd;
extern RECT  g_rRect;
extern HDC   g_hDC;
extern HGLRC g_hRC;
extern HINSTANCE g_hInstance;
 /// таймер, используемый для замера временного шага между кадрами

 class Sphere
{  
public:
	Sphere(float x,float y ,float z);
	~Sphere(void);
	CVector3 g_vPosition;
	float radius;
	int detal;
	void paint(float r, int d);
	void move(float timer,float speedx,float speedy);

};


// Прототип главной функции программы - WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprev, PSTR cmdline, int ishow);
 
// Прототип функции обработки сообщений
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
 
// Функция - главный цикл программы
WPARAM MainLoop();
 
// Функция, создающая окно
HWND CreateMyWindow(LPSTR strWindowName, int width, int height, DWORD dwStyle, bool bFullScreen, HINSTANCE hInstance);
 
// Функция, устанавливающая формат пиксела
bool bSetupPixelFormat(HDC hdc);
 
// Прототип функции, устанавливающей размеры окна OpenGL
void SizeOpenGLScreen(int width, int height);
 
// Функция, инициализирующая OpenGL
void InitializeOpenGL(int width, int height);
 
// Общая инициализация
void Init(HWND hWnd);
 
// Функция, которая собственно рисует сцену
void RenderScene();
 
// Де-инициализация
void DeInit();
void CheckForMovement();
class Quads
{
public:
	CVector3 g_vQuads[4];
float r,g,b;
	Quads(void);
	~Quads(void);
	void  mas(CVector3 g_vTriangle0,CVector3 g_vTriangle1,CVector3 g_vTriangle2,CVector3 g_vTriangle3);
	void paint(float R, float G, float B);
};

class Bloks
{public:

	CVector3 g_vBloksP[4];
	CVector3 g_vBloksV[4];
	CVector3 g_vBloksR[4];
	CVector3 g_vBloksL[4];
	CVector3 g_vBloksN[4];
	float x,y,z,r,g,b;	
	Bloks(float X,float Y, float Z);
	~Bloks(void);
	
	void paint(float r,float g,float b);
	void mouvR()
	{
	x+=0.003f;
	}

	void mouvL()
	{
			x-=0.003f;
	}

};

#endif
