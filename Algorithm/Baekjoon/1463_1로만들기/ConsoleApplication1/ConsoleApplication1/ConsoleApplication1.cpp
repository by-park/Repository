﻿// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int ans = 1000000;

int calMin(int number, int howmany)
{
	if (number == 1) {
		if (ans > howmany) {
			ans = howmany;
		}
		return 0;
	}

	if (howmany > ans) {
		return 0; // 가지치기
	}

	if (number % 3 == 0) {
		calMin(number / 3, howmany+1);
	}
	if (number % 2 == 0) {
		calMin(number / 2, howmany+1);
	} 
	calMin(number-1, howmany+1);
}

int main()
{
	int N;
	std::cin >> N;
	calMin(N, 0);
	// 3으로 나눠지는가 -> 1을 빼면 3으로 나눠지는가?
	// 2로 나눠지는가? -> 1을 빼면 2로 나눠지는가?
	// 아무것도 아니면 그냥 1 빼기
    std::cout << ans << std::endl; 
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
