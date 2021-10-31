#include "floor.hpp"
#define ROWS 2000
#define COLS 2000
#define GRIDSIZE (ROWS * COLS)
#define SQUAREWIDTH 10
#define SQAUREHEIGHT (ROWS / SQUAREWIDTH)

#include "../Vec3D/vec3d.hpp"

#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <cmath>

Floor::Floor(int zIndex, const Color &color)
{
    m_type = "Floor";
    intensity = 2;
    m_zIndex = zIndex;
    m_color = color;
}

float Floor::distFromRay(Ray &ray) const
{
    float t = (-ray.m_origin.m_z / ray.m_direction.m_z);
    Vec3D scaledVector = ray.m_origin + (ray.m_direction * t);
    if (t < 0)
        return -1;
    if ((int)(floor(scaledVector.m_x / 20) + floor(scaledVector.m_y / 20)) % 2 != 0)
        return -1;

    Vec3D point = ray.m_origin + ray.m_direction * t;
    Vec3D origin = ray.m_origin;
    return std::sqrt(std::pow(point.m_x - origin.m_x, 2) +
                     std::pow(point.m_y - origin.m_y, 2) +
                     std::pow(point.m_z - origin.m_z, 2));
}

bool Floor::hit(Ray &ray) const
{
    float t = (-ray.m_origin.m_z / ray.m_direction.m_z);
    Vec3D scaledVector = ray.m_origin + (ray.m_direction * t);
    if (t > 0)
    {
        Vec3D normal = (Vec3D(0, 0, 1));
        Vec3D reflect = (ray.m_direction - (2 * ray.m_direction.dot(normal) * normal)).unit();
        ray.m_origin = scaledVector;
        ray.m_direction = reflect;
        return (int)(floor(scaledVector.m_x / 20) + floor(scaledVector.m_y / 20)) % 2 == 0;
    }

    return false;
}
