#include <assert.h>
#include "car.h"

namespace KK {
Car::Car(Point pos, Point dir) {
  this->pos = pos;
  this->direction_acc = normalize(dir);

  assert(point_module(direction_acc)!=0.f);

  vel.x = 0.0f;
  vel.x = 0.0f;
  
  module_acc = 0.0f;

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
}

void KK::Car::move(float t, float k) {
  Point acc = {module_acc * direction_acc.x, module_acc * direction_acc.y};
  vel.x += (acc.x - k * vel.x) * t;
  vel.y += (acc.y - k * vel.y) * t;
  pos.x += vel.x * t;
  pos.y += vel.y * t;
}

void KK::Car::accelerate() { module_acc = 300.f; }

void KK::Car::rest() { module_acc = 0.f; }

void KK::Car::turn_right() {
  KK::Point vel_norm = normalize(vel);
  direction_acc.x = -vel_norm.y;
  direction_acc.y = +vel_norm.x;
}

void KK::Car::turn_left() {
  KK::Point vel_norm = normalize(vel);
  direction_acc.x = +vel_norm.y;
  direction_acc.y = -vel_norm.x;
}

void KK::Car::go_straight() {
  KK::Point vel_norm = normalize(vel);
  direction_acc.x += vel_norm.x;
  direction_acc.y += vel_norm.y;
}

KK::Point KK::Car::get_pos() { return pos; }

KK::Point KK::Car::get_acc() { return direction_acc * module_acc; }

KK::Point KK::Car::get_vel() { return vel; }

} // namespace KK
