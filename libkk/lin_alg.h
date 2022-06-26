#ifndef KK_LIN_ALG
#define KK_LIN_ALG

#include <ostream>

namespace KK {
struct Point {
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
Point operator+(const Point &p1, const Point &p2);
Point operator-(const Point &p1, const Point &p2);
float operator*(const Point &p1, const Point &p2);
Point operator+(const Point &p, const float a);
Point operator-(const Point &p, const float a);
Point operator*(const Point &p, const float a);
Point operator/(const Point &p, const float a);
Point operator+(const float a, const Point &p);
Point operator-(const float a, const Point &p);
Point operator*(const float a, const Point &p);
Point operator/(const float a, const Point &p);
std::ostream& operator<<(std::ostream& os, const Point &p);
}
#endif
