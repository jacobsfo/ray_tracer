#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>
using namespace std;
// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
Hit a;
a.object = NULL;
a.dist = std::numeric_limits<double>::max();
a.part = 10;

double inf = std::numeric_limits<double>::max();

//(p-e)dot n / u dot n
//p=x1
//e->endpt
//u->direction

double top = dot((x1-ray.endpoint),normal);
double bot = dot((ray.direction),normal); 
if(bot == 0.0)
{

    a.dist = 0.0;
a.object = NULL;
a.part = part;

// if((abs(u) < 1.0) && (abs(normal) < 1.0))
// {
//     a.dist = ;
// a.object = this;
// a.part = part;
// }

//t ->b=0 when inside plane
}

//double u = -1.0*(ray.direction);

//= to 0, < than 0 , > than 0

//cout << "top:" << top << endl;
//cout << "bot" << bot << endl;
//cout << "b:" << b << endl;

//if there is an intersection

//if no intersection
//b<0


else 
{
double b=top/bot;
    if(b < small_t)
    {
    a.dist = 0.0;
    a.object = NULL;
    a.part = part; 
    }
    else
    {
        // if(top == 0.0)
        // {
        //     a.dist = 0.0;
        // }
    a.dist = b;
    a.object = this;
    a.part = part;
    }


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
