#include "main.h"
#include "3dmath.h"

Sphere::Sphere(float x, float y,float z)
{
		g_vPosition=CVector3(x,y,z);
}


Sphere::~Sphere(void)
{
}
void Sphere::paint(float r, int d)
{
	radius=r;
	detal=d;

		// ������ �������� ����� ������� �� �������� quadric-������.
	GLUquadricObj *pObj = gluNewQuadric();
 
	// ����� ����� �� ���������������, ������� ����� ���������
	gluQuadricDrawStyle(pObj, GLU_LINE);
	gluSphere(pObj, radius, detal,detal);
}
void Sphere::move(float timer,float speedx,float speedy)
{
	g_vPosition.x=g_vPosition.x+speedx*timer;
	g_vPosition.y=g_vPosition.y+speedy*timer;
}