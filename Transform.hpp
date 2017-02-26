#ifndef LINEARCHEXT_TRANSFORM_HPP
#define LINEARCHEXT_TRANSFORM_HPP
#include "Vector2.hpp"
#include "Component.hpp"
#include <vector>

namespace LinearchExt{
    class GameObject;
    enum Space{localSpace, worldSpace};
    class Transform : public Component{
    private:
        Transform* parent;
    public:
        Vector2 localPosition;
        double localRotation;
        Vector2 localScale;

        Transform();
        ~Transform();
        Transform(GameObject*);
        Transform* GetParent();
        void SetParent(Transform*);
        Vector2 WorldPosition();
        double WorldRotation();
        Vector2 WorldToLocalPoint(Vector2);
        Vector2 LocalToWorldPoint(Vector2);
        Vector2 WorldToLocalDirection(Vector2);
        Vector2 LocalToWorldDirection(Vector2);
        Vector2 WorldToLocalVector(Vector2);
        Vector2 LocalToWorldVector(Vector2);
        void RotateAround(double, Vector2, Space, bool);
        Transform* GetRoot();
        std::vector<Transform*> GetParentalVector();
        std::vector<Transform*> GetParentalVector(std::vector<Transform*>);
    };
}

#endif // TRANSFORM_HPP
