// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the result
#ifndef LINEARCHEXT_VECTOR2_CPP
#define LINEARCHEXT_VECTOR2_CPP

#include <cmath>
#include "Vector2.hpp"
#include "Misc.hpp"

namespace LinearchExt{



    Vector2::Vector2(){};

    Vector2::Vector2(double x, double y){
        this->x = x;
        this->y = y;
    }

    Vector2 Vector2::zero = Vector2(0,0);
    Vector2 Vector2::up = Vector2(0,1);
    Vector2 Vector2::down = Vector2(0,-1);
    Vector2 Vector2::left = Vector2(-1,0);
    Vector2 Vector2::right = Vector2(1,0);

    double Vector2::Magnitude(){
        return sqrt(x*x + y*y);
    }

    Vector2 Vector2::Normalized(){
        double mag = Magnitude();
        if(mag == 0)
            return *this;
        return Vector2(x/mag, y/mag);
    }

    void Vector2::Normalize(){
        double mag = Magnitude();
        if(mag == 0)
            return;
        x /= mag;
        y /= mag;
    }


     double Vector2::Distance(Vector2 a, Vector2 b){
        return (b-a).Magnitude();
    }
     double Vector2::Dot(Vector2 a, Vector2 b){
        return a.x * b.x + a.y * b.y;
    }
     double Vector2::Cross(Vector2 a, Vector2 b){
        return a.x * b.y - a.y * b.x;
    }
     Vector2 Vector2::ClampMagnitude(Vector2 v, double m){
        if (v.IsZero())
            return v;
        double mag = v.Magnitude();
        return v / mag * Min(mag, m);
    }
     Vector2 Vector2::Rotate(Vector2 v, double rad){
        double sina = sin(rad);
        double cosa = cos(rad);
        return Vector2(v.x * cosa - v.y * sina, v.x * sina + v.y * cosa);
    }
     Vector2 Vector2::Rotate(Vector2 v0, double rad, Vector2 pivot){
        Vector2 v = v0 - pivot;
        double sina = sin(rad);
        double cosa = cos(rad);
        return Vector2(v.x * cosa - v.y * sina, v.x * sina + v.y * cosa) + pivot;
    }
     Vector2 Vector2::Lerp(Vector2 a, Vector2 b, double t){
        return a + (b-a) * t;
    }
     Vector2 Vector2::MoveTowards(Vector2 a, Vector2 b, double maxDelta){
        return a + ClampMagnitude(b-a, maxDelta);
    }
    bool Vector2::IsZero (){
        return x==0 && y==0;
    }
     Vector2 Vector2::Project(Vector2 v, Vector2 to){
        if (v.IsZero())
            return v;
        if (to.IsZero())
            return to;
        double mag = to.Magnitude();
        return Dot(v,to) * to / (mag * mag);
    }

    Vector2 Vector2::Reject(Vector2 v, Vector2 to){
        return v - Project(v, to);
    }
    Vector2 Vector2::Reflect(Vector2 v, Vector2 onNormal){
        return v - 2 * Project(v, onNormal);
    }

    Vector2 operator*(const double& d, const Vector2& v){
        return Vector2(v.x * d, v.y * d);
    }
    Vector2 operator*(const Vector2& v, const double& d){
        return Vector2(v.x * d, v.y * d);
    }
    Vector2 operator/(const double& d, const Vector2& v){
        return Vector2(d/v.x, d/v.y);
    }
    Vector2 operator/(const Vector2& v, const double& d){
        return Vector2(v.x / d, v.y / d);
    }
    Vector2 operator*(const int& d, const Vector2& v){
        return Vector2(v.x * d, v.y * d);
    }
    Vector2 operator*(const Vector2& v, const int& d){
        return Vector2(v.x * d, v.y * d);
    }
    Vector2 operator/(const int& d, const Vector2& v){
        return Vector2(d/v.x, d/v.y);
    }
    Vector2 operator/(const Vector2& v, const int& d){
        return Vector2(v.x / d, v.y / d);
    }
    Vector2 operator*(const float& d, const Vector2& v){
        return Vector2(v.x * d, v.y * d);
    }
    Vector2 operator*(const Vector2& v, const float& d){
        return Vector2(v.x * d, v.y * d);
    }
    Vector2 operator/(const float& d, const Vector2& v){
        return Vector2(d/v.x, d/v.y);
    }
    Vector2 operator/(const Vector2& v, const float& d){
        return Vector2(v.x / d, v.y / d);
    }
    Vector2 operator+(const Vector2& a, const Vector2& b){
        return Vector2(a.x + b.x, a.y + b.y);
    }
    Vector2 operator-(const Vector2& a, const Vector2& b){
        return Vector2(a.x - b.x, a.y - b.y);
    }
    Vector2 operator*(const Vector2& a, const Vector2& b){
        return Vector2(a.x * b.x, a.y * b.y);
    }
    Vector2 operator/(const Vector2& a, const Vector2& b){
        return Vector2(a.x / b.x, a.y / b.y);
    }
    bool operator==(const Vector2& a, const Vector2& b){
        return a.x == b.x && a.y == b.y;
    }
    bool operator!=(const Vector2& a, const Vector2& b){
        return a.x != b.x || a.y != b.y;
    }

    Vector2 Vector2::operator+=(Vector2 b){
        return Vector2(x+b.x, y+b.y);
    }
    Vector2 Vector2::operator-=(Vector2 b){
        return Vector2(x-b.x, y-b.y);
    }
    Vector2 Vector2::operator*=(Vector2 b){
        return Vector2(x*b.x, y*b.y);
    }
    Vector2 Vector2::operator/=(Vector2 b){
        return Vector2(x/b.x, y/b.y);
    }

    std::ostream& operator << (std::ostream &o,const Vector2 &v){
        return o << "(" << v.x << ", " << v.y << ")";
    }
}

#endif // VECTOR2_CPP
