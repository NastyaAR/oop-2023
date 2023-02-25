#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include <cstdlib>
#include "math.h"
#include "errors.h"

struct point
{
    double x;
    double y;
    double z;
};

using point_t = struct point;

struct transfer
{
    double dx;
    double dy;
    double dz;
};

using transfer_t = struct transfer;

struct scale
{
    double kx;
    double ky;
    double kz;
};

using scale_t = struct scale;

struct turn
{
    double dxo;
    double dyo;
    double dzo;
};

using turn_t = struct turn;

err_t read_point(point_t &point, FILE *file);
void transfer_point(point_t &point, const transfer_t &transfer);
void scale_point(point_t &point, const point_t center, const scale_t &scale);
void turn_point(point_t &point, const point_t center, const turn_t &turn);
double to_radians(const double angle);
void turn_x(point_t &point, const point_t center, const double angle);
void turn_y(point_t &point, const point_t center, const double angle);
void turn_z(point_t &point, const point_t center, const double angle);

#endif // POINT_H
