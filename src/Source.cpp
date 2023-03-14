#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
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
	switch (rand()%3)
	{
	case 0:
		return shared_ptr<Circle>(new Circle(getRandomPositive()));

	case 1:
		return shared_ptr<Ellipse>(new Ellipse(getRandomPositive(), getRandomPositive()));

	default:
		return shared_ptr<Helix>(new Helix(getRandomPositive(), getRandomPositive()));
	}
}

int main()
{
	srand(0);

	int numberOfCurves = 10;
	vector<shared_ptr<ICurve>> curves(numberOfCurves);
	for (auto& elem : curves)
	{
		elem = generateRandomObject();
	}

	for (const auto& elem : curves)
	{
		cout << (*elem).getPoint(acos(-1.) / 4) << ", " << (*elem).getDerivative(acos(-1.) / 4) << endl;
	}
	cout << endl;

	return 0;
}
