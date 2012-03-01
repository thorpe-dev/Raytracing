#include "raycast.h"

// Add any code you need here and in the corresponding header
// file.


Sphere::Sphere()
{
    
}



Sphere::Sphere(Vec3f centre, float radius, Vec3f color)
{
    this->_color = color;
    this->centre = centre;
    this->radius = radius;
}


bool Sphere::intersect(const Ray &r, Hit &h)
{
//     float A = r.getDirection().Dot3(r.getDirection());
//     float B = 2 * r.getDirection().Dot3(r.getOrigin());
//     float C = r.getOrigin().Dot3(r.getOrigin()) - radius * radius;
//     
//     float discriminant = B * B - 4 * A * C;
//     
//     // If the discriminant is less than zero, ray does not intersect sphere
//     if (discriminant < 0)
//         return false;
//     
//     float distsqrt = sqrt(discriminant);
//     float q;
//     if (B < 0)
//         q = (-B - distsqrt)/2.0f;
//     else
//         q = (-B + distsqrt)/2.0f;
//     
//     float t0 = q/A;
//     float t1 = C/q;
//     
//     // Make sure t0 > t1, swap if they're not
//     if (t0 > t1)
//     {
//         float temp = t0;
//         t0 = t1;
//         t1 = temp;
//     }
//     
//     // If t1 is less than zero, ray is heading away from the sphere, won't ever intersect
//     if (t1 < 0)
//         return false;

    Vec3f distance = this->centre - r.getOrigin();
    
    float distanceSqrd = distance.Dot3(distance);
    float radiusSqrd = this->radius * this->radius;
    
    if (distanceSqrd <= radiusSqrd)
    {
            h.set(0.0,this->_color);
            return true;
    }
    
    float dotProduct = distance.Dot3(r.getDirection());
    
    if (dotProduct < 0.0)
    {
        return false;
    }
    
    float t = distanceSqrd - (dotProduct * dotProduct);
    if (radiusSqrd < t)
    {
        return false;
    }
    
    float value = dotProduct - sqrt(radiusSqrd - t);
    
    if (value < h.getT())
    {
        h.set(value,this->_color);
    }
    
    return true;
}
