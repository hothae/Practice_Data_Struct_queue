/*
2022-01-03 C를 이용, 자료구조 큐(Queue) 구조 공부
스택과 다르게 선입선출(FIFO)형식. ex) 은행 번호표
스택은 top 과 bottom 을 기준으로 데이터를 다루지만,
큐는 Front 와 Rear 을 기준으로 데이터를 다룬다고 생각

Deletion - Front - array - Rear - Insertion

front : 큐의 맨 앞의 위치(인덱스), 다음 서비스를 받을 손님의 번호
rear : 큐의 맨 뒤의 위치(인덱스), 마지막에 온 손님의 번호

Enqueue : 큐 맨 뒤에 어떠한 요소를 추가, 마지막으로 온 손님에게 번호표 발부
Dequeue : 큐 맨 앞쪽의 요소를 삭제, 창구에서 서비스를 받은 손님의 번호표를 대기목록에서 삭제

원형큐가 아닌 경우를 코딩했음
따라서 Front배열에 있는 값을 추출한 이후에 Rear의 값이 SIZE 도달하게 되면 실제 큐에서의 배열에 빈공간이 생겼음에도
값이 들어가지 않음

author : 하태훈
ver : 1.0
*/
#include <stdio.h>
#define SIZE 10	//큐의 크기가 10

typedef struct {
	int Front;
	int Rear;
	int queue[SIZE];
}Queue;

void initQueue();			//배열 초기화 Front와 Rear의 값을 -1로 하고, 이전에 있던 값들을 NULL로 초기화
int isempty();				//조건에 따라 1 또는 0을 반환, Front와 Rear 값을 비교해, 배열이 비어있는지 확인
int  isfull()	;					//조건에 따라 1 또는 0을 반환, Rear와 SIZE 값을 비교해, 배열이 꽉 차있는지 확인
void Enq();					//rear번째 배열에 값을 집어넣을 함수
void Deq();					//front 배열에 있는 값을 추출후 제거
void printQueue();		//현재 배열에 담긴 값들 출력

int main() {
	Queue queue;
	initQueue(&queue);		//배열 초기화
	Enq(&queue, 1);				//rear번째 배열에 1을 집어넣고 rear의 값을 1 증가시킴

	Deq(&queue);					//Front에 있는 값을 추출후 제거

	printQueue(&queue);		//현재 배열에 담긴 값들 출력, 상태 확인용도
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
	if (isfull(p)) {							//isfull() 함수가 1을 반환했을 시(Rear와 SIZE 의 값이 같을 때) 실행
		printf("Queue is full\n");
	}
	else {
		p->queue[p->Rear++] = value;		//Rear 값의 시작이 -1 이므로 먼저 값을 증가 시킨 후 해당 배열에 값을 집어 넣음
	}
}

void Deq(Queue* p) {
	if	(isempty(p)) {					//isempty() 함수가 1을 반환했을 시 실행
		printf("Queue is empty\n");
	}
	else {
		printf("Front Value = %d\n", p->queue[p->Front++]);	//Front 값의 시작이 -1 이므로 먼저 값을 증가 시킨 후 해당 배열의 값을 출력
	}
}

void printQueue(Queue* p) {
	if (isempty(p)) {					//isempty() 함수가 1을 반환했을 시 실행
		printf("Queue is empty\n");
	}
	else {
		for (int i = 0; i <= p->Rear-1; i++) printf("%d\n", p->queue[i]);	//0번째부터 Rear번째 까지 담긴 배열의 값들을 일렬로 출력
	}
}

