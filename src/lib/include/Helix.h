#pragma once
#include "Point.h"
#include "ICurve.h"

/**
 * @brief Трёхмерная спираль
*/
class Helix :public ICurve
{
private:

	/** Радиус спирали */
	double radius = 1;

	/** Шаг спирали по оси Z */
	double step = 1;

public:

	Helix() = default;

	/**
	 * Основной конструктор для создания экземпляра класса
	 * @param r радиус спирали
	 * @param step шаг спирали
	*/
	Helix(double r, double step)
	{
		setRadius(r);
		setStep(step);
	}

	double getRadius() const { return radius; }

	double getStep() const { return step; }

	void setRadius(double r);

	void setStep(double step);

	Point getPoint(double t) const override;

	Vector getDerivative(double t) const override;
};
