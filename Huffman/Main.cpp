#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>

struct Node
{
	Node() = default;
	Node(char value, uint32_t count) : Value{value}, Count{count} {}
	Node* Over = nullptr;
	Node* Left = nullptr;
	Node* Right = nullptr;
	uint32_t Count;
	char Value;
	operator uint32_t () const { return Count; }
};

bool HuffCmp(const std::pair<char, uint32_t>& l, const std::pair<char, uint32_t>& r)
{
	return l.second < r.second;
}

bool IsLeaf(Node* node)
{
	if (!node->Left && !node->Right)
		return true;
	return false;
}

void PrintCodes(Node* root, int arr[], int top)

{

	// Assign 0 to left edge and recur
	if (root->Left) {

		arr[top] = 0;
		PrintCodes(root->Left, arr, top + 1);
	}

	// Assign 1 to right edge and recur
	if (root->Right) {

		arr[top] = 1;
		PrintCodes(root->Right, arr, top + 1);
	}

	// If this is a leaf node, then
	// it contains one of the input
	// characters, print the character
	// and its code from arr[]
	if (IsLeaf(root)) {

		std::cout << root->Value << ": ";
		for (size_t i = 0; i < top; i++)
		{
			std::cout << arr[i];
		}
		std::cout << std::endl;
	}
}
void Compress()
{
	
	// Do the huffman
	// Read file to string
	std::string fileString;
	if (std::ifstream inFile{ "Orginal.txt", std::ios::ate })
	{
		auto size = inFile.tellg();
		fileString.resize(size, '\0');
		inFile.seekg(0);
		inFile.read(&fileString[0], size);
	}

	// Make table for huffman tree
	std::unordered_map<char, uint32_t> huffmanTable;
	for (int i = 0; i < fileString.size(); i++)
		huffmanTable[fileString[i]]++;
	for (auto [key, value] : huffmanTable)
		std::cout << key << ' ' << value << std::endl;

	// Make huffman tree
	auto cmp = [](Node* l, Node* r) { return l->Count > r->Count; };
	std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> apq(cmp);

	for (auto [key, value] : huffmanTable)
		apq.emplace(new Node(key, value));

	std::cout << "APQ" << std::endl;

	Node* root = nullptr;
	while (!apq.empty())
	{
		Node* left = apq.top();
		Node* right;
		apq.pop();
		if (!apq.empty())
		{
			right = apq.top();
			apq.pop();
		}
		else
		{
			root = left;
			break;
		}
		auto newNode = new Node();
		newNode->Count = left->Count + right->Count;
		newNode->Left = left;
		newNode->Right = right;
		apq.push(newNode);
	}

	// Print huffman codes
	int arr[100];
	PrintCodes(root, arr, 0);
}

void Decompress()
{

}

int main()
{
	Compress();
	Decompress();
}