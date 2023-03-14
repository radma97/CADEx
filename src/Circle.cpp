#include <cmath>
#include <stdexcept>
#include "Circle.h"

void Circle::setRadius(double r)
{
	/* если радиус неположительный, то имеет место исключительная ситуация,
	продолжать вычисления в этом случае некорректно */
	if (r <= 0)
	{
		throw std::runtime_error("Radius of circle must be positive number!");
	}

	radius = r;
}

Point Circle::getPoint(double t) const
{
	return { radius * std::cos(t), radius * std::sin(t), 0. };
}

Vector Circle::getDerivative(double t) const
{
	return { -radius * std::sin(t), radius * std::cos(t), 0. };
}
