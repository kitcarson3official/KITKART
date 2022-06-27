#ifndef KK_TRACK
#define KK_TRACK

#include <vector>
#include "lin_alg.h"

namespace KK
{
    class Segment 
    {
        public:
            virtual KK::Point coord_from_d(float d);
            virtual float d_from_coord(KK::Point x);
    };

    class Line : public Segment 
    {
        KK::Point x0, xf;
    };

    class Curve : public Segment 
    {
        public:
            KK::Point x0, xf, center;
    };

    class Track 
    {
        std::vector<Segment> segments;

        public:
        /** TODO
         * @brief return the k parameter of the track at coord x
         * @param x coord
         * @return k
         */
        float get_k(const KK::Point x);
    };
}
#endif