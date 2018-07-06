#ifndef Circle_h
#define Circle_h

#include <vector>
#include "Vector2.h"

#define DOUBLE_PRECISION 0.01

using namespace Math;

//! Defines a data object that can store a circle
template <typename T>
class Circle : public Vector2<T>
{
public:
	//! Default constructor
	Circle()
	{

	}

	Circle(const Point2<T>& center, T radius)
	{
		this->_x = center.x();
		this->_y = center.y();

		this->_radius = radius;
	}

	//! Creates a new circle where all three points are at its boundary
	//! \param p1 The first point
	//! \param p2 The second point
	//! \param p3 The third point
	Circle(const Point2<T>& p1, const Point2<T>& p2, const Point2<T>& p3)
	{
		// Calculate the circle
		T x1 = p1.x();
		T y1 = p1.y();

		T x2 = p2.x();
		T y2 = p2.y();

		T x3 = p3.x();
		T y3 = p3.y();

		T A = x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - x3 * y2;


		T term1 = (pow(x1, 2.0) + pow(y1, 2.0));
		T term2 = (pow(x2, 2.0) + pow(y2, 2.0));
		T term3 = (pow(x3, 2.0) + pow(y3, 2.0));

		T B = term1 * (y3 - y2) + term2 * (y1 - y3) + (term3 * (y2 - y1));
		T C = term1 * (x2 - x3) + term2 * (x3 - x1) + (term3 * (x1 - x2));
		T D = term1 * (x3*y2 - x2 * y3) + term2 * (x1*y3 - x3 * y1) + (term3 * (x2*y1 - x1 * y2));

		// Calculate the radius
		_radius = sqrt((pow(B, 2.0) + pow(C, 2.0) - 4 * A * D) / (4 * pow(A, 2.0)));

		if(std::isnan(_radius)){
			_radius = 0;
		}

		// Set the coordinates
		this->_x = (-B) / (2*A);
		this->_y = (-C) / (2*A);		
	}



	//! Default deconstructor
	~Circle()
	{

	}

	bool static pointsAreCollinear(Point2<T> p1, Point2<T> p2, Point2<T> p3)
	{
		auto circle = Circle(p1, p2, p3);

		return isinf(circle->GetRadius());
	}

	//! Returns the radius of the circle
	T GetRadius() const
	{
		return _radius;
	}

	//! Sets the radius of the circle
	//! \param radius The new radius of the circle
	void SetRadius(T radius)
	{
		_radius = radius;
	}

	//! Returns the center of the circle
	Point2<T> GetCenter() const
	{
		return *this;
	}

	//! Determines if a point is contained within the circle or not
	//! \param point The point to check against
	bool containsPoint(const Point2<T>& point) const
	{
		return ((*this) - Vector2<T>(point)).length() <= (_radius + DOUBLE_PRECISION);
	}

	//! Determines for a set of points if they are contained within the circle
	//! \param points Set of points
	bool containsAllPoints(const std::vector<Point2<T>> points) const
	{
		for(auto&& point : points)
		{
			
			if (!containsPoint(point))
			{
				return false;
			}
		}

		return true;		
	}


private:
	T _radius;
};

typedef Circle<int> Circlei;
typedef Circle<float> Circlef;
typedef Circle<double> Circled;


#endif