#include "stdafx.h"
#include "Triangle.h"

SphereView::Triangle::Triangle(int inIdxP1, int inIdxP2, int inIdxP3)
    :mIdxP1(inIdxP1),
    mIdxP2(inIdxP2),
    mIdxP3(inIdxP3)
{

}


SphereView::Triangle::~Triangle()
{

}

void SphereView::Triangle::setNormal(int inNormal)
{
    mNormal = inNormal;
}

int SphereView::Triangle::getNormal()
{
    return mNormal;
}

int SphereView::Triangle::getIdxP1()
{
    return mIdxP1;
}

int SphereView::Triangle::getIdxP2()
{
    return mIdxP2;
}

int SphereView::Triangle::getIdxP3()
{
    return mIdxP3;
}
