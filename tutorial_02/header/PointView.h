#ifndef PointView_h
#define PointView_h

#include <math/Point2.h>
#include "ModelView.h"

using namespace Math;

template <typename T>
class PointView : public Point2<T>, public ModelView
{
    public:
        PointView(Point2<T> position, Color4 backgroundColor) : Point2<T>(position.x(), position.y())
        {
             _backgroundColor = backgroundColor;
        }
};

#endif