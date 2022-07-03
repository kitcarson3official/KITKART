#ifndef KK_TRACK
#define KK_TRACK

#include "lin_alg.h"
#include <vector>

namespace KK {
struct Segment {

  enum SEGMENT_TYPE {
    LINE = 1,
    CURVE = 2,
  };

  // virtual ~Segment() = 0;
  virtual Point sector_from_world(Point w) = 0;
  virtual Point world_from_sector(Point s) = 0;
  virtual float getLength() const = 0;
};

class Line : public Segment {
  Point x0, xf;
  float angle;

public:
  Line(Point x0, Point xf);
  // virtual ~Line();
  virtual Point sector_from_world(Point w) override;
  virtual Point world_from_sector(Point s) override;
  virtual float getLength() const override;
};

class Curve : public Segment {
  Point x0, xf, center;
  float total_angle, current_angle, radius;

public:
  Curve(Point x0, Point xf, Point center);
  // virtual ~Curve();
  virtual Point sector_from_world(Point w) override;
  virtual Point world_from_sector(Point s) override;
  virtual float getLength() const override;
};

class Track {
  unsigned int current_segment = 0;
  std::vector<Segment*> segments;

public:
  /** TODO
   * @brief return the k parameter of the track at coord x
   * @param x coord
   * @return k
   */
  ~Track();
  float get_k(const KK::Point x);
  bool load_track(std::string filename);
  std::vector<Point> track_vertices(float max_curve_split = 1.f);
};
} // namespace KK
#endif
