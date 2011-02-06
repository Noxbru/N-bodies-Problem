#include <stdio.h>
#include <math.h>
#include "vector3D.h"
#include "body.h"
#include "system.h"

int main(int argc, const char *argv[])
{

    struct system Earth_Moon,*s=&Earth_Moon;
    unsigned long int time=0;

    //get_system(s);
    //print_system(Earth_Moon);

    //Earth_Moon.b[0]=(struct body){1.98892e30,{0,0,0},{0,0,0},{0,0,0},{0,0,0},1};                  //Sun if it's in the centre and fixed
    //Earth_Moon.b[1]=(struct body){5.9737e24,{1.5e11,0,0},{0,29.7389e3,0},{0,0,0},{0,0,0},0};      //Earth
    //Earth_Moon.b[2]=(struct body){7.3477e22,{1.8384e9,0,0},{0,30.802e3,0},{0,0,0},{0,0,0},0};     //Moon
    
    Earth_Moon.n=2;
    Earth_Moon.b=malloc(Earth_Moon.n*sizeof(struct system));
    Earth_Moon.b[0]=(struct body){5.9737e24,{0,0,0},{0,0,0},{0,0,0},{0,0,0},1};                     //Earth
    Earth_Moon.b[1]=(struct body){7.3477e22,{384e6,0,0},{0,1018.865,0},{0,0,0},{0,0,0},0};          //Moon
    print_system(Earth_Moon);

    while (time<2500000)
    {
        temporal_evolution_rk(s);
        time+=1;
        if(time%200==0)
        {
            printf("%lu\t%Lf\t%Lf\t%Lf\t",time,Earth_Moon.b[0].r.x,Earth_Moon.b[0].r.y,Earth_Moon.b[0].r.z);
            printf("%Lf\t%Lf\t%Lf\n",Earth_Moon.b[1].r.x,Earth_Moon.b[1].r.y,Earth_Moon.b[1].r.z);
        }
    }
    return 0;
}
