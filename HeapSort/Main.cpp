#include <iostream>

// 배열을 힙으로 만드는 함수
// array : 정렬 중인 배열
// length : 배열 항목 수
// index : 현재 처리 중인 인덱스
// 인덱스 기반으로 부모도 구하고 자손도 구한다
void Heapify(int* array, int length, int index)
{
	// 힙 구성을 완료할 때까지 반복
	while (true)
	{
		// 최대 힙(MaxHeap)
		int largest = index; // 가정하고 시작 (더 큰 값 찾으면 바꿈)

		// 자손 인덱스 구하기
		// 왼쪽 자손 : 2N + 1
		int leftChild = 2 * index + 1;
		
		// 오른쪽 자손 : 2N + 2
		int rightChild = 2 * index + 2;

		// 왼쪽 자손을 먼저 largest에 넣고 그다음에 오른쪽 자손과 왼쪽 자손을 비교해서 더 큰 값을 Largest에 박음
		// 더 큰값 (+ 자손 인덱스 존재 여부 확인)
		if (leftChild < length && array[leftChild] > array[largest])
		{
			largest = leftChild;
		}

		// 더 큰값 (+ 자손 인덱스 존재 여부 확인)
		if (rightChild < length && array[rightChild] > array[largest])
		{
			largest = rightChild;
		}

		// 현재 노드가 가장 크면 종료
		// 힙 구조가 유지된 것이기 때문
		if (largest == index)
		{
			break;
		}

		// 현재 노드와 (가장 큰 값을 가지는)자손 노드 교환
		std::swap<int>(array[index], array[largest]);

		// largest를 index로 업데이트
		index = largest; // Loop가 진행되어도 index는 파라미터라서 잘 유지가 되고 largest는 한 번 루프가 끝나면 사라짐
	}
}

// 힙 정렬 함수
// 원시 배열이라 길이를 넘겨줘야함
void HeapSort(int* array, int length)
{
	// 1. 힙 구조로 변환
	for (int ix = length / 2 - 1; ix >= 0; --ix)
	{
		Heapify(array, length, ix);
	}

	// 2. 힙 정렬
	// > 0 : 루트 노드는 포함 안함
	// 거꾸로 교환을 해나감 (마지막 노드에서 점차 루트노드로 가까워짐)
	for (int ix = length - 1; ix > 0; --ix)
	{
		// (2)(3)번 과정 진행
		// 루트 노드와 마지막 노드 (현재 노드)를 교환
		std::swap<int>(array[0], array[ix]);

		// 힙 구조를 유지하기 위해 루트 노드부터 다시 힙으로 만들기
		// 이미 사용한 값을 맨뒤로 보내고 앞에 사용한 값을 맨 마지막에서 자연스럽게 사라짐 (인덱스 1씩 줄이기때문에)
		Heapify(array, ix, 0);
	}
}

// 배열 항목 출력 함수.
void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];

		// 마지막 원소 전까지는 콤마 출력.
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

//### ** 힙 정렬의 동작 방식**
//
//1. 주어진 배열을 최대 힙(Max Heap) 구조로 만든다.
//2. 최대 힙에서 루트 노드(가장 큰 값)를 추출하여 배열의 마지막 요소와 교환한다.
//3. 배열의 크기를 하나 줄이고, 변경된 부분 힙을 다시 최대 힙으로 만든다.
//4. 위 과정을 반복하여 정렬을 완성한다.
int main()
{
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 길이 구하기
	int length = _countof(array);

	// 출력
	PrintArray(array, length);

	// 정렬
	HeapSort(array, length);

	// 출력
	PrintArray(array, length);
	std::cin.get();
}