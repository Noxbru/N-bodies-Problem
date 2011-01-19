#include <stdio.h>
#include <stdio.h>

#ifndef BODY
    #include "body.h"
#endif

struct system
{
    struct body b[10];
    unsigned int n;
};

void get_system(struct system *s)
{
    struct body *b1;
    int i;
    printf("Imput the number of bodies\n");
    scanf("%u",&s->n);
    for (i = 0; i < s->n; i++)
    {
        b1=&s->b[i];
        get_body(b1);
    }
}

void print_system(struct system s)
{
    int i;
    for (i = 0; i < s.n; i++)
    {
        print_body(s.b[i]);
    }
}

void temporal_evolution(struct system *s,double h)
{
    int i,j;
    struct vector3D f;
    for (i = 0; i < s->n; i++)
        if(!s->b[i].fixed)
            s->b[i].r=suma(s->b[i].r,(struct vector3D){h*s->b[i].v.x,h*s->b[i].v.y,h*s->b[i].v.z}); 

    for (i = 0; i < s->n; i++)
        for (j = i+1; j < s->n; j++)
        {
            f=force(s->b[i],s->b[j]);
            s->b[i].dv=(struct vector3D) {f.x*h/s->b[i].m,f.y*h/s->b[i].m,f.z*h/s->b[i].m};
            s->b[i].v=suma(s->b[i].v,s->b[i].dv);
            s->b[j].dv=(struct vector3D) {-f.x*h/s->b[j].m,-f.y*h/s->b[j].m,-f.z*h/s->b[j].m};
            s->b[j].v=suma(s->b[j].v,s->b[j].dv);
        }
}
