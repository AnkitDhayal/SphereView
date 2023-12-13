#include "stdafx.h"
#include "Triangulation.h"


SphereView::Triangulation::Triangulation()
{

}

SphereView::Triangulation::~Triangulation()
{

}

TriangleList SphereView::Triangulation::triangles()
{
    return mTriangles;
}

PointList SphereView::Triangulation::points()
{
    return mPoints;
}

PointList SphereView::Triangulation::normals()
{
    return mNormals;
}

void SphereView::Triangulation::addTriangle(SphereView::Point3D p1, SphereView::Point3D p2, SphereView::Point3D p3, SphereView::Point3D normal)
{
    int idx1 = getVIndex(p1);
    int idx2 = getVIndex(p2);
    int idx3 = getVIndex(p3);
    int idxn = getNIndex(normal);
    SphereView::Triangle t1 = SphereView::Triangle(idx1, idx2, idx3);
    t1.setNormal(idxn);
    mTriangles.push_back(SphereView::Triangle(idx1, idx2, idx3));

}

int SphereView::Triangulation::getVIndex(SphereView::Point3D point)
{
    for (int i = 0; i < mPoints.size(); i++)
    {
        if (mPoints[i] == point)
        {
            return i;
        }
    }

    mPoints.push_back(point);

    return mPoints.size() - 1;
}

int SphereView::Triangulation::getNIndex(SphereView::Point3D point)
{
    for (int i = 0; i < mNormals.size(); i++)
    {
        if (mNormals[i] == point)
        {
            return i;
        }
    }

    mNormals.push_back(point);

    return mNormals.size() - 1;
}
