#include <math.h>
#include "lin_alg.h"

namespace KK
{
	float point_module(const Point x) 
	{ 
		return sqrt(x.x * x.x + x.y * x.y); 
	}

	Point normalize(const Point x) 
	{
		float modulev = KK::point_module(x);
		if (modulev == 0.f) return {0.f, 0.f};
		return {x.x / modulev, x.y / modulev};
	}
}