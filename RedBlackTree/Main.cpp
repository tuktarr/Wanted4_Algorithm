#include <iostream>
struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};
	Color color = Color::Black;
};

// Red-Black Tree
// 1) 모든 노드는 Red or Black
// 2) Root : Black
// 3) Leaf(NIL)은 Black
// 4) Red 노드의 자식은 Black
// 5) 각 노드로 부터 하위 리프까지의 경로들은 모두 같은 수의 Black
int main()
{

}