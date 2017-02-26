#ifndef LINEARCHEXT_RENDERER_HPP
#define LINEARCHEXT_RENDERER_HPP
#include "Component.hpp"
#include <list>
#include "GameObject.hpp"
namespace LinearchExt{

    class Renderer : public Component{
        public:
        static std::list<Renderer> renderers;
        void Init(GameObject*);
        Renderer();
        ~Renderer();
        Renderer(GameObject*);
        virtual void Draw();
    };

}

#endif // RENDERER_HPP


