#pragma once
#include <iostream>
#include <time.h>

using namespace std;

enum EVENTNUM
{
	EVENTNUM_ARRIVAL = 1,
	EVENTNUM_ORDER,
	EVENTNUM_LEAVE
};

#define MAX_ELEMENT 100

struct element
{
	EVENTNUM type;//이벤트 종류
	int key;//이벤트 시간
	int number;//고객의 숫자
};

inline int random(int n)//난수 생성 함수
{
	return rand() % n;
}