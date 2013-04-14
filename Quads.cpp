#include "main.h"


Quads::Quads(void)
{
}


Quads::~Quads(void)
{
}

void Quads::mas(CVector3 g_vTriangle0,CVector3 g_vTriangle1,CVector3 g_vTriangle2,CVector3 g_vTriangle3)
{
	g_vQuads[0]=g_vTriangle0;
	g_vQuads[1]=g_vTriangle1;
	g_vQuads[2]=g_vTriangle2;
	g_vQuads[3]=g_vTriangle3;
}
void Quads::paint(float R, float G, float B)
{
	r=R;g=G;b=B;	
	glBegin (GL_QUADS);
		glColor3ub(r, g, b);
		glVertex3f(g_vQuads[0].x, g_vQuads[0].y, g_vQuads[0].z);
		glVertex3f(g_vQuads[1].x, g_vQuads[1].y, g_vQuads[1].z);
		glVertex3f(g_vQuads[2].x, g_vQuads[2].y, g_vQuads[2].z);
		glVertex3f(g_vQuads[3].x, g_vQuads[3].y, g_vQuads[3].z);
	glEnd();
}
