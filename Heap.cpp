#include "Heap.h"

void Heap::init()//�ʱ�ȭ
{
	heap_size = 0;//������ 0���� �ʱ�ȭ
}

bool Heap::heap_is_empty()//������ ������� Ȯ���ϴ� �Լ�
{
	if (heap_size == 0)//����� 0�̸� �� ��
		return true;
	else return false;
}

void Heap::insert_min_heap(element item)//���� �Լ�
{
	int i;
	i = ++(heap_size);//�����ϸ鼭 ���� ũ�� ����

	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < heap[i / 2].key))
		//i�� ��Ʈ�� 1�� �ƴϰ� i��° ��尡 i�� �θ� ��庸�� ������
	{
		heap[i] = heap[i / 2];//�θ� ���� ��ȯ
		i /= 2;//i�� �� �ܰ� ���==�θ� ��� ������ ���
	}

	heap[i] = item;//���ο� ��带 ����
}

element Heap::delete_min_heap()//���� �Լ�
{
	int parent, child;
	element item, temp;

	item = heap[1];//��Ʈ ����� ���� ����
	temp = heap[(heap_size)--];//���� �ϴ��� ��带 ��Ʈ�� �ű�� ���� ũ�� 1 ����
	parent = 1;
	child = 2;//��Ʈ�� ���ʺ��� �� ����
	while (child <= heap_size)//child�� ���� Ʈ���� ũ�⺸�� ������ == ���� Ʈ���� ����� ������
	{
		//���� ����� �ڽ� ��� �� �� ���� �ڽ� ��带 ã�´�
		if ((child < heap_size) && (heap[child].key) > heap[child + 1].key)
			//�ش� ��尡 ���� ������� �۰� ������ �ڽ��� �� ������
			child++;//����� ������ �ڽ����� ����
		if (temp.key <= heap[child].key)//���ϴ� ��忡�� ��Ʈ�� �ø� ����� ���� ��� ��庸�� ������
			break;//����

		//�� ���� �Ʒ��� �̵�
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;//�ش� ��带 �θ� ���� �ø�

	return item;//�ּ� �����̹Ƿ� �ּ� ������ ��ȯ
}