#ifndef LINEARCHEXT_BEHAVIOUR_HPP
#define LINEARCHEXT_BEHAVIOUR_HPP
#include "Component.hpp"
namespace LinearchExt{
    class Behaviour : public Component{
    public:
        Behaviour();
        Behaviour(GameObject*);
        ~Behaviour();
        virtual void Awake();
        virtual void Start();
        virtual void PreFixedUdpate();
        virtual void FixedUpdate();
        virtual void PostFixedUpdate();
        virtual void PreCollisionUpdate();
        virtual void PostCollisionUpdate();
        virtual void PreUpdate();
        virtual void Update();
        virtual void PostUpdate();
        virtual void PreRenderUpdate();
        virtual void PostRenderUpdate();
        /*
        virtual void OnCollisionEnter(Collision);
        virtual void OnCollisionStay(Collision);
        virtual void OnCollisionExit(Collision);
        virtual void OnTriggerEnter(Trigger);
        virtual void OnTriggerStay(Trigger);
        virtual void OnTriggerExit(Trigger);
        */
    };
}
#endif
