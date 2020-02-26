
#include"Game.hpp"
#include"texturemanager.hpp"
#include"GameObject.hpp"


GameObject* player;
GameObject* enemy;
SDL_Renderer* Game::renderer = nullptr;

Game::~Game()
{}
Game::Game()
{}
void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen = true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL INITIALIZED" << std::endl;

		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			std::cout << "Window Created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	player = new  GameObject("assets/player.png",0,0);
	enemy = new GameObject("assets/npc.png", 400, 400);

	
}

void Game::update()
{
	player->update();
	enemy->update();

	
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	enemy->render();
	SDL_RenderPresent(renderer);
	SDL_RENDERER_PRESENTVSYNC;
	

}

void Game::handle_events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
	 
}

bool Game::running()
{	
	return isRunning;
}
