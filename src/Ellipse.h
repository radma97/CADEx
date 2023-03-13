#pragma once
#include "Point.h"
#include "ICurve.h"

/**
 * @brief Эллипс в плоскости XoY
*/
class Ellipse :public ICurve
{
private:

	/** Радиус круга */
	double radius = 1;
	
public:

	Ellipse() = default;

	/**
	 * Основной конструктор для создания экземпляра класса
	 * @param r радиус круга
	*/
	Ellipse(double r)
	{
		setRadius(r);
	}

	double getRadius() const { return radius; }

	void setRadius(double r);

	Point getPoint(double t) const override;

	Vector getDerivative(double t) const override;
};
