#include <stdio.h>
#include <math.h>

#define BODY

#ifndef VECTOR3D
    #include "vector3D.h"
#endif

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

struct body
{
    long double m;
    struct vector3D r,v;
    struct vector3D dr,dv;
    char fixed;
    FILE *fout;
};

void get_body(struct body *v)
{
    struct vector3D *r1=&v->r;
    struct vector3D *v1=&v->v;
    v->dv=(struct vector3D){0,0,0};
    printf("Imput the mass of the body\n");
    scanf("%Lf",&v->m);
    printf("Imput its position vector\n");
    get_vector(r1);
    printf("Imput its velocity vector\n");
    get_vector(v1);
    printf("Is the body fixed in space?(Y/N)\n");
    scanf(" %c",&v->fixed);
    
    switch(v->fixed)
    {
        case 'Y':
        case 'y':   v->fixed=TRUE; break;
        default:    v->fixed=FALSE;break;
    }
}

void print_body(struct body c)
{
    printf("Mass:\t%Lf\n",c.m);
    printf("Position vector\n");
    print_vector(c.r);
    printf("Velocity vector\n");
    print_vector(c.v);
    if (c.fixed)
        printf("Body fixed in space\n");
    else
        printf("Body not fixed in space\n");
}

struct vector3D linear_moment(struct body a)
{
    return (struct vector3D){a.m*a.v.x,a.m*a.v.y,a.m*a.v.z};
}

struct vector3D angular_moment(struct body a)
{
    return vectorial_product(a.r,linear_moment(a));
}

struct vector3D force(struct body a, struct body b)
{
    long double aux1=distancia(a.r,b.r);
    long double aux2=6.67e-11*a.m*b.m/aux1/aux1/aux1;
    struct vector3D r=resta(b.r,a.r);
    return (struct vector3D){r.x*aux2,r.y*aux2,r.z*aux2};
}

long double potential_energy(struct body a,struct body b)
{
    return 6.67e-11*a.m*b.m/distancia(a.r,b.r);
}

long double kinetic_energy(struct body a)
{
    return 0.5*a.m*distancia(a.v,a.dv)*distancia(a.v,a.dv);
}
