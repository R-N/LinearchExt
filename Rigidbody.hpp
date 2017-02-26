#ifndef LINEARCHEXT_RIGIDBODY_HPP
#define LINEARCHEXT_RIGIDBODY_HPP
#include "Component.hpp"
#include "Vector2.hpp"
#include <list>
#include "GameObject.hpp"
#include "Collider.hpp"

namespace LinearchExt{

    class Rigidbody : public Component{
        public:
        bool isKinematic;
        Vector2 velocity;
        static std::list<Rigidbody> rigidbodies;
        Rigidbody(GameObject*);
        ~Rigidbody();
        Collider GetCollider();
        void PhysicsUpdate();
    };

}

#endif // RIGIDBODY_HPP




