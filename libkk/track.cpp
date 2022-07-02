#include "track.h"
#include "assert.h"

namespace KK {

Line::Line(Point x0, Point xf) {
  this->x0 = x0;
  this->xf = xf;
  m = (xf.y - x0.y) / (xf.x - x0.x);
  angle = atan(m); // Check for angles greater than π/2
}

Point Line::sector_from_world(Point w) {
  return {(w - x0) * Point({cos(angle), sin(angle)}),
          (w - x0) * Point({-sin(angle), cos(angle)})};
}

Point Line::world_from_sector(Point s) {
  return {x0.x + s * Point({cos(angle), -sin(angle)}),
          x0.y + s * Point({sin(angle), cos(angle)})};
}

float Line::getLength() const { return module(xf - x0); }

Curve::Curve(Point x0, Point xf, Point center) {
  this->x0 = x0;
  this->xf = xf;
  this->center = center;
  assert(module(center - x0) == module(center - xf));

  radius = module(center - x0);
  assert(radius != 0.f);
  total_angle = acos(x0 * xf / (radius * radius));
  assert(total_angle != 0.f);
  current_angle = 0.f;
}

/* TODO check the angle sign */
Point Curve::sector_from_world(Point w) {
  current_angle = acos((x0 - center) * (w - center) /
                       (module(x0 - center) * module(w - center)));
  return {current_angle * radius, radius - module(w - center)};
}

Point Curve::world_from_sector(Point s) {
  float angle = s.x / radius - atan(x0.y / x0.x);
  return center + (radius + s.y) * Point({-cos(angle), sin(angle)});
}

std::vector<Point> Track::track_vertices(float max_curve_split) {
  std::vector<Point> vertices;
  for (Segment &s : segments) {
    if (dynamic_cast<Line *>(&s)) {
      vertices.push_back(s.world_from_sector({0.f, 0.f}));
      vertices.push_back(s.world_from_sector({s.getLength(), 0.f}));
    } else if (dynamic_cast<Curve *>(&s)) {
      vertices.push_back(s.world_from_sector({0.f, 0.f}));
      for (unsigned int i = 0; i < (s.getLength() / max_curve_split); i++)
        vertices.push_back(s.world_from_sector({max_curve_split * i, 0.f}));
      vertices.push_back(s.world_from_sector({s.getLength(), 0.f}));
    }
  }
  return vertices;
}

bool Track::load_track(std::string filename) { return true; }

} // namespace KK
