#include "raycast.h"

// Add any code you need here and in the corresponding header
// file.


// Constructor with parameters.
OrthographicCamera::OrthographicCamera(Vec3f centre, Vec3f direction, Vec3f up, float size)
{
    direction.Normalize();
    up.Normalize();
    
    Vec3f left;
    
    up.Cross3(left, direction,up);
    up.Cross3(up,left,direction);
    
    up.Normalize();
    
    Vec3f horizontal;
    up.Cross3(horizontal,direction,up);
    horizontal.Normalize();
    
    Vec3f scale = (up + horizontal)*(size/2);
    
    this->min = centre - scale;
    this->max = centre + scale;
    this->centre = centre;
    this->projection = direction;
    this->up = up;
    this->horizontal=horizontal;
    this->size = size;
}


Ray OrthographicCamera::generateRay(Vec2f point)
{
    Vec3f upMod = this->up*point.x();
    Vec3f horMod = this->horizontal*point.y();
//     Ray val = new Ray(this->projection);   
}
