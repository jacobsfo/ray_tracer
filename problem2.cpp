#include<iostream>
#include "vec.h"
using namespace std;
int main(){
vec3 * u = new vec3(2.0,3.0,5.0);
vec3 * v = new vec3(1.0,0.0,0.0);
//vec3 w = (*u / 5.0) + ((*v*3)/1.0);
//cout << w;

//vec3 w = new vec3();
//cout << cross <double> ((*u*3), *v);
//cout << u->normalized(); 
vec3 w = (u->magnitude() + 1) * (*v); 
//cout << w;
double a;
a = dot<double> ( (*u/4), *v);
//cout << a;

a = u[0][0];
cout << a;
}
