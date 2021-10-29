#include "rayscanner.hpp"
#include "../ray/ray.hpp"
#include "../sphere/sphere.hpp"
#include <iostream>
#define SCREEN_WIDTH 400
#define SREEN_LENGTH 400

RayScanner::RayScanner(VPO objects) : m_objects(objects)
{
}
void RayScanner::scan()
{
    // shoot a ray from the camera to the screen
    // for each object in the scene, check if the ray intersects with the object

    for (int i = 0; i < SREEN_LENGTH; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            // int jj = j - SCREEN_WIDTH / 2;
            // int ii = i - SREEN_LENGTH / 2;
            // std::cout << "i: " << ii << " j: " << jj << std::endl;
            // int ii = i;
            // int jj = j;

            Vec3D endPoint = Vec3D(-200 + j, 0, 200 - i);
            Vec3D origin = Vec3D(0, -600, 20);
            // (endPoint - origin).show("Top left corner");
            // endPoint = Vec3D(200, 0, 200);
            // (endPoint - origin).show("Top right corner");
            // endPoint = Vec3D(-200, 0, -200);
            // (endPoint - origin).show("Bottom left corner");
            // endPoint = Vec3D(200, 0, -200);
            // (endPoint - origin).show("Bottom right corner");
            // endPoint = Vec3D(0, 0, 0);
            // (endPoint - origin).show("Center");

            Vec3D dir = endPoint - origin;
            // Ray testray = Ray(origin, dir);
            // testray.m_direction.show("first direction ray: ");
            // Sphere testsphere = Sphere(Vec3D(1, 10, 0), 3);
            // Sphere testsphere2 = Sphere(Vec3D(-1, -10, 0), 3);

            // testsphere.hit(testray);
            // testray.m_direction.show("bounced direction ray: ");
            // testsphere2.hit(testray);
            // testray.m_direction.show("bounced direction ray (2): ");
            // testsphere.hit(testray);
            // testray.m_direction.show("bounced direction ray (3): ");
            // testsphere2.hit(testray);
            // testray.m_direction.show("bounced direction ray (4): ");


            Ray startPoint = Ray(origin, dir, m_objects);

            int intensity = startPoint.scan();
            // m_screenBuffer[i][j] = intensity;
            if (intensity == 0)
            {
                m_screenBuffer[i][j] = "   ";
            }
            else if (intensity == 1)
            {
                m_screenBuffer[i][j] = "LLL";
            }
            else if (intensity == 2)
            {
                m_screenBuffer[i][j] = "MMM";
            }
            else if (intensity == 3)
            {
                m_screenBuffer[i][j] = "\u001b[30mKKK\033[0m";
            }
            else if (intensity == 4)
            {
                m_screenBuffer[i][j] = "TTT";
            }
        }
    }
    // 𝙺𝙼𝚁𝙽𝚃
}

void RayScanner::render()
{
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SREEN_LENGTH; j++)
        {
            std::cout << m_screenBuffer[i][j];
        }
        std::cout << std::endl;
    }
}
