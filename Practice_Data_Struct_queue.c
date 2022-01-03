/*
2022-01-03 C�� �̿�, �ڷᱸ�� ť(Queue) ���� ����
���ð� �ٸ��� ���Լ���(FIFO)����. ex) ���� ��ȣǥ
������ top �� bottom �� �������� �����͸� �ٷ�����,
ť�� Front �� Rear �� �������� �����͸� �ٷ�ٰ� ����

Deletion - Front - array - Rear - Insertion

front : ť�� �� ���� ��ġ(�ε���), ���� ���񽺸� ���� �մ��� ��ȣ
rear : ť�� �� ���� ��ġ(�ε���), �������� �� �մ��� ��ȣ

Enqueue : ť �� �ڿ� ��� ��Ҹ� �߰�, ���������� �� �մԿ��� ��ȣǥ �ߺ�
Dequeue : ť �� ������ ��Ҹ� ����� ����, â������ ���񽺸� ���� �մ��� ��ȣǥ�� ����Ͽ��� ����

�Ϲ� ť ������ ������ ����ť ����
Deq�Լ��� Front��° �迭�� ���� ��� �� Front ���� 1 ���� ������ ��,
���� Rear ���� SIZE�� ���� �� ���� Enq�Լ� ������� ��, ������Ű�� ���� Front��° �迭�� ���� ������
����, ����� ���� �Լ� Deq�� printQueue �Լ� �Ѵ� ��������� ��

author : ������
ver : 1.1
*/

#include <stdio.h>
#define SIZE 5	//ť�� ũ�Ⱑ 10

typedef struct {
	int Front;
	int Rear;
	int queue[SIZE];
}Queue;

void initQueue();			//�迭 �ʱ�ȭ Front�� Rear�� ���� -1�� �ϰ�, ������ �ִ� ������ NULL�� �ʱ�ȭ
int isempty();				//���ǿ� ���� 1 �Ǵ� 0�� ��ȯ, Front�� Rear ���� ����, �迭�� ����ִ��� Ȯ��
int  isfull()	;					//���ǿ� ���� 1 �Ǵ� 0�� ��ȯ, Rear�� SIZE ���� ����, �迭�� �� ���ִ��� Ȯ��
void Enq();					//rear��° �迭�� ���� ������� �Լ�
void Deq();					//front �迭�� �ִ� ���� ������ ����
void printQueue();		//���� �迭�� ��� ���� ���

int main() {
	Queue queue;
	initQueue(&queue);		//�迭 �ʱ�ȭ

	Enq(&queue, 1);				//�迭�� 0��°���ƴ� 1��°�� ���� ��
	Enq(&queue, 2);				//�迭�� 2��°�� ���� ��
	Deq(&queue);					//�迭�� 1��° ���� ����

}

void initQueue(Queue *p) {
	p->Front = 0;
	p->Rear = 0;
}

int isempty(Queue *p) {
	if (p->Rear == p->Front) return 1;
	else return 0;
}

int isfull(Queue* p) {
	if ( p->Front > p->Rear) return 1;
	else return 0;
}

void Enq(Queue* p, int value) {
	if (isfull(p)) {							//isfull() �Լ��� 1�� ��ȯ���� �� ����
		printf("Queue is full\n");
	}
	else {
		p->queue[(++p->Rear)%SIZE] = value;		//Rear ��ó�� 0 ��° �迭�� ���� ����ְ� 1��° �迭�� ���� ��
	}
}

void Deq(Queue* p) {
	if (isempty(p)) {					//isempty() �Լ��� 1�� ��ȯ���� �� ����
		printf("Queue is empty\n");
	}
	else {
		printf("Front Value = %d\n", p->queue[(++p->Front)%SIZE]);	//�� ó�� 0 ��° �迭�� ���� ��������Ƿ� 1��° �迭�� ���� ����
	}
}

void printQueue(Queue* p) {
	if (isempty(p)) {					//isempty() �Լ��� 1�� ��ȯ���� �� ����
		printf("Queue is empty\n");
	}
	else {
		for (int i = 0; i < SIZE; i++) printf("%d\n", p->queue[i]);	//0��°���� Rear��° ���� ��� �迭�� ������ �Ϸķ� ��� ����Ȯ�ο�
	}
}