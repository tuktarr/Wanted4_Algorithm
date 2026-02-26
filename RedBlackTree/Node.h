#pragma once

#include <iostream>
#include <string>

// 메모리 삭제 함수
template<typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

// 추가를 할 때, 레드로 추가 ( 레드 - 레드 : 재구성)
// 하위 리프 노드의 경로에는 같은 개수의 블랙 노드가 있다.
// 노드 색상 열거형
enum class Color
{
	Red = 0,
	Black = 1,
};

// 노드 클래스
class Node
{
public:

	// 생성자
	Node(int data = 0, Color color = Color::Red);
	~Node() = default;

	// Getter/Setter
	inline const int Data() const { return data; }
	inline void SetData(int newData) { data = newData; }

	// 색상
	inline const Color GetColor() const { return color; }
	inline void SetColor(Color newColor) { color = newColor; }
	const char* ColorString() const;

	// 부모 노드
	inline Node* Parent() const { return parent; }
	inline void SetParent(Node* newParent) { parent = newParent; }

	// 왼쪽 자식 노드
	inline Node* Left() const { return left; }
	inline void SetLeft(Node* newLeft) { left = newLeft; }

	// 오른쪽 자식 노드
	inline Node* Right() const { return right;}
	inline void SetRight(Node* newRight) { right = newRight; }

private:

	// 데이터
	int data = 0;

	// 색상
	Color color = Color::Red;

	// 부모 노드
	Node* parent = nullptr;

	// 왼쪽 자식 노드
	Node* left = nullptr;

	// 오른쪽 자식 노드
	Node* right = nullptr;
};

