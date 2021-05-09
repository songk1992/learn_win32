#include "pch.h"
#include "framework.h"

// 출처 https://blog.naver.com/tipsware/221028018666
// 용도 코딩 공부 및 참조용
// 코드의 출처 및 참조는 위에 블로그이며 자세한 내용이 무료로 설명과 함께 공개되어 있습니다.
// 해당 블로그의 라이센스를 전적으로 따르며
// 코딩적인 부분만 참조해서 배워서 응용하는 부분입니다.
// 자세한 내용은 해당 블로그 참조
// 저작자표시-비영리-변경금지 2.0 대한민국 (CC BY-NC-ND 2.0 KR)


// 사용자 메시지를 처리하는 함수
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// 새로운 윈도우가 만들어진 경우
	if (uMsg == WM_CREATE) {
		CREATESTRUCT *p_create_type = (CREATESTRUCT *)lParam;
		return 0;
	}



	// 윈도우의 그림을 다시 그려야 하는 경우
	else if (uMsg == WM_PAINT) {
		PAINTSTRUCT ps;
		HDC h_dc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
		return 1;
	}

	// 마우스 왼쪽 클릭시 발생
	else if (uMsg == WM_LBUTTONDOWN) 
	{
		if (uMsg == WM_LBUTTONDOWN) {
			int x = LOWORD(lParam); // 하위 16비트
			int y = HIWORD(lParam); // 상위 16비트

			x -= 15;
			y -= 15;

			POINT polygon[10] = { x, y, x+30, y, x + 30, y + 30, x, y+30  };
			HDC h_dc = GetDC(hWnd);
			Polygon(h_dc, polygon, 4);
			ReleaseDC(hWnd, h_dc);
		}
	} 
	else if (uMsg == WM_DESTROY) PostQuitMessage(0);


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

