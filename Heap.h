#pragma once
#include "header.h"

class Heap//���� ����
{
private:
	element heap[MAX_ELEMENT];//��带 MAX ������ŭ ������ �� �ִ� �迭
	int heap_size;//����� ����� ����
public:
	void init();//�ʱ�ȭ
	bool heap_is_empty();//������ ������� Ȯ���ϴ� �Լ�
	void insert_min_heap(element item);//���� �Լ�
	element delete_min_heap();//���� �Լ�
};

