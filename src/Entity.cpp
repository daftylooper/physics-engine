#include "Entity.hpp"
VectorMath vec;

Rect::Rect(int width, int height, float posx, float posy, float velx, float vely, float acclx, float accly, SDL_Renderer* renderer){
    Rect::width = width;
    Rect::height = height;

    vec.initVec2(Rect::position, posx, posy);
    vec.initVec2(Rect::velocity, velx, vely);
    vec.initVec2(Rect::acceleration, acclx, accly);
    vec.initVec2(Rect::temp, 0, 0);

    Rect::renderer = renderer;
}

void Rect::updateParamaters(float dt){
    //acceleration is assumed instantaneous

    // std::cout<<Rect::velocity->x<<" "<<Rect::velocity->y<<"\n";

    //calculate velocity
    vec.scalarProduct(Rect::acceleration, temp, dt);
    vec.add(Rect::velocity, temp);

    //calculate position
    vec.scalarProduct(Rect::velocity, temp, dt);
    vec.add(Rect::position, temp);

    //zero the acceleration since it is instantaneous
    vec.initVec2(Rect::acceleration, 0, 0);
}

void Rect::render(){
    SDL_Rect rect;
    SDL_SetRenderDrawColor(Rect::renderer, 255, 0, 0, 255);
    rect.x = Rect::position->x;
    rect.y = Rect::position->y;
    rect.w = Rect::width;
    rect.h = Rect::height;
    SDL_RenderFillRect(Rect::renderer, &rect);
}