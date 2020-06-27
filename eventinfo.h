#pragma once
#include "Heap.h"

class eventinfo
{
private:
	int free_seats;
	float profit;
	element event_element;
	Heap heap;
public:
	eventinfo() { free_seats = 10; profit = 0.0; }
	inline int getfree_seats() { return free_seats; }
	inline void setfree_seats(int i) { free_seats = i; }
	inline float getprofit() { return profit; }
	inline void setprofit(float i) { profit = i; }
	bool is_seat_available(int number);//�ڸ��� �����ϸ� ���ڸ� ���� ��� ����ŭ ����
	void order(int scoops);//�ֹ��� ������ ������ ��Ÿ���� ������ ������Ų��
	void leave(int number);//���� ������ ���ڸ� �� ����
	void process_event(Heap* heap, element e);//�̺�Ʈ ó�� �Լ�
	void virtual_event();//������ �̺�Ʈ �ùķ��̼� �Լ�
};