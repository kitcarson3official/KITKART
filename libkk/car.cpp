#include "car.h"

namespace KK {
Car::Car(float x0, float y0) {
  pos.x = x0;
  pos.y = y0;

  vel.x = 0.0f;
  vel.x = 0.0f;

  direction_acc = {1.f, 0.f};
  module_acc = 0.0f;
}

void KK::Car::move(float t, float k) {
  Point acc = {module_acc * direction_acc.x, module_acc * direction_acc.y};
  vel.x += (acc.x - k * vel.x) * t;
  vel.y += (acc.y - k * vel.y) * t;
  pos.x += vel.x * t;
  pos.y += vel.y * t;
}

void KK::Car::accelerate() { module_acc = 100.f; }

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
