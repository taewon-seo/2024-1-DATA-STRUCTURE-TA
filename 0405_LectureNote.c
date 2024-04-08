#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-04-08 update
/*
*****************
* 20240405 실습 *
*****************
*/

/* 

[ 실습 내용 ]
SLL의 주요 function들을 스스로 구현하기 (Online Judge) 
SLL을 거꾸로 뒤집어서 링크를 연결하기 (추가 학습)

*/

/*

[ SLL의 주요 Function ]

Struct Node

void add_to_SLL(int _v) < 1번 문제

void print_SLL(void) < 1번 문제

void del_from_SLL(int _v) < 2번 문제

void insert_into_SLL(int _nth, int _v) < 3번 문제

struct Node* reverse(struct Node* head) < 4번 문제

void destroy_SLL(void)

*/


#if 0
#include <stdio.h>
#include <stdlib.h>
// 1769: [2024 데이터구조 실습] SLL 구현 1

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// 새로운 노드 추가
void add_to_SLL(int _v) {

	// 새 노드 생성
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// 새 노드에 값 저장
	new_node->data = _v;
	// 새 노드의 끝 0
	new_node->next = 0;

	// 맨 앞일 경우, 새 노드가 head가 됨
	if (head == 0) {   
		head = new_node;
		return;
	}

	// 그렇지 않으면
	// head 복사
	struct Node* tmp = head;

	// SLL의 마지막(꼬리) 찾기
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// 맨 마지막(꼬리)와 새 노드 연결
	tmp->next = new_node;
	return;
}

// 모든 노드 출력
void print_SLL(void) {

	// head 찾고,
	// head 는 SLL의 이름과 같음, 수정되지 않도록 조심
	struct Node* tmp = head;

	while (1) {
		
		// 탈출 조건
		if (tmp == 0) {
			break;
		}

		// 꼬리 찾아가는 과정과 동일,
		// 찾아가며 출력
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	return;
}

int main() {

	int num = 0;
	int v = 0;

	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		scanf("%d", &v);
		add_to_SLL(v);
	}

	print_SLL();

	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

// 1770: [2024 데이터구조 실습] SLL 구현 2

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// 새로운 노드 추가
void add_to_SLL(int _v) {

	// 새 노드 생성
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// 새 노드에 값 저장
	new_node->data = _v;
	// 새 노드의 끝 0
	new_node->next = 0;

	// 맨 앞일 경우, 새 노드가 head가 됨
	if (head == 0) {
		head = new_node;
		return;
	}

	// 그렇지 않으면
	// head 복사
	struct Node* tmp = head;

	// SLL의 마지막(꼬리) 찾기
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// 맨 마지막(꼬리)와 새 노드 연결
	tmp->next = new_node;
	return;
}

// 모든 노드 출력
void print_SLL(void) {

	// head 찾고,
	// head 는 SLL의 이름과 같음, 수정되지 않도록 조심
	struct Node* tmp = head;

	while (1) {

		// 탈출 조건
		if (tmp == 0) {
			break;
		}

		// 꼬리 찾아가는 과정과 동일,
		// 찾아가며 출력
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	return;
}

// SLL 삭제
void del_from_SLL(int _v) {

	// 아무것도 없는 경우
	if (head == 0) {
		return;
	}

	// _v를 값으로 갖는 노드 찾기
	struct Node* tmp = head;

	while (1) {

		// 원하는 _v를 가진 노드를 찾았고,
		// 그것을 tmp가 가리키고 있음
		if (tmp->data == _v) {
			break;
		}
		tmp = tmp->next;

		// 찾는 것이 없으면 return
		if (tmp == 0) {
			return;
		}
	}

	// 지우려는 노드가 맨 앞 노드이면
	if (tmp == head) {
		// head 이동
		head = head->next;

		// head 삭제
		free(tmp);
		return;
	}

	// 지우려는 노드의 바로 앞 노드 찾기
	struct Node* tt = head;

	// tt를 움직여서 tt뒤에 tmp가 오도록 이동
	while (tt->next != tmp) {
		tt = tt->next;
	}

	// tt와 tmp 다음 노드를 연결
	tt->next = tmp->next;

	// tmp 삭제
	free(tmp);
	return;
}

int main() {

	int num = 0;
	int v = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &v);
		add_to_SLL(v);
	}

	int d = 0;
	scanf("%d", &d);

	del_from_SLL(d);
	
	print_SLL();

	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

// 1771: [2024 데이터구조 실습] SLL 구현 3

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// 새로운 노드 추가
void add_to_SLL(int _v) {

	// 새 노드 생성
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// 새 노드에 값 저장
	new_node->data = _v;
	// 새 노드의 끝 0
	new_node->next = 0;

	// 맨 앞일 경우, 새 노드가 head가 됨
	if (head == 0) {
		head = new_node;
		return;
	}

	// 그렇지 않으면
	// head 복사
	struct Node* tmp = head;

	// SLL의 마지막(꼬리) 찾기
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// 맨 마지막(꼬리)와 새 노드 연결
	tmp->next = new_node;
	return;
}

// 모든 노드 출력
void print_SLL(void) {

	// head 찾고,
	// head 는 SLL의 이름과 같음, 수정되지 않도록 조심
	struct Node* tmp = head;

	while (1) {

		// 탈출 조건
		if (tmp == 0) {
			break;
		}

		// 꼬리 찾아가는 과정과 동일,
		// 찾아가며 출력
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	return;
}

// SLL 삽입
// 0, 1, 2, 3, 4.... 번째 ===> _nth
// value to be inserted ==> _v
void insert_into_SLL(int _nth, int _v) {

	if (_nth < 0) {   // 음수 인덱스는 무시
		return;
	}
	// 아무것도 없는 경우
	if (head == 0) {
		return;
	}

	// _nth 번째 노드를 찾아가는 과정
	// tmp는 삽입하려는 위치 노드의 바로 앞 노드를 가리킴

	struct Node* tmp = head; // head부터 시작
	for (int i = 0; i < _nth - 1; i++) {

		tmp = tmp->next;
		if (tmp == 0) {
			// _nth가 없음
			return;
		}
	}

	// 새로운 노드 생성
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = _v;
	new_node->next = 0;

	// 맨 앞에 넣는 경우
	// 새 노드가 head 위치로
	if (_nth == 0) {
		new_node->next = head;
		head = new_node;
	}
	else {

		// 1. 뒷 노드와 연결
		new_node->next = tmp->next;
		// 2. 앞 노드와 연결
		tmp->next = new_node;
	}
}

int main() {

	int num = 0;
	int v = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &v);
		add_to_SLL(v);
	}

	int x, y;
	scanf("%d %d", &x, &y);

	insert_into_SLL(x, y);

	print_SLL();

	return 0;
}

#endif

#if 0

#include <stdio.h>
#include <stdlib.h>

// 1772: [2024 데이터구조 실습] SLL 구현 4
// SLL 역순으로 만들기

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// 새로운 노드 추가
void add_to_SLL(int _v) {

	// 새 노드 생성
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// 새 노드에 값 저장
	new_node->data = _v;
	// 새 노드의 끝 0
	new_node->next = 0;

	// 맨 앞일 경우, 새 노드가 head가 됨
	if (head == 0) {
		head = new_node;
		return;
	}

	// 그렇지 않으면
	// head 복사
	struct Node* tmp = head;

	// SLL의 마지막(꼬리) 찾기
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// 맨 마지막(꼬리)와 새 노드 연결
	tmp->next = new_node;
	return;
}

// 모든 노드 출력
void print_SLL(void) {

	// head 찾고,
	// head 는 SLL의 이름과 같음, 수정되지 않도록 조심
	struct Node* tmp = head;

	while (1) {

		// 탈출 조건
		if (tmp == 0) {
			break;
		}

		// 꼬리 찾아가는 과정과 동일,
		// 찾아가며 출력
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	return;
}
struct Node* reverse(struct Node* head) {

	// 순환 포인터 p, q, r 사용
	struct Node* p, * q, * r;

	p = head; // p는 역순으로 만들 리스트
	q = NULL; // q는 역순으로 만들 노드

	while (p != NULL) {
		r = q;

		q = p;
		p = p->next;
		q->next = r;
	}

	return q;
}

int main() {

	int num = 0;
	int v = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &v);
		add_to_SLL(v);
	}

	head = reverse(head);
	print_SLL();

	return 0;
}


#endif




#if 0

// SLL 전체 삭제
void destroy_SLL(void) {

	// bomb은 지워버릴 노드의 주소를 담고 있는 포인터 변수
	struct Node* bomb = 0;

	while (1) {

		// 모두 삭제
		if (head == 0) {
			break;
		}

		bomb = head;   // 폭탄 설치
		head = head->next;  // 다음 노드로 이동
		free(bomb);    // 삭제
	}
}

#endif