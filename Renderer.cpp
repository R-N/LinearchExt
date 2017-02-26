#ifndef LINEARCHEXT_RENDERER_CPP
#define LINEARCHEXT_RENDERER_CPP

#include "Renderer.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"

namespace LinearchExt{
    std::list<Renderer> renderers0;
    std::list<Renderer> Renderer::renderers = renderers0;

    void Renderer::Init(GameObject* gameObject){
        Component::Init(gameObject);
        gameObject->renderer = this;
    }
    Renderer::Renderer(){
        Renderer::renderers.push_back(*this);
    }
    Renderer::Renderer(GameObject* gameObject){
        Init(gameObject);
        Renderer::renderers.push_back(*this);
    }
    Renderer::~Renderer(){
        if(gameObject != 0 && gameObject->renderer == this)
            gameObject->renderer = 0;
    }
    void Renderer::Draw(){
    }
}

#endif // RENDERER_CPP

