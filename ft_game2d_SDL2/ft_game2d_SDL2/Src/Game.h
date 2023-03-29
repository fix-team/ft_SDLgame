#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "AssetManager.h"

class AssetManager;
class ColliderComponent;

class Game
{
public:
	Game();
	~Game();
	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return bIsRunning; }
	
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool bIsRunning;
	static SDL_Rect camera;
	static AssetManager* assets;

	enum groupLables : std::size_t {
		groupMap,
		groupPlayers,
		groupColliders
	};

private:
	int cnt = 0;
	SDL_Window* window;
};

