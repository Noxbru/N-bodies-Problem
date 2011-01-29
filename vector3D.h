#include <stdio.h>
#include <math.h>

#define VECTOR3D

struct vector3D
{
    long double x,y,z;
}; 

/* We pass a pointer to a vector to get it from
 * keyboard                                     */
void get_vector(struct vector3D *v)
{
    printf("Imput the x component of the vector\n");
    scanf("%Lf",&v->x);
    printf("Imput the y component of the vector\n");
    scanf("%Lf",&v->y);
    printf("Imput the z component of the vector\n");
    scanf("%Lf",&v->z);
}

/* Prints out a vector with the format
 * (1st component,<TAB>2nd component,<TAB>3rd component) */
void print_vector(struct vector3D v)
{
    printf("(%Lf,\t%Lf,\t%Lf)\n",v.x,v.y,v.z);
}

/*const char *to_string(struct vector3D v)
{
    return "("+v.x+",\t"+v.y+",\t"+v.z+")"; //problemas al pasar un double a char *
}*/

/* Returns a vector which is the sume of two */
struct vector3D suma(struct vector3D v,struct vector3D w)
{
    return (struct vector3D) {v.x+w.x,v.y+w.y,v.z+w.z};
}

/* Returns the vector which is the adition of the first
 * and the negative of the second                       */
struct vector3D resta(struct vector3D v,struct vector3D w)
{
    return suma(v,(struct vector3D){-w.x,-w.y,-w.z});
}

/* Returns the length of the vector */
long double module(struct vector3D v)
{
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

/* Returns the distance between two vectors as if the
 * origin of both were at (0,0,0)                     */
long double distancia(struct vector3D v,struct vector3D w)
{
    return module(resta(v,w));
}

/* Returns the scalar or inner product of two vectors */
long double scalar_product(struct vector3D v,struct vector3D w)
{
    return v.x*w.x+v.y*w.y+v.z*w.z;
}

/* Returns the vector which is the vectorial product
 * of two vectors */
struct vector3D vectorial_product(struct vector3D v,struct vector3D w)
{
    return (struct vector3D){v.y*w.z-w.y*v.z,v.z*w.x-v.x*w.z,v.x*w.y-v.y*w.x};
}
