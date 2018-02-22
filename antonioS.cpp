#include "Asteroid.h"
#include <iostream>
#include <cmath>
//defined types 
#define PI 3.141592653589793


using namespace std;
void physicSwitch(Asteroid *a, bool value) 
{
    if (value) {
	a->physics = true;
    } else {
	a->physics = false;
    }
}


void buildAsteroidFragment2(Asteroid *ta, Asteroid *a)
{
        //build ta from a
        ta->nverts = 8;
        physicSwitch(ta, true);
        ta->radius = a->radius / 2.0;
        Flt r2 = ta->radius / 2.0;
        Flt angle = 0.0f;
        Flt inc = (PI * 2.0) / (Flt)ta->nverts;
        for (int i=0; i<ta->nverts; i++) {
                ta->vert[i][0] = sin(angle) * (r2 + rnd() * ta->radius);
                ta->vert[i][1] = cos(angle) * (r2 + rnd() * ta->radius);
                angle += inc;
        }
        ta->pos[0] = a->pos[0] + rnd()*10.0-5.0;
        ta->pos[1] = a->pos[1] + rnd()*10.0-5.0;
        ta->pos[2] = 0.0f;
        ta->angle = 0.0;
        ta->rotate = a->rotate + (rnd() * 4.0 - 2.0);
        ta->color[0] = a->color[0];
        ta->color[1] = a->color[1];
        ta->color[2] = a->color[2];
        ta->vel[0] = a->vel[0] + (rnd()*2.0-1.0);
        ta->vel[1] = a->vel[1] + (rnd()*2.0-1.0);
}


