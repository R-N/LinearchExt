#ifndef LINEARCHEXT_BEHAVIOUR_CPP
#define LINEARCHEXT_BEHAVIOUR_CPP
#include "Behaviour.hpp"

namespace LinearchExt{
    Behaviour::Behaviour(){
    }
    Behaviour::Behaviour(GameObject* gameObject){
        Component::Init(gameObject);
    }

    void Behaviour::Awake(){
    }
    void Behaviour::Start(){
    }
    void Behaviour::PreFixedUdpate(){
    }
    void Behaviour::FixedUpdate(){
    }
    void Behaviour::PostFixedUpdate(){
    }
    void Behaviour::PreCollisionUpdate(){
    }
    void Behaviour::PostCollisionUpdate(){
    }
    void Behaviour::PreUpdate(){
    }
    void Behaviour::Update(){
    }
    void Behaviour::PostUpdate(){
    }
    void Behaviour::PreRenderUpdate(){
    }
    void Behaviour::PostRenderUpdate(){
    }
}

#endif
