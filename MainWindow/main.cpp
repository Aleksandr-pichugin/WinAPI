#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<cstdio>

CONST CHAR g_sz_MY_WINDOW_CLASS[] = "My Window";

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.style = 0;
	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;  // cb... -Count Bytes

	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wc.hInstance = hInstance;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_MY_WINDOW_CLASS;
	wc.lpfnWndProc = (WNDPROC)WndProc;


	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", NULL, MB_OK | MB_ICONERROR);
		return 0;
	}

	//2)Создание окна :

	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);


	INT window_width = screen_width * 3 / 4;
	INT window_height = screen_height * .75;
	INT window_start_x = screen_width / 8;
	INT window_start_y = window_height / 8;

	HWND hwnd = CreateWindowEx
		(
			NULL,     //ExStyles
			g_sz_MY_WINDOW_CLASS,  //class name
			g_sz_MY_WINDOW_CLASS,  //Window title
			WS_OVERLAPPEDWINDOW,   //windown style
			window_start_x, window_start_y,    //Window position
			window_width, window_height,//window size
			NULL,  //Parent Window
			NULL,  ///Main menu ResourseID for MainWindow or ResourceID for childWindow
			hInstance,
			NULL
			);
	ShowWindow(hwnd, nCmdShow);//Задает режим отображения окна
	                           //(Развернута на весь экран, свернуто в окно , свернуто в панель задач)   

	UpdateWindow(hwnd);   // прорисовывает окно
	//3)Запуск цикла сообщений:
	MSG msg;// 
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.message;
	return 0;
}
INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
			break;
	case WM_MOVE:
	case WM_SIZE:
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		INT window_width = rect.right - rect.left;
		INT window_height = rect.bottom - rect.top;
		CONST INT SIZE = 256;
		CHAR sz_title[SIZE]{};
		sprintf(sz_title, "%s - Position:%ix%i;\tSize: %ix%i", g_sz_MY_WINDOW_CLASS, rect.left, rect.top,
			window_width, window_height);
		//Функция sprintf(dst,src, parameters) форматирует src-строку , и результат форматирования сохраняет в другую строку
		// dst-строка получатель 
		//src- Sourse (строка источник) .Как правило является форматированной строкой.
		// Которые подменяются соответствующими параметрамию
		// %i - На место этого спецификатора встовляются значения типа 'int'
		// %s - на место этого спецификатора вставляется значения типа 'char'
		// ...f-format
		//s... -string
		// printf()- print formated string (Вывести на экран отформатированную строку ).
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_title);
	}

		break;
	case WM_COMMAND:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:  return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;

}