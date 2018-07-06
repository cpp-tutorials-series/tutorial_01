#ifndef MinimalEnclosingCircle_h
#define MinimalEnclosingCircle_h

#include <vector>
#include <math/Vector2.h>
#include <math/Circle.h>

#include <random>
#include <limits>

template <typename T>
const inline Circle<T> _calculateSmallestEnclosingCircle(std::vector<Point2<T>*> points, std::vector<Point2<T>*> r)
{
    // Store the size of two point vectors to reduce calculations
    int pSize = points.size();
    int rSize = r.size();

    // Holds the result
    Circle<T> d;

    // Calculate the circle if we processed all points or if we already know three border points
    if(pSize == 0 || rSize == 3)
    {
        // Calculate the circle using three border points
        if(rSize == 3)
        {
            d = Circle<T>(*r.at(0), *r.at(1), *r.at(2));
        }

        // Calculate the circle by determine the midpoint between two points
        else if(rSize == 2)
        {
            d = Circle<T>((*r.at(0) + *r.at(1)) / 2.0, Vector2<T>(*r.at(0) - *r.at(1)).length() / 2.0);
        }

        // Return a pseudocircle with radius = 0
        else if(rSize == 1)
        {
            d = Circle<T>(*r.at(0), 0);
        }
    }
    else
    {
        // Determine randomly & uniformly a number for the next point
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<int>  distr(0, pSize - 1);

        // Choose a random point of the point vector
        int index = distr(generator);
        auto p = points.at(index);

        // Erase the point of the list of points
        points.erase(points.begin() + index);

        // Calculate the circle recursivly 
        d = _calculateSmallestEnclosingCircle(points, r);

        // In case the current point is not inside or at the boundary of the 
        // currently calculated smallest circle add the point to the list of
        // boundary points because it must be a new boundary point and
        // calculate the smallest circle recursively
        if(!d.containsPoint(*p))
        {
            r.push_back(p);
            d = _calculateSmallestEnclosingCircle(points, r);
        }
    }

    return d;
}

template <typename T>
const inline Circle<T> calculateSmallestEnclosingCircle(std::vector<Point2<T>*> &points)
{
    std::vector<Point2<T>*> r;

    return _calculateSmallestEnclosingCircle(points, r);
}

#endif