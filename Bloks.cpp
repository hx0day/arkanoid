#include "main.h"


Bloks::Bloks(float X,float Y, float Z)
{
	z=Z;x=X;y=Y;
	
}
Bloks::Bloks(float HP)
{
	hp=HP;
	
}


Bloks::~Bloks(void)
{
}



void Bloks::paint()
{	
	
	x=0.2f;
	y=0;
	z=0;
	if(hp==3){r=0;g=0;b=255;}
	else
	if(hp==2){r=0;g=255;b=0;}
	else
	if(hp==1){r=255;g=0;b=0;}
	if(hp==0){r=0;g=0;b=0;x=10;y=10;}
	g_vBloksP[0] = CVector3(x,  y,   z);
	g_vBloksP[1] = CVector3(x+0.08f,y,z);
	g_vBloksP[2] = CVector3(x+0.08f,y+0.04f,z+0);
	g_vBloksP[3] = CVector3(x+0,y+0.04f,z+0);

	g_vBloksV[0] = CVector3(x+0,y+0.04f,z+0);
	g_vBloksV[1] = CVector3(x+0.08f, y+0.04f,z+0);
	g_vBloksV[2] = CVector3(x+0.08f,y+0.04f,z+(-1.0f));
	g_vBloksV[3] = CVector3(x+0,  y+0.04f,z+(-1.0f));

	g_vBloksN[0] = CVector3(x,y,z);
	g_vBloksN[1] = CVector3(x+0.08f, y,z);
	g_vBloksN[2] = CVector3(x+0.08f,y,z+(-1.0f));
	g_vBloksN[3] = CVector3(x+0,  y,z+(-1.0f));
	g_vBloksR[0] = CVector3(x+0.08f,y+0,z+0);
	g_vBloksR[1] = CVector3(x+0.08f,y+0,z+(-1.0f));
	g_vBloksR[2] = CVector3(x+0.08f,y+0.04f,z+(-1.0f));
	g_vBloksR[3] = CVector3(x+0.08f,y+0.04f,z+0);	
	g_vBloksL[0] = CVector3(x+0,  y+0,   z+0);
	g_vBloksL[1] = CVector3(x+0,y+0,z+(-1.0f));
	g_vBloksL[2] = CVector3(x+0,y+0.04f,z+(-1.0f));
	g_vBloksL[3] = CVector3(x+0, y+ 0.04f,z+0);
	glBegin (GL_QUADS);
		glColor3ub(r, g, b);
		glVertex3f(g_vBloksP[0].x, g_vBloksP[0].y, g_vBloksP[0].z);
		glVertex3f(g_vBloksP[1].x, g_vBloksP[1].y, g_vBloksP[1].z);
		glVertex3f(g_vBloksP[2].x, g_vBloksP[2].y, g_vBloksP[2].z);
		glVertex3f(g_vBloksP[3].x, g_vBloksP[3].y, g_vBloksP[3].z);
	glEnd();
}

void Bloks::paint(float r, float g, float b)
{
	g_vBloksP[0] = CVector3(x,  y,   z);
	g_vBloksP[1] = CVector3(x+0.08f,y,z);
	g_vBloksP[2] = CVector3(x+0.08f,y+0.04f,z+0);
	g_vBloksP[3] = CVector3(x+0,y+0.04f,z+0);

	g_vBloksV[0] = CVector3(x+0,y+0.04f,z+0);
	g_vBloksV[1] = CVector3(x+0.08f, y+0.04f,z+0);
	g_vBloksV[2] = CVector3(x+0.08f,y+0.04f,z+(-1.0f));
	g_vBloksV[3] = CVector3(x+0,  y+0.04f,z+(-1.0f));

	g_vBloksN[0] = CVector3(x,y,z);
	g_vBloksN[1] = CVector3(x+0.08f, y,z);
	g_vBloksN[2] = CVector3(x+0.08f,y,z+(-1.0f));
	g_vBloksN[3] = CVector3(x+0,  y,z+(-1.0f));
	g_vBloksR[0] = CVector3(x+0.08f,y+0,z+0);
	g_vBloksR[1] = CVector3(x+0.08f,y+0,z+(-1.0f));
	g_vBloksR[2] = CVector3(x+0.08f,y+0.04f,z+(-1.0f));
	g_vBloksR[3] = CVector3(x+0.08f,y+0.04f,z+0);	
	g_vBloksL[0] = CVector3(x+0,  y+0,   z+0);
	g_vBloksL[1] = CVector3(x+0,y+0,z+(-1.0f));
	g_vBloksL[2] = CVector3(x+0,y+0.04f,z+(-1.0f));
	g_vBloksL[3] = CVector3(x+0, y+ 0.04f,z+0);
	glBegin (GL_QUADS);
		glColor3ub(r, g, b);
		glVertex3f(g_vBloksP[0].x, g_vBloksP[0].y, g_vBloksP[0].z);
		glVertex3f(g_vBloksP[1].x, g_vBloksP[1].y, g_vBloksP[1].z);
		glVertex3f(g_vBloksP[2].x, g_vBloksP[2].y, g_vBloksP[2].z);
		glVertex3f(g_vBloksP[3].x, g_vBloksP[3].y, g_vBloksP[3].z);
	glEnd();	
}
