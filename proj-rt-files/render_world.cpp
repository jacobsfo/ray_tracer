#include "render_world.h"
#include "flat_shader.h"
#include "object.h"
#include "light.h"
#include "ray.h"
#include <vector>
using namespace std;
extern bool disable_hierarchy;

Render_World::Render_World()
    :background_shader(0),ambient_intensity(0),enable_shadows(true),
    recursion_depth_limit(3)
{}

Render_World::~Render_World()
{
    delete background_shader;
    for(size_t i=0;i<objects.size();i++) delete objects[i];
    for(size_t i=0;i<lights.size();i++) delete lights[i];
}

// Find and return the Hit structure for the closest intersection.  Be careful
// to ensure that hit.dist>=small_t.
Hit Render_World::Closest_Intersection(const Ray& ray)
{
    double min_t;
   min_t = std::numeric_limits<double>::max();
    Hit a;
    a.dist = min_t; 
    a.part = 1;
    a.object = NULL;
  //  Hit b;
//    b = a.object->Intersection(ray,a.part);
//vector<Hit>c;
//if(b 
//
for(int i = 0; i < objects.size();i++)
{   
  //counter stores closest obj a->obj,dist
 // double b = a.dist; 
 // new
 Hit b;
b = objects[i]->Intersection(ray,1);

//new closest intersection put in hit obj
if( b.dist < a.dist  && b.dist > small_t)
   {
     a = b;
   }
}
 return a;
}

// set up the initial view ray and call
void Render_World::Render_Pixel(const ivec2& pixel_index)
{
    Ray ray;
    ray.endpoint = camera.position; 
   vec3 v = camera.World_Position(pixel_index);
//camera(ray endpt) - pixel -> normalize
//  v-e/||v-e||(normalized)
    ray.direction = (v-ray.endpoint).normalized();
    
   // ray(endpoint,direction);
    vec3 color=Cast_Ray(ray,1);
    camera.Set_Pixel(pixel_index,Pixel_Color(color));
}

void Render_World::Render()
{
    if(!disable_hierarchy)
        Initialize_Hierarchy();

    for(int j=0;j<camera.number_pixels[1];j++)
        for(int i=0;i<camera.number_pixels[0];i++)
            Render_Pixel(ivec2(i,j));
}

// cast ray and return the color of the closest intersected surface point,
// or the background color if there is no object intersection
vec3 Render_World::Cast_Ray(const Ray& ray,int recursion_depth)
{
    vec3 color;
    //vec3 y;
  //Shader h;
  //  Object o;
//    Flat_Shader p;
 //Hit b;
//Ray c;
   //if ray hits object
vec3 v = {0,0,0};
vec3 e = {0,0,0};
Hit closest_hit = Closest_Intersection(ray);
   if(closest_hit.object!=NULL)
     {//obj->shader
      color = closest_hit.object->material_shader->Shade_Surface(ray,ray.Point(closest_hit.dist),closest_hit.object->Normal(ray.Point(closest_hit.dist),1),1);  
     }
     
    //set color to intersection
 //   color = Closest_intersection(ray); 
    //else
    //set color to background color
   // color = p.Shade_Surface(ray,
     else
     {
     color = background_shader->Shade_Surface(ray,v,e,1);
     } 
   return color;
}

void Render_World::Initialize_Hierarchy()
{
    // each part of each object.
    //extra credit
    hierarchy.Reorder_Entries();
    hierarchy.Build_Tree();
}
