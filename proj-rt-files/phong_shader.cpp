#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"
using namespace std;
vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    //if
  //  Hit closest_hit = world.Closest_Intersection(ray);
     vec3 color;
     vec3 ambient = world.ambient_color * world.ambient_intensity * color_ambient;
     Ray shadow;
     for(int i = 0; i < world.lights.size();i++)
    {
        shadow.direction= (world.lights[i]->position - intersection_point).normalized();
        shadow.endpoint= intersection_point;
        
        //double diffnum = dot(normal,(world.lights[0]->position-ray.Point(closest_hit.dist)));

        // double diffnum = dot(normal,(world.lights[0]->position));
    //  double L_d = diffnum/dot(normal.normalized(),(world.lights[0]->position-ray.Point(closest_hit.dist)).normalized());
        // double diffpower = diffnum/dot(normal.normalized(),world.lights[0].position-ray.Point(world.Cast_Ray(ray,1)).normalized());
        double L_d =  max(dot(normal.normalized(),(world.lights[i]->position-intersection_point).normalized()),0.0);
        vec3 R_d = world.lights[i]->Emitted_Light((world.lights[i]->position-intersection_point));
        vec3 diffuse = L_d * R_d * color_diffuse;



        //double l=
        vec3 r = (2.0*dot(((world.lights[i]->position-intersection_point).normalized()),normal)*normal - (world.lights[i]->position-intersection_point).normalized());
        double L_1 = max(dot(r,-ray.direction),0.0);
        double L_s = pow(L_1,specular_power);
        vec3 R_s = world.lights[i]->Emitted_Light((world.lights[i]->position-intersection_point));
        vec3 specular = L_s * R_s * color_specular;

        if(world.enable_shadows == true)
        {
            Hit check = world.Closest_Intersection(shadow);
           // Hit light = world.Closest_Intersection(world.lights[i]);
           //light 
                vec3 hitpt = shadow.Point(check.dist); //ray intersects obj

                vec3 dist = hitpt - intersection_point;   //t 

            if(check.object == NULL)
            {
                //check if obj behind light source or not
                //world.lights[i]->position-intersection_point ->dl
                //object to intersection pt
                color+=diffuse + specular;
                //hitpt + dist = ray
            }
            else if((dist.magnitude() > small_t) && (dist.magnitude() > (world.lights[i]->position-intersection_point).magnitude()))
            {
                   color+=diffuse + specular;
                //hitpt + dist = ray
                    
            }
            // else
            //  {
               
            //         color += diffuse + specular;
            //  }
        }

        else 
        {
            color+=diffuse + specular;
        }

    }
    TODO; //determine the color
    
    color+=ambient;

    //else
    return color;
}
