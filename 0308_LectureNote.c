#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-03-12 update
/*
*****************
* 20240308 �ǽ� *
***************** 
*/

#include <stdio.h>


#if 0

/*
���� ����
���� ���� 1���� �Է¹޾�, ¦���̸� even, Ȧ���̸� odd�� ����Ͻÿ�.

��, even�� odd ���� �ٹٲ� ���ڴ� ����.
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
ũ�Ⱑ 10�� �迭 two[]�� �����ϰ� ���⿡ 2�� ���� ������ �����϶�.
��, �迭�� ù��° ��ҿ��� 2^0�� �����ϰ� �� ��° ��ҿ��� 2^1 ���� �����Ѵ�.
������ ��ҿ��� 2^9 ���� �����Ѵ�.
for ������ �̿��Ͽ� two[] �迭�� ��ü ����� ���� ����ϴ� ���α׷��� �ۼ��϶�.
*/

int main() {
    int two[10]; // ũ�Ⱑ 10�� �迭 two[] ����

    int power = 1; // 2�� �ŵ����� ���� ������ ����

    // �迭�� 2�� ���� ���� ����
    for (int i = 0; i < 10; i++) {
        two[i] = power;
        power *= 2; // ���� 2�� ���� ���� ����ϱ� ���� 2�� ����
    }

    /*
    ����) ��Ʈ ����Ʈ�� Ȱ���� �ٸ� Ǯ��
    */
    
    // �迭�� 2�� ���� ���� ����
    //for (int i = 0; i < 10; i++) {
    //    two[i] = 1 << i; // 2�� i ������ 1�� i�� left shift�� ���� ����.
    //}

    // �迭�� ��� ���
    // printf("two[] �迭�� ��� ��:\n");
    for (int i = 0; i < 10; i++) {
        printf("two[%d] = %d\n", i, two[i]);
    }

    return 0;
}

#endif

#if 0

/*
���� �ǽ� ����)
person �̶�� ����ü�� �ۼ��϶�.
�� ����ü���� ���� �迭�� �� �̸�, ����� ���̸� ��Ÿ���� ���� ��,
�� ������ ������ ��Ÿ���� float �� ���� ������ ���� �Ѵ�.
*/

// person ����ü ����
struct person {
    char name[50]; // ���� �迭�� �� �̸�
    int age; // ����� ���̸� ��Ÿ���� ���� ��
    float salary; // �� ������ ������ ��Ÿ���� float ��
};

int main() {
    // person ����ü ���� ����
    struct person individual;

    // ���� �Է�
    printf("�̸��� �Է��ϼ���: ");
    scanf("%s", individual.name);

    printf("���̸� �Է��ϼ���: ");
    scanf("%d", &individual.age);

    printf("������ �Է��ϼ���: ");
    scanf("%f", &individual.salary);

    // ���� ���
    printf("\n�Էµ� ����:\n");
    printf("�̸�: %s\n", individual.name);
    printf("����: %d\n", individual.age);
    printf("����: %.2f\n", individual.salary);

    return 0;
}

#endif

#if 0

/*
2���� ��ǥ�� ���� ���� ��Ÿ���� points ����ü�� �ۼ��Ѵ�.
points ����ü�� x��ǥ�� y��ǥ�� ������.

����ڷκ��� x��ǥ�� y��ǥ�� �ԷµǸ�,
�� ���� ��и� �� ��� ��ġ�ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

��, �� ���� ��ġ�ϰų� �����̸� 0�� ����Ѵ�.
*/


// ��ǥ�� ��Ÿ���� points ����ü ����
struct Point {
    int x;  // x ��ǥ
    int y;  // y ��ǥ
};

int main() {
    struct Point point; // Point ����ü ���� ����

    // ����ڷκ��� x��ǥ�� y��ǥ �Է� �ޱ�
    printf("x ��ǥ�� �Է��ϼ���: ");
    scanf("%d", &point.x);
    printf("y ��ǥ�� �Է��ϼ���: ");
    scanf("%d", &point.y);

    // �Է� ���� ��ǥ�� ��� ��и鿡 ���ϴ��� �Ǻ��Ͽ� ���
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
C ���� ��ȯ(recursion)�� �Լ��� �ڱ� �ڽ��� ȣ���ϴ� ���� �ǹ�.
��ȯ�� �ݺ����� ���������� ���α׷����� Ư�� �۾��� �ݺ��Ͽ� ������ �� ���.
��ȯ�� ��� �Լ�(recursive function)��� ���·� �����Ǹ�, 
��� ȣ���� ���� ������ �ذ���.

��ȯ�� ����ϴ� ���, 
�Լ��� �⺻ ���(base case)�� ������ ������ �ڱ� �ڽ��� ȣ����.
�⺻ ���(Ż�� ����)�� �Լ��� �� �̻� ȣ����� �ʰ� ����Ǿ�� �ϴ� ��츦 �ǹ�.

�⺻ ��ʿ� ������ �� ����, �Լ��� ��� ȣ���� �����Ͽ� ������ �� ���� �κ� ������ 
�����ϰ�, �̸� �ذ��ϱ� ���� �ڱ� �ڽ��� ȣ��.

��� ȣ���� �ᱹ �⺻ ��ʿ� �����Ͽ� ��Ͱ� ����� ������ �ݺ���.

��ȯ�� �ڵ带 �� �����ϰ� �����ϱ� ���� ���� �� ������, 
�߸��� ������ ���� ������ ���� �� �ֱ� ������ ���ǰ� �ʿ�.

/*
��� �Լ��� ����Ͽ� 
���� ���� n���� 1������ ���� ����ϴ� �Լ� sumFromNtoOne �� �ۼ��Ͻÿ�.
*/

// ��� �Լ��� ����Ͽ� n���� 1������ ���� ����ϴ� �Լ�
int sumFromNtoOne(int n) {
    // �⺻ ���: n�� 1 ������ �� n�� ��ȯ
    if (n <= 1) {
        return n;
    }
    // ��� ȣ��: n�� n-1���� 1������ ���� ����
    else {
        return n + sumFromNtoOne(n - 1);
    }
}

int main() {
    int n;
    //printf("���� ������ �Է��ϼ���: ");
    scanf("%d", &n);
    // �Լ� ȣ���Ͽ� ��� ���
    printf("%d\n", sumFromNtoOne(n));

    return 0;
}


/*
�� �ڵ�� ��� �Լ��� ����Ͽ� ���� ���� n���� 1������ ���� ����Ѵ�.
�Լ��� �ڱ� �ڽ��� ȣ���Ͽ� n���� n - 1������ ���� ����� ��, �̸� n�� ���Ͽ� ��ȯ.
�⺻ ���(base case)������ n�� 1 ������ �� n�� ��ȯ�Ͽ� ��� ȣ���� ����. (n�� 1�� ��ȯ)
*/

#endif


/*
******************
* �߰� �н� �ڷ� *
******************
*/

#if 0

/*
�����ͷ� swap �����ϱ�
*/

// ���� �����͸� �޾� �ش��ϴ� �� ���� ���� ���� �ٲٴ� �Լ�
void swap(int* px, int* py)
{
    int temp;  // �ӽ� ���� ����

    temp = *px;  // temp�� px�� ����Ű�� ���� ���� ����
    *px = *py;   // py�� ����Ű�� ���� ���� px�� ����Ű�� ��ġ�� ����
    *py = temp;  // temp�� ����� ���� py�� ����Ű�� ��ġ�� ����
}

int main() {
    int a = 1, b = 2;  // ���� ���� a�� b�� �����ϰ� �ʱ�ȭ

    // �ʱ� �� ���
    printf("a: %d, b: %d\n", a, b);

    // swap �Լ��� ȣ���Ͽ� a�� b�� �� ��ȯ
    swap(&a, &b);

    // ��ȯ�� �� ���
    printf("a: %d, b: %d", a, b);

    return 0;  // ���α׷� ����
}



/*
�� �ڵ�� swap �Լ��� ����Ͽ� �� ������ ���� ���� �ٲ� �����.
swap �Լ��� �����͸� �̿��Ͽ� �� ������ ���� ��ȯ.
main �Լ�������swap �Լ��� ȣ���Ͽ� a�� b�� ���� ��ȯ�� ��, ����� ���.
*/

#endif


#if 0

/*
���� ���� ����) 
ũ�Ⱑ n�� �迭 array���� ������ ��ġ loc�� ���� value�� �����ϴ� �Լ�
insert()�� �ۼ��Ͻÿ�.

������ ���ԵǸ� �� �ڿ� �ִ� �������� �� ĭ�� �ڷ� �з��� �Ѵ�.
���� �迭�� ����ִ� ������ ������ items����� ����.
(���⼭ items < n��� ����)

void insert(int array[], int loc, int value} {

}
*/

void insert(int array[], int loc, int value) {

    // �迭�� ���� ����
    for (int i = loc; i >= 0; i--) {
        array[i + 1] = array[i];
    }
    array[loc] = value;
}

int main() {
    int array[10] = { 1, 2, 3, 4, 5 };

    // �迭�� �� ����
    insert(array, 2, 10);

    // ��� ���
    printf("�迭: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
#endif


#if 0

/*
���� ���� ����)
typedef�� �̿��Ͽ� complex ��� �ϴ� ���ο� �ڷ����� �����϶�.
complex �ڷ����� ����ü�μ� float ���� real ������ imaginary ������ ���´�.
complex �ڷ������� ���� c1�� c2�� �����϶�.
*/

/*
typedef�� C ���α׷��� ���� ���Ǵ� Ű�����, ���ο� �ڷ����� ������ �� ���
typedef�� ����ϸ� ������ �ڷ����� ���� ����� ���� �ڷ����� �����, �ڵ带 �� �����ϱ� ���� ���� �� ����

typedef�� �⺻���� ����:
typedef ����_�ڷ��� ���ο�_�ڷ���_�̸�;

���� ���, struct�� ����Ͽ� ����ü�� ������ ������ struct Ű���带 ����ؾ� ������,
typedef�� ����ϸ� �̸� ���ϰ� ���� �� ����
�Ʒ��� ����ü�� typedef�� �����ϴ� ����:

typedef struct {
    int age;
    char name[50];
} Person;

Person person1;

*/

// complex �ڷ����� �����ϴ� ����ü
typedef struct {
    float real;       // �Ǽ� �κ�
    float imaginary;  // ��� �κ�
} complex;

int main() {
    // ���� c1�� c2�� complex �ڷ������� ����
    complex c1, c2;

    // ���� c1�� �ʱ�ȭ
    c1.real = 3.0;
    c1.imaginary = 4.0;

    // ���� c2�� �ʱ�ȭ
    c2.real = 1.5;
    c2.imaginary = -2.5;

    // ���� c1�� c2�� �� ���
    printf("c1 = %.2f + %.2fi\n", c1.real, c1.imaginary);
    printf("c2 = %.2f + %.2fi\n", c2.real, c2.imaginary);

    return 0;
}

#endif



#if 0

/*
���Ҽ��� ����ü�� ǥ���غ���.
���Ҽ� a�� ���Ҽ� b�� �޾Ƽ� a+b�� ����ϴ� �Լ��� �ۼ��Ͻÿ�.
�Լ��� ����ü�� ��ȯ�� �� ������,
���Ҽ��� read+imag*i �� ���� ���¸� ���´�.

Complex complex_add(complex a, Complex b) {
...
}

*/

// ���Ҽ��� ǥ���ϴ� ����ü
typedef struct {
    float real;       // �Ǽ� �κ�
    float imaginary;  // ��� �κ�
} Complex;

// ���Ҽ� ���ϱ� �Լ�
Complex complex_add(Complex a, Complex b) {
    Complex result;

    // �Ǽ� �κ� ���ϱ�
    result.real = a.real + b.real;

    // ��� �κ� ���ϱ�
    result.imaginary = a.imaginary + b.imaginary;

    return result;
}

int main() {
    // ���Ҽ� a�� b ���� �� �ʱ�ȭ
    Complex a = { 2.0, 3.0 };  // a = 2 + 3i
    Complex b = { 1.5, -2.5 }; // b = 1.5 - 2.5i

    // a�� b�� ���� ��� ���
    Complex sum = complex_add(a, b);

    // ��� ���
    printf("a + b = %.2f + %.2fi\n", sum.real, sum.imaginary);

    return 0;
}

#endif
