/*
2022-01-03 C를 이용, 자료구조 큐(Queue) 구조 공부
스택과 다르게 선입선출(FIFO)형식. ex) 은행 번호표
스택은 top 과 bottom 을 기준으로 데이터를 다루지만,
큐는 Front 와 Rear 을 기준으로 데이터를 다룬다고 생각

Deletion - Front - array - Rear - Insertion

front : 큐의 맨 앞의 위치(인덱스), 다음 서비스를 받을 손님의 번호
rear : 큐의 맨 뒤의 위치(인덱스), 마지막에 온 손님의 번호

Enqueue : 큐 맨 뒤에 어떠한 요소를 추가, 마지막으로 온 손님에게 번호표 발부
Dequeue : 큐 맨 앞쪽의 요소를 출력후 삭제, 창구에서 서비스를 받은 손님의 번호표를 대기목록에서 삭제

일반 큐 단점을 보완한 원형큐 구현
Deq함수로 Front번째 배열의 값을 출력 후 Front 값을 1 증가 시켰을 때,
만약 Rear 값이 SIZE에 도달 한 이후 Enq함수 사용했을 때, 증가시키기 전의 Front번째 배열의 값을 수정함
또한, 출력을 위한 함수 Deq와 printQueue 함수 둘다 수정해줘야 함

author : 하태훈
ver : 1.1
*/

#include <stdio.h>
#define SIZE 5	//큐의 크기가 10

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

	Enq(&queue, 1);				//배열의 0번째가아닌 1번째에 값이 들어감
	Enq(&queue, 2);				//배열의 2번째에 값이 들어감
	Deq(&queue);					//배열의 1번째 값이 추출

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
	if (isfull(p)) {							//isfull() 함수가 1을 반환했을 시 실행
		printf("Queue is full\n");
	}
	else {
		p->queue[(++p->Rear)%SIZE] = value;		//Rear 맨처음 0 번째 배열의 값이 비어있고 1번째 배열에 값이 들어감
	}
}

void Deq(Queue* p) {
	if (isempty(p)) {					//isempty() 함수가 1을 반환했을 시 실행
		printf("Queue is empty\n");
	}
	else {
		printf("Front Value = %d\n", p->queue[(++p->Front)%SIZE]);	//맨 처음 0 번째 배열의 값이 비어있으므로 1번째 배열에 값이 추출
	}
}

void printQueue(Queue* p) {
	if (isempty(p)) {					//isempty() 함수가 1을 반환했을 시 실행
		printf("Queue is empty\n");
	}
	else {
		for (int i = 0; i < SIZE; i++) printf("%d\n", p->queue[i]);	//0번째부터 Rear번째 까지 담긴 배열의 값들을 일렬로 출력 상태확인용
	}
}