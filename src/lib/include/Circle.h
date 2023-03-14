#pragma once
#include "Point.h"
#include "ICurve.h"

/**
 * @brief Окружность в плоскости XoY
*/
class Circle :public ICurve
{
private:

	/** Радиус круга */
	double radius = 1;

public:

	Circle() = default;

	/**
	 * Основной конструктор для создания экземпляра класса
	 * @param r радиус круга
	*/
	Circle(double r)
	{
		setRadius(r);
	}

	double getRadius() const { return radius; }

	void setRadius(double r);

	Point getPoint(double t) const override;

	Vector getDerivative(double t) const override;
};
