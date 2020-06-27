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
	bool is_seat_available(int number);//자리가 가능하면 빈자리 수를 사람 수만큼 감소
	void order(int scoops);//주문을 받으면 순익을 나타내는 변수를 증가시킨다
	void leave(int number);//고객이 떠나면 빈자리 수 증가
	void process_event(Heap* heap, element e);//이벤트 처리 함수
	void virtual_event();//가상의 이벤트 시뮬레이션 함수
};