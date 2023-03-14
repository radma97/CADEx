#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <algorithm>
#include <ctime>
#include <omp.h>
#include "Point.h"
#include "ICurve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

using namespace std;

/** Возвращает случайное положительное число, не большее 100 */
inline double getRandomPositive()
{
	return 100 * static_cast<double>(rand() + 1) / (RAND_MAX + 1);
}

shared_ptr<ICurve> generateRandomObject()
{
	switch (rand() % 3)
	{
	case 0:
		return make_shared<Circle>(getRandomPositive());

	case 1:
		return make_shared<Ellipse>(getRandomPositive(), getRandomPositive());

	default:
		return make_shared<Helix>(getRandomPositive(), getRandomPositive());
	}
}

int main()
{
	srand(time(0));

	int numberOfCurves = 10;

	vector<shared_ptr<ICurve>> curves(numberOfCurves);
	for (auto& elem : curves)
	{
		elem = generateRandomObject();
	}

	cout << "The coordinates of point and derivative of curves in first container:" << endl;
	for (const auto& elem : curves)
	{
		cout << (*elem).getPoint(acos(-1.) / 4) << '\t' << (*elem).getDerivative(acos(-1.) / 4) << endl;
	}
	cout << endl;

	vector<shared_ptr<Circle>> circles;
	for (auto& elem : curves)
	{
		if (auto p = dynamic_pointer_cast<Circle>(elem))
		{
			circles.push_back(move(p));
		}
	}

	/** сортировка окружностей по радиусу */
	sort(circles.begin(), circles.end(), [](const auto& p1, const auto& p2) {
		return p1->getRadius() < p2->getRadius();
		});

	double sumOfRadii = 0;

#pragma omp parallel for reduction(+:sumOfRadii)
	for (int i = 0; i < (int)circles.size(); ++i)
	{
		sumOfRadii += circles[i]->getRadius();
	}
	cout << "The sum of the radii of the second container elements = " << sumOfRadii << endl;

	return 0;
}
