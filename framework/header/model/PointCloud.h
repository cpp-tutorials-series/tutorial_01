/**
 * \class PointCloud
 * 
 * \brief Represents a model that contains a number of points. You can use it to add, remove or get points to the model
 * 
 * \author (Gil Engel)
 * 
 * \date 2018/06/24
 * 
 * Created on 2018/06/24
 */
#ifndef PointCloud_h
#define PointCloud_h

#include "Model.h"
#include <vector>

struct Point
{
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class PointCloud : public Model
{
    public:
        /// Default constructor
        PointCloud();

        /// Default deconstructor
        ~PointCloud();

        /**
         * Creates a new point with the coordinates provided by the parameters
         * and adds the point to the model
         * 
         * \param x The horizontal coordinate of the new point
         * \param y The vertical coordinate of the new point
         */
        void addPoint(int x, int y);

        /**
         * Removes the point of the model at the given index
         * 
         * \param index The index of the point that you want to remove
         */
        void removePoint(int index);

        /**
         * Returns a point of the model at the index specified by the parameter
         * 
         * \param index The index of the point you want to return
         */
        Point GetPoint(int index);

        /// Removes all saved points from the model
        void clear();

        /// Returns the begin iterator of the vector of saved points
        std::vector<Point>::const_iterator GetBegin() const;

        /// Returns the end iterator of the vector of saved points
        std::vector<Point>::const_iterator GetEnd() const;

        /// Returns all saved points within this model
        std::vector<Point> GetPoints() const;

    protected:
        std::vector<Point> _points;
};

#endif