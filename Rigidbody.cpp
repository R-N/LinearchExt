#ifndef LINEARCHEXT_RIGIDBODY_CPP
#define LINEARCHEXT_RIGIDBODY_CPP

#include "Rigidbody.hpp"

namespace LinearchExt{
    std::list<Rigidbody> rigidbodies0;
    std::list<Rigidbody> Rigidbody::rigidbodies = rigidbodies0;

    Rigidbody::Rigidbody(GameObject* gameObject){
        Component::Init(gameObject);
        Rigidbody::rigidbodies.push_back(*this);
        gameObject->rigidbody = this;
    }
    Rigidbody::~Rigidbody(){
        if(gameObject != 0 && gameObject->rigidbody == this)
            gameObject->rigidbody = 0;
    }

    void Rigidbody::PhysicsUpdate(){
    }
}

#endif // RIGIDBODY_CPP



