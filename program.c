#include <stdio.h>
#include <math.h>
#include "vector3D.h"
#include "body.h"
#include "system.h"

int main(int argc, const char *argv[])
{

    struct system Earth_Moon,*s=&Earth_Moon;
    double time=0;

    Earth_Moon.b[0]=(struct body){5.97e24,{0,0,0},{0,0,0},{0,0,0},{0,0,0},0};
    Earth_Moon.b[1]=(struct body){7.3477e22,{384e6,0,0},{0,1.022e3,0},{0,0,0},{0,0,0},0};
    Earth_Moon.n=2;

    while (time<2500)
    {
        temporal_evolution(s,time);
        time+=0.1;
        printf("%lf\t%lf\t%lf\t%lf\t",time,Earth_Moon.b[0].r.x,Earth_Moon.b[0].r.y,Earth_Moon.b[0].r.z);
        printf("%lf\t%lf\t%lf\n",Earth_Moon.b[1].r.x,Earth_Moon.b[1].r.y,Earth_Moon.b[1].r.z);
    }
    return 0;
}
