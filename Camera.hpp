#ifndef LINEARCHEXT_CAMERA_HPP
#define LINEARCHEXT_CAMERA_HPP
#include "Component.hpp"

namespace LinearchExt{

    class Camera : public Component{
    public:
        static Camera* main;
        Camera(GameObject*);
        ~Camera();
        void Render();
        void SetAsMain();
    };

}

#endif // CAMERA_HPP



