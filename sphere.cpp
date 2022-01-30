#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    TODO;
//x-xc.normsq - r2
Hit a;
double inf = std::numeric_limits<double>::max();
vec3 pt1 = 2.0*ray.direction;
double b = dot(pt1,(ray.endpoint - center));
double rest = dot(ray.endpoint - center, ray.endpoint - center) - pow(radius,2); 
double discriminant = pow(b,2) - 4*(rest);
//if b2 - 4ac = 0 -> 1 solution
if(discriminant == 0)
{
a.dist = -b/2;
a.object = this;
a.part = part;
}

else if(discriminant > 0)
{

a.dist = std::min((-b+pow(discriminant,0.5)/2),(-b-pow(discriminant,0.5)/2));
a.object = this;
a.part = part;
}

//else if b2-4ac > 0 -> 2 solution
//if b2-4ac < 0 -> no solution
else
{
a.dist = inf;
a.object = NULL;
a.part = part;
}



   return a;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;

    TODO; // compute the normal direction
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
