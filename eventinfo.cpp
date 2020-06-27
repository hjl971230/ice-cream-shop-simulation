#include "eventinfo.h"

bool eventinfo::is_seat_available(int number)//자리가 가능하면 빈자리 수를 사람 수만큼 감소
{
	cout << number << "명의 고객 도착" << endl;
	if (free_seats >= number)//빈 자리가 도착한 고객 수보다 크면
	{
		free_seats -= number;//도착 고객 수만큼 좌석 감소
		return true;
	}
	else
	{
		cout << "자리 없음, 손님 떠남" << endl;
		return false;
	}
}

void eventinfo::order(int scoops)//주문을 받으면 순익을 나타내는 변수를 증가시킨다
{
	cout << "아이스크림 " << scoops << "개 주문 받음" << endl;
	profit += 0.2 * scoops;//순이익에 주문량만큼 증가
}

void eventinfo::leave(int number)//고객이 떠나면 빈자리 수 증가
{
	cout << number << "명이 매장을 떠남" << endl;
	free_seats += number;//떠난 수만큼 빈 좌석 증가
}

void eventinfo::process_event(Heap* heap, element e)//이벤트 처리 함수
{
	int i = 0;
	element new_event;

	cout << "현재 시간 : " << e.key << endl;
	switch (e.type)
	{
	case EVENTNUM_ARRIVAL://자리가 가능하면 주문 이벤트를 만든다
		if (is_seat_available(e.number))//자리가 빈 경우
		{
			new_event.type = EVENTNUM_ORDER;//다음 이벤트 값은 주문으로
			new_event.key = e.key + 1 + random(5);
			//이벤트 시간은 현재 시간 + 무작위 값의 시간(무작위 도착, 주문이므로 시간 진행도 무작위)
			new_event.number = e.number;//고객이 떠나지는 않았으므로 값 그대로 저장
			heap->insert_min_heap(new_event);//히프에 삽입
		}
		break;
	case EVENTNUM_ORDER://사람 수만큼 주문을 받는다
		for (i = 0; i < e.number; i++)//사람 수만큼 반복
			order(1 + random(3));//1~3개 사이 무작위 주문
		//매장을 떠나는 이벤트 생성
		new_event.type = EVENTNUM_LEAVE;//다음 이벤트 값은 떠나는 이벤트로
		new_event.key = e.key + random(10);//떠날 때는 전부 떠날 수 있다
		new_event.number = e.number;//떠나기 전까지는 고객 수 변화 없음
		heap->insert_min_heap(new_event);//히프에 이벤트 저장
		break;
	case EVENTNUM_LEAVE://고객이 떠나면 빈자리 수 증가
		leave(e.number);//이벤트의 고객 수만큼 떠남
		break;
	}
}

void eventinfo::virtual_event()//가상의 이벤트 시뮬레이션 함수
{
	int t = 0;

	heap.init();
	while (t < 10)//초기 이벤트 몇개 생성==이벤트를 몇 개 만들어두고 쌓음
	{
		t += random(11);//이벤트 생성 갯수 랜덤
		event_element.type = EVENTNUM_ARRIVAL;//초기이므로 손님 입장 뿐
		event_element.key = t;//이벤트 시간을 이벤트의 노드 값으로 저장
		event_element.number = 1 + random(3);//해당 이벤트의 고객수는 1~3명으로 랜덤 저장
		heap.insert_min_heap(event_element);//해당 이벤트를 히프에 삽입
	}

	while (!(heap.heap_is_empty()))//시뮬레이션을 수행, 히프가 비면 종료
	{
		event_element = heap.delete_min_heap();//최상위==루트의 노드 이벤트부터 실행하며 하나씩 히프에서 꺼냄
		process_event(&heap, event_element);//해당 이벤트 실행
	}

	cout << "전체 순이익은 " << profit << " 입니다" << endl;//최종 순이익 출력
}