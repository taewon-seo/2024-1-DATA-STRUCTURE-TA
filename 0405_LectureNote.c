#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-04-08 update
/*
*****************
* 20240405 �ǽ� *
*****************
*/

/* 

[ �ǽ� ���� ]
SLL�� �ֿ� function���� ������ �����ϱ� (Online Judge) 
SLL�� �Ųٷ� ����� ��ũ�� �����ϱ� (�߰� �н�)

*/

/*

[ SLL�� �ֿ� Function ]

Struct Node

void add_to_SLL(int _v) < 1�� ����

void print_SLL(void) < 1�� ����

void del_from_SLL(int _v) < 2�� ����

void insert_into_SLL(int _nth, int _v) < 3�� ����

struct Node* reverse(struct Node* head) < 4�� ����

void destroy_SLL(void)

*/


#if 0
#include <stdio.h>
#include <stdlib.h>
// 1769: [2024 �����ͱ��� �ǽ�] SLL ���� 1

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// ���ο� ��� �߰�
void add_to_SLL(int _v) {

	// �� ��� ����
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// �� ��忡 �� ����
	new_node->data = _v;
	// �� ����� �� 0
	new_node->next = 0;

	// �� ���� ���, �� ��尡 head�� ��
	if (head == 0) {   
		head = new_node;
		return;
	}

	// �׷��� ������
	// head ����
	struct Node* tmp = head;

	// SLL�� ������(����) ã��
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// �� ������(����)�� �� ��� ����
	tmp->next = new_node;
	return;
}

// ��� ��� ���
void print_SLL(void) {

	// head ã��,
	// head �� SLL�� �̸��� ����, �������� �ʵ��� ����
	struct Node* tmp = head;

	while (1) {
		
		// Ż�� ����
		if (tmp == 0) {
			break;
		}

		// ���� ã�ư��� ������ ����,
		// ã�ư��� ���
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

// 1770: [2024 �����ͱ��� �ǽ�] SLL ���� 2

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// ���ο� ��� �߰�
void add_to_SLL(int _v) {

	// �� ��� ����
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// �� ��忡 �� ����
	new_node->data = _v;
	// �� ����� �� 0
	new_node->next = 0;

	// �� ���� ���, �� ��尡 head�� ��
	if (head == 0) {
		head = new_node;
		return;
	}

	// �׷��� ������
	// head ����
	struct Node* tmp = head;

	// SLL�� ������(����) ã��
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// �� ������(����)�� �� ��� ����
	tmp->next = new_node;
	return;
}

// ��� ��� ���
void print_SLL(void) {

	// head ã��,
	// head �� SLL�� �̸��� ����, �������� �ʵ��� ����
	struct Node* tmp = head;

	while (1) {

		// Ż�� ����
		if (tmp == 0) {
			break;
		}

		// ���� ã�ư��� ������ ����,
		// ã�ư��� ���
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	return;
}

// SLL ����
void del_from_SLL(int _v) {

	// �ƹ��͵� ���� ���
	if (head == 0) {
		return;
	}

	// _v�� ������ ���� ��� ã��
	struct Node* tmp = head;

	while (1) {

		// ���ϴ� _v�� ���� ��带 ã�Ұ�,
		// �װ��� tmp�� ����Ű�� ����
		if (tmp->data == _v) {
			break;
		}
		tmp = tmp->next;

		// ã�� ���� ������ return
		if (tmp == 0) {
			return;
		}
	}

	// ������� ��尡 �� �� ����̸�
	if (tmp == head) {
		// head �̵�
		head = head->next;

		// head ����
		free(tmp);
		return;
	}

	// ������� ����� �ٷ� �� ��� ã��
	struct Node* tt = head;

	// tt�� �������� tt�ڿ� tmp�� ������ �̵�
	while (tt->next != tmp) {
		tt = tt->next;
	}

	// tt�� tmp ���� ��带 ����
	tt->next = tmp->next;

	// tmp ����
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

// 1771: [2024 �����ͱ��� �ǽ�] SLL ���� 3

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// ���ο� ��� �߰�
void add_to_SLL(int _v) {

	// �� ��� ����
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// �� ��忡 �� ����
	new_node->data = _v;
	// �� ����� �� 0
	new_node->next = 0;

	// �� ���� ���, �� ��尡 head�� ��
	if (head == 0) {
		head = new_node;
		return;
	}

	// �׷��� ������
	// head ����
	struct Node* tmp = head;

	// SLL�� ������(����) ã��
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// �� ������(����)�� �� ��� ����
	tmp->next = new_node;
	return;
}

// ��� ��� ���
void print_SLL(void) {

	// head ã��,
	// head �� SLL�� �̸��� ����, �������� �ʵ��� ����
	struct Node* tmp = head;

	while (1) {

		// Ż�� ����
		if (tmp == 0) {
			break;
		}

		// ���� ã�ư��� ������ ����,
		// ã�ư��� ���
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	return;
}

// SLL ����
// 0, 1, 2, 3, 4.... ��° ===> _nth
// value to be inserted ==> _v
void insert_into_SLL(int _nth, int _v) {

	if (_nth < 0) {   // ���� �ε����� ����
		return;
	}
	// �ƹ��͵� ���� ���
	if (head == 0) {
		return;
	}

	// _nth ��° ��带 ã�ư��� ����
	// tmp�� �����Ϸ��� ��ġ ����� �ٷ� �� ��带 ����Ŵ

	struct Node* tmp = head; // head���� ����
	for (int i = 0; i < _nth - 1; i++) {

		tmp = tmp->next;
		if (tmp == 0) {
			// _nth�� ����
			return;
		}
	}

	// ���ο� ��� ����
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = _v;
	new_node->next = 0;

	// �� �տ� �ִ� ���
	// �� ��尡 head ��ġ��
	if (_nth == 0) {
		new_node->next = head;
		head = new_node;
	}
	else {

		// 1. �� ���� ����
		new_node->next = tmp->next;
		// 2. �� ���� ����
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

// 1772: [2024 �����ͱ��� �ǽ�] SLL ���� 4
// SLL �������� �����

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;


// ���ο� ��� �߰�
void add_to_SLL(int _v) {

	// �� ��� ����
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	// �� ��忡 �� ����
	new_node->data = _v;
	// �� ����� �� 0
	new_node->next = 0;

	// �� ���� ���, �� ��尡 head�� ��
	if (head == 0) {
		head = new_node;
		return;
	}

	// �׷��� ������
	// head ����
	struct Node* tmp = head;

	// SLL�� ������(����) ã��
	while (1) {
		if (tmp->next == 0) {
			break;
		}
		tmp = tmp->next;
	}
	// �� ������(����)�� �� ��� ����
	tmp->next = new_node;
	return;
}

// ��� ��� ���
void print_SLL(void) {

	// head ã��,
	// head �� SLL�� �̸��� ����, �������� �ʵ��� ����
	struct Node* tmp = head;

	while (1) {

		// Ż�� ����
		if (tmp == 0) {
			break;
		}

		// ���� ã�ư��� ������ ����,
		// ã�ư��� ���
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	return;
}
struct Node* reverse(struct Node* head) {

	// ��ȯ ������ p, q, r ���
	struct Node* p, * q, * r;

	p = head; // p�� �������� ���� ����Ʈ
	q = NULL; // q�� �������� ���� ���

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

// SLL ��ü ����
void destroy_SLL(void) {

	// bomb�� �������� ����� �ּҸ� ��� �ִ� ������ ����
	struct Node* bomb = 0;

	while (1) {

		// ��� ����
		if (head == 0) {
			break;
		}

		bomb = head;   // ��ź ��ġ
		head = head->next;  // ���� ���� �̵�
		free(bomb);    // ����
	}
}

#endif