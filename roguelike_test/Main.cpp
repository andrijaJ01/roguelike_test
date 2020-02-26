
#include"Game.hpp"
const int FPS = 60;
const int framedelay = 1000 / FPS;
Game *game=nullptr;

Uint32 framestart;
int frametime;

int main(int argc, const char *argv[])
{	
	SDL_SetMainReady();

	game = new Game();
	game->init("Dungeon Crawler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running())
	{	
		framestart = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		frametime = SDL_GetTicks() - framestart;

		if (framedelay > frametime) {
			SDL_Delay(framedelay - frametime);
		}
	}
	game->clean();
	return 0;
}