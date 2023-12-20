#pragma once
#include "Triangle.h"
#include <vector>
class GEOMETRY_API Triangulation
{
public:
    Triangulation(std::vector<Triangle> triangles);
    ~Triangulation();

    std::vector<Triangle> getTriangles();

private:
    std::vector<Triangle> mTriangles;
};

