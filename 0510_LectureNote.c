#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-09 update
/*
*****************
* 20240510 �ǽ� *
*****************
*/

/*
[ �ǽ� ���� ]

STACK, QUEUE, Linked List(SLL, DLL) ������ �� ���

1797: [�����ͱ��� �߰���� 2024] 1. �ϳ���ž -> ���� ���� ����

1798: [�����ͱ��� �߰���� 2024] 2. STACK
1805: [�����ͱ��� �߰���� 2024] 9. Stack Heavy Weight -> ������ ����

1799: [�����ͱ��� �߰���� 2024] 3. QUEUE

1800: [�����ͱ��� �߰���� 2024] 4. Linked List
1801: [�����ͱ��� �߰���� 2024] 5. Linked List Part 2 ->  DLL ���� ��õ
1804: [�����ͱ��� �߰���� 2024] 8. Linked List Reverse -> Reverse �Լ� ���� �ʿ�
1806: [�����ͱ��� �߰���� 2024] 10. Linked List Delete

1802: [�����ͱ��� �߰���� 2024] 6. Binary Search Tree
1803: [�����ͱ��� �߰���� 2024] 7. Binary Search Tree Part 2

1807: [�����ͱ��� �߰���� 2024] 11. BST max and min
1808: [�����ͱ��� �߰���� 2024] 12. BST how many

*/

// 0�� ���
// 1797: [�����ͱ��� �߰���� 2024] 1. �ϳ���ž
#if 0
/*
���� ����
�� �̸��� ������ �ϳ���ž ������ Ǯ����� �Ѵ�.

���� ��� 3�� (A, B, C)�� �ְ�, �ϳ���ž�� ��Ģ�� ���� A���� C�� �ű�� ���̴�.

�Է����� ���� ������ �޾�, �� A���� �� C�� �ű���� �Ѵ�.

���ø� �ϳ��� ž ��Ģ (ū �������� ���� ������ �ͼ��� �ȵȴ�.)�� ���� �ű�� ��������,

���ݵ��� ������ �Űܰ��� �Ǵµ�, ���� ���� ������ �� B�� �������� Ƚ���� ����Ͻÿ�.
================> ����

���� ���, ������ 1����, ���� ���� ������ �� B�� ��ġ�� �����Ƿ� 0�� ����Ѵ�.

������ 2����, ���� ���� ������ �� B�� 1ȸ ��ġ�� �ǹǷ� 1�� �ȴ�.

������ 3������ 1�� �ȴ�.

�Է�
�� A�� �ִ� ������ ����

���
���� ���� ���ð� �� B�� ��ġ�� Ƚ��

*/

#include <stdio.h>
int count = 0;
void hanoi(int n, char from, char to, char tmp) {
    if (n == 1) { // 1�� ����, ���� ���� ����
        if (to == 'B') count++;
        return;
    }
    // ===========> ���� 1, 1�� ������ B�� �Ű����� ���

    hanoi(n - 1, from, tmp, to);
    hanoi(n - 1, tmp, to, from);
}

int main() {
    int num_disks;
    scanf("%d", &num_disks);

    if (num_disks > 0) {
        hanoi(num_disks, 'A', 'C', 'B');
    }

    printf("%d\n", count);
    return 0;
}

#endif

// 18�� ���
// 1805: [�����ͱ��� �߰���� 2024] 9. Stack Heavy Weight
#if 0
/*
���� ����
���� ������ �ִ� 5�� ������ �� �ִ� STACK�� �����Ͻÿ�.
�Է� ���� ���� �����̸� stack�� �����Ѵ�.
==============> �⺻ ����

Full stack ���¿��� �Էµ� ���� ������ 100���� ũ�ų� ������,
stack�� bottom�� �� ���ڰ� �������, �Էµ� ���� ������ ����ȴ�.
==============> ���� 1

�Է� ���� 0�̸�, stack top�������� ���ڵ��� ���� 1���� �����Ͽ� ����ϰ� �����Ѵ�.
stack�� ���������, empty�� ����Ѵ�.
==============> ���� 2

�Է�
1 2 3 4 5 100 200 0
���
200 100 5 4 3

*/

#include <stdio.h>
#include <stdlib.h>

#define MS 5

int top = -1;
int data[MS];

int is_empty()
{
	return (top == -1);
}

int is_full()
{
	return (top == (MS - 1));
}

void push(int _v)
{
	if (is_full()) return;
	data[++top] = _v;
}

int pop()
{
	if (is_empty()) return;

	return data[top--];
}

// ====================> ���� �⺻ ����

void push_bottom(int _v)
{
	for (int i = 0; i < MS - 1; i++) {
		data[i] = data[i + 1]; // =========> �ϳ��� �о�ֱ�
	}
	data[MS - 1] = _v; // =========> 100 �̻��� �� PUSH
	return;
}

// =====================> ���� 1 ����

int main()
{
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		else if (n >= 100) {
			push_bottom(n);
		}

		else {
			push(n);
		}
	}
	if (is_empty()) printf("empty");
	while (!is_empty()) {
		printf("%d ", pop());
	}
}

#endif


// 16�� ���
// 1806: [�����ͱ��� �߰���� 2024] 10. Linked List Delete 
#if 0
/*
���� ����
���� ������ �����ϴ� linked List�� �����Ͻÿ�. 
�Է� ���� ���� �����̸� linked list�� �����Ѵ�. 
======================> linked list �⺻ ����

�Է� ���� ���� �����̸�, 
linked list���� ���� ������ ���밪�� ���� ���� �������� ã�Ƽ� ��� �����Ѵ�. 
======================> ���� 1

�Է� ���� 0�̸�, 
linked list�� ������ �տ������� ���ڵ��� ���� 1���� �����Ͽ� ����ϰ� �����Ѵ�. 
���� linked list�� ���������, empty�� ����Ѵ�.
======================> ���� 2

�Է�
1 1 2 2 -1 3 0
���
2 2 3

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
};

struct node* head = 0;

void add_SLL(int v) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = v;
    new_node->next = 0;

    if (head == 0) {
        head = new_node;
        return;
    }
    struct node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}
// =================> �⺻ ����

void deleteSLL(int v) {

    struct node* tmp = head;
    if (head == 0) return;
    if (head->data == v) {
        if (head->next == 0) {
            head = 0;
            return;
        }
        head = head->next;
        return;
    }
    while (tmp->next != NULL) {
        if (tmp->next->data == v) {
            if (tmp->next->next == 0) {
                tmp->next = 0;
                return;
            }
            tmp->next = tmp->next->next;
            return;
        }
        tmp = tmp->next;
    }
}
// ================> ���� 2, DELETE SLL

void printSLL() {
    struct node* tmp = head;
    if (head == 0) {
        printf("empty");
        return;
    }
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
// ==================> ���� 3, PRINT

int main() {

    for (int i = 0; 1; i++) { // while(1)�� ����, i ������ �ݺ� Ƚ�� �Ǵ�

        int n;
        scanf("%d", &n);
        if (n == 0) break;
        
		if (n < 0) {

            int a = 0 - n; // ���� ���� -> ���� ����

            for (int j = 0; j < i; j++) { // �ּ���, �Էµ� ���� ���� ��ŭ ȣ��
                deleteSLL(a);
            }
            continue;
        }
        
		add_SLL(n); // SLL �� �߰�
    }
    printSLL();
}

#endif

// 13�� ���
// 1804: [�����ͱ��� �߰���� 2024] 8. Linked List Reverse -> Reverse �Լ� ���� �ʿ�
#if 0
/*
���� ����
���� �������� �����ϴ� linked list�� �����Ͻÿ�.
====================> �⺻ SLL ����

�Է°��� ���� �����̸� linked list�� ���� �����Ѵ�.
====================> ���� 1

�Է°��� -1�̸�, linked list�� ������ �����´�.
���� ���, 1->2->3 �������ٸ� 3->2->1 �� �Ǿ�� �Ѵ�.
���� �ԷµǴ� ���ڵ��� 1 �ڿ� ����Ǿ�� �Ѵ�.
====================> ���� 2, REVERSE ����

�Է°��� 0�̸�, linked list���� �տ������� �� ����, ���� 1���� �����Ͽ� ����ϰ� �����Ѵ�.
���� linked list�� ���� ���ٸ� empty�� ����ϰ� �����Ѵ�.
====================> ���� 3, ���

�Է�
1 2 3 -1 4 5 0
���
3 2 1 4 5
*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;
// ==================> �⺻ ����

void addsll(int _v) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = _v;
	new_node->next = 0;

	if (head == 0) {
		head = new_node;
		return;
	}
	struct Node* tmp = head;
	while (tmp->next != 0) {
		tmp = tmp->next;
	}
	tmp->next = new_node;
}
// ====================> ���� 1, ADD SLL ����

void printsll() {
	struct Node* tmp = head;
	while (tmp != 0) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	return;
}
// ======================> ���� 3, PRINT SLL ����

struct Node* reverse(struct Node* head) {
	struct Node* p, * q, * r;
	p = head;
	q = 0;
	while (p != 0) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return q;
}
// =====================> ���� 2, REVERSE ����, ������ 3�� ���

int main() {

	int a = 0;

	while (1) {

		scanf("%d", &a);

		if (a > 0) { // ====> ���� 1
			addsll(a);
		}

		if (a == 0) { // ====> ���� 3
			printsll();
			break;
		}

		if (a == -1) { // ====> ���� 2
			head = reverse(head);
		}
	}

	if (head == 0) {
		printf("empty");
	}
}

#endif


// 7�� ���
// 1803: [�����ͱ��� �߰���� 2024] 7. Binary Search Tree Part 2
#if 0

/*
���� ����
���� ������ �����ϴ� binary search tree�� �����Ͻÿ�.
====================> �⺻ ����

�Է°��� ���� �����̸� BST�� �����Ѵ�.
====================> ���� 1

�Է� ���� 0�̸�, BST�� ����� terminal node���� ������ ����ϰ� �����Ѵ�.
====================> ���� 2

���� BST�� ��������� empty�� ����Ѵ�.
====================> ���� 3

�Է�
30 10 50 0
���
2

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = 0;

// =============> �⺻ ���� 

void add(int n)
{
    struct node* new_one = (struct node*)malloc(sizeof(struct node));
    new_one->data = n;
    new_one->left = 0;
    new_one->right = 0;

    if (root == 0)
    {
        root = new_one;
        return;
    }

    struct node* tmp = root;
    while (1)
    {
        if (tmp->data > new_one->data)
        {
            if (tmp->left == 0)
            {
                tmp->left = new_one;
                return;
            }

            tmp = tmp->left;
        }
        else
        {
            if (tmp->right == 0)
            {
                tmp->right = new_one;
                return;
            }

            tmp = tmp->right;
        }
    }
}
// =============> ���� 1, ADD

int count = 0;


void check(struct node* na)
{
    if (na == 0)
    {
        return;
    }

    // INORDER_TRAVERSAL ����
    // ��带 ���鼭, �ڽ��� 0���� ��带 Ž��
    check(na->left);

    if (na->left == 0 && na->right == 0) // ����, ������ �ڽ��� ������
    {
        count++; // ī��Ʈ
    }

    check(na->right);
}
// =============> ���� 2, �͹̳� ����� ���� ����
// �͹̳� ��� -> �ڽ��� ���� ���

int main()
{
    while (1)
    {
        int input;
        scanf("%d", &input);
        if (input == 0)
        {
            if (root == 0)
            {
                printf("empty");
                break;
            }
            check(root);
            printf("%d ", count);
            break;
        }
        else
        {
            add(input);
        }
    }
    return 0;
}

#endif


// 11�� ���
// 1807: [�����ͱ��� �߰���� 2024] 11. BST max and min
#if 0
/*
���� ����
���� ������ �����ϴ� BST�� �����Ͻÿ�. 
====================> �⺻ ����

�Է� ���� ���� �����̸� BST�� �����Ѵ�. 
====================> ���� 1

�Է� ���� 0�̸� BST�� ��� ���� ���� ���� ���� ū �� ���� ���̸� ����ϰ� �����Ѵ�. 
BST���� 1�� �̻��� ���� ����Ǹ�, 1���� ���, min�� max�� ����.
====================> ���� 2

�Է�
30 10 50 0

���
40
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int data;
    struct node* up;
    struct node* down;

}node;

node* root = 0;
// ================> �⺻ ����

void add_node(int n) {

    node* _new = (node*)malloc(sizeof(node));
    _new->data = n;
    _new->up = 0;
    _new->down = 0;

    if (root == 0) {
        root = _new;
    }
    else {
        node* cur = root;
        while (1) {
            if (cur->data > n) {
                if (cur->down == 0) {
                    cur->down = _new;
                    return;
                }
                cur = cur->down;
            }
            else {
                if (cur->up == 0) {
                    cur->up = _new;
                    return;
                }
                cur = cur->up;
            }
        }
    }
}
// ================> ���� 1, ADD

int max;
int min;

void inorder_min(node* arg) {

    if (arg == 0) return;

    inorder_min(arg->down);
    if (arg->data <= min) min = arg->data;

    inorder_min(arg->up);
}
void inorder_max(node* arg) {

    if (arg == 0) return;

    inorder_max(arg->down);
    if (arg->data >= max) max = arg->data;

    inorder_max(arg->up);
}

// ====================> ���� 2, min, max ã��

int main() {

    while (1) {

        int k; scanf("%d", &k);

        if (k > 0) {
            add_node(k);
        }
        else {
            break;
        }
    }

    if (root == 0) {
        printf("empty");
    }

    else {

        max = root->data; 
        min = root->data;
        // ==============> �ִ�, �ּ� �� �ʱ�ȭ

        inorder_min(root);
        inorder_max(root);
        printf("%d", max - min); // =========> �ִ� - �ּ� �� ���
    }
}
#endif


// 2�� ���
// 1808: [�����ͱ��� �߰���� 2024] 12. BST how many
#if 1
/*
���� ����
���� ������ �����ϴ� BST�� �����Ͻÿ�.
�Է� ���� ���� �����̸� BST�� �����Ѵ�.
===================> �⺻ ����

�Է� ���� �����̸�, �� ���� ���밪�� �ش��ϴ� ��带 ã��, 
===================> ���� 1

�� ����� ���� subtree�� ��� ������ ������ 
������ subtree�� ��� ������ ���� ���� ������ ���밪�� ����ϰ� �����Ѵ�.
===================> ���� 2

���� subtree�� ���ٸ�, ������ 0�̴�. BST���� 1�� �̻��� ���ڰ� ����ȴ�.
===================> ���� 3

�Է�
30 10 50 60 -30
���
1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int data;
    struct node* up;
    struct node* down;

}node;

node* root = 0;

void add_node(int n) {

    node* _new = (node*)malloc(sizeof(node));
    _new->data = n;
    _new->up = 0;
    _new->down = 0;

    if (root == 0) {
        root = _new;
    }
    else {
        node* cur = root;
        while (1) {
            if (cur->data > n) {
                if (cur->down == 0) {
                    cur->down = _new;
                    return;
                }
                cur = cur->down;

            }
            else {
                if (cur->up == 0) {
                    cur->up = _new;
                    return;
                }
                cur = cur->up;
            }
        }
    }
}
// ==================> �⺻ ����

node* serch = 0;
void inorder_serch(node* arg, int target) {

    // ==============> arg Ʈ������ target �� ��ġ ã��
    if (arg == 0) return;

    inorder_serch(arg->down, target);
    if (arg->data == target) serch = arg;
    inorder_serch(arg->up, target);
    // ==============> INORDER_TRAVERSAL ����

}
// ==================> ���� 1

int sub_down = 0; // ���� SUB TREE ��� ����
int sub_up = 0; // ������ SUB TREE ��� ����

void inorder_down(node* arg) {

    if (arg == 0) return;

    inorder_down(arg->down);
    sub_down++; // ===========> ���� ��尡 ������ ++
    inorder_down(arg->up);
    // =========> INORDER_TRAVERSAL �ϸ鼭, ��� ���� ����
}

void inorder_up(node* arg) {

    if (arg == 0) return;

    inorder_up(arg->down);
    sub_up++;
    inorder_up(arg->up);
}


int main() {
    int k;

    while (1) {

        scanf("%d", &k);
        if (k > 0) {
            add_node(k);
        }
        else {
            break;
        }
    }

    if (root == 0) {
        printf("empty");
    }
    else {// ===> ���⼭ ��� ����

        k = k * -1; // ===> ���� -> ���
        inorder_serch(root, k); // ===> ã�� �� ������

        inorder_down(serch->down); // ===> ���� SUB TREE ��� ����
        inorder_up(serch->up);   // ===> ������ SUB TREE ��� ����
        int c = sub_down - sub_up;

        if (c > 0) {

        }
        else { // ===> �����̸�, ����
            c = c * -1;
        }
        printf("%d", c);
    }
}

#endif