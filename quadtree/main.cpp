
#include "quadtree.h"

int main()
{
	Rect r = {
		{0, 0},
		{1, 0},
		{1, 1},
		{0, 1},
	};

	QuadNode gameworld{ r };
	gameworld.print_corners();
	std::cout << std::endl << std::boolalpha;
	for (size_t i = 0; i < 64; i++)
	{
		std::string name;
		(rand() % 2) ? name = "Adrian" : name = "Espen";
		Vector2d pos = {
			((double)rand() / (double)RAND_MAX),
			((double)rand() / (double)RAND_MAX)
		};
		if (auto [node, confirmation] = gameworld.insert_gameobject({ name, pos }); confirmation)
		{
			std::cout << "inserted gameobject: " << name << ' ' << pos << " in: ";
			node->print_corners();
		}
		else
		{
			std::cout << "failed insert for pos: " << pos << std::endl;
		}
	}
	gameworld.print_corners();
	std::cout << std::endl;
	gameworld.print_leaf_corners();
}