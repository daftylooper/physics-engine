#pragma once
#include <SDL2/SDL.h>
#include "VectorMath.hpp"
#include <iostream>

class Rect{
    public:
        Rect(int width, int height, float posx, float posy, float velx, float vely, float acclx, float accly, SDL_Renderer* renderer);
        //since all parameters depend on acceleration, there's only a need for one function
        void updateParamaters(float dt);
        //position is private, this will return it for render in main()
        Vec2* getPosition();
        void render();
        
    private:
        int width;
        int height;
        Vec2* position = new Vec2{0, 0};
        Vec2* velocity = new Vec2{0, 0};
        Vec2* acceleration = new Vec2{0, 0};
        Vec2* temp = new Vec2{0, 0};
        SDL_Renderer* renderer;
        
        //inertia, angle/rotation/angular accl, restituition
};