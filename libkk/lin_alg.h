/*
 * This module is intended to host all functions and structures releated just to
 * linear algebra.
 * The problem to solve is for now only in 2D so there is just the Point class
 * and not a vector of generic dimension. If worth will be maybe implemented
 * via templates.
 *
 * The point is represented as a collection of two floats named x and y but it
 * could also be used as a generic vector that as a direction and a module so
 * such utilities functions are provided together with the most useful
 * operator overloading.
 */

#ifndef KK_LIN_ALG
#define KK_LIN_ALG

#include "math.h"
#include <ostream>

namespace KK {

/********************** CONSTANTS ***********************/
const float PRECISION = 1e-3;

/********************* SCALAR **************************/

/**
 * @brief A numerical zero is sometimes just a very small number so a threshold
 *        to distinguish a zero from a number is needed
 * @param a the scalar to check
 * @return true if zero, false if not
 */
bool is_zero(float a);

/************************** POINT ***********************/

struct Point {
  float x;
  float y;

  Point operator+=(const Point &p);
  Point operator-=(const Point &p);
  std::string to_string();
};

/**
 * @brief the magnitude of a vector
 * @param x the vector coordinates
 * @return the magnitude
 */
float module(const KK::Point x);

/**
 * @brief normalize a vector (returns a copy of it)
 * @param x the vector coordinates
 * @return a vector with length 1 and same direction as x
 */
Point normalize(const KK::Point x);

Point rotate(const Point p, const float angle);

Point operator+(const Point &p1, const Point &p2);
Point operator-(const Point &p1, const Point &p2);
Point operator+=(const Point &p1, const Point &p2);
Point operator-=(const Point &p1, const Point &p2);
float operator*(const Point &p1, const Point &p2);
Point operator+(const Point &p, const float a);
Point operator-(const Point &p, const float a);
Point operator*(const Point &p, const float a);
Point operator/(const Point &p, const float a);
Point operator+(const float a, const Point &p);
Point operator-(const float a, const Point &p);
Point operator*(const float a, const Point &p);
Point operator/(const float a, const Point &p);
std::ostream &operator<<(std::ostream &os, const Point &p);

namespace funcs {
float step(float x);
}

} // namespace KK
#endif
