#include "stdafx.h"
#include "Point3D.h"

SphereView::Point3D::Point3D(double inX, double inY, double inZ)
    : mX(0),
    mY(0),
    mZ(0)
{
    mX = inX;
    mY = inY;
    mZ = inZ;
}

SphereView::Point3D::~Point3D()
{
}

double SphereView:: Point3D::x()
{
    return mX;
}

double SphereView:: Point3D::y()
{
    return mY;
}

double SphereView::Point3D::z()
{
    return mZ;
}

void SphereView:: Point3D::setX(double x)
{
    mX = x;
}

void SphereView::Point3D::setY(double y)
{
    mY = y;
}

void SphereView::Point3D::setZ(double z)
{
    mZ = z;
}

bool SphereView:: Point3D::operator==(const Point3D& p1)
{
    return mX == p1.mX && mY == p1.mY && mZ == p1.mZ;
}