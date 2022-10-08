#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct vec3
{
    float x;
    float y;
    float z;
};

struct Intersection
{
    vec3 t1;
    vec3 t2;
    vec3 normal1;
    vec3 normal2;
    bool exist;
};

struct Ray
{
    vec3 origin;
    vec3 direction;
};

struct Plane
{
    vec3 point;
    vec3 norm;
};

struct Sphere
{
    float o;
    float r;
};

vec3 operator+(vec3 const v1, vec3 const v2)
{
    return
    {
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z,
    };
}

vec3 operator-(vec3 const v1, vec3 const v2)
{
    return
    {
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z,
    };
}

vec3 operator*(vec3 const v, float const f)
{
    return
    {
        v.x * f,
        v.y * f,
        v.z * f,
    };
}

float dot(vec3 const v1, vec3 const v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float length(vec3 v){
    return sqrt( v.x*v.x + v.y*v.y + v.z*v.z );
};

struct quadraticAns
{
    float x1;
    float x2;
    bool b;
};

quadraticAns quadratic(float a, float b, float c){
    float d = b*b - 4*a*c;
    if (d < 0){
        return{
            0,
            0,
            0,
        }
    }
    else{
        float x1 = ( -b + sqrt(d))/2/a;
        float x2 = ( -b - sqrt(d))/2/a;
        return{
            x1,
            x2,
            0,
        }
    }
};

vec3 rayPlaneIntersection(Ray const ray, Plane const plane)
{
    float const t = dot(plane.point - ray.origin, plane.norm)
                  / dot(           ray.direction, plane.norm);
    return ray.origin + ray.direction * t;
}

Intersection raySphereIntersection(Ray ray, Sphere sphere){
    float a = length(ray.direction);
    float b = 2*dot(ray.direction,ray.origin - sphere.o);
    float c = pow(dot(ray.origin - sphere.o),2) - sphere.r*sphere.r;
    quadraticAns t = quadratic(a,b,c);
    if (t.b == 0){
        return
        {
            0,
            0,
            0,
            0,
            0,
        };
    }
    else{
        return
        {
            ray.origin + ray.direction*t.x1;
            ray.origin + ray.direction*t.x2;
            ray.origin + ray.direction*t.x1 - sphere.o;
            ray.origin + ray.direction*t.x2 - sphere.o;
            1,
        };
    }
}



/*

struct Intersection
{
    vec3 t1;
    vec3 t2;
    vec3 normal1;
    vec3 normal2;
    bool exist;
};

*/