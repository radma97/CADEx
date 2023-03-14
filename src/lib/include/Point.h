#pragma once
#include <cmath>
#include <iostream>

/**
 * @brief Точка в пространстве
*/
struct Point
{
	double x;
	double y;
	double z;
};

inline std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "P = (" << p.x << ", " << p.y << ", " << p.z << ")";
	return os;
}

inline double sqr(double x)
{
	return x * x;
}

/**
 * @brief Вектор в пространстве
*/
struct Vector : Point
{
	/** Вычисление модуля вектора */
	double length()
	{
		return std::sqrt(sqr(x) + sqr(y) + sqr(z));
	}
};

inline std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "V = (" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}
