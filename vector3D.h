#include <stdio.h>
#include <math.h>

#define VECTOR3D

struct vector3D
{
    long double x,y,z;
}; 

void get_vector(struct vector3D *v)
{
    printf("Imput the x component of the vector\n");
    scanf("%Lf",&v->x);
    printf("Imput the y component of the vector\n");
    scanf("%Lf",&v->y);
    printf("Imput the z component of the vector\n");
    scanf("%Lf",&v->z);
}

void print_vector(struct vector3D v)
{
    printf("(%Lf,\t%Lf,\t%Lf)\n",v.x,v.y,v.z);
}

/*const char *to_string(struct vector3D v)
{
    return "("+v.x+",\t"+v.y+",\t"+v.z+")"; //problemas al pasar un double a char *
}*/

struct vector3D suma(struct vector3D v,struct vector3D w)
{
    return (struct vector3D) {v.x+w.x,v.y+w.y,v.z+w.z};
}

struct vector3D resta(struct vector3D v,struct vector3D w)
{
    return suma(v,(struct vector3D){-w.x,-w.y,-w.z});
}

long double module(struct vector3D v)
{
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

long double distancia(struct vector3D v,struct vector3D w)
{
    return module(resta(v,w));
}

long double scalar_product(struct vector3D v,struct vector3D w)
{
    return v.x*w.x+v.y*w.y+v.z*w.z;
}

struct vector3D vectorial_product(struct vector3D v,struct vector3D w)
{
    return (struct vector3D){v.y*w.z-w.y*v.z,v.z*w.x-v.x*w.z,v.x*w.y-v.y*w.x};
}
