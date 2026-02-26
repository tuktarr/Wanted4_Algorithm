#include <iostream>

// 함수(Function) / 메소드(Method)
// c++
// 일반 함수 - Function
// 객체의 멤버 함수 - Method



// 버블 정렬 -> 가장 간단한 정렬 알고리즘
// 인접한 두 원소 비교 -> 서로 위치 교환
// 가장 큰 원소가 배열의 가장 마지막으로 이동
// 첫 번째 원소부터 마지막 원소까지 순회한다
// (n-1) * n / 2

// 함수 포인터 타입 지정
using Comparer = bool (*)(int, int);

// 함수 포인터 활용
bool IsGreater(int left, int right)
{
	return left > right;
}

bool IsLess(int left, int right)
{
	return left < right;
}

// 버블 정렬 함수
// 비교 조건 확인 로직을 Comparer에게 맡김 -> 위임
// -> Delegate(델리게이트)
void BubbleSort(int* array, int length, Comparer comparer)
{
	// 둘둘비교
	// 1회차
	for (int ix = 0; ix < length - 1; ++ix)
	{
		// array 비교
		for (int jx = 0; jx < length - 1 - ix; ++jx)
		{
			// 비교
			/*if (array[jx] > array[jx + 1])*/
			if(comparer(array[jx], array[jx + 1]))
			{
				// 교체
				std::swap<int>(array[jx], array[jx + 1]);
			}
		}
	}
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

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 길이
	int length = sizeof(array) / sizeof(array[0]);

	// 출력
	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	// 정렬
	//BubbleSort(array, length, IsGreater);
	BubbleSort(array, length, IsLess);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);

	std::cin.get();
}