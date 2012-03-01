#include "raycast.h"
#include <boost/foreach.hpp>

// Constructor for a group of n objects.
Group::Group(int n) {

    this->_object = new std::vector<Object3D*>(n);
    this->_count  = n;
}

// Destructor.
Group::~Group() {

    if (this->_object->empty()) {
        return;
    }

    for (int i = 0; i < this->_count; i++) {
        delete (*this->_object)[i];
    }

    delete[] this->_object;
}

// Insert an object into the array.
void Group::addObject(int index, Object3D *obj) 
{
    // Using vector means no need for _count, but will leave it
    if ((*this->_object)[index] != NULL)
        std::cerr << "already an element at this position!" << std::endl;

    (*this->_object)[index] = obj;
}

bool Group::intersect(const Ray &r, Hit &h)
{
    bool intersect = false;
    BOOST_FOREACH(Object3D* o, *this->_object)
    {
        intersect = intersect || o->intersect(r,h);
    }

    return intersect;
}
