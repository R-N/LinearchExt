#ifndef LINEARCHEXT_COMPONENT_CPP
#define LINEARCHEXT_COMPONENT_CPP

#include "Misc.cpp"
#include "Transform.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#include "Collider.hpp"
#include "Renderer.hpp"
#include "Rigidbody.hpp"

namespace LinearchExt{

    void Component::OnCreate(){
    }

    void Component::OnDestroy(){
    }
    void OnDisable(){
    }
    void OnEnable(){
    }

    void Component::SetEnabled(bool enabled){
        this->enabled = enabled;
    }

    GameObject* Component::GetGameObject(){
        return gameObject;
    }
    Collider* Component::GetCollider(){
        return gameObject->collider;
    }
    Rigidbody* Component::GetRigidbody(){
        return gameObject->rigidbody;
    }
    Transform* Component::GetTransform(){
        return gameObject->transform;
    }
    Renderer* Component::GetRenderer(){
        return gameObject->renderer;
    }

    Component::Component(){}

    Component::~Component(){
        if(gameObject != 0)
            gameObject->components.remove(*this);
    }

    bool Component::IsActiveAndEnabled(){
        return enabled && gameObject->IsActiveInHierarchy();
    }

    void Component::Init(GameObject* gameObject){
        this->gameObject = gameObject;
    }

    template<typename T> bool IsComponent(){
        return TestDerivation<Component, T>();
    }
    bool operator==(const Component& a, const Component& b){
        return &a == &b;
    }
    bool operator!=(const Component& a, const Component& b){
        return &a != &b;
    }
    bool Component::operator==(const Component& b){
        return this == &b;
    }
    bool Component::operator!=(const Component& b){
        return this != &b;
    }
}
#endif
