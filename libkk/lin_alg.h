#ifndef KK_LIN_ALG
#define KK_LIN_ALG

namespace KK
{
	struct Point
	{
		float x;
		float y;
	};

	
	/**
	 * @brief the magnitude of a vector
	 * @params x the vector coordinates
	 * @return the magnitude
	 */
	float point_module(const KK::Point x);

	/**
	 * @brief normalize a vector (returns a copy of it)
	 * @params x the vector coordinates
	 * @return a vector with length 1 and same direction as x
	 */
	KK::Point normalize(const KK::Point x);

}

#endif