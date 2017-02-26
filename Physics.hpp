#ifndef LINEARCHEXT_PHYSICS_HPP
#define LINEARCHEXT_PHYSICS_HPP
#include <cmath>
#include "Vector2.hpp"
namespace LinearchExt{
struct Ray{
    public:
    Vector2 startPoint;
    Vector2 direction;
    double length;
    static double step;
};
class Collider;
struct RaycastHit{
    public:
    Collider* collider;
    Vector2 point;
    Vector2 normal;
    double distance;
};

class Physics{
    public:
    static Vector2 gravity;
    static bool LineLineIntersection(Line2, Line2);
    static bool IsPointWithinLine(Line2, Vector2, double);
};
}
#endif // PHYSICS_HPP
