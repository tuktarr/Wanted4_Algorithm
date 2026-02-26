#include <iostream>
#include <time.h>

// 나눗셈을 활용한 랜덤
int RandomRange(int min, int max)
{
	//범위의 차이
	int diff = (max - min + 1);

	// 나눗셈을 이용해서 원하는 범위의 랜덤 반환
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

// 나눗셈을 이용한 랜덤 (부동소수형 - float)
float RandomPercent()
{
	// 0 ~ 1 사이의 부동소수형 값을 반환하는 랜덤 하수
	return rand() / static_cast<float>(RAND_MAX);
}

// 범위를 지정해 사용하는 랜덤 함수 (부동 소수형)
float RandomRange(float min, float max)
{
	// min-max 사이의 차 구하기

	int diff = max - min;
	return  (RandomPercent() * diff) + min;
}

int main()
{
	// __cdecl : 프로그램의 기본 호출 규칙
	// 함수 호출 시 스택정리를 호출자가 담당함
	// <-> __stdcall : 불리는 쪽에서 담당함

	// rand 함수에 seed(종자값)을 주지 않으면 rand()는 계속 같은 수를 생성함
	// 종자값(Seed) 설정
	srand(static_cast<unsigned int>(time(nullptr)));
	std::cout << "Random" << RandomRange(1.0f, 10.0f) << "\n";
	std::cout << "Random" << RandomRange(1.0f, 10.0f) << "\n";
	std::cout << "Random" << RandomRange(1.0f, 10.0f) << "\n";
	std::cin.get();
}