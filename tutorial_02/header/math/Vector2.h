#ifndef Vector2_h
#define Vector2_h

#include <stdlib.h>
#include <cmath>

#include "Point2.h"


namespace Math
{

    /**
     * @brief Representation of a vector for two dimensions of type float.
     * Extends the Point2f by typical vector functions like cross-, dotproduct etc.
     */
    template <typename T>
    class Vector2 : public Point2<T>
    {
        public:
            //Vector2(const Point2<int> &other);
            
            Vector2(T x, T y)
            {
                this->_x = x;
                this->_y = y;
            }

            Vector2(const Point2<T>& point)
            {
                this->_x = point.x();
                this->_y = point.y();
            }

            Vector2()
            {

            }

            Vector2 operator - (const Vector2 &other) const
            {
                return Vector2(this->_x - other.x(), this->_y - other.y());
            }

            Vector2 operator + (const Vector2 &other) const
            {
                return Vector2(this->_x + other.x(), this->_y + other.y());
            }

            Vector2 operator / (const Vector2 &other)
            {
                return Vector2(this->_x / other.x(), this->_y / other.y());
            }

            Vector2& operator/=(const Vector2 &other)
            {
                this->_x /= other.x();
                this->_y /= other.y();

                return *this;
            }

            Vector2& operator*=(const T &scalar)
            {
                this->_x *= scalar;
                this->_y *= scalar;

                return *this;
            }

            Vector2& operator/=(const T scalar)
            {
                this->_x /= scalar;
                this->_y /= scalar;

                return *this;
            }

            Vector2 &operator+=(const T scalar)
            {
                this->_x += scalar;
                this->_y += scalar;

                return *this;
            }

            Point2<T> toPoint2() const
            {
                return Point2<T>(this->_x, this->_y);
            }

            /**
             * @brief Checks if two points are equal (based on their position) or not
             * @param The other point to check for equallity
             * @return true if both points are equal, otherwise false
             */
            bool operator==(const Vector2 &other)
            {
                return this->_x == other.x() && this->_y == other.y();
            }

            /**
             * @brief Checks if two points are not equal (based on their position) or not
             * @param The other point to check for inequallity
             * @return true if points differs, otherwise false
             */
            bool operator!=(const Vector2 &other)
            {
                return !(*this == other);
            }

            Vector2 operator * (const Vector2 &other)
            {
                return Vector2(this->_x * other.x(), this->_y * other.y());
            }

            /**
             * @brief Calculates the dot product of two vectors. The dot product returns a scalar
             * value which determines the angle between the two vectors.
             * @param Other Vector2 for calculation
             * @return The angle between the two vector. Returns 0 if both are equal
             */
            T dot (const Vector2 &other) const 
            {
                return this->_x * other.x() + this->_y * other.y();
            }

            void normalize()
            {
                T l = length();
                this->_x /= l;
                this->_y /= l;
            }

            /**
             * @brief creates a copy of the vector with normalized length
             * @return normalized vector
             */
            Vector2 normalized()
            {
                Vector2 v(this->_x, this->_y);
                T l = v.length();

                v.x /= l;
                v.y /= l;

                return v;
            }

            T cross(const Vector2 &other)
            {
                return (this->_x * other.y() - this->_y * other.x());
            }

            void operator=(const Vector2 &other)
            {
                this->_x = other.x();
                this->_y = other.y();
            }

            Vector2 operator*(const T &scalar)
            {
                return Vector2(this->_x * scalar, this->_y * scalar);
            }

            Vector2 operator/(const T &scalar)
            {
                return Vector2(this->_x / scalar, this->_y / scalar);
            }

            Vector2& operator *= (const Vector2 &other)
            {
                this->_x *= other.x;
                this->_y *= other.y;

                return *this;
            }

            Vector2& operator += (const Vector2 &other)
            {
                this->_x += other.x;
                this->_y += other.y;

                return *this;
            }

            Vector2& operator -= (const Vector2 &other){
                this->_x -= other.x;
                this->_y -= other.y;

                return *this;
            }

            /**
             * @brief Returns the length of the vector
             * @return scalar value that defines the length
             */
            T length( void )
            {
                return( (T)sqrt( this->_x * this->_x + this->_y * this->_y ) );
            }

            T horizontalDegree()
            {
                Vector2 x = normalized();
                Vector2 y(1, 0);

                T val = acos(x.dot(y));
                if(x.y > 0)
                    val = 2 * M_PI - val;
                return val;

            }
        };

    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;   
} 

#endif 
