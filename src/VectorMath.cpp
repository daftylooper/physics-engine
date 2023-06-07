#include "VectorMath.hpp"

void VectorMath::initVec2(Vec2* first, float x, float y){
    first->x=x;
    first->y=y;
}
void VectorMath::add(Vec2* first, Vec2* second){
    first->x += second->x;
    first->y += second->y;
}
void VectorMath::subtract(Vec2* first, Vec2* second){
    first->x -= second->x;
    first->y -= second->y;
}
float VectorMath::absolute(Vec2* first){
    return sqrtf(powf(first->x, 2)+powf(first->y, 2));
}
float VectorMath::distance(Vec2* first, Vec2* second){
    return sqrtf(powf(first->x-second->x, 2)+powf(first->y-second->y, 2));
}
void VectorMath::scalarProduct(Vec2* first, Vec2* target, float x){
    target->x=first->x*x;
    target->y=first->y*x;    
}
float VectorMath::dotproduct(Vec2* first, Vec2* second){
    return first->x*second->x + first->y*second->y;
}