#pragma once
#include <cmath>

typedef struct Vec2{
    float x;
    float y;
} Vec2;

class VectorMath{
    public:
        void initVec2(Vec2* first, float x, float y);
        void add(Vec2* first, Vec2* second);
        void subtract(Vec2* first, Vec2* second);
        float absolute(Vec2* first);
        float distance(Vec2* first, Vec2* second);
        void scalarProduct(Vec2* first, Vec2* target, float x);
        float dotproduct(Vec2* first, Vec2* second);
        // void crossproduct(Vec2* first, Vec2* second);
};