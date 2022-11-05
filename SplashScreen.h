
//Headers
#include <Windows.h>
#include "Resource.h"
/*
//global function declerations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Entry Point Function -> WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declerations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ASTEROIDICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ASTEROIDICON));

	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("Ancient Asteroids"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//code
	HINSTANCE hInstance;
	static HBITMAP hBitmap;
	BITMAP bitmap;
	HDC hdc, cdc;
	RECT rect;
	PAINTSTRUCT paintStruct;
	switch (iMsg)
	{
	case WM_CREATE:
		hInstance = GetModuleHandle(NULL);
		hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_WSCREEN));
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &paintStruct);
		GetClientRect(hwnd, &rect);
		cdc = CreateCompatibleDC(hdc);
		SelectObject(cdc, hBitmap);
		GetObject(hBitmap, sizeof(BITMAP), &bitmap);
		StretchBlt(hdc, 0, 0, rect.right, rect.bottom, cdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		DeleteObject(cdc);
		EndPaint(hwnd, &paintStruct);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
*/
void DisplayScreen(HWND hwnd)
{
	HINSTANCE hInstance;
	static HBITMAP hBitmap;
	BITMAP bitmap;
	HDC hdc, cdc;
	RECT rect;
	PAINTSTRUCT paintStruct;
	hInstance = GetModuleHandle(NULL);
	hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_WSCREEN));
	hdc = BeginPaint(hwnd, &paintStruct);
	GetClientRect(hwnd, &rect);
	cdc = CreateCompatibleDC(hdc);
	SelectObject(cdc, hBitmap);
	GetObject(hBitmap, sizeof(BITMAP), &bitmap);
	StretchBlt(hdc, 0, 0, rect.right, rect.bottom, cdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	DeleteObject(cdc);
	EndPaint(hwnd, &paintStruct);
}