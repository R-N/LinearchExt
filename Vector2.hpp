
#ifndef LINEARCHEXT_VECTOR2_HPP
#define LINEARCHEXT_VECTOR2_HPP

#include<cmath>
#include<iostream>


namespace LinearchExt{

    struct Vector2{
    public:
        double x;
        double y;

        Vector2();

        Vector2(double, double);

        static Vector2 zero;
        static Vector2 up;
        static Vector2 down;
        static Vector2 left;
        static Vector2 right;

        double Magnitude();

        Vector2 Normalized();
        void Normalize();

        bool IsZero();

        Vector2 operator/=(Vector2);
        Vector2 operator-=(Vector2);
        Vector2 operator*=(Vector2);
        Vector2 operator+=(Vector2);
        Vector2 operator*=(double);
        Vector2 operator/=(double);
        Vector2 operator*=(float);
        Vector2 operator/=(float);
        Vector2 operator*=(int);
        Vector2 operator/=(int);

        static double Distance(Vector2, Vector2);
        static double Dot(Vector2, Vector2);
        static double Cross(Vector2, Vector2);
        static Vector2 ClampMagnitude(Vector2, double);
        static Vector2 Rotate(Vector2, double);
        static Vector2 Rotate(Vector2, double, Vector2);
        static Vector2 Lerp(Vector2, Vector2, double);
        static Vector2 MoveTowards(Vector2, Vector2, double);
        static Vector2 Project(Vector2, Vector2);
        static Vector2 Reject(Vector2, Vector2);
        static Vector2 Reflect(Vector2, Vector2);

    };
    std::ostream& operator << (std::ostream&,const Vector2&);

    Vector2 operator*(const double&, const Vector2&);
    Vector2 operator*(const Vector2&, const double&);
    Vector2 operator/(const double&, const Vector2&);
    Vector2 operator/(const Vector2&, const double&);
    Vector2 operator*(const float&, const Vector2&);
    Vector2 operator*(const Vector2&, const float&);
    Vector2 operator/(const float&, const Vector2&);
    Vector2 operator/(const Vector2&, const float&);
    Vector2 operator*(const int&, const Vector2&);
    Vector2 operator*(const Vector2&, const int&);
    Vector2 operator/(const int&, const Vector2&);
    Vector2 operator/(const Vector2&, const int&);
    Vector2 operator+(const Vector2&, const Vector2&);
    Vector2 operator-(const Vector2&, const Vector2&);
    Vector2 operator*(const Vector2&, const Vector2&);
    Vector2 operator/(const Vector2&, const Vector2&);
    bool operator==(const Vector2&, const Vector2&);
    bool operator!=(const Vector2&, const Vector2&);

    struct Line2{
        public:
        Vector2 from;
        Vector2 to;
    };
}

#endif // VECTOR2_HPP
