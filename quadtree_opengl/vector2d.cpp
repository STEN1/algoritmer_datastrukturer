#include "vector2d.h"


std::ostream& operator << (std::ostream& out, const Vector2d& v)
{
	out << "(" << v.x << ", " << v.y << ")";
	return out;
}