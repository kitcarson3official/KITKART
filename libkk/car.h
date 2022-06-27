#ifndef KK_CAR
#define KK_CAR

#include "lin_alg.h"

namespace KK {
class Car {
  // car state
  Point pos;      // m
  Point vel;      // m/s
  float acc;      // m/s^2
  float steer;    // range : [-pi/2, pi/2]
  Point direction;

public:
  Car(Point pos, Point dir);
  void move(float t, float k);
  void accelerate();
  void decelerate();
  void rest();
  void turn_right();
  void turn_left();
  void go_straight();
  Point get_pos();
  Point get_acc();
  Point get_vel();
};

} // namespace KK

#endif
