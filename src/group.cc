#include "raycast.h"

// Constructor for a group of n objects.
Group::Group(int n) {

  this->_object = new Object3D*[n];
  this->_count  = n;
}

// Destructor.
Group::~Group() {

  if (this->_object == NULL) {
    return;
  }

  for (int i = 0; i < this->_count; i++) {
    delete this->_object[i];
  }

  delete[] this->_object;
}

// Insert an object into the array.
void Group::addObject(int index, Object3D *obj) {

  // YOUR CODE HERE.
}

bool Group::intersect(const Ray &r, Hit &h)
{

  // YOUR CODE HERE.

}
