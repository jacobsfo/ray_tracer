#include "sphere.h"
#include "ray.h"
using namespace std;
// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
//x-xc.normsq - r2
Hit a;
a.dist = 1.0;
a.object = NULL;
a.part = 1;

double inf = std::numeric_limits<double>::max();
vec3 pt1 = ray.direction;
double rest1 = dot(pt1,pt1);
double b = 2 * dot(pt1,(ray.endpoint - center));
double rest = dot(ray.endpoint - center, ray.endpoint - center) - pow(radius,2); 
double discriminant = pow(b,2) - 4*rest1*(rest);
//if b2 - 4ac = 0 -> 1 solution
//std::cout<< b << std::endl;
//std::cout << pow(b,2) << std::endl;
// cout << pow(b,2) << endl;
// cout << 4*rest1*(rest) << endl;
//<0, >small , <small

if((discriminant >= 0.0 ) && (discriminant <= small_t))
{
a.dist = -b/2*rest1;
a.object = this;
a.part = part;
}

else if(discriminant > small_t)
{
double x = (-b/2+pow(discriminant,0.5)/2*rest1);
double y = (-b/2-pow(discriminant,0.5)/2*rest1);
//a.dist = std::min(x,y);
//if one is negative, ret pos
if(x <= small_t && y > small_t)
{
    a.dist = y;
    a.object = this;

}
if(y <= small_t && x>small_t)
{
    a.dist = x;
    a.object = this;

}
//if both are pos,ret smaller one
if(x>small_t && y>small_t)
{
    a.dist = std::min(x,y);
    a.object = this;
}

//if both neg->no intersection
if(x<=small_t && y<=small_t)
{
    a.dist = inf;
    a.object = NULL;
}



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
    normal = (point - center).normalized();

    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    
    return box;
}
