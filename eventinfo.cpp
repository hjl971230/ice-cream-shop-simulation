#include "eventinfo.h"

bool eventinfo::is_seat_available(int number)//�ڸ��� �����ϸ� ���ڸ� ���� ��� ����ŭ ����
{
	cout << number << "���� �� ����" << endl;
	if (free_seats >= number)//�� �ڸ��� ������ �� ������ ũ��
	{
		free_seats -= number;//���� �� ����ŭ �¼� ����
		return true;
	}
	else
	{
		cout << "�ڸ� ����, �մ� ����" << endl;
		return false;
	}
}

void eventinfo::order(int scoops)//�ֹ��� ������ ������ ��Ÿ���� ������ ������Ų��
{
	cout << "���̽�ũ�� " << scoops << "�� �ֹ� ����" << endl;
	profit += 0.2 * scoops;//�����Ϳ� �ֹ�����ŭ ����
}

void eventinfo::leave(int number)//���� ������ ���ڸ� �� ����
{
	cout << number << "���� ������ ����" << endl;
	free_seats += number;//���� ����ŭ �� �¼� ����
}

void eventinfo::process_event(Heap* heap, element e)//�̺�Ʈ ó�� �Լ�
{
	int i = 0;
	element new_event;

	cout << "���� �ð� : " << e.key << endl;
	switch (e.type)
	{
	case EVENTNUM_ARRIVAL://�ڸ��� �����ϸ� �ֹ� �̺�Ʈ�� �����
		if (is_seat_available(e.number))//�ڸ��� �� ���
		{
			new_event.type = EVENTNUM_ORDER;//���� �̺�Ʈ ���� �ֹ�����
			new_event.key = e.key + 1 + random(5);
			//�̺�Ʈ �ð��� ���� �ð� + ������ ���� �ð�(������ ����, �ֹ��̹Ƿ� �ð� ���൵ ������)
			new_event.number = e.number;//���� �������� �ʾ����Ƿ� �� �״�� ����
			heap->insert_min_heap(new_event);//������ ����
		}
		break;
	case EVENTNUM_ORDER://��� ����ŭ �ֹ��� �޴´�
		for (i = 0; i < e.number; i++)//��� ����ŭ �ݺ�
			order(1 + random(3));//1~3�� ���� ������ �ֹ�
		//������ ������ �̺�Ʈ ����
		new_event.type = EVENTNUM_LEAVE;//���� �̺�Ʈ ���� ������ �̺�Ʈ��
		new_event.key = e.key + random(10);//���� ���� ���� ���� �� �ִ�
		new_event.number = e.number;//������ �������� �� �� ��ȭ ����
		heap->insert_min_heap(new_event);//������ �̺�Ʈ ����
		break;
	case EVENTNUM_LEAVE://���� ������ ���ڸ� �� ����
		leave(e.number);//�̺�Ʈ�� �� ����ŭ ����
		break;
	}
}

void eventinfo::virtual_event()//������ �̺�Ʈ �ùķ��̼� �Լ�
{
	int t = 0;

	heap.init();
	while (t < 10)//�ʱ� �̺�Ʈ � ����==�̺�Ʈ�� �� �� �����ΰ� ����
	{
		t += random(11);//�̺�Ʈ ���� ���� ����
		event_element.type = EVENTNUM_ARRIVAL;//�ʱ��̹Ƿ� �մ� ���� ��
		event_element.key = t;//�̺�Ʈ �ð��� �̺�Ʈ�� ��� ������ ����
		event_element.number = 1 + random(3);//�ش� �̺�Ʈ�� ������ 1~3������ ���� ����
		heap.insert_min_heap(event_element);//�ش� �̺�Ʈ�� ������ ����
	}

	while (!(heap.heap_is_empty()))//�ùķ��̼��� ����, ������ ��� ����
	{
		event_element = heap.delete_min_heap();//�ֻ���==��Ʈ�� ��� �̺�Ʈ���� �����ϸ� �ϳ��� �������� ����
		process_event(&heap, event_element);//�ش� �̺�Ʈ ����
	}

	cout << "��ü �������� " << profit << " �Դϴ�" << endl;//���� ������ ���
}