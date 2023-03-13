#include <cmath>
#include <stdexcept>
#include "Circle.h"

void Circle::setRadius(double r)
{
	/* ���� ������ ���������������, �� ����� ����� �������������� ��������,
	���������� ���������� � ���� ������ ����������� */
	if (r <= 0)
	{
		throw std::runtime_error("Radius of circle must be positive number!");
	}

	radius = r;
}

Point Circle::getPoint(double t) const
{
	return { std::cos(t), std::sin(t), 0. };
}

Vector Circle::getDerivative(double t) const
{
	return { -std::sin(t), std::cos(t), 0. };
}
