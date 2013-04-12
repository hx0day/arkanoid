#ifndef _MAIN_H
#define _MAIN_H
 
// ������, ����������� ��� ������ ���������
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <avo\Timer.h>
#include "3dmath.h"

// ������� ���������� ����������, ������, ������ � ������� ����� ������
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_DEPTH 16
 using avo::Timer;
// ���������� ��������� ����; ����� �������� �� ������ ������:
extern HWND  g_hWnd;
extern RECT  g_rRect;
extern HDC   g_hDC;
extern HGLRC g_hRC;
extern HINSTANCE g_hInstance;
 /// ������, ������������ ��� ������ ���������� ���� ����� �������

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


// �������� ������� ������� ��������� - WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprev, PSTR cmdline, int ishow);
 
// �������� ������� ��������� ���������
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
 
// ������� - ������� ���� ���������
WPARAM MainLoop();
 
// �������, ��������� ����
HWND CreateMyWindow(LPSTR strWindowName, int width, int height, DWORD dwStyle, bool bFullScreen, HINSTANCE hInstance);
 
// �������, ��������������� ������ �������
bool bSetupPixelFormat(HDC hdc);
 
// �������� �������, ��������������� ������� ���� OpenGL
void SizeOpenGLScreen(int width, int height);
 
// �������, ���������������� OpenGL
void InitializeOpenGL(int width, int height);
 
// ����� �������������
void Init(HWND hWnd);
 
// �������, ������� ���������� ������ �����
void RenderScene();
 
// ��-�������������
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
