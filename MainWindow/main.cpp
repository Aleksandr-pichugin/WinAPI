#include<windows.h>


CONST CHAR g_sz_MY_WINDOW_CLASS[] = "My Window";

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) ����������� ������ ����:
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

	//2)�������� ���� :
	HWND hwnd = CreateWindowEx
		(
			NULL,     //ExStyles
			g_sz_MY_WINDOW_CLASS,  //class name
			g_sz_MY_WINDOW_CLASS,  //Window title
			WS_OVERLAPPEDWINDOW,   //windown style
			CW_USEDEFAULT, CW_USEDEFAULT,    //Window position
			CW_USEDEFAULT, CW_USEDEFAULT,//window size
			NULL,  //Parent Window
			NULL,  ///Main menu ResourseID for MainWindow or ResourceID for childWindow
			hInstance,
			NULL
			);
	ShowWindow(hwnd, nCmdShow);//������ ����� ����������� ����
	                           //(���������� �� ���� �����, �������� � ���� , �������� � ������ �����)   

	UpdateWindow(hwnd);   // ������������� ����
	//3)������ ����� ���������:
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