#pragma once
#include"TypeDef.h"
namespace SphereView {
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        TriangleList triangles();
        PointList points();
        PointList normals();

        void addTriangle(SphereView::Point3D p1, SphereView::Point3D p2, SphereView::Point3D p3, SphereView::Point3D normal);

    private:
        int getVIndex(SphereView::Point3D point);
        int getNIndex(SphereView::Point3D point);

    private:
        TriangleList mTriangles;
        PointList mPoints;
        PointList mNormals;
    };
}