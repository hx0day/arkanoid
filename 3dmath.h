#ifndef _3DMATH_H
#define _3DMATH_H
 

#include <float.h>	// Чтобы использовать _isnan() для acos()
 
#define PI 3.1415926535897932		// Наш знаменитый ПИ %)

// Сначала три константы. Они будут использоватся для возвращаемых значений ClassifySphere().
#define BEHIND		0	// Если сфера позади плоскости
#define INTERSECTS	1	// Если сфера пересекает плоскость
#define FRONT		2	// Если сфера спереди плоскости


// Эта структура используется для хранения 3д точек и векторов. Она использовалась
// в наших уроках по камере, вернитесь назад, чтобы узнать подробности.
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
 
// Возвращает вектор, перпендикулярный двум переданным векторам (плоскости)
CVector3 Cross(CVector3 vVector1, CVector3 vVector2);
 
// Возвращает вектор между 2мя точками.
CVector3 Vector(CVector3 vPoint1, CVector3 vPoint2);
 
// Возвращает величину нормали или любого другого вектора
float Magnitude(CVector3 vNormal);
 
// Возвращает нормализованный вектор (его длинна становится равной 1)
CVector3 Normalize(CVector3 vNormal);
 
// Возвращает нормаль полигона (направление, куда повернут полигон)
CVector3 Normal(CVector3 vTriangle[]);

// Возвращает расстояние плоскости от начала координат (0,0,0).
// Принимает нормаль к плоскости и ЛЮБУЮ точку, лежащую на этой плоскости:
float PlaneDistance(CVector3 Normal, CVector3 Point);
 
// Принимает треугольник (плоскость) и линию, и возвращает true при их пересечении.
bool IntersectedPlane(CVector3 vPoly[], CVector3 vLine[], CVector3 &vNormal, float &originDistance);
 
 
 
// Возвращяет dot product между двумя векторами
float Dot(CVector3 vVector1, CVector3 vVector2);
 
// Возвращает угол между двумя векторами
double AngleBetweenVectors(CVector3 Vector1, CVector3 Vector2);
 
// Возвращает точку пересечения полигона и линии (подразумевается пересечение плоскости)
CVector3 IntersectionPoint(CVector3 vNormal, CVector3 vLine[], double distance);
 
// Возвращает true если точка пересечения находится внутри полигона
bool InsidePolygon(CVector3 vIntersection, CVector3 Poly[], long verticeCount);
 
// Используйте эту функцию для теста пересечения линии и полигона
bool IntersectedPolygon(CVector3 vPoly[], CVector3 vLine[], int verticeCount);

// Возвращает абсолютное значение переданного числа
float Absolute(float num);
 
//	Результат скалярного произведения двух векторов
float Dot(CVector3 vVector1, CVector3 vVector2);
 
// Возвращает дистанцию между двумя 3D точками
float Distance(CVector3 vPoint1, CVector3 vPoint2);
 
// Возвращает точку на отрезке линии vA___vB, которая ближе всего к vPoint
CVector3 ClosestPointOnLine(CVector3 vA, CVector3 vB, CVector3 vPoint);

// Эта ф-я сообщает нам, находится ли сфера спереди, сзади, или пересекает плоскость. Принимаемые
// значения  - центр сферы, нормаль плоскости, точку плоскости, радиус сферы и переменную для 
// хранения дистанции.
int ClassifySphere(CVector3 &vCenter,CVector3 &vNormal, CVector3 &vPoint, float radius, float &distance);
 
// Возвращает true, если сфера пересекает ребро переданного треугольника. Принимает центр сферы,
// радиус, вершины полигона и их число. Функция вызывается только если не прошла следующая функция:
// ребра треугольника не пересекаются, но сфера ещё может быть внутри него.
bool EdgeSphereCollision(CVector3 &vPosition,CVector3 vPolygon[], int vertexCount, float radius);
 
// Возвращает true, если сфера пересекает переданный полигон. Параметры - вершины полигона,
// их число, центр и радиус сферы.
bool SpherePolygonCollision(CVector3 vPolygon[], CVector3 &vCenter,int vertexCount, float radius);


#endif
