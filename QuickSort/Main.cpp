#include <iostream>
#include <Windows.h>

// 퀵 정렬 재귀 함수

// 파티션(기준점-Pivot)
// - 기준점 -Pivot 선택 및 분할 함수
int Partition(int* array, int left, int right)
{
	// TODO: 구현해야함
	// Incomplete , Hack , Problem, Performance : Todo처럼 쓰는거

	// 분할을 위한 변수
	// 전달된 배열의 첫 항목을 피벗으로 선택(다른 방법도 가능)
	int pivot = array[left];
	int low = left + 1;
	int high = right;

	// 왼쪽에서 오른쪽으로, 오른쪽에서 왼쪽으로 이동하면서 분할 처리
	while (low <= right)
	{
		// 왼쪽에서 오른쪽으로 이동 처리
		// 기준 값보다 큰 값 찾기 (low 증가 처리)
		while (low <= right && array[low] <= pivot)
		{
			++low;
		}
		// 1회차 : low 2번 인덱스가리키고 있음

		// 오른쪽에서 왼쪽으로 이동 처리
		// 기준 값보다 작은 값 찾기 (high 감소 처리)
		while (high > left && array[high] >= pivot)
		{
			--high;
		}

		// 두 인덱스가 교차했는지 확인
		if (low > high)
		{
			break;
		}
		// 1회차 : 교차 x -> 계속 반복

		// low와 high 교환
		std::swap<int>(array[low], array[high]);
	}

	// 피벗 값과 왼쪽 데이터 집합의 마지막 요소(high)를 교환
	// 노션 노트의 분할과정 이미지 참고
	// array[left] :현재 피벗
	std::swap<int>(array[left], array[high]);

	// 피벗의 최종 위치 반환
	return high;
}

// 배열 항목 출력 함수
void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];

		// 마지막 원소 까지는 콤마 출력
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

// 퀵 정렬 재귀 함수
void QuickSort(int* array, int left, int right)
{
	// left와 right가 만나면 종료
	if (left >= right)
	{
		return;
	}

	// 배열 분할
	int pivot = Partition(array, left, right);

	// 왼쪽 배열 정렬 (재귀)
	QuickSort(array, left, pivot - 1);

	// 오른쪽 배열 정렬 (재귀)
	QuickSort(array, pivot + 1, right);
}



int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 항목 개수 구하기
	// sizeof(array) / sizeof(array[0])
	int length = _countof(array);

	// 출력
	// 정렬 전
	std::cout << "정렬 전: ";
	PrintArray(array, length);

	// 정렬
	QuickSort(array, 0, length - 1);

	std::cout << "정렬 후: ";
	PrintArray(array, length);

	// F5로 실행했을 때, 의미있음
	std::cin.get();
}