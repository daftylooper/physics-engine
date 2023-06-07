#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "EngineEntities.hpp"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("GAME v1.0", 1280, 720);
	EngineEntities entities(window.getRenderer());

	bool gameRunning = true;
	float dt = 0.1;
	float speed = 10;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT){
				gameRunning = false;
			}
		}

		window.clear();
		entities.renderEntities();
		window.show();
		entities.updateEntities(dt);
		SDL_Delay(1/(speed*dt));
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}