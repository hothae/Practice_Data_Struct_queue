/*
2022-01-03 C�� �̿�, �ڷᱸ�� ť(Queue) ���� ����
���ð� �ٸ��� ���Լ���(FIFO)����. ex) ���� ��ȣǥ
������ top �� bottom �� �������� �����͸� �ٷ�����,
ť�� Front �� Rear �� �������� �����͸� �ٷ�ٰ� ����

Deletion - Front - array - Rear - Insertion

front : ť�� �� ���� ��ġ(�ε���), ���� ���񽺸� ���� �մ��� ��ȣ
rear : ť�� �� ���� ��ġ(�ε���), �������� �� �մ��� ��ȣ

Enqueue : ť �� �ڿ� ��� ��Ҹ� �߰�, ���������� �� �մԿ��� ��ȣǥ �ߺ�
Dequeue : ť �� ������ ��Ҹ� ����, â������ ���񽺸� ���� �մ��� ��ȣǥ�� ����Ͽ��� ����

����ť�� �ƴ� ��츦 �ڵ�����
���� Front�迭�� �ִ� ���� ������ ���Ŀ� Rear�� ���� SIZE �����ϰ� �Ǹ� ���� ť������ �迭�� ������� ����������
���� ���� ����

author : ������
ver : 1.0
*/
#include <stdio.h>
#define SIZE 10	//ť�� ũ�Ⱑ 10

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
	Enq(&queue, 1);				//rear��° �迭�� 1�� ����ְ� rear�� ���� 1 ������Ŵ

	Deq(&queue);					//Front�� �ִ� ���� ������ ����

	printQueue(&queue);		//���� �迭�� ��� ���� ���, ���� Ȯ�ο뵵
}

void initQueue(Queue *p) {
	p->Front = 0;
	p->Rear = 0;
}

int isempty(Queue *p) {
	if (p->Rear <= p->Front) return 1;
	else return 0;
}

int isfull(Queue* p) {
	if (p->Rear >= SIZE) return 1;
	else return 0;
}

void Enq(Queue* p, int value) {
	if (isfull(p)) {							//isfull() �Լ��� 1�� ��ȯ���� ��(Rear�� SIZE �� ���� ���� ��) ����
		printf("Queue is full\n");
	}
	else {
		p->queue[p->Rear++] = value;		//Rear ���� ������ -1 �̹Ƿ� ���� ���� ���� ��Ų �� �ش� �迭�� ���� ���� ����
	}
}

void Deq(Queue* p) {
	if	(isempty(p)) {					//isempty() �Լ��� 1�� ��ȯ���� �� ����
		printf("Queue is empty\n");
	}
	else {
		printf("Front Value = %d\n", p->queue[p->Front++]);	//Front ���� ������ -1 �̹Ƿ� ���� ���� ���� ��Ų �� �ش� �迭�� ���� ���
	}
}

void printQueue(Queue* p) {
	if (isempty(p)) {					//isempty() �Լ��� 1�� ��ȯ���� �� ����
		printf("Queue is empty\n");
	}
	else {
		for (int i = 0; i <= p->Rear-1; i++) printf("%d\n", p->queue[i]);	//0��°���� Rear��° ���� ��� �迭�� ������ �Ϸķ� ���
	}
}

