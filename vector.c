#if !defined(VECTOR_C)
#define VECTOR_C

#include "vector.h"
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>


struct vcom
{
    double value;
};

struct vec
{
    double xcomp;
    double ycomp;
    double zcomp;
};

vector create_vector(double xsize, double ysize, double zsize){
    vector temp = malloc(sizeof(struct vec));

    temp->xcomp = xsize;
    temp->ycomp = ysize;
    temp->zcomp = zsize;
    
    return temp;
}

void set_values(vector v, double x, double y, double z)
{
    v->xcomp = x;
    v->ycomp = y;
    v->zcomp = z;
}

double get_xval(vector v){
    return v->xcomp;
}

void set_xval(vector v, double val){
    v->xcomp = val;
}

double get_yval(vector v){
    return v->ycomp;
}

void set_yval(vector v, double val){
    v->ycomp = val;
}

double get_zval(vector v){
    return v->zcomp;
}

void set_zval(vector v, double val){
    v->zcomp = val;
}

double get_xangle(vector v)
{
    double x = get_xval(v);
    double norm = get_norm(v) ;
    return acos(x / norm);
}

double get_yangle(vector v)
{
    double y = get_yval(v);
    double norm = get_norm(v) ;
    return acos(y / norm);
}

double get_zangle(vector v)
{
    double z = get_zval(v);
    double norm = get_norm(v) ;
    return acos(z / norm);
}

double get_norm(vector v)
{
    double a, b, c, norm;

    a = pow(v->xcomp, 2);     //applying pythagoras theorem
    b = pow(v->ycomp, 2);
    c = pow(v->zcomp, 2);

    norm = sqrt(a+b+c);
}

void summation(int args, vector v, ... )
{
    va_list ap;
    va_start(ap, v);

    for (int i = 1; i<args; i++) {
        
        vector nv = va_arg(ap, vector);
        v->xcomp += nv->xcomp;      //sum values
        v->ycomp += nv->ycomp;
        v->zcomp += nv->zcomp;
    }

    va_end(ap);
}

void subtraction(int args, vector v, ... )
{
    va_list ap;
    va_start(ap, v);

    for (int i = 1; i<args; i++) {
        
        vector nv = va_arg(ap, vector);
        v->xcomp -= nv->xcomp;      //subtraction values
        v->ycomp -= nv->ycomp;
        v->zcomp -= nv->zcomp;
    }

    va_end(ap);
}

void dot_product(int args, vector v, ...)
{

    va_list ap;
    va_start(ap, v);

    for (int i = 1; i<args; i++) {
        
        vector nv = va_arg(ap, vector);
        v->xcomp *= nv->xcomp;      //multiply values
        v->ycomp *= nv->ycomp;
        v->zcomp *= nv->zcomp;
    }

    va_end(ap);
}

void cross_product(int args, vector v, ...)
{

    va_list ap;
    va_start(ap, v);

    for (int i = 1; i<args; i++) {
        
        vector nv = va_arg(ap, vector);
        double vi = (v->ycomp * nv->zcomp)-(v->zcomp * nv->ycomp);      //multiply values
        double vj = (v->zcomp * nv->xcomp)-(v->xcomp * nv->zcomp);
        double vk = (v->xcomp * nv->ycomp)-(v->ycomp * nv->xcomp);

        v->xcomp = vi;        //save multiplications into isolated variables
        v->ycomp = vj;        //to not modify the pointer before other calculus
        v->zcomp = vk;
    }

    va_end(ap);
}

#endif // VECTOR_C
