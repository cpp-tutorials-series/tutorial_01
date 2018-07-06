#ifndef Point2_h
#define Point2_h

namespace Math
{
    template <typename T>
    /// Primitive data type with basic mathematical functions
    class Point2
    {

    public:
        
        // Default constructor
        Point2() {}

        /**
         * @brief Initialize the point with specific values
         * @param The value for x
         * @param The value for y
         */
        Point2(T x, T y)
        {
            _x = x;
            _y = y;
        }

        /**
         * @brief Checks if two points are equal (based on their position) or not
         * @param The other point to check for equallity
         * @return true if both points are equal, otherwise false
         */
        bool operator==(const Point2 &other) const
        {
            return _x == other.x() && _y == other.y();
        }

        /**
         * @brief Checks if two points are not equal (based on their position) or not
         * @param The other point to check for inequallity
         * @return true if points differs, otherwise false
         */
        bool operator!=(const Point2 &other) const
        {
            return !(*this == other);
        }

        /**
         * @brief Adds the values of the other point to the current and returns a new point
         * with the calculated values
         * @param Other point for addition
         * @return Result as Point2f
         */
        Point2 operator+(const Point2 &other) const
        {
            return Point2(_x + other.x(), _y + other.y());
        }

        /**
         * @brief Adds the values of the other point to the current
         * @param Other point for addition
         * @return Result reference to the point with new values
         */
        Point2 operator+=(const Point2 &other)
        {
            _x += other.x();
            _y += other.y();

            return *this;
        }

        /**
         * @brief Reduces the values of the other point to the current and returns a new point
         * with the calculated values
         * @param Other point for Subtraction
         * @return Result as Point2f
         */
        Point2 operator-(const Point2 &other) const
        {
            return Point2(_x - other.x(), _y - other.y());
        }

        /**
         * @brief Divides the point by a scalar
         * @param Scalar value for division
         * @return Result as Point2f
         */
        Point2 operator/(const T skalar) const
        {
            return Point2(_x / skalar, _y / skalar);
        }

        bool collinear(const Point2& p1, const Point2& p2) const
        {
            T a = _x * (p1.y() - p2.y()) +
                  p1.x() * (p2.y() - _y) +
                  p2.x() * (_y - p1.y());

            return a == 0;
        }
    
        T x() const
        {
            return _x;
        }

        void SetX(T x)
        {
            _x = x;
        }

        T y() const
        {
            return _y;
        }

        void SetY(T y)
        {
            _y = y;
        }

    protected:
        T _x;
        T _y;
    };


    typedef Point2<int> Point2i;
    typedef Point2<float> Point2f;
    typedef Point2<double> Point2d;
}

#endif
