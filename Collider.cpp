#ifndef LINEARCHEXT_COLLIDER_CPP
#define LINEARCHEXT_COLLIDER_CPP

#include "Collider.hpp"

namespace LinearchExt{

    std::list<Collider> colliders0;
    std::list<Collider> Collider::colliders = colliders0;


    void Collider::Init(GameObject* gameObject){
        Component::Init(gameObject);
        gameObject->collider = this;
    }

    Collider::Collider(){
        Collider::colliders.push_back(*this);
    }


    Collider::Collider(GameObject* gameObject){
        Init(gameObject);
        Collider::colliders.push_back(*this);
    }

    Collider::~Collider(){
        if(gameObject != 0 && gameObject->collider == this)
            gameObject->collider = 0;
    }

    bool IsPointInCollider(){
        return false;
    }
    bool LineColliderIntersection(Vector2 from, Vector2 to, Intersection** out = 0){
        return false;
    }
    bool CheckIntersection(Collider col, Intersection** out = 0){
        return false;
    }
    bool Raycast(Ray ray, RaycastHit** out = 0){
        return false;
    }
}

#endif // COLLIDER_CPP
