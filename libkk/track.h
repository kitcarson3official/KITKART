#ifndef KK_TRACK
#define KK_TRACK

#include "lin_alg.h"
#include <vector>

namespace KK {
struct Segment {
  virtual ~Segment();
  virtual Point sector_from_world(Point w) = 0;
  virtual Point world_from_sector(Point s) = 0;
  virtual float getLength() const = 0;
};

class Line : public Segment {
  Point x0, xf;
  float m, angle;

public:
  Line(Point x0, Point xf);
  Point sector_from_world(Point w) override;
  Point world_from_sector(Point s) override;
  float getLength() const override;
};

class Curve : public Segment {
  Point x0, xf, center;
  float total_angle, current_angle, radius;

public:
  Curve(Point x0, Point xf, Point center);
  Point sector_from_world(Point w) override;
  Point world_from_sector(Point s) override;
  float getLength() const override;
};

class Track {
  unsigned int current_segment = 0;
  std::vector<Segment> segments;

public:
  /** TODO
   * @brief return the k parameter of the track at coord x
   * @param x coord
   * @return k
   */
  float get_k(const KK::Point x);
  bool load_track(std::string filename);
  std::vector<Point> track_vertices(float max_curve_split = 1.f);
};
} // namespace KK
#endif
