#pragma once
#include"Point3D.h"

namespace SphereView {
    class Triangle
    {
    public:
        Triangle(int inIdxP1, int inIdxP2, int inIdxP3);
        ~Triangle();

        void setNormal(int inNormal);

        int getIdxP1();
        int getIdxP2();
        int getIdxP3();

        int getNormal();

    private:
        int mIdxP1;
        int mIdxP2;
        int mIdxP3;
        int mNormal;
    };
}