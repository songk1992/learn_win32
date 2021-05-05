#include "pch.h"
#include "framework.h"

// 출처 https://blog.naver.com/tipsware/221028018666
// 용도 코딩 공부 및 참조용
// 코드의 출처는 위에 블로그이며 자세한 내용이 무료로 설명과 함께 공개되어 있습니다.


// 사용자 메시지를 처리하는 함수
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY) PostQuitMessage(0);
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 윈도우 클래스 등록
	WNDCLASS wc;

	wchar_t my_class_name[] = L"nxver";
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = my_class_name;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	// 윈도우 생성
	HWND hWnd = CreateWindow(my_class_name, L"www.nxver.com",
		WS_OVERLAPPEDWINDOW, 100, 90, 400, 350, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// 프로그램에 전달된 메시지를 번역하고 실행하는 작업

	// 읽어온 메시지를 저장할 구조체
	MSG msg; 

	// 메시지를 큐에서 읽는 함수
	while (GetMessage(&msg, NULL, 0, 0)) {
		// 가상 키 메시지이면 ASCII 형태의 메시지를 추가로 생성
		TranslateMessage(&msg);
		// 변환된 메시지를 처리하는 함수
		DispatchMessage(&msg);
	}
	

	return msg.wParam;
}

