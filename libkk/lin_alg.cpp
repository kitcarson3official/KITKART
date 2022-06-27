#include "lin_alg.h"
#include <assert.h>
#include <math.h>
#include <string>

namespace KK {

/************************ SCALAR *************************/

bool is_zero(float a) { return abs(a) < PRECISION; }

/************************ POINT **************************/

std::string Point::to_string() {
  return "x:" + std::to_string(x) + " y:" + std::to_string(y);
}

float module(const Point x) { return sqrt(x.x * x.x + x.y * x.y); }

Point normalize(const Point x) {
  float modulev = KK::module(x);
  if (modulev == 0.f)
    return {0.f, 0.f};
  return {x.x / modulev, x.y / modulev};
}

Point rotate(const Point p, const float angle) {
  return {cos(angle) * p.x + sin(angle) * p.y,
          -sin(angle) * p.x + cos(angle) * p.y};
}

Point operator+(const Point &p1, const Point &p2) {
  return {p1.x + p2.x, p1.y + p2.y};
}

Point operator-(const Point &p1, const Point &p2) {
  return {p1.x - p2.x, p1.y - p2.y};
}

Point Point::operator+=(const Point &p) {
  this->x += p.x;
  this->y += p.y;
  return *this;
}

Point Point::operator-=(const Point &p) {
  this->x -= p.x;
  this->y -= p.y;
  return *this;
}

float operator*(const Point &p1, const Point &p2) {
  return p1.x * p2.x + p1.y * p2.y;
}

Point operator+(const Point &p, float a) { return {p.x + a, p.y + a}; }
Point operator-(const Point &p, float a) { return {p.x - a, p.y - a}; }
Point operator*(const Point &p, float a) { return {p.x * a, p.y * a}; }
Point operator/(const Point p, float a) {
  assert(a != 0.f);
  return {p.x / a, p.y / a};
}
Point operator+(const float a, const Point &p) { return {p.x + a, p.y + a}; }
Point operator-(const float a, const Point &p) { return {p.x - a, p.y - a}; }
Point operator*(const float a, const Point &p) { return {p.x * a, p.y * a}; }
Point operator/(const float a, const Point &p) {
  assert(a != 0.f);
  return {p.x / a, p.y / a};
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "{" << p.x << ", " << p.y << "}";
  return os;
}

namespace funcs {
float step(float x) { return x > 0.f ? 1.f : 0.f; }
} // namespace funcs

} // namespace KK
