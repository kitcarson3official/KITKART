#include "car.h"
#include <assert.h>
#include <cmath>
#include <iostream>
using namespace std;

// some precomputed stuff
//
// the velocity is expressed in meters/second but when represented
// on the screen it becomes pixels/second so that it becomes needed
// a conversion rate of pixels/meter

#define PIXELS_PER_METER 30.f

// the max velocity is suck that
//                  acc - k * vel_max = 0
// so
//                       vel/max = acc/k

#define MAX_VELOCITY 250.f // m/s

// k means how much of velocity it's subtracted form itself
// greater the k, slower the velocity reaches its maximum value
// k = 0.1 means that each time step a 10% of velocity it's subtracted from
// itself. i think it should be around 0.01

namespace KK {

Car::Car(Point pos, Point dir): pos(pos), direction(dir) {}

void KK::Car::move(float t, float k) {
  Point acc_vector = acc * rotate(direction, steer);
  vel += (acc_vector - k * vel) * t;
  pos += vel * t;
  std::cout << acc_vector << "; " << vel << "; " << k << "; " << t << endl;
  if (!is_zero(module(vel))){
    direction = normalize(vel);
  }
}

/**
 * @brief accelerating means having a positive acceleration in the moving
 * direction
 *
 */
void KK::Car::accelerate() { acc = 300.f; }

/**
 * @brief decelerating means having a negative acceleration in the moving
 * direction
 *
 */
void KK::Car::decelerate() { acc = -100.f; }

void KK::Car::rest() { acc = 0.f; }

void KK::Car::turn_right() {
  steer = -M_PIf/2;
}

void KK::Car::turn_left() {
  steer = M_PIf/2;
}

void KK::Car::go_straight() {
  steer = 0.f;
}

KK::Point KK::Car::get_pos() { return pos; }

KK::Point KK::Car::get_acc() { return direction * acc; }

KK::Point KK::Car::get_vel() { return vel; }

} // namespace KK
