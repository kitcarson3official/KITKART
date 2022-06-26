#include "car.h"

namespace KK {
Car::Car(float x0, float y0) {
  pos.x = x0;
  pos.y = y0;

  vel.x = 0.0f;
  vel.x = 0.0f;

  direction_acc = {1.f, 0.f};
  module_acc = 0.0f;

  // some precomputed stuff
  //
  // the velocity is expressed in meters/second but when represented
  // on the screen it becomes pixels/second so that it becomes needed
  // a conversion rate of pixels/meter
  
  const float PIXELS_PER_METER = 30.f;
  
  // the max velocity is suck that 
  //                  acc - k * vel_max = 0
  // so
  //                       vel/max = acc/k 

  const float MAX_VELOCITY = 250.f; // m/s
                                    
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
  direction_acc.x = vel_norm.y;
  direction_acc.y = vel_norm.x;
}

void KK::Car::turn_left() {
  KK::Point vel_norm = normalize(vel);
  direction_acc.x = +module_acc * vel_norm.y;
  direction_acc.y = -module_acc * vel_norm.x;
}

void KK::Car::go_straight() {
  KK::Point vel_norm = normalize(vel);
  direction_acc.x += +module_acc * vel_norm.x;
  direction_acc.y += +module_acc * vel_norm.y;
}

KK::Point KK::Car::get_pos() { return pos; }

} // namespace KK
