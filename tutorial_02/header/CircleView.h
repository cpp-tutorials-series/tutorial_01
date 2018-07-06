#ifndef CircleView_h
#define CircleView_h

#include "ModelView.h"
#include <math/Circle.h>

template <typename T>
class CircleView : public Circle<T>, public ModelView
{
    public:
        CircleView(const Point2<T>& p1, const Point2<T>& p2, const Point2<T>& p3, Color4 backgroundColor) : Circle<T>(p1, p2, p3)
        {
            _borderColor.red = 0;
            _borderColor.green = 0;
            _borderColor.blue = 0;

            _borderSize = 0;
            _backgroundColor = backgroundColor;
        }

        CircleView(const Circle<T> circle, Color4 backgroundColor) : Circle<T>(circle.GetCenter(), circle.GetRadius())
        {
            _borderColor.red = 0;
            _borderColor.green = 0;
            _borderColor.blue = 0;

            _borderSize = 0;
            _backgroundColor = backgroundColor;
        }

};

#endif