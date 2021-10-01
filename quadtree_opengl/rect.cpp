#include "rect.h"

Vector2d Rect::mid()
{
	return (a + c) / 2.0;
}

bool Rect::intersect(const Vector2d& pos)
{
	// inclusive box intersect since the random function populating can be 1.0,
	// and i want them all to succeed. :)
	// But this means gameobjects on boarders will return true for both.
	// Witch is fine since that loop will break;
	if (pos.x >= a.x && pos.x <= b.x
		&& pos.y >= a.y && pos.y <= d.y)
	{
		return true;
	}
	return false;
}

Rect& Rect::offset(const Vector2d& offset)
{
	a.x += offset.x;
	a.y += offset.y;
	b.x += offset.x;
	b.y += offset.y;
	c.x += offset.x;
	c.y += offset.y;
	d.x += offset.x;
	d.y += offset.y;
	return *this;
}



std::ostream& operator << (std::ostream& out, const Rect& r)
{
	out << r.a << ' ' << r.b << ' ' << r.c << ' ' << r.d;
	return out;
}