#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
Hit a;
double inf = std::numeric_limits<double>::max();
//normalize X
//(p-e)dot n / u dot n
//p=x1
//e->endpt
//u->direction
double top = dot(x1 - ray.endpoint,normal);
double bot = dot(ray.direction,normal); 

//if there is an intersection
if(bot != 0.0)
{

double b= top/bot;
a.dist = b;
a.object = this;
a.part = part;
}

//if no intersection
else
{
a.dist = inf;
a.object = NULL;
a.part = part;
}


    return a;
}

vec3 Plane::Normal(const vec3& point, int part) const
{
    return normal;
}

// There is not a good answer for the bounding box of an infinite object.
// The safe thing to do is to return a box that contains everything.
Box Plane::Bounding_Box(int part) const
{
    Box b;
    b.hi.fill(std::numeric_limits<double>::max());
    b.lo=-b.hi;
    return b;
}
