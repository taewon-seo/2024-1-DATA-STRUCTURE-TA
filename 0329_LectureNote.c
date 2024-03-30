
// made by taewon-seo, INU ESE, 2024-03-30 update
/*
*****************
* 20240329 실습 *
*****************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
[ Theme ]
* stack을 이용한 postfix 계산
* nfix의 postfix 변환
* ndeque (double ended queue)의 구현
*/


/*

[ 중위, 전위, 후위 표기법의 개념 ]

1. 중위 표기법 (Infix)

중위 표기법은 가장 일반적으로 사용되는 수식의 표기법
연산자가 피연산자 사이에 위치하는 표기법

표기 예시) 2 + 3 

2. 전위 표기법 (Prefix)

전위 표기법은 연산자가 피연산자 앞에 위치하는 표기법
C언어에서는 전위 표기법을 사용하여 수식을 계산하기 위해 함수 호출 방식을 사용
즉, 연산자가 함수의 이름이 되고, 피연산자가 함수의 인수가 됨

표기 예시) + 2 3

3. 후위 표기법 (Postfix)

후위 표기법은 연산자가 피연산자 뒤에 위치하는 표기법
C언어에서는 후위 표기법을 사용하여 수식을 게산하기 위해 스택을 사용
즉, 피연산자는 스택에 push 연산자가 나타나면 pop 하여 계산

표기 예시) 2 3 +

4. 표기법 간 변환

중위 순회를 전위, 후위 표기로 변환하기 위해서는 아래와 같은 방법을 사용한다.
3 + 2 - 4 / 5 + 3 * 2

1) 연산자 우선순위에 맞게 괄호를 쳐준다. (((3 + 2) - (4 / 5)) + (3 * 2))
2) 괄호 안에 있는 연산자를 괄호 밖으로 꺼낸다. 
괄호의 앞으로 꺼내면 전위, 뒤로 꺼내면 후위 수식이 된다.

전위 : + - + 3  2 / 4  5 * 3  2
후위 : 3 2 + 4 5 / - 3 2 * +

*/



#if 0

// 스택 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element; 

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)];
}


#endif 

#if 0

// 후위 표기식 계산 알고리즘
/*

수식을 왼쪽에서 오른쪽으로 스캔하며
1. 피연산자이면 스택에 저장
2. 연산자이면 필요한 수만큼의 피연산자를 스택에서 꺼내 연산을 실행하고, 
연산 결과를 다시 스택에 저장

[ pseudo code ]
스택 s를 생성하고 초기화한다.
for 항목 in 후위표기식
	do if (항목이 피연산자이면)
		push(s, item)
	if (항목이 연산자 op이면)
		then second ← pop(s)
			first ← pop(s)
			result ← first op second (op 는 + - * / 중의 하나)
			push(s, result)
final_result ← pop(s);

*/


// 후위 표기 수식 계산 함수

int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);

	char ch;
	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0'; // 입력이 피연산자이면
			push(&s, value);
		}
		else { // 연산자이면 피연산자를 스택에서 제거
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) { //연산을 수행하고 스택에 저장
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main(void)
{
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
	return 0;
}


#endif


#if 0

// 중위표기식 -> 후위표기식

/*
중위 표기법과 후위 표기법의 공통점은 피연산자의 순서는 동일
연산자들의 순서만 다름(우선순위순서)
	->연산자만 스택에 저장했다가 출력하면 된다.
2+3*4 -> 234*+
*/

/*

[ pseudo code ]
infix_to_postfix(exp) :
스택 s를 생성하고 초기화
while (exp에 처리할 문자가 남아 있으면)
	ch ← 다음에 처리할 문자
	switch (ch)
		case 연산자:
			while ( peek(s)의 우선순위 ≥ ch의 우선순위 )
			do e ← pop(s)
				e를 출력
			push(s, ch);
			break;
		case 왼쪽 괄호:
			push(s, ch);
			break;
		case 오른쪽 괄호:
			e ← pop(s);
			while( e ≠ 왼쪽괄호 )
			do e를 출력
				e ← pop(s)
			break;
		case 피연산자:
			ch를 출력
			break;

while( not is_empty(s) )
	do e ← pop(s)
		e를 출력
*/


// 연산자의 우선순위를 반환한다.
int prec(char op)
{
	switch (op) {
	case '(': 
	case ')': 
		return 0;
	case '+': 
	case '-': 
		return 1;
	case '*': 
	case '/': 
		return 2;
	}
	return -1;
}

// 중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;
	init_stack(&s); // 스택 초기화

	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // 연산자

		// 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;

		case '(': // 왼쪽 괄호
			push(&s, ch);
			break;

		case ')': // 오른쪽 괄호
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;

		default: // 피연산자
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) // 스택에 저장된 연산자들 출력
		printf("%c", pop(&s));
}

int main(void)
{
	char* s = "(2+3)*4+9";
	printf("중위표시수식 %s \n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}

#endif

#if 1

/*
덱 ADT

1. 덱 생성
▪ create() ::= 덱을 생성한다.

2. 덱 초기화
▪ init(dq) ::= 덱을 초기화한다.

3. 공백상태인지 포화상태인지 검사
▪ is_empty(dq) ::= 덱이 공백상태인지를 검사한다.
▪ is_full(dq) ::= 덱이 포화상태인지를 검사한다.

4. add_front(앞에 추가) / add_rear(뒤에 추가)
▪ add_front(dq, e) ::= 덱의 앞에 요소를 추가한다.
▪ add_rear(dq, e) ::= 덱의 뒤에 요소를 추가한다.

5. delete_front(앞에서 삭제) / delete_rear(뒤에서 삭제)
▪ delete_front(dq) ::= 덱의 앞에 있는 요소를 반환한 다음 삭제한다
▪ delete_rear(dq) ::= 덱의 뒤에 있는 요소를 반환한 다음 삭제한다.

6. get_front(뒤에서 요소반환) / get_rear(뒤에서 요소반환)
▪ get_front(q) ::= 덱의 앞에서 삭제하지 않고 앞에 있는 요소를 반환한다.
▪ get_rear(q) ::= 덱의 뒤에서 삭제하지 않고 뒤에 있는 요소를 반환한다.
7. 덱 출력

*/

#include <stdio.h>
#define MAX_DEQUE 5

// 1. 덱 생성
#include <stdio.h>
#define MAX_DEQUE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_DEQUE];
} DequeType;

// 2. 덱 초기화
void init_deque(DequeType* dq)
{
	dq->front = 0;
	dq->rear = 0;
}

// 3. 공백상태인지 포화상태인지 검사
int is_empty(DequeType* dq)
{
	if (dq->front == dq->rear)
		return 1; //공백 상태
	else
		return 0;
}

int is_full(DequeType* dq)
{
	if (dq->front == (dq->rear + 1) % MAX_DEQUE)
		return 1; //포화 상태
	else
		return 0;
}

// 4. add_front(앞에 추가) / add_rear(뒤에 추가)
void add_front(DequeType* dq, element item)
{
	if (is_full(dq) == 1) {
		printf("full\n");
	}
	else {
		dq->data[dq->front] = item;
		dq->front = (dq->front - 1 + MAX_DEQUE) % MAX_DEQUE;
	}
}
// front에 데이터 삽입할 때, 일단 front에 데이터 삽입 후, 반시계 방향으로 한칸 이동.


void add_rear(DequeType* dq, element item)
{
	if (is_full(dq) == 1) {
		printf("full\n");
	}
	else {
		dq->rear = (dq->rear + 1) % MAX_DEQUE;
		dq->data[dq->rear] = item;
	}
}

// rear에 데이터를 삽입할 때, rear를 시계방향으로 한칸 이동 후, 데이터 삽입한다.

// 5. delete_front(앞에서 삭제) / delete_rear(뒤에서 삭제)
int delete_front(DequeType* dq)
{
	if (is_empty(dq) == 1) {
		printf("empty\n");
	}
	else {
		dq->front = (dq->front + 1) % MAX_DEQUE;
		return dq->data[dq->front];
	}
}

int delete_rear(DequeType* dq)
{
	element item;
	if (is_empty(dq) == 1) {
		printf("empty\n");
	}
	else {
		item = dq->data[dq->rear];
		dq->rear = (dq->rear - 1 + MAX_DEQUE) % MAX_DEQUE;
		return item;
	}
}

// 6. get_front(앞에서 요소반환) / get_rear(뒤에서 요소반환)
int get_front(DequeType* dq)
{
	if (is_empty(dq) == 1) {
		printf("empty\n");
	}
	else {
		return dq->data[(dq->front + 1) % MAX_DEQUE];
	}
}

int get_rear(DequeType* dq)
{
	if (is_empty(dq) == 1) {
		printf("empty\n");
	}
	else {
		return dq->data[dq->rear];
	}
}

// 뽑아낼 땐 front, rear 이동 x


// 7.덱 출력
void print_deque(DequeType* dq)
{
	printf("(front = %d rear = %d) = ", dq->front, dq->rear);
	if (!is_empty(dq) == 1) {
		int i = dq->front;
		do {
			i = (i + 1) % MAX_DEQUE;
			printf("%d | ", dq->data[i]);
			if (i == dq->rear)
				break;
		} while (i != dq->front);
		printf("\n");
	}
}

int main(void)
{
	DequeType dq;
	init_deque(&dq);

	add_rear(&dq, 1); //뒤에 삽입
	print_deque(&dq);

	add_rear(&dq, 2); //뒤에 삽입
	print_deque(&dq);

	add_front(&dq, 3); //앞에 삽입
	print_deque(&dq);

	delete_rear(&dq); //뒤에서 삭제
	print_deque(&dq);

	delete_front(&dq); //앞에서 삭제
	print_deque(&dq);

	return 0;
}

#endif