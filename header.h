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
	EVENTNUM type;//�̺�Ʈ ����
	int key;//�̺�Ʈ �ð�
	int number;//���� ����
};

inline int random(int n)//���� ���� �Լ�
{
	return rand() % n;
}