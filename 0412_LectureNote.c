#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-04-13 update
/*
*****************
* 20240412 실습 *
*****************
*/

/*

[ 실습 내용 ]
SLL을 거꾸로 뒤집어서 링크 연결 (역순 만들기)
DLL 구현 실습

*/


// DLL
// doubly linked list

#include <stdio.h>
#include <stdlib.h>  // malloc, free

#if 0 // 1772: [2024 데이터구조 실습] SLL 구현 4

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

#if 0 // 1774: [2024 데이터구조 실습] DLL 구현 1

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head = 0;

struct Node* createNode(int _v) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = _v;
	new_node->next = new_node->prev = 0;

	// 새로 만든 노드의 시작주소를 new_node가 가지고 있으므로,
	// 그 주소를 반환하기 위해서, new_node를 반환
	return new_node;
}

void add_to_DLL(int _v) {

	// 1. _v를 담는 새로운 노드를 생성
	struct Node* new_node = createNode(_v);

	// 2. DLL이 비어있으면, 새 노드는 haed가 됨
	if (head == 0) {
		head = new_node;
		return;
	}

	// 3. 아니면, 맨 마지막을 찾아가서, 그 뒤에 붙여넣기
	struct Node* temp = head;  // temp를 움직여서 맨 마지막을 가리키게 함.

	while (temp->next != 0) {
		temp = temp->next;
	}
	// 이제, temp는 맨 마지막 노드를 가리키고 있음
	new_node->prev = temp;
	temp->next = new_node;
	return;
}

void print_DLL(void) {

	struct Node* temp = head;
	while (temp != 0) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	return;
}


int main(void) {

	int num = 0;
	int d = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &d);
		add_to_DLL(d);
	}

	print_DLL();

	return 0;
}

#endif

#if 0 // 1775: [2024 데이터구조 실습] DLL 구현 2 - 뒤에 삽입

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head = 0;


struct Node* createNode(int _v) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = _v;
	new_node->next = new_node->prev = 0;
	return new_node;
}

void add_to_DLL(int _v) {

	struct Node* new_node = createNode(_v);

	if (head == 0) {
		head = new_node;
		return;
	}

	struct Node* temp = head;  

	while (temp->next != 0) {
		temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
	return;
}

void print_DLL(void) {

	struct Node* temp = head;
	while (temp != 0) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	return;
}

// find_Node
// _k를 담은 노드를 찾아서, 그 노드의 주소를 반환
// _k가 없으면 0을 반환하는 함수
struct Node* find_Node(int _k) {

	struct Node* temp = head;

	while (temp != 0) {
		if (temp->data == _k) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

// insert_after_DLL
// _k를 담은 노드를 찾아서,
// _v를 담은 노드를 그 뒤에 추가하는 함수
void insert_after_DLL(int _k, int _v) {

	// 1. _k를 담은 노드를 찾는다.
	struct Node* target = find_Node(_k);

	// 2. 없으면 return
	if (target == 0) {
		return;
	}
	// 3. 있으면,
	
	// 4. _v를 담은 새 노드 생성
	struct Node* new_node = createNode(_v);

	// 5. 경우의 수 
	// _k 뒤에 노드의 존재 여부에 따라 결정
	
	// 5.1 뒤에 노드가 존재하는 경우
	if (target->next != 0) {
		new_node->next = target->next; // 1.
		new_node->prev = target;       // 2.
		target->next = new_node;       // 3.
		new_node->next->prev = new_node; // 4.
	}
	else { 	// 5.2 뒤에 노드가 없는 경우
		new_node->prev = target; // 1.
		target->next = new_node; // 2.
	}
}

int main(void) {

	int num = 0;
	int d = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &d);
		add_to_DLL(d);
	}

	int k1 = 0;
	int k2 = 0;
	scanf("%d %d", &k1, &k2);
	
	insert_after_DLL(k1, k2);

	print_DLL();

	return 0;
}

#endif

#if 0 // 1776: [2024 데이터구조 실습] DLL 구현 - 삭제

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head = 0;

struct Node* createNode(int _v) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = _v;
	new_node->next = new_node->prev = 0;
	return new_node;
}

void add_to_DLL(int _v) {

	struct Node* new_node = createNode(_v);

	if (head == 0) {
		head = new_node;
		return;
	}

	struct Node* temp = head;

	while (temp->next != 0) {
		temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
	return;
}

void print_DLL(void) {

	struct Node* temp = head;
	if (temp == 0) {
		printf("-999");
	}
	while (temp != 0) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	return;
}

struct Node* find_Node(int _k) {

	struct Node* temp = head;

	while (temp != 0) {
		if (temp->data == _k) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

// del_from_DLL
// _k를 가진 노드를 찾아서 지우는 함수
void del_from_DLL(int _k) {

	while (1) {

		//1. _k를 가진 노드를 찾는다.
		struct Node* target = find_Node(_k);

		//2. 없으면, return
		if (target == 0) {
			return;
		}

		while (1) {
			//3. 있으면, 
	//3.1 지우려는 노드가 중간에 위치
			if (target->prev != 0 && target->next != 0) {
				target->prev->next = target->next;
				target->next->prev = target->prev;
				free(target);
				break;
			}

			// 맨 앞인데 혼자
			//3.2 맨 앞에 있는 경우, head 처리
			if (target == head) {
				// 맨 앞, 혼자
				if (target->next == 0) {
					head = 0;
					free(target);
					break;
				}
				// 맨 앞, 혼자가 아님
				else {
					head = head->next;
					head->prev = 0;
					free(target);
					break;
				}
			}

			//3.3 맨 끝
			if (target->next == 0) {
				target->prev->next = 0;
				free(target);
				break;
			}
		}
	}
}

int main(void) {

	int num = 0;
	int d = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &d);
		add_to_DLL(d);
	}

	int k = 0;
	
	scanf("%d", &k);

	del_from_DLL(k);

	print_DLL();

	return 0;
}

#endif
