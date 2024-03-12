#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-03-12 update
/*
*****************
* 20240308 실습 *
***************** 
*/

#include <stdio.h>


#if 0

/*
문제 설명
양의 정수 1개를 입력받아, 짝수이면 even, 홀수이면 odd를 출력하시오.

단, even과 odd 끝에 줄바꿈 문자는 없음.
*/


int main() {

	int a;

	scanf(" %d", &a);

	if (a % 2 == 0) {
		printf("even");
	}
	else {
		printf("odd");
	}

	return 0;
}
#endif



#if 0

/*
크기가 10인 배열 two[]를 선언하고 여기에 2의 제곱 값들을 저장하라.
즉, 배열의 첫번째 요소에는 2^0을 저장하고 두 번째 요소에는 2^1 값을 저장한다.
마지막 요소에는 2^9 값을 저장한다.
for 루프를 이용하여 two[] 배열의 전체 요소의 값을 출력하는 프로그램을 작성하라.
*/

int main() {
    int two[10]; // 크기가 10인 배열 two[] 선언

    int power = 1; // 2의 거듭제곱 값을 저장할 변수

    // 배열에 2의 제곱 값들 저장
    for (int i = 0; i < 10; i++) {
        two[i] = power;
        power *= 2; // 다음 2의 제곱 값을 계산하기 위해 2를 곱함
    }

    /*
    참고) 비트 시프트를 활용한 다른 풀이
    */
    
    // 배열에 2의 제곱 값들 저장
    //for (int i = 0; i < 10; i++) {
    //    two[i] = 1 << i; // 2의 i 제곱은 1을 i번 left shift한 값과 같다.
    //}

    // 배열의 요소 출력
    // printf("two[] 배열의 요소 값:\n");
    for (int i = 0; i < 10; i++) {
        printf("two[%d] = %d\n", i, two[i]);
    }

    return 0;
}

#endif

#if 0

/*
교재 실습 문제)
person 이라는 구조체를 작성하라.
이 구조체에는 문자 배열로 된 이름, 사람의 나이를 나타내는 정수 값,
각 개인의 월급을 나타내는 float 값 등이 변수로 들어가야 한다.
*/

// person 구조체 정의
struct person {
    char name[50]; // 문자 배열로 된 이름
    int age; // 사람의 나이를 나타내는 정수 값
    float salary; // 각 개인의 월급을 나타내는 float 값
};

int main() {
    // person 구조체 변수 선언
    struct person individual;

    // 정보 입력
    printf("이름을 입력하세요: ");
    scanf("%s", individual.name);

    printf("나이를 입력하세요: ");
    scanf("%d", &individual.age);

    printf("월급을 입력하세요: ");
    scanf("%f", &individual.salary);

    // 정보 출력
    printf("\n입력된 정보:\n");
    printf("이름: %s\n", individual.name);
    printf("나이: %d\n", individual.age);
    printf("월급: %.2f\n", individual.salary);

    return 0;
}

#endif

#if 0

/*
2차원 좌표계 위의 점을 나타내는 points 구조체를 작성한다.
points 구조체는 x좌표와 y좌표를 가진다.

사용자로부터 x좌표와 y좌표가 입력되면,
그 점이 사분면 중 어디에 위치하는지 출력하는 프로그램을 작성하시오.

단, 축 위에 위치하거나 원점이면 0을 출력한다.
*/


// 좌표를 나타내는 points 구조체 정의
struct Point {
    int x;  // x 좌표
    int y;  // y 좌표
};

int main() {
    struct Point point; // Point 구조체 변수 선언

    // 사용자로부터 x좌표와 y좌표 입력 받기
    printf("x 좌표를 입력하세요: ");
    scanf("%d", &point.x);
    printf("y 좌표를 입력하세요: ");
    scanf("%d", &point.y);

    // 입력 받은 좌표가 어느 사분면에 속하는지 판별하여 출력
    if (point.x > 0 && point.y > 0)
        printf("1\n");
    else if (point.x < 0 && point.y > 0)
        printf("2\n");
    else if (point.x < 0 && point.y < 0)
        printf("3\n");
    else if (point.x > 0 && point.y < 0)
        printf("4\n");
    else
        printf("0\n");

    return 0;
}


#endif


#if 0
/*
C 언어에서 순환(recursion)은 함수가 자기 자신을 호출하는 것을 의미.
순환은 반복문과 마찬가지로 프로그램에서 특정 작업을 반복하여 수행할 때 사용.
순환은 재귀 함수(recursive function)라는 형태로 구현되며, 
재귀 호출을 통해 문제를 해결함.

순환을 사용하는 경우, 
함수는 기본 사례(base case)에 도달할 때까지 자기 자신을 호출함.
기본 사례(탈출 조건)란 함수가 더 이상 호출되지 않고 종료되어야 하는 경우를 의미.

기본 사례에 도달할 때 까지, 함수는 재귀 호출을 수행하여 문제를 더 작은 부분 문제로 
분할하고, 이를 해결하기 위해 자기 자신을 호출.

재귀 호출은 결국 기본 사례에 도달하여 재귀가 종료될 때까지 반복됨.

순환은 코드를 더 간결하고 이해하기 쉽게 만들 수 있지만, 
잘못된 구현은 무한 루프에 빠질 수 있기 때문에 주의가 필요.

/*
재귀 함수를 사용하여 
양의 정수 n부터 1까지의 합을 계산하는 함수 sumFromNtoOne 을 작성하시오.
*/

// 재귀 함수를 사용하여 n부터 1까지의 합을 계산하는 함수
int sumFromNtoOne(int n) {
    // 기본 사례: n이 1 이하일 때 n을 반환
    if (n <= 1) {
        return n;
    }
    // 재귀 호출: n과 n-1부터 1까지의 합을 더함
    else {
        return n + sumFromNtoOne(n - 1);
    }
}

int main() {
    int n;
    //printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);
    // 함수 호출하여 결과 출력
    printf("%d\n", sumFromNtoOne(n));

    return 0;
}


/*
이 코드는 재귀 함수를 사용하여 양의 정수 n부터 1까지의 합을 계산한다.
함수는 자기 자신을 호출하여 n부터 n - 1까지의 합을 계산한 후, 이를 n과 더하여 반환.
기본 사례(base case)에서는 n이 1 이하일 때 n을 반환하여 재귀 호출이 종료. (n은 1을 반환)
*/

#endif


/*
******************
* 추가 학습 자료 *
******************
*/

#if 0

/*
포인터로 swap 구현하기
*/

// 정수 포인터를 받아 해당하는 두 정수 값을 서로 바꾸는 함수
void swap(int* px, int* py)
{
    int temp;  // 임시 변수 선언

    temp = *px;  // temp에 px가 가리키는 정수 값을 복사
    *px = *py;   // py가 가리키는 정수 값을 px가 가리키는 위치에 복사
    *py = temp;  // temp에 저장된 값을 py가 가리키는 위치에 복사
}

int main() {
    int a = 1, b = 2;  // 정수 변수 a와 b를 선언하고 초기화

    // 초기 값 출력
    printf("a: %d, b: %d\n", a, b);

    // swap 함수를 호출하여 a와 b의 값 교환
    swap(&a, &b);

    // 교환된 값 출력
    printf("a: %d, b: %d", a, b);

    return 0;  // 프로그램 종료
}



/*
이 코드는 swap 함수를 사용하여 두 정수의 값을 서로 바꿔 출력함.
swap 함수는 포인터를 이용하여 두 변수의 값을 교환.
main 함수에서는swap 함수를 호출하여 a와 b의 값을 교환한 후, 결과를 출력.
*/

#endif


#if 0

/*
교재 연습 문제) 
크기가 n인 배열 array에서 임의의 위치 loc에 정수 value를 삽입하는 함수
insert()를 작성하시오.

정수가 삽입되면 그 뒤에 있는 정수들은 한 칸씩 뒤로 밀려야 한다.
현재 배열에 들어있는 원소의 개수는 items개라고 하자.
(여기서 items < n라고 가정)

void insert(int array[], int loc, int value} {

}
*/

void insert(int array[], int loc, int value) {

    // 배열에 정수 삽입
    for (int i = loc; i >= 0; i--) {
        array[i + 1] = array[i];
    }
    array[loc] = value;
}

int main() {
    int array[10] = { 1, 2, 3, 4, 5 };

    // 배열에 값 삽입
    insert(array, 2, 10);

    // 결과 출력
    printf("배열: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
#endif


#if 0

/*
교재 연습 문제)
typedef를 이용하여 complex 라고 하는 새로운 자료형을 정의하라.
complex 자료형은 구조체로서 float 형인 real 변수와 imaginary 변수를 갖는다.
complex 자료형으로 변수 c1과 c2를 선언하라.
*/

/*
typedef는 C 프로그래밍 언어에서 사용되는 키워드로, 새로운 자료형을 정의할 때 사용
typedef를 사용하면 기존의 자료형에 대해 사용자 정의 자료형을 만들어, 코드를 더 이해하기 쉽게 만들 수 있음

typedef의 기본적인 구문:
typedef 기존_자료형 새로운_자료형_이름;

예를 들어, struct를 사용하여 구조체를 정의할 때마다 struct 키워드를 사용해야 하지만,
typedef를 사용하면 이를 편리하게 만들 수 있음
아래는 구조체를 typedef로 정의하는 예시:

typedef struct {
    int age;
    char name[50];
} Person;

Person person1;

*/

// complex 자료형을 정의하는 구조체
typedef struct {
    float real;       // 실수 부분
    float imaginary;  // 허수 부분
} complex;

int main() {
    // 변수 c1과 c2를 complex 자료형으로 선언
    complex c1, c2;

    // 변수 c1의 초기화
    c1.real = 3.0;
    c1.imaginary = 4.0;

    // 변수 c2의 초기화
    c2.real = 1.5;
    c2.imaginary = -2.5;

    // 변수 c1과 c2의 값 출력
    printf("c1 = %.2f + %.2fi\n", c1.real, c1.imaginary);
    printf("c2 = %.2f + %.2fi\n", c2.real, c2.imaginary);

    return 0;
}

#endif



#if 0

/*
복소수를 구조체로 표현해보자.
복소수 a와 복소수 b를 받아서 a+b를 계산하는 함수를 작성하시오.
함수는 구조체를 반환할 수 있으며,
복소수는 read+imag*i 와 같은 형태를 갖는다.

Complex complex_add(complex a, Complex b) {
...
}

*/

// 복소수를 표현하는 구조체
typedef struct {
    float real;       // 실수 부분
    float imaginary;  // 허수 부분
} Complex;

// 복소수 더하기 함수
Complex complex_add(Complex a, Complex b) {
    Complex result;

    // 실수 부분 더하기
    result.real = a.real + b.real;

    // 허수 부분 더하기
    result.imaginary = a.imaginary + b.imaginary;

    return result;
}

int main() {
    // 복소수 a와 b 선언 및 초기화
    Complex a = { 2.0, 3.0 };  // a = 2 + 3i
    Complex b = { 1.5, -2.5 }; // b = 1.5 - 2.5i

    // a와 b를 더한 결과 계산
    Complex sum = complex_add(a, b);

    // 결과 출력
    printf("a + b = %.2f + %.2fi\n", sum.real, sum.imaginary);

    return 0;
}

#endif
