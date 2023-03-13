#pragma once
#include "Point.h"
#include "ICurve.h"

/**
 * @brief Эллипс в плоскости XoY
*/
class Ellipse :public ICurve
{
private:

	/** X-полуось эллипса */
	double radiusX = 1;

	/** Y-полуось эллипса */
	double radiusY = 1;
	
public:

	Ellipse() = default;

	/**
	 * Основной конструктор для создания экземпляра класса
	 * @param a X-полуось эллипса
	 * @param b Y-полуось эллипса
	*/
	Ellipse(double a, double b)
	{
		setRadiusX(a);
		setRadiusY(b);
	}

	double getRadiusX() const { return radiusX; }

	double getRadiusY() const { return radiusY; }

	void setRadiusX(double a);

	void setRadiusY(double b);

	Point getPoint(double t) const override;

	Vector getDerivative(double t) const override;
};
