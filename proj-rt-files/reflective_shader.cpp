#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"
using namespace std;
vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
   // world.recursion_depth_limit;
    //cout << "wlimit"<<world.recursion_depth_limit<< endl;
    //recursion_depth--;
    
    //Color 
    vec3 color = shader->Shade_Surface(ray,intersection_point,normal,recursion_depth);
    int depth = 0;

    //Compute Reflected Vector
    Ray reflected;
    reflected.endpoint = intersection_point;
    reflected.direction = (-2 * dot(normal,ray.direction.normalized())*normal + ray.direction.normalized()).normalized();
    //cout << "rd:" << recursion_depth << endl;


   if(recursion_depth <= 1)
   {
        color = (1-reflectivity)*color;
        //cout << "rda:" << recursion_depth << endl;

   }
   else{   
        recursion_depth--;
        color = (1-reflectivity)*color + reflectivity*world.Cast_Ray(reflected,recursion_depth);
        
      //  world.recursion_depth_limit--;
        //cout << "rdb:" << world.recursion_depth_limit << endl;


   }
  
 

    TODO; // determine the color
    return color;
}
