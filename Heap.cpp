#include "Heap.h"

void Heap::init()//초기화
{
	heap_size = 0;//사이즈 0으로 초기화
}

bool Heap::heap_is_empty()//히프가 비었는지 확인하는 함수
{
	if (heap_size == 0)//사이즈가 0이면 빈 것
		return true;
	else return false;
}

void Heap::insert_min_heap(element item)//삽입 함수
{
	int i;
	i = ++(heap_size);//삽입하면서 히프 크기 증가

	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < heap[i / 2].key))
		//i가 루트인 1이 아니고 i번째 노드가 i의 부모 노드보다 작으면
	{
		heap[i] = heap[i / 2];//부모 노드와 교환
		i /= 2;//i는 한 단계 상승==부모 노드 레벨로 상승
	}

	heap[i] = item;//새로운 노드를 삽입
}

element Heap::delete_min_heap()//삭제 함수
{
	int parent, child;
	element item, temp;

	item = heap[1];//루트 노드의 값을 저장
	temp = heap[(heap_size)--];//제일 하단의 노드를 루트로 옮기고 히프 크기 1 감소
	parent = 1;
	child = 2;//루트의 왼쪽부터 비교 시작
	while (child <= heap_size)//child가 히프 트리의 크기보다 작으면 == 히프 트리를 벗어나지 않으면
	{
		//현재 노드의 자식 노드 중 더 작은 자식 노드를 찾는다
		if ((child < heap_size) && (heap[child].key) > heap[child + 1].key)
			//해당 노드가 히프 사이즈보다 작고 오른쪽 자식이 더 작으면
			child++;//대상을 오른쪽 자식으로 변경
		if (temp.key <= heap[child].key)//최하단 노드에서 루트로 올릴 노드의 값이 대상 노드보다 작으면
			break;//종료

		//한 레벨 아래로 이동
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;//해당 노드를 부모 노드로 올림

	return item;//최소 히프이므로 최소 노드부터 반환
}