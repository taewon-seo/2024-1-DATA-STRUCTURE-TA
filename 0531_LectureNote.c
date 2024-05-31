
#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-31 update
/*
*****************
* 20240531 실습 *
*****************
*/


// 정렬 알고리즘 실습

// insertion, selection, bubble, merge, heap sort.

#include <stdio.h>

#if 0
// selection sort (선택 정렬)

/*

현재 위치의 값이 가장 작다고 가정, 
이후의 값들과 비교하여 더 작은 값이 존재하면 위치를 바꾼다.

*/

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int _data[], int _sz) {

	int k = 0; // 가장 작은 애를 찾으면 데려올 위치
	int temp;
	int least = 0; // 가장 작은 값을 갖는 index
	for (k = 0; k < _sz - 1; k++) {

		least = k;
		for (int i = k + 1; i < _sz; i++) {
			// 현재 알려진 가장 작은 애(least) 보다
			// 더 작은 애가 나오면,
			// 그 위치를 기억
			if (_data[least] > _data[i]) {
				least = i; // 새로운 작은 애!!!
			}
		}

		// least에는 가장 작은 애의 index가 담겨
		// 있으니, 위치를 바꿔준다.
		temp = _data[least];
		_data[least] = _data[k];
		_data[k] = temp;

		// SWAP(least, k, temp)
	}
}


#endif

#if 0
// insertion sort (삽입 정렬)
/*

나 (me) 보다 앞에 것이 크면 앞의 것을 뒤로, 
나 (me) 보다 앞에 것이 작으면 내가 앞의 것의 뒤로 들어간다.

맨 앞까지 왔을 경우 j = -1, 따라서 me는 j + 1 = 0자리에 들어감. 
즉, 맨 앞 자리에 들어간다.

*/

void insertion_sort(int _data[], int _sz) {

	int i, j, temp;

	for (i = 1; i < _sz; i++) {  // 반복

		int me = _data[i]; // 일단, 자리를 비켜준다. 나보다 큰 애가 올 수 있도록
		for (j = i - 1; j >= 0; j--) { // for문을 깨고 나오면 j = -1이 들어있다.
			if (_data[j] > me) {
				_data[j + 1] = _data[j];
			}
			if (_data[j] < me) { // 더이상 갈 수 없는 조건
				break;
			}
		}
		// 여기까지 오면,,,,
		_data[j + 1] = me;
	}
}


#endif

#if 0
// bubble sort (버블 정렬)
/*

앞에서부터 차례로 2개씩 비교,
앞의 것이 뒤보다 크면 자리를 바꾼다.

*/
void do_bubble_sort(int _data[], int _sz) {

	int i, j, temp;

	for (i = 0; i < _sz; i++) {

		for (j = 0; j < _sz - 1 - i; j++) {
			if (_data[j] > _data[j + 1]) { // 앞방울이 뒷방울보다 크다!!! 띄워라!!!

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

// merge sort (병합 정렬)
int sorted[MAX_SIZE];// 추가적인 공간이 필요

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
		merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
		merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
	}
}

void main() {
	int i;
	int list[MAX_SIZE] = { 21, 10, 12, 20, 25, 13, 15, 22 };

	// 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
	merge_sort(list, 0, MAX_SIZE - 1);

	// 정렬 결과 출력
	for (i = 0; i < MAX_SIZE; i++) {
		printf("%d\n", list[i]);
	}
}

#endif

