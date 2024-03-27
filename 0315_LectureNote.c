#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// made by taewon-seo, INU ESE, 2024-03-15 update
/*
*****************
* 20240315 실습 *
*****************
*/


// 피보나치 수열 순환으로 구현하기

/*

피보나치 수열
피보나치 수열이란 첫째 항, 둘째 항이 1이고, 그 뒤의 항은 바로 앞의 두 항의 합인 수열을 뜻함
0, 1, 1, 2, 3, 5, 8, 13 ...

fibo(n) {
n = 0) 0
n = 1) 1
otherwise) fibo(n-2) + fib(n-1)

*/

// 반복을 이용하여 구현
// 수업시간 


#if 0

// 순환을 이용하여 구현 (비효율)
int fib(int n) {

	// 기저 조건 (base case)
	if (n == 0) { // 0번째 피보나치 수열 값
		return 0;
	}
	if (n == 1) { // 1번째 피보나치 수열 값
		return 1;
	}
	// 재귀 호출을 통해 n번째 피보나치 수열 값을 계산
	return (fib(n - 1) + fib(n - 2));

}

int main() {

	int num = 7; // 계산할 피보나치 수열의 항 번호
	int result; // 결과 값을 저장할 변수

	// fib 함수 호출
	result = fib(num);

	printf("%d번째 피보나치 수열 값: %d", num, result);

	return 0;
}

/*
// 큰 문제를, base case에 해당하는 문제로 분할하여 풀이

fib(6) =
fib(5) + fib(4)

fib(4) + fib(3) + fib(4)

fib(3) + fib(2) + fib(3) + fib(3) + fib(2)

한번 fib 함수를 호출하면, 두 번의 fib 함수를 호출하게 됨
이전 항들의 값을 가지고 계산하기 때문에 중복되는 부분이 많아짐

피보나치 수열을 계산하는 순환 알고리즘의 시간 복잡도는 O(2^n)

*/


#endif

#if 0

// 메모이제이션 (memoization)을 사용하여 프로그램 개선
// 메모이제이션이란 한번 그 값을 계산하였다면 그 값을 저장해두어
// 다시 계산해야 할 때 계산하는 대신, 값을 바로 가져오는 방법
// 이 방법으로 동일한 피보나치 수를 다시 계산하는 것을 방지할 수 있음

#define MAX_SIZE 100 // 배열의 최대 크기를 100 으로 정의

int fibo(int n) {

	static int arr[MAX_SIZE] = { 0, }; // 정적 배열 arr를 선언하여 이전에 계산된 피보나치 수열의 값을 계산

	if (n < 2) { // n이 0 또는 1인 경우 
		return n; // n을 반환
	}

	if (arr[n] > 0) {  // arr 배열에 이미 값이 저장되어 있는 경우 
		return arr[n]; // 저장된 값을 반환

	}
	else {
		// 재귀 호출을 통해 피보나치 수열을 계산하고 arr 배열에 저장
		// n번째 피보나치 수열 값은 n-1번째와 n-2번째 피보나치 수열 값의 합
		return arr[n] = fibo(n - 1) + fibo(n - 2);

	}

}

int main() {

	int num = 0;

	scanf("%d", &num);

	int result = 0;
	result = fibo(num);

	printf("%d번째 fibo 수열 값: %d", num, result);


}

#endif


#if 0

/*

하노이 탑 문제 (Hanoi Tower Problem)는 재귀적인 알고리즘의 대표적인 예시
이 문제는 세개의 기둥과 그 위에 쌓인 서로 다른 크기의 원판들이 있을 때,
한 번에 하나의 원판만 옮기며

1. 한 번에 하나의 원판만을 다른 기둥으로 옮길 수 있음
2. 큰 원판은 작은 원판 위에 올려놓을 수 없음

위 규칙을 지켜서 모든 원판을 목표 기둥으로 옮기는 것

*/


// 원판을 옮기는 함수
// from: 출발 기둥, to: 목표 기둥, tmp: 보조 기둥, n: 옮길 원판의 수

void hanoi(int n, char from, char to, char tmp) {

	// 기저 조건: 원판이 하나일 때
	if (n == 1) {
		printf("원판 1을 %c 에서 %c로 옮기니다.\n", from, to);
		return;

	}

	// 원판 n-1개를 보조 기둥으로 옮기고
	hanoi(n - 1, from, tmp, to);
	// 가장 큰 원판을 목표 기둥으로 옮기고 
	printf("원판 %d를 %c에서 %c로 옮깁니다.\n", n, from, to);
	// 나머지 원판을 목표 기둥으로 옮깁니다.
	hanoi(n - 1, tmp, to, from);


}

/*
1. hanoi 함수는 원판의 개수 n, 출발 기둥 from, 목표 기둥 to, 보조 기둥 tmp를 매개변수로
가짐
2. 만약 n이 1이면, 한 개의 원판만을 옮기면 되므로 단순히 출발 기둥에서 목표 
기둥으로 이동시키면 됨
3. 그렇지 않은 경우, hanoi 함수는 먼저 n-1개의 원판을 보조 기둥으로 옮김
4. 그 다음, 가장 큰 원판을 목표 기둥으로 옮김
5. 마지막으로, 보조 기둥에 옮겨놓은 원판들을 목표 기둥으로 옮김
*/

int main() {

	// 원판의 개수
	int num_disks = 3;

	// 'A' 에서 'C'로 옮기는 작업 수행
	hanoi(num_disks, 'A', 'C', 'B');
	return 0;
}

#endif