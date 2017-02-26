#ifndef LINEARCHEXT_COLLIDER_HPP
#define LINEARCHEXT_COLLIDER_HPP
#include "Component.hpp"
#include "GameObject.hpp"
#include "Vector2.hpp"
#include <list>
#include "Physics.hpp"
namespace LinearchExt{
    struct Intersection{
        public:
        Vector2 midPoint;
        double area;
        Vector2 normal;
    };

    class Collider : public Component {
    public:
        static std::list<Collider> colliders;
        void Init(GameObject*);
        Collider();
        ~Collider();
        Collider(GameObject*);
        bool isTrigger;
        virtual bool IsPointInCollider();
        virtual bool LineColliderIntersection(Vector2 from, Vector2 to, Intersection** out = 0);
        virtual bool CheckIntersection(Collider col, Intersection** out = 0);
        virtual bool Raycast(Ray ray, RaycastHit** out = 0);
    };
}
#endif // COLLIDER_HPP
