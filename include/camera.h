#pragma once
#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "frustum.h"
#include "quaternion.h"

namespace aline {

class Camera {
public:
    real aspectRatio;
    real focalDistance;
    Vec3r position;
    Vec3r rotation;
    real speedMove;
    real speedRotation;
    real speedZoom;
    Frustum fov;

    Vec3r moveAdd;
    Vec3r rotateAdd;

    Quaternion qRotation;

    bool moveTab[3];
    bool rotateTab[3];

    Camera(real aspectRatio, real focalDistance = 2, Vec3r position = {}, Vec3r rotation = {}, real speedMove = 0.5, real speedRotation = 0.5, real speedZoom = 0.0625);

    Mat44r transform() const;

    void move(int idAxis, const Vec3r &axis);
    void rotate(int idAxis, const Vec3r &axis);

    void stopMove(int axis);
    void stopRotate(int axis);

    void update();

    Object culling(const Object &object);

private:
    const Vec3r LOOK_IN = {0, 0, -1};

    Mat44r matrixRotationQuaternion() const;
    Mat44r matrixTranslation() const;

    void updateRotation();
    void updateTranslation();
    bool sees(const Vertex& v1, const Vertex& v2, const Vertex& v3);
};

}