#include <stdio.h>
#include <math.h>
#include "vector3D.h"
#include "body.h"
#include "system.h"

int main(int argc, const char *argv[])
{

    struct system Sun_Earth,*s=&Sun_Earth;
    double time=0;

    //Sun_Earth.b[0]=(struct body){2e30,{0,0,0},{0,0,0},{0,0,0},{0,0,0},1};
    //Sun_Earth.b[0]=(struct body){5.97e24,{150e9,0,0},{0,29.78e3,0},{0,0,0},{0,0,0},0};
    Sun_Earth.b[0]=(struct body){5.97e24,{0,0,0},{0,0,0},{0,0,0},{0,0,0},0};
    Sun_Earth.b[1]=(struct body){7.3477e22,{384e6,0,0},{0,1.022e3,0},{0,0,0},{0,0,0},0};
    //Sun_Earth.b[2]=(struct body){1.899e27,{778412026000.,0,0},{0,13069.7,0},{0,0,0},{0,0,0},0};
    Sun_Earth.n=2;

    //print_body(Sun_Earth.b[0]);
    //printf("\n");

    while (time<2500)
    {
        temporal_evolution(s,time);
        time+=0.1;
        printf("%lf\t%lf\t%lf\t%lf\t",time,Sun_Earth.b[0].r.x,Sun_Earth.b[0].r.y,Sun_Earth.b[0].r.z);
        printf("%lf\t%lf\t%lf\n",Sun_Earth.b[1].r.x,Sun_Earth.b[1].r.y,Sun_Earth.b[1].r.z);
    }
    //print_body(Sun_Earth.b[0]);
    //printf("\n");

    /*struct vector3D a1,a2; 
    struct vector3D *b;

    b=&a1;
    get_vector(b);
    print_vector(a1);

    b=&a2;
    get_vector(b);
    print_vector(a2);*/

    /*print_vector(resta(a1,a2));
    printf("%lf\n",module(a1));*/

    /*struct body a,*b=&a;

    get_body(b);
    print_body(a);*/

    /*struct system s,*s1=&s;
    get_system(s1);
    print_system(s);*/

    return 0;
}
