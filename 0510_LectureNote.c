#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-09 update
/*
*****************
* 20240510 실습 *
*****************
*/

/*
[ 실습 내용 ]

STACK, QUEUE, Linked List(SLL, DLL) 까지는 잘 통과

1797: [데이터구조 중간고사 2024] 1. 하노이탑 -> 예상 외의 문제

1798: [데이터구조 중간고사 2024] 2. STACK
1805: [데이터구조 중간고사 2024] 9. Stack Heavy Weight -> 스택의 응용

1799: [데이터구조 중간고사 2024] 3. QUEUE

1800: [데이터구조 중간고사 2024] 4. Linked List
1801: [데이터구조 중간고사 2024] 5. Linked List Part 2 ->  DLL 구현 추천
1804: [데이터구조 중간고사 2024] 8. Linked List Reverse -> Reverse 함수 구현 필요
1806: [데이터구조 중간고사 2024] 10. Linked List Delete

1802: [데이터구조 중간고사 2024] 6. Binary Search Tree
1803: [데이터구조 중간고사 2024] 7. Binary Search Tree Part 2

1807: [데이터구조 중간고사 2024] 11. BST max and min
1808: [데이터구조 중간고사 2024] 12. BST how many

*/

// 0명 통과
// 1797: [데이터구조 중간고사 2024] 1. 하노이탑
#if 0
/*
문제 설명
그 이름도 유명한 하노이탑 문제를 풀어보고자 한다.

폴은 모두 3개 (A, B, C)가 있고, 하노이탑의 규칙에 따라 A에서 C로 옮기는 것이다.

입력으로 원반 개수를 받아, 폴 A에서 폴 C로 옮기고자 한다.

접시를 하노이 탑 규칙 (큰 원반위에 작은 원반이 와서는 안된다.)에 따라 옮기는 과정에서,

원반들은 폴들을 옮겨가게 되는데, 가장 작은 원반이 폴 B에 놓여지는 횟수를 출력하시오.
================> 조건

예를 들어, 원반이 1개면, 가장 작은 원반은 폴 B를 거치지 않으므로 0을 출력한다.

원반이 2개면, 가장 작은 원반은 폴 B를 1회 거치게 되므로 1이 된다.

원반이 3개여도 1이 된다.

입력
폴 A에 있는 원반의 개수

출력
가장 작은 접시가 폴 B를 거치는 횟수

*/

#include <stdio.h>
int count = 0;
void hanoi(int n, char from, char to, char tmp) {
    if (n == 1) { // 1번 원반, 제일 작은 원반
        if (to == 'B') count++;
        return;
    }
    // ===========> 조건 1, 1번 원반이 B로 옮겨지는 경우

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

// 18명 통과
// 1805: [데이터구조 중간고사 2024] 9. Stack Heavy Weight
#if 0
/*
문제 설명
양의 정수를 최대 5개 저장할 수 있는 STACK을 구현하시오.
입력 값의 양의 정수이면 stack에 저장한다.
==============> 기본 구현

Full stack 상태에서 입력된 양의 정수가 100보다 크거나 같으면,
stack의 bottom에 깔린 숫자가 사라지고, 입력된 양의 정수가 저장된다.
==============> 조건 1

입력 값이 0이면, stack top에서부터 숫자들을 공백 1개로 구분하여 출력하고 종료한다.
stack이 비어있으면, empty를 출력한다.
==============> 조건 2

입력
1 2 3 4 5 100 200 0
출력
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

// ====================> 스택 기본 구현

void push_bottom(int _v)
{
	for (int i = 0; i < MS - 1; i++) {
		data[i] = data[i + 1]; // =========> 하나씩 밀어넣기
	}
	data[MS - 1] = _v; // =========> 100 이상의 값 PUSH
	return;
}

// =====================> 조건 1 구현

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


// 16명 통과
// 1806: [데이터구조 중간고사 2024] 10. Linked List Delete 
#if 0
/*
문제 설명
양의 정수를 저장하는 linked List를 구현하시오. 
입력 값이 양의 정수이면 linked list에 저장한다. 
======================> linked list 기본 구현

입력 값이 음의 정수이면, 
linked list에서 음의 정수와 절대값이 같은 양의 정수들을 찾아서 모두 삭제한다. 
======================> 조건 1

입력 값이 0이면, 
linked list의 값들을 앞에서부터 숫자들을 공백 1개로 구분하여 출력하고 종료한다. 
만약 linked list가 비어있으면, empty를 출력한다.
======================> 조건 2

입력
1 1 2 2 -1 3 0
출력
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
// =================> 기본 구현

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
// ================> 조건 2, DELETE SLL

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
// ==================> 조건 3, PRINT

int main() {

    for (int i = 0; 1; i++) { // while(1)과 동일, i 값으로 반복 횟수 판단

        int n;
        scanf("%d", &n);
        if (n == 0) break;
        
		if (n < 0) {

            int a = 0 - n; // 음의 정수 -> 양의 정수

            for (int j = 0; j < i; j++) { // 최소한, 입력된 숫자 개수 만큼 호출
                deleteSLL(a);
            }
            continue;
        }
        
		add_SLL(n); // SLL 에 추가
    }
    printSLL();
}

#endif

// 13명 통과
// 1804: [데이터구조 중간고사 2024] 8. Linked List Reverse -> Reverse 함수 구현 필요
#if 0
/*
문제 설명
양의 정수들을 저장하는 linked list를 구현하시오.
====================> 기본 SLL 구현

입력값이 양의 정수이면 linked list의 끝에 저장한다.
====================> 조건 1

입력값이 -1이면, linked list의 순서를 뒤집는다.
예를 들어, 1->2->3 순서였다면 3->2->1 이 되어야 한다.
이후 입력되는 숫자들은 1 뒤에 저장되어야 한다.
====================> 조건 2, REVERSE 구현

입력값이 0이면, linked list값을 앞에서부터 한 개씩, 공백 1개로 구분하여 출력하고 종료한다.
만약 linked list에 값이 없다면 empty를 출력하고 종료한다.
====================> 조건 3, 출력

입력
1 2 3 -1 4 5 0
출력
3 2 1 4 5
*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = 0;
// ==================> 기본 구현

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
// ====================> 조건 1, ADD SLL 구현

void printsll() {
	struct Node* tmp = head;
	while (tmp != 0) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	return;
}
// ======================> 조건 3, PRINT SLL 구현

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
// =====================> 조건 2, REVERSE 구현, 포인터 3개 사용

int main() {

	int a = 0;

	while (1) {

		scanf("%d", &a);

		if (a > 0) { // ====> 조건 1
			addsll(a);
		}

		if (a == 0) { // ====> 조건 3
			printsll();
			break;
		}

		if (a == -1) { // ====> 조건 2
			head = reverse(head);
		}
	}

	if (head == 0) {
		printf("empty");
	}
}

#endif


// 7명 통과
// 1803: [데이터구조 중간고사 2024] 7. Binary Search Tree Part 2
#if 0

/*
문제 설명
양의 정수를 저장하는 binary search tree를 구현하시오.
====================> 기본 구현

입력값이 양의 정수이면 BST에 저장한다.
====================> 조건 1

입력 값이 0이면, BST에 저장된 terminal node들의 개수를 출력하고 종료한다.
====================> 조건 2

만약 BST가 비어있으면 empty를 출력한다.
====================> 조건 3

입력
30 10 50 0
출력
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

// =============> 기본 구현 

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
// =============> 조건 1, ADD

int count = 0;


void check(struct node* na)
{
    if (na == 0)
    {
        return;
    }

    // INORDER_TRAVERSAL 응용
    // 노드를 돌면서, 자식이 0명인 노드를 탐색
    check(na->left);

    if (na->left == 0 && na->right == 0) // 왼쪽, 오른쪽 자식이 없으면
    {
        count++; // 카운트
    }

    check(na->right);
}
// =============> 조건 2, 터미널 노드의 개수 세기
// 터미널 노드 -> 자식이 없는 노드

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


// 11명 통과
// 1807: [데이터구조 중간고사 2024] 11. BST max and min
#if 0
/*
문제 설명
양의 정수를 저장하는 BST를 구현하시오. 
====================> 기본 구현

입력 값이 양의 정수이면 BST에 저장한다. 
====================> 조건 1

입력 값이 0이면 BST에 담긴 가장 작은 값과 가장 큰 값 간의 차이를 출력하고 종료한다. 
BST에는 1개 이상의 값이 저장되며, 1개인 경우, min과 max는 같다.
====================> 조건 2

입력
30 10 50 0

출력
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
// ================> 기본 구현

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
// ================> 조건 1, ADD

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

// ====================> 조건 2, min, max 찾기

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
        // ==============> 최대, 최소 값 초기화

        inorder_min(root);
        inorder_max(root);
        printf("%d", max - min); // =========> 최대 - 최소 값 출력
    }
}
#endif


// 2명 통과
// 1808: [데이터구조 중간고사 2024] 12. BST how many
#if 1
/*
문제 설명
양의 정수를 저장하는 BST를 구현하시오.
입력 값이 양의 정수이면 BST에 저장한다.
===================> 기본 구현

입력 값이 음수이면, 그 값의 절대값에 해당하는 노드를 찾아, 
===================> 조건 1

그 노드의 왼쪽 subtree에 담긴 노드들의 개수와 
오른쪽 subtree에 담긴 노드들의 개수 간의 차이의 절대값을 출력하고 종료한다.
===================> 조건 2

만약 subtree가 없다면, 개수는 0이다. BST에는 1개 이상의 숫자가 저장된다.
===================> 조건 3

입력
30 10 50 60 -30
출력
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
// ==================> 기본 구현

node* serch = 0;
void inorder_serch(node* arg, int target) {

    // ==============> arg 트리에서 target 값 위치 찾기
    if (arg == 0) return;

    inorder_serch(arg->down, target);
    if (arg->data == target) serch = arg;
    inorder_serch(arg->up, target);
    // ==============> INORDER_TRAVERSAL 응용

}
// ==================> 조건 1

int sub_down = 0; // 왼쪽 SUB TREE 노드 개수
int sub_up = 0; // 오른쪽 SUB TREE 노드 개수

void inorder_down(node* arg) {

    if (arg == 0) return;

    inorder_down(arg->down);
    sub_down++; // ===========> 현재 노드가 있으면 ++
    inorder_down(arg->up);
    // =========> INORDER_TRAVERSAL 하면서, 노드 개수 세기
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
    else {// ===> 여기서 계산 시작

        k = k * -1; // ===> 음수 -> 양수
        inorder_serch(root, k); // ===> 찾는 값 정해짐

        inorder_down(serch->down); // ===> 왼쪽 SUB TREE 노드 개수
        inorder_up(serch->up);   // ===> 오른쪽 SUB TREE 노드 개수
        int c = sub_down - sub_up;

        if (c > 0) {

        }
        else { // ===> 음수이면, 반전
            c = c * -1;
        }
        printf("%d", c);
    }
}

#endif