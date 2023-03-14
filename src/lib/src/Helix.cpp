#include <cmath>
#include <stdexcept>
#include "Helix.h"

using namespace Cur3D;

void Helix::setRadius(double r)
{
	if (r <= 0)
	{
		throw std::runtime_error("Radius of helix must be positive number!");
	}

	radius = r;
}

void Helix::setStep(double step)
{
	if (step <= 0)
	{
		throw std::runtime_error("Step of helix must be positive number!");
	}

	this->step = step;
}

Point Helix::getPoint(double t) const
{
	return { radius * std::cos(t), radius * std::sin(t), step * t / (2 * std::acos(-1.)) };
}

Vector Helix::getDerivative(double t) const
{
	return { -radius * std::sin(t), radius * std::cos(t), step / (2 * std::acos(-1.)) };
}
