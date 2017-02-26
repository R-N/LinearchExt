#ifndef LINEARCHEXT_TRANSFORM_CPP
#define LINEARCHEXT_TRANSFORM_CPP
#include "Vector2.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"
#include <vector>

namespace LinearchExt{

    Transform::Transform(GameObject* gameObject){
        gameObject->transform = this;
        Component::Init(gameObject);
    }
    Transform* Transform::GetParent(){
        return parent;
    }
    Transform* Transform::GetRoot(){
        if (parent==0)
            return this;
        return parent->GetRoot();
    }
    Transform::~Transform(){
        if(gameObject != 0 && gameObject->transform == this)
            gameObject->transform = 0;
    }
   std::vector<Transform*> Transform::GetParentalVector(std::vector<Transform*> vt){
        vt.push_back(this);

        if (parent==0){
            return vt;
        }else{
            return parent->GetParentalVector(vt);
        }

    }
    std::vector<Transform*> Transform::GetParentalVector(){
        std::vector<Transform*> vt;
        return GetParentalVector(vt);
    }

    Vector2 Transform::WorldToLocalPoint(Vector2 point){
        std::vector<Transform*> pv = GetParentalVector();
        for(std::vector<Transform*>::iterator it = pv.begin(); it != pv.end(); ++it){
            point -= (*it)->localPosition;
            point = Vector2::Rotate(point, (*it)->localRotation);
            point /= (*it)->localScale;
        }
        return point;
    }

    void Transform::RotateAround(double d, Vector2 point, Space relativeTo = worldSpace, bool keepRotation = true){

    }
}

#endif // TRANSFORM_CPP
