/*
3.2.2
Det er noen ganger interessant � ha en finere oppdeling i enkelte omr�der.For
eksempel kan man tenke seg at man fortsetter oppdelingen av et rektangel som
inneholder et gitt punkt P0 helt til arealet av (det oppdelte) rektangelet som
inneholder P0 er mindre enn et forh�ndsbestemt areal A0. Implementer en slik
l�sning.
*/

#include "plainrectangle.h"
#include <iostream>

int main()
{
	Vector2d a{ 0, 0 };
	Vector2d b{ 1, 0 };
	Vector2d c{ 1, 1 };
	Vector2d d{ 0, 1 };
	
	PlainRectangle::subDivide(a, b, c, d, 0.02);
	PlainRectangle::print();
}