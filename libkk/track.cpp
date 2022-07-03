#include "track.h"
#include "assert.h"
#include <exception>
#include <fstream>
#include <iostream>

using std::cout, std::endl;

namespace KK {

Line::Line(Point x0, Point xf) {
  this->x0 = x0;
  this->xf = xf;
  float dx = xf.x - x0.x;
  float dy = xf.y - x0.y;
  if (dx == 0.f)
    angle = dy > 0 ? M_PI_2 : 3 * M_PI_2;
  else {
    if (dx > 0) {
      angle = atan(dy / dx);
    } else {
      angle = atan(dy / dx) + M_PI;
    }
  }
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
  total_angle = acos((x0 - center) * (xf - center) / (radius * radius));
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

float Curve::getLength() const { return radius * total_angle; }

Track::~Track() {}

std::vector<Point> Track::track_vertices(float max_curve_split) {
  std::vector<Point> vertices;
  for (Segment *seg : segments) {
    Segment &s = *seg;
    if (dynamic_cast<Line *>(&s)) {
      vertices.push_back(s.world_from_sector({0.f, 0.f}));
      vertices.push_back(s.world_from_sector({s.getLength(), 0.f}));
    } else if (dynamic_cast<Curve *>(&s)) {
      for (unsigned int i = 0; i < (s.getLength() / max_curve_split); i++) {
        vertices.push_back(s.world_from_sector({max_curve_split * i, 0.f}));
      }
      vertices.push_back(s.world_from_sector({s.getLength(), 0.f}));
    }
  }
  return vertices;
}

bool Track::load_track(std::string filename) {
  std::ifstream f(filename);
  if (f.is_open()) {
    try {
      unsigned int n_segments;
      f >> n_segments;
      segments.reserve(n_segments);

      for (unsigned int i = 0; i < n_segments; i++) {
        unsigned int type;
        float x0x, x0y, xfx, xfy;
        f >> type;
        switch (type) {
        case Segment::SEGMENT_TYPE::LINE: {
          f >> x0x >> x0y >> xfx >> xfy;
          cout << "Line {" << x0x << ", " << x0y << "} {" << xfx << ", " << xfy
               << "}" << endl;
          segments.push_back(new Line({x0x, x0y}, {xfx, xfy}));
        } break;
        case Segment::SEGMENT_TYPE::CURVE: {
          float xcx, xcy;
          f >> x0x >> x0y >> xfx >> xfy >> xcx >> xcy;
          cout << "Curve {" << x0x << ", " << x0y << "} {" << xfx << ", " << xfy
               << "} {" << xcx << ", " << xcy << "}" << endl;
          segments.push_back(new Curve({x0x, x0y}, {xfx, xfy}, {xcx, xcy}));
        } break;
        default:
          return false;
        }
      }

    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  } else
    return false;

  return true;
}
} // namespace KK
