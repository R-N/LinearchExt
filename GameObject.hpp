#ifndef LINEARCHEXT_GAMEOBJECT_HPP
#define LINEARCHEXT_GAMEOBJECT_HPP
#include <list>
#include "Component.hpp"
#include <string>


namespace LinearchExt{
    class Transform;
    //class Component;
    class Rigidbody;
    class Collider;
    class GameObject{
    private:
        bool isActive;
    public:
        Transform* transform;
        Collider* collider;
        Rigidbody* rigidbody;
        Renderer* renderer;
        std::string name;
        static std::list<GameObject> gameObjects;
        std::list<Component> components;
        GameObject();
        ~GameObject();
        bool IsActiveInHierarchy();
        template <typename T>  T* GetComponent ();
        template <typename T>  T* AddComponent ();
        template <typename T>  bool RemoveComponent ();
        bool operator==(const GameObject&);
        bool operator!=(const GameObject&);
        inline Transform* GetTransform();
        inline Collider* GetCollider();
        inline Rigidbody* GetRigidbody();
        inline Renderer* GetRenderer();
        inline GameObject* GetGameObject();
        void SetActive(bool);
    };
    bool operator==(const GameObject&, const GameObject&);
    bool operator!=(const GameObject&, const GameObject&);

}

#endif // GAMEOBJECT_HPP
