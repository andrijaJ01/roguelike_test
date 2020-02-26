#include"texturemanager.hpp"

SDL_Texture* textureManager::LoadTex(const char* texture) 
{
	SDL_Surface* temp_surface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,temp_surface);
	SDL_FreeSurface(temp_surface);
	return tex;
}