#ifndef LINEARCHEXT_CAMERA_CPP
#define LINEARCHEXT_CAMERA_CPP

#include "Camera.hpp"

namespace LinearchExt{
    Camera::Camera(GameObject* gameObject){
        Component::Init(gameObject);
        if (Camera::main == 0)
            Camera::main = this;
    }
    void Camera::SetAsMain(){
        Camera::main = this;
    }
    Camera::~Camera(){
        if (Camera::main == this)
            Camera::main = 0;
    }
}

#endif // CAMERA_CPP


