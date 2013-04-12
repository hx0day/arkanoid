// Включаем необходимые библиотеки:
// OpelGL
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")
 
// Наш главный хидер:
#include "main.h"
#include "3dmath.h"
float speedx =-0.2f;
float speedy =0.1f;

Sphere shar(0.3f, 0.01f, 0); 
// Необходимые дескрипторы:
HWND  g_hWnd;
RECT  g_rRect;
HDC   g_hDC;
HGLRC g_hRC;
HINSTANCE g_hInstance;
Timer<> timer;
Quads stenka[3];
Bloks doska(0,-0.40,0);
// Массив из трех вершин для хранения координат треугольника
CVector3 g_vStenka[4],g_vStenka2[4],g_vStenka3[4];
CVector3 g_vDoska1[4],g_vDoska2[4],g_vDoska3[4];


// Центр нашей сферы. Мы сможем перемещать его клавишами-стрелками.
CVector3 g_vPosition;
 
// Текущее вращение камеры (F1 & F2)
float g_rotateY = 0;

///////////////////////////////////////////////////////////////
//
//			Функция вызывается каждый кадр и рендерит сцену
//
///////////////////////////////////////////////////////////////

void RenderScene()
{
	int i=0;
 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//gluLookAt(0.f, 0.0, -1.f,  0, 0.0f, 0,   0, 1, 0);
 gluLookAt(0.f, 0.0, 1.f,  0, 0.0f, 0,   0, 1, 0);
 
	// Врощаем камеру на угол g_rotateY
	//glRotatef(g_rotateY, 0, 1, 0);
 
	// устанавливаем радиус сферы
	float radius = 0.02f;
 
	// Рисуем полигон/*
	doska.paint(150,150,150);
	
	// Move the sphere to it's center position
	glTranslatef(g_vPosition.x, g_vPosition.y, g_vPosition.z);
 
	glColor3ub(255, 0, 255);
	
	// Рисуем сферу с радиусом .1 и детальностью 15х15.
	  timer.stop();
	  float h = timer();
  timer.start();
  shar.move(h,speedx,speedy);
	g_vPosition= shar.g_vPosition;
 
  shar.paint(radius,5000);
 
	// Теперь воспользуемся замечательной функцией, которая сделает всё за нас.
	// Всё, что нам нужно сделать - передать в неё массив вершин треугольника,
	// центр сферы и её радиус. Функция вернёт true/false в зависимости от
	// факта пересечения.
	bool bCollided = SpherePolygonCollision(stenka[0].g_vQuads, g_vPosition, 4, radius);

bool bCollided2 = SpherePolygonCollision(stenka[1].g_vQuads, g_vPosition, 4, radius);
bool bCollided3 = SpherePolygonCollision(stenka[2].g_vQuads, g_vPosition, 4, radius);
bool bCollided4 = SpherePolygonCollision(doska.g_vBloksP, g_vPosition, 4, radius);
bool bCollided5 = SpherePolygonCollision(doska.g_vBloksL, g_vPosition, 4, radius);
bool bCollided6 = SpherePolygonCollision(doska.g_vBloksR, g_vPosition, 4, radius);

	// Если есть пересечение, делаем сферу зеленой, иначе - фиолетовой
	if(bCollided||bCollided4)
		{
			speedy*=-1;
			 			
		}
	
	if(bCollided2||bCollided3){
 			speedx*=-1;
	}
	if((bCollided5||bCollided6)){
 			speedx*=-1;
			speedy*=-1;
	}
	if((bCollided5&&bCollided4)||(bCollided6&&bCollided4))
	{
			speedx*=-1;
			speedy*=-1;
	}
	SwapBuffers(g_hDC);
}

///////////////////////////////////////////////////////////////
//
//			Инициализирует игровое окно
//
///////////////////////////////////////////////////////////////
 
void Init(HWND hWnd)
{
	g_hWnd = hWnd;
	GetClientRect(g_hWnd, &g_rRect);
	InitializeOpenGL(g_rRect.right, g_rRect.bottom);	// Init OpenGL with the global rect
 
	// Здесь мы инициализируем наш треугольник. Помните, имеет значение,
	// в каком порядке вы инициализируете вершины. Это важно, поскольку
	// исходя из этого будет рассчитыватся нормаль. Мы обьявим вершины
	// против часовой стрелки - нижнюю-левую, нижнюю-правую, и наконец верхнюю.
	g_vStenka[0] = CVector3(-1,  0.41f,   -10);
	g_vStenka[1] = CVector3( 1,  0.41f,   -10);
	g_vStenka[2] = CVector3( 1,  0.41f,   10);
	g_vStenka[3] = CVector3( -1,  0.41f,   10);
	stenka[0].mas(g_vStenka[0],g_vStenka[1],g_vStenka[2],g_vStenka[3]);

	g_vStenka2[0] = CVector3(-0.55f,  1,   -10);
	g_vStenka2[1] = CVector3( -0.55f,  -1,   -10);
	g_vStenka2[2] = CVector3( -0.55f,  -1,   10);
	g_vStenka2[3] = CVector3( -0.55f,  1,   10);
	stenka[1].mas(g_vStenka2[0],g_vStenka2[1],g_vStenka2[2],g_vStenka2[3]);
	g_vStenka3[0] = CVector3(0.55f,  1,   -10);
	g_vStenka3[1] = CVector3(0.55f,  -1,   -10);
	g_vStenka3[2] = CVector3(0.55f,  -1,   10);
	g_vStenka3[3] = CVector3(0.55f,  1,   10);
	stenka[2].mas(g_vStenka3[0],g_vStenka3[1],g_vStenka3[2],g_vStenka3[3]);
	

	
	// Теперь инициализируем позицию центра сферы.
	
}
 
///////////////////////////////////////////////////////////////
//
//			Главный цикл
//
///////////////////////////////////////////////////////////////
 
WPARAM MainLoop()
{
	MSG msg;
 
	while(1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
			if(msg.message == WM_QUIT)
				break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
		else
		{
			CheckForMovement();
			RenderScene();
        }
	}
 
	DeInit();
 
	return(msg.wParam);
}
///////
void CheckForMovement()
{
    // Функция GetKeyState() возвращает true или false
    // в зависимости от того, нажата ли переданная ей клавиша.
    if(GetKeyState(VK_UP) & 0x80 || GetKeyState('W') & 0x80)
		speedx*=-1;

  //  if(GetKeyState(VK_DOWN) & 0x80 || GetKeyState('S') & 0x80)
        //g_Camera.MoveCamera(-kSpeed);

    //Вращаем вокруг оси Y
    if(GetKeyState(VK_LEFT) & 0x80 || GetKeyState('A') & 0x80)         // Если нажали "влево"
		doska.mouvL();    

   if(GetKeyState(VK_RIGHT) & 0x80 || GetKeyState('D') & 0x80 )        // Если "вправо"
    doska.mouvR();
}
 
///////////////////////////////////////////////////////////////
//
//			Обработка сообщений windows
//
///////////////////////////////////////////////////////////////
 
LRESULT CALLBACK WinProc(HWND hWnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LONG    lRet = 0;
    PAINTSTRUCT    ps;
 
    switch (uMsg)
	{
    case WM_SIZE:		// Если изменён размер окна
 
		SizeOpenGLScreen(LOWORD(lParam),HIWORD(lParam));// LoWord=Width, HiWord=Height
		GetClientRect(hWnd, &g_rRect);		// получаем window rectangle
        break;
 
	case WM_PAINT:			// Если нужно перерисовать сцену
		BeginPaint(hWnd, &ps);	// Иниц. paint struct
		EndPaint(hWnd, &ps);	// EndPaint, подчищаем
		break;
 
	case WM_KEYDOWN:
		switch(wParam)
		{
			case VK_ESCAPE:
				PostQuitMessage(0);
				break;
 
			
		}
 
		break;
 
    case WM_CLOSE:		// Если окно было закрыто
        PostQuitMessage(0);	// Выходим
        break;
 
    default:		// Return по умолчанию
        lRet = DefWindowProc (hWnd, uMsg, wParam, lParam);
        break;
    }
 
    return lRet;
}