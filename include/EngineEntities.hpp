#pragma once
#include "Entity.hpp"
#include <vector>

class EngineEntities{
    public:
        EngineEntities(SDL_Renderer* renderer);
        void addEntity(Rect rect);
        void renderEntities();
        void updateEntities(float dt);
    private:
        std::vector<Rect> rectEntities;

};

EngineEntities::EngineEntities(SDL_Renderer* renderer){
    //add entities here
    rectEntities.push_back(Rect(50, 50, 50, 50, 0, 0, 50, 0, renderer));
    rectEntities.push_back(Rect(50, 50, 1000, 600, 0, 0, -50, -50, renderer));
    rectEntities.push_back(Rect(50, 50, 1000, 700, 0, 0, -50, -10, renderer));
    rectEntities.push_back(Rect(50, 50, 200, 0, 0, 0, 0, 30, renderer));
    rectEntities.push_back(Rect(50, 50, 100, 650, 0, 0, 50, -40, renderer));
    rectEntities.push_back(Rect(0, 50, 600, 350, 0, 0, 0, 0, renderer));
}

void EngineEntities::renderEntities(){
    for(int i=0; i<rectEntities.size(); i++){
        rectEntities[i].render();
    }
}

void EngineEntities::updateEntities(float dt){
    for(int i=0; i<rectEntities.size(); i++){
        rectEntities[i].updateParamaters(dt);
    }
}