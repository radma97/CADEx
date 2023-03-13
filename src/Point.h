#pragma once
#include <cmath>

inline double sqr(double x)
{
	return x * x;
}

/**
 * @brief Точка в пространстве
*/
struct Point
{
	double x;
	double y;
	double z;

	/** Вычисление расстояния от текущей точки до другой */
	double distanceTo(Point const& other) const
	{
		return std::sqrt(sqr(x - other.x) + sqr(y - other.y) + sqr(z - other.z));
	}
};


/**
 * @brief Вектор в пространстве
*/
struct Vector : Point
{
	/** Вычисление модуля вектора */
	double length()
	{
		return std::sqrt(sqr(x) + sqr(y)+ sqr(z));
	}
};
