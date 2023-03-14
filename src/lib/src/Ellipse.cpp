#include <cmath>
#include <stdexcept>
#include "Ellipse.h"

void Ellipse::setRadiusX(double a)
{
	if (a <= 0)
	{
		throw std::runtime_error("X-radius of ellipse must be positive number!");
	}

	radiusX = a;
}

void Ellipse::setRadiusY(double b)
{
	if (b <= 0)
	{
		throw std::runtime_error("Y-radius of ellipse must be positive number!");
	}

	radiusY = b;
}

Point Ellipse::getPoint(double t) const
{
	return { radiusX * std::cos(t), radiusY * std::sin(t), 0. };
}

Vector Ellipse::getDerivative(double t) const
{
	return { -radiusX * std::sin(t), radiusY * std::cos(t), 0. };
}
