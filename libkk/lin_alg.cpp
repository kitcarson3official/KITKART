#include <math.h>
#include <assert.h>
#include <string>
#include "lin_alg.h"

namespace KK {

std::string Point::to_string()
{
  return "x:" + std::to_string(x) + " y:" + std::to_string(y);
}

float point_module(const Point x) { return sqrt(x.x * x.x + x.y * x.y); }

Point normalize(const Point x) {
  float modulev = KK::point_module(x);
  if (modulev == 0.f)
    return {0.f, 0.f};
  return {x.x / modulev, x.y / modulev};
}

Point operator+(const Point &p1, const Point &p2) {
  return {p1.x + p2.x, p1.y + p2.y};
}
Point operator-(const Point &p1, const Point &p2) {
  return {p1.x - p2.x, p1.y - p2.y};
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
} // namespace KK
