#ifndef KK_CAR
#define KK_CAR

#include "lin_alg.h"

namespace KK {
class Car {
  // car state
  Point pos;
  Point vel;

  // car acceleration
  Point direction_acc;
  float module_acc;

public:
  Car(float x0, float y0);
  void move(float t, float k);
  void accelerate();
  void rest();
  void turn_right();
  void turn_left();
  void go_straight();
  Point get_pos();
};

} // namespace KK

#endif
