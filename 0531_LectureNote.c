
#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-31 update
/*
*****************
* 20240531 �ǽ� *
*****************
*/


// ���� �˰��� �ǽ�

// insertion, selection, bubble, merge, heap sort.

#include <stdio.h>

#if 0
// selection sort (���� ����)

/*

���� ��ġ�� ���� ���� �۴ٰ� ����, 
������ ����� ���Ͽ� �� ���� ���� �����ϸ� ��ġ�� �ٲ۴�.

*/

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int _data[], int _sz) {

	int k = 0; // ���� ���� �ָ� ã���� ������ ��ġ
	int temp;
	int least = 0; // ���� ���� ���� ���� index
	for (k = 0; k < _sz - 1; k++) {

		least = k;
		for (int i = k + 1; i < _sz; i++) {
			// ���� �˷��� ���� ���� ��(least) ����
			// �� ���� �ְ� ������,
			// �� ��ġ�� ���
			if (_data[least] > _data[i]) {
				least = i; // ���ο� ���� ��!!!
			}
		}

		// least���� ���� ���� ���� index�� ���
		// ������, ��ġ�� �ٲ��ش�.
		temp = _data[least];
		_data[least] = _data[k];
		_data[k] = temp;

		// SWAP(least, k, temp)
	}
}


#endif

#if 0
// insertion sort (���� ����)
/*

�� (me) ���� �տ� ���� ũ�� ���� ���� �ڷ�, 
�� (me) ���� �տ� ���� ������ ���� ���� ���� �ڷ� ����.

�� �ձ��� ���� ��� j = -1, ���� me�� j + 1 = 0�ڸ��� ��. 
��, �� �� �ڸ��� ����.

*/

void insertion_sort(int _data[], int _sz) {

	int i, j, temp;

	for (i = 1; i < _sz; i++) {  // �ݺ�

		int me = _data[i]; // �ϴ�, �ڸ��� �����ش�. ������ ū �ְ� �� �� �ֵ���
		for (j = i - 1; j >= 0; j--) { // for���� ���� ������ j = -1�� ����ִ�.
			if (_data[j] > me) {
				_data[j + 1] = _data[j];
			}
			if (_data[j] < me) { // ���̻� �� �� ���� ����
				break;
			}
		}
		// ������� ����,,,,
		_data[j + 1] = me;
	}
}


#endif

#if 0
// bubble sort (���� ����)
/*

�տ������� ���ʷ� 2���� ��,
���� ���� �ں��� ũ�� �ڸ��� �ٲ۴�.

*/
void do_bubble_sort(int _data[], int _sz) {

	int i, j, temp;

	for (i = 0; i < _sz; i++) {

		for (j = 0; j < _sz - 1 - i; j++) {
			if (_data[j] > _data[j + 1]) { // �չ���� �޹�ﺸ�� ũ��!!! �����!!!

				temp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = temp;
			}
		}

	}
}

#endif


# define MAX_SIZE 8

#if 0

// merge sort (���� ����)
int sorted[MAX_SIZE];// �߰����� ������ �ʿ�

// i: ���ĵ� ���� ����Ʈ�� ���� �ε���
// j: ���ĵ� ������ ����Ʈ�� ���� �ε���
// k: ���ĵ� ����Ʈ�� ���� �ε���
/* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
/* (������ ���ڵ��� ���ĵǴ� ����) */

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// ���� �ִ� ������ �ϰ� ����
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	// ���� �ִ� ������ �ϰ� ����
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

// �պ� ����
void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge_sort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
	}
}

void main() {
	int i;
	int list[MAX_SIZE] = { 21, 10, 12, 20, 25, 13, 15, 22 };

	// �պ� ���� ����(left: �迭�� ���� = 0, right: �迭�� �� = 7)
	merge_sort(list, 0, MAX_SIZE - 1);

	// ���� ��� ���
	for (i = 0; i < MAX_SIZE; i++) {
		printf("%d\n", list[i]);
	}
}

#endif

