#pragma once
#include "Point.h"

/**
 * @brief Интерфейс для трёхмерной кривой
*/
class ICurve
{
	virtual ~ICurve() = default;
	
	/**
	 * @brief Вычисление трёхмерной точки, соответствующей данному значению параметра
	 * @param t значение параметра, при котором вычисляется точка
	 * @return точка на кривой
	*/
	virtual Point getPoint(double t) = 0;

	/**
	 * @brief Вычисление производной первого порядка в заданной точке
	 * @param t значение параметра, при котором вычисляется производная
	 * @return значение производной
	*/
	virtual Vector getDerivative(double t) = 0;
};
