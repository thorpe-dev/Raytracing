// Orthographic camera class.

// Add any code you need here and in the corresponding .cc file.

#ifndef ORTHOGRAPHIC_CAMERA_H_
#define ORTHOGRAPHIC_CAMERA_H_

#include "raycast.h"

class OrthographicCamera : public Camera{


public:

  // Constructor.
  OrthographicCamera(Vec3f centre, Vec3f direction, Vec3f up, float size);

  // Concrete implementation of pure virtual function in the
  // parent class.
  virtual Ray generateRay(Vec2f point);

private:
    Vec3f centre;
    Vec3f projection;
    Vec3f up;
    Vec3f horizontal;
    float size;
    Vec3f min;
    Vec3f max;
};

#endif /* ORTHOGRAPHIC_CAMERA_H_ */
