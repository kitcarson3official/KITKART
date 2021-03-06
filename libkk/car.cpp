#include "car.h"

#define _USE_MATH_DEFINES
#include <assert.h>
#include <math.h>

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

Car::Car(Point pos, Point dir) {
  this->pos = pos;
  this->direction = normalize(dir);

  assert(module(direction) != 0.f);

  vel = {0.f, 0.f};
  acc = 0.0f;
}

void KK::Car::move(float t, float k) {
  Point acc_vector = acc * rotate(direction, steer);
  vel += (acc_vector - k * vel) * t;
  pos += vel * t;
  if (!is_zero(module(vel))) {
    direction = normalize(vel);
  }
}

/**
 * @brief accelerating means having a positive acceleration in the moving
 * direction
 *
 */
void Car::accelerate() { acc = 300.f; }

/**
 * @brief decelerating means having a negative acceleration in the moving
 * direction
 *
 */
void Car::decelerate() { acc = -100.f; }

void Car::rest() { acc = 0.f; }

void Car::turn_right() { steer = -M_PI_4; }

void Car::turn_left() { steer = M_PI_4; }

void Car::go_straight() { steer = 0.f; }

Point Car::get_pos() { return pos; }

Point Car::get_acc() { return direction * acc; }

Point Car::get_vel() { return vel; }

} // namespace KK
