#include <model/PointCloud.h>

PointCloud::PointCloud() : Model()
{

}

PointCloud::~PointCloud()
{

}

void PointCloud::addPoint(int x, int y)
{
    _points.push_back(Point(x, y));
}

void PointCloud::removePoint(int index)
{
    //_points.erase(index);   
}

Point PointCloud::GetPoint(int index)
{
    return _points.at(index);
}

void PointCloud::clear()
{
    _points.clear();
}

std::vector<Point>::const_iterator PointCloud::GetBegin() const
{
    return _points.begin();
}

std::vector<Point>::const_iterator PointCloud::GetEnd() const
{
    return _points.end();
}

std::vector<Point> PointCloud::GetPoints() const
{
    return _points;
}