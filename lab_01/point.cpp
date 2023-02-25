#include "point.h"

err_t read_point(point_t &point, FILE *file)
{
    err_t rc = SUCCESS;

    if (file == NULL)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(file, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        rc = READ_POINT_ERROR;

    return rc;
}

void transfer_point(point_t &point, const transfer_t &transfer)
{
    point.x += transfer.dx;
    point.y += transfer.dy;
    point.z += transfer.dz;
}

void scale_point(point_t &point, const point_t center, const scale_t &scale)
{
    point.x = center.x + scale.kx * (point.x - center.x);
    point.y = center.y + scale.ky * (point.y - center.y);
    point.z = center.z + scale.kz * (point.z - center.z);
}

double to_radians(const double angle)
{
    return M_PI / 180 * angle;
}

void turn_x(point_t &point, const point_t center, const double angle)
{
    double radians = to_radians(angle);
    double cos_angle = cos(radians);
    double sin_angle = sin(radians);
    double temp_y = point.y;


    point.y = (point.y - center.y)  * cos_angle + (point.z - center.z) * sin_angle + center.y;
    point.z = -(temp_y - center.y) * sin_angle + (point.z - center.z) * cos_angle + center.z;
}

void turn_y(point_t &point, const point_t center, const double angle)
{
    double radians = to_radians(angle);
    double cos_angle = cos(radians);
    double sin_angle = sin(radians);
    double temp_x = point.x;


    point.x = (point.x - center.x) * cos_angle + (point.z - center.z) * sin_angle + center.x;
    point.z = -(temp_x - center.x) * sin_angle + (point.z - center.z) * cos_angle + center.z;
}

void turn_z(point_t &point, const point_t center, const double angle)
{
    double radians = to_radians(angle);
    double cos_angle = cos(radians);
    double sin_angle = sin(radians);
    double temp_x = point.x;


    point.x = (point.x - center.x) * cos_angle + (point.y - center.y)* sin_angle + center.x;
    point.y = -(temp_x - center.x) * sin_angle + (point.y - center.y) * cos_angle + center.y;
}

void turn_point(point_t &point, const point_t center, const turn_t &turn)
{
    turn_x(point, center, turn.dxo);
    turn_y(point, center, turn.dyo);
    turn_z(point, center, turn.dzo);
}
