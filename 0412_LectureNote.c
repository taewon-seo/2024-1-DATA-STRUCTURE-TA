#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-04-13 update
/*
*****************
* 20240412 �ǽ� *
*****************
*/

/*

[ �ǽ� ���� ]
SLL�� �Ųٷ� ����� ��ũ ���� (���� �����)
DLL ���� �ǽ�

*/


// DLL
// doubly linked list

#include <stdio.h>
#include <stdlib.h>  // malloc, free

#if 0 // 1772: [2024 �����ͱ��� �ǽ�] SLL ���� 4

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

#if 0 // 1774: [2024 �����ͱ��� �ǽ�] DLL ���� 1

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

	// ���� ���� ����� �����ּҸ� new_node�� ������ �����Ƿ�,
	// �� �ּҸ� ��ȯ�ϱ� ���ؼ�, new_node�� ��ȯ
	return new_node;
}

void add_to_DLL(int _v) {

	// 1. _v�� ��� ���ο� ��带 ����
	struct Node* new_node = createNode(_v);

	// 2. DLL�� ���������, �� ���� haed�� ��
	if (head == 0) {
		head = new_node;
		return;
	}

	// 3. �ƴϸ�, �� �������� ã�ư���, �� �ڿ� �ٿ��ֱ�
	struct Node* temp = head;  // temp�� �������� �� �������� ����Ű�� ��.

	while (temp->next != 0) {
		temp = temp->next;
	}
	// ����, temp�� �� ������ ��带 ����Ű�� ����
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

#if 0 // 1775: [2024 �����ͱ��� �ǽ�] DLL ���� 2 - �ڿ� ����

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
// _k�� ���� ��带 ã�Ƽ�, �� ����� �ּҸ� ��ȯ
// _k�� ������ 0�� ��ȯ�ϴ� �Լ�
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
// _k�� ���� ��带 ã�Ƽ�,
// _v�� ���� ��带 �� �ڿ� �߰��ϴ� �Լ�
void insert_after_DLL(int _k, int _v) {

	// 1. _k�� ���� ��带 ã�´�.
	struct Node* target = find_Node(_k);

	// 2. ������ return
	if (target == 0) {
		return;
	}
	// 3. ������,
	
	// 4. _v�� ���� �� ��� ����
	struct Node* new_node = createNode(_v);

	// 5. ����� �� 
	// _k �ڿ� ����� ���� ���ο� ���� ����
	
	// 5.1 �ڿ� ��尡 �����ϴ� ���
	if (target->next != 0) {
		new_node->next = target->next; // 1.
		new_node->prev = target;       // 2.
		target->next = new_node;       // 3.
		new_node->next->prev = new_node; // 4.
	}
	else { 	// 5.2 �ڿ� ��尡 ���� ���
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

#if 0 // 1776: [2024 �����ͱ��� �ǽ�] DLL ���� - ����

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
// _k�� ���� ��带 ã�Ƽ� ����� �Լ�
void del_from_DLL(int _k) {

	while (1) {

		//1. _k�� ���� ��带 ã�´�.
		struct Node* target = find_Node(_k);

		//2. ������, return
		if (target == 0) {
			return;
		}

		while (1) {
			//3. ������, 
	//3.1 ������� ��尡 �߰��� ��ġ
			if (target->prev != 0 && target->next != 0) {
				target->prev->next = target->next;
				target->next->prev = target->prev;
				free(target);
				break;
			}

			// �� ���ε� ȥ��
			//3.2 �� �տ� �ִ� ���, head ó��
			if (target == head) {
				// �� ��, ȥ��
				if (target->next == 0) {
					head = 0;
					free(target);
					break;
				}
				// �� ��, ȥ�ڰ� �ƴ�
				else {
					head = head->next;
					head->prev = 0;
					free(target);
					break;
				}
			}

			//3.3 �� ��
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
