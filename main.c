#include "draw.h"
#include "vector.h"
#include "objects.h"
#include <ncurses.h>
#include <time.h>
#include <unistd.h> // sleep
#include <math.h> // sin, cos


int main() {
    draw_init();
    int x = 0, y = 0, z = 300;
    cube_t* cube = obj_cube_new(x, y, z, 40);
    ray_t* ray = obj_ray_new(0, 0, 0);
    plane_t* plane = obj_plane_new(cube->vertices[0], cube->vertices[1], cube->vertices[2]);

    int j = 0;
    int n = 0;
    const int ms_to_wait = 20;
    while(1) {
        clear();
        obj_cube_rotate(cube, cos(2*sin(n/100.0))*4, sin(1.5*n/100.0)*4, 4*sin(0.5*n/100.0));
        draw_cube(cube);
        //refresh();
        usleep(ms_to_wait * 1000);
        n++;
        n %= 200000000;
    }

    obj_cube_free(cube);
    draw_end();

    return 0;
}
