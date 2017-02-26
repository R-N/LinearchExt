#ifndef LINEARCHEXT_COMPONENT_HPP
#define LINEARCHEXT_COMPONENT_HPP
#include <string>
#include <iostream>
namespace LinearchExt{
    class GameObject;
    class Transform;
    class Rigidbody;
    class Collider;
    class Renderer;
    class Component{
    private:
        bool enabled;
    public:
        GameObject* gameObject;
        bool IsActiveAndEnabled();
        Component();
        ~Component();
        virtual void Init(GameObject*);
         template<typename T> static bool IsComponent();
         virtual bool operator==(const Component&);
         virtual bool operator!=(const Component&);
        inline Transform* GetTransform();
        inline GameObject* GetGameObject();
        inline Rigidbody* GetRigidbody();
        inline Collider* GetCollider();
        inline Renderer* GetRenderer();
        virtual void SetEnabled(bool);
        virtual void OnCreate();
        virtual void OnDestroy();
        virtual void OnDisable();
        virtual void OnEnable();
    };
     bool operator==(const Component&, const Component&);
     bool operator!=(const Component&, const Component&);

}
#endif
