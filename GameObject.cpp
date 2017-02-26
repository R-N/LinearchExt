#ifndef LINEARCHEXT_GAMEOBJECT_CPP
#define LINEARCHEXT_GAMEOBJECT_CPP

#include<list>
#include "GameObject.hpp"
#include "Transform.hpp"
#include <typeinfo>
#include <stdexcept>
#include <string>
#include "Component.hpp"
#include "Collider.hpp"
#include "Rigidbody.hpp"
#include "Renderer.hpp"


namespace LinearchExt{
    std::list<GameObject> gameObjects0;
    std::list<GameObject> GameObject::gameObjects = gameObjects0;

    void GameObject::SetActive(bool active){
        isActive = active;
    }

    Collider* GameObject::GetCollider(){
        return collider;
    }
    Rigidbody* GameObject::GetRigidbody(){
        return rigidbody;
    }
    Transform* GameObject::GetTransform(){
        return transform;
    }
    Renderer* GameObject::GetRenderer(){
        return renderer;
    }
    GameObject* GameObject::GetGameObject(){
        return this;
    }

    GameObject::GameObject(){
        GameObject::gameObjects.push_back(*this);
        Transform(this);
    }
    GameObject::~GameObject(){
        GameObject::gameObjects.remove(*this);
    }
    bool GameObject::IsActiveInHierarchy(){
        return isActive;
    }

    bool GameObject::operator==(const GameObject& b){
        return this==&b;
    }
    bool GameObject::operator!=(const GameObject& b){
        return this!=&b;
    }
    bool operator==(const GameObject& a, const GameObject& b){
        return &a == &b;
    }
    bool operator!=(const GameObject& a, const GameObject& b){
        return &a != &b;
    }
    template <typename T> T* GameObject::GetComponent(){
        std::type_info id = typeid(T);
        for (std::list<Component>::iterator it = components.begin(); it != components.end(); ++it){
            if(typeid(*it) == id){
                return &(*it);
            }
        }
        return 0;
    }
    template <typename T> T* GameObject::AddComponent(){
        if (!Component::IsComponent<T>()){
            throw std::runtime_error((std::string)typeid(T).name() + (std::string)" is not a LinearchExt component.");
            return 0;
        }

        std::type_info id = typeid(T);
        for (std::list<Component>::iterator it = components.begin(); it != components.end(); ++it){
            if(typeid(*it) == id){
                throw std::runtime_error("GameObject " + name + " already has component of type " + (std::string)typeid(T).name() + ".");
                return &(*it);
            }
        }
        T t(this);
        components.push_back(t);
        return &t;
    }
    template <typename T> bool GameObject::RemoveComponent(){
        std::type_info id = typeid(T);
        for (std::list<Component>::iterator it = components.begin(); it != components.end(); ++it){

            if(typeid(*it) == id){
                components.remove(*it);
                return 1;
            }
        }
        return 0;
    }

}

#endif
