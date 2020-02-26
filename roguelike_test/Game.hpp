#pragma once
#ifndef game_hpp
#define game_hpp
#define SDL_MAIN_HANDLED
#include"SDL.h"
#include"SDL_image.h"

#include<iostream>
#endif // !game_hpp

class Game {

public:
	Game();
	~Game();
	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	
	void handle_events();
	void update();
	void render();
	void clean();

	bool running();

	static SDL_Renderer *renderer;
		
private:
	bool isRunning;
	int count = 0;
	SDL_Window *window;
	




};