#ifndef LINEARCHEXT_BEHAVIOUR_CPP
#define LINEARCHEXT_BEHAVIOUR_CPP
#include "Behaviour.hpp"

namespace LinearchExt{
    Behaviour::Behaviour(){
    }
    Behaviour::Behaviour(GameObject* gameObject){
        Component::Init(gameObject);
    }

    void Awake(){
    }
    void Start(){
    }
    void PreFixedUdpate(){
    }
    void FixedUpdate(){
    }
    void PostFixedUpdate(){
    }
    void PreCollisionUpdate(){
    }
    void PostCollisionUpdate(){
    }
    void PreUpdate(){
    }
    void Update(){
    }
    void PostUpdate(){
    }
    void PreRenderUpdate(){
    }
    void PostRenderUpdate(){
    }
}

#endif
