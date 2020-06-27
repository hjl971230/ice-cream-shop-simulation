#pragma once
#include "header.h"

class Heap//히프 구현
{
private:
	element heap[MAX_ELEMENT];//노드를 MAX 개수만큼 저장할 수 있는 배열
	int heap_size;//저장된 요소의 갯수
public:
	void init();//초기화
	bool heap_is_empty();//히프가 비었는지 확인하는 함수
	void insert_min_heap(element item);//삽입 함수
	element delete_min_heap();//삭제 함수
};

