
#include "quadtree.h"

int main()
{
	Rect r = {
		{0, 0},
		{1, 0},
		{1, 1},
		{0, 1},
	};

	QuadNode qtre = { r };
	qtre.divide();
	qtre.a()->divide();
	qtre.print();
}