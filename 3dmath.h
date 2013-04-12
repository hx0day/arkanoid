#ifndef _3DMATH_H
#define _3DMATH_H
 

#include <float.h>	// ����� ������������ _isnan() ��� acos()
 
#define PI 3.1415926535897932		// ��� ���������� �� %)

// ������� ��� ���������. ��� ����� ������������� ��� ������������ �������� ClassifySphere().
#define BEHIND		0	// ���� ����� ������ ���������
#define INTERSECTS	1	// ���� ����� ���������� ���������
#define FRONT		2	// ���� ����� ������� ���������


// ��� ��������� ������������ ��� �������� 3� ����� � ��������. ��� ��������������
// � ����� ������ �� ������, ��������� �����, ����� ������ �����������.
struct CVector3
{
public:

	// A default constructor
	CVector3() {}

	// This is our constructor that allows us to initialize our data upon creating an instance
	CVector3(float X, float Y, float Z)
	{
		x = X; y = Y; z = Z;
	}

	// Here we overload the + operator so we can add vectors together
	CVector3 operator+(CVector3 vVector)
	{
		// Return the added vectors result.
		return CVector3(vVector.x + x, vVector.y + y, vVector.z + z);
	}

	// Here we overload the - operator so we can subtract vectors
	CVector3 operator-(CVector3 vVector)
	{
		// Return the subtracted vectors result
		return CVector3(x - vVector.x, y - vVector.y, z - vVector.z);
	}

	// Here we overload the - operator so we can subtract vectors
	CVector3 operator*(float num)
	{
		// Return the subtracted vectors result
		return CVector3(x * num, y * num, z * num);
	}

	float x, y, z;
};
 
// ���������� ������, ���������������� ���� ���������� �������� (���������)
CVector3 Cross(CVector3 vVector1, CVector3 vVector2);
 
// ���������� ������ ����� 2�� �������.
CVector3 Vector(CVector3 vPoint1, CVector3 vPoint2);
 
// ���������� �������� ������� ��� ������ ������� �������
float Magnitude(CVector3 vNormal);
 
// ���������� ��������������� ������ (��� ������ ���������� ������ 1)
CVector3 Normalize(CVector3 vNormal);
 
// ���������� ������� �������� (�����������, ���� �������� �������)
CVector3 Normal(CVector3 vTriangle[]);

// ���������� ���������� ��������� �� ������ ��������� (0,0,0).
// ��������� ������� � ��������� � ����� �����, ������� �� ���� ���������:
float PlaneDistance(CVector3 Normal, CVector3 Point);
 
// ��������� ����������� (���������) � �����, � ���������� true ��� �� �����������.
bool IntersectedPlane(CVector3 vPoly[], CVector3 vLine[], CVector3 &vNormal, float &originDistance);
 
 
 
// ���������� dot product ����� ����� ���������
float Dot(CVector3 vVector1, CVector3 vVector2);
 
// ���������� ���� ����� ����� ���������
double AngleBetweenVectors(CVector3 Vector1, CVector3 Vector2);
 
// ���������� ����� ����������� �������� � ����� (��������������� ����������� ���������)
CVector3 IntersectionPoint(CVector3 vNormal, CVector3 vLine[], double distance);
 
// ���������� true ���� ����� ����������� ��������� ������ ��������
bool InsidePolygon(CVector3 vIntersection, CVector3 Poly[], long verticeCount);
 
// ����������� ��� ������� ��� ����� ����������� ����� � ��������
bool IntersectedPolygon(CVector3 vPoly[], CVector3 vLine[], int verticeCount);

// ���������� ���������� �������� ����������� �����
float Absolute(float num);
 
//	��������� ���������� ������������ ���� ��������
float Dot(CVector3 vVector1, CVector3 vVector2);
 
// ���������� ��������� ����� ����� 3D �������
float Distance(CVector3 vPoint1, CVector3 vPoint2);
 
// ���������� ����� �� ������� ����� vA___vB, ������� ����� ����� � vPoint
CVector3 ClosestPointOnLine(CVector3 vA, CVector3 vB, CVector3 vPoint);

// ��� �-� �������� ���, ��������� �� ����� �������, �����, ��� ���������� ���������. �����������
// ��������  - ����� �����, ������� ���������, ����� ���������, ������ ����� � ���������� ��� 
// �������� ���������.
int ClassifySphere(CVector3 &vCenter,CVector3 &vNormal, CVector3 &vPoint, float radius, float &distance);
 
// ���������� true, ���� ����� ���������� ����� ����������� ������������. ��������� ����� �����,
// ������, ������� �������� � �� �����. ������� ���������� ������ ���� �� ������ ��������� �������:
// ����� ������������ �� ������������, �� ����� ��� ����� ���� ������ ����.
bool EdgeSphereCollision(CVector3 &vPosition,CVector3 vPolygon[], int vertexCount, float radius);
 
// ���������� true, ���� ����� ���������� ���������� �������. ��������� - ������� ��������,
// �� �����, ����� � ������ �����.
bool SpherePolygonCollision(CVector3 vPolygon[], CVector3 &vCenter,int vertexCount, float radius);


#endif
