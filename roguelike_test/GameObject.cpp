#include"GameObject.hpp"
#include"Game.hpp"
#include"texturemanager.hpp"

GameObject::GameObject(const char* texturesheet ,int x, int y)
{
	objTexture = textureManager::LoadTex(texturesheet);
	xpos = x;
	ypos = y;

}
void GameObject::update() 
{
	xpos++;
	ypos++;
	src.h = 720;
	src.w = 720;
	src.x = 0;
	src.y = 0;
	dest.x = xpos;
	dest.y = ypos;
	dest.w = src.w / 4;
	dest.h = src.h / 4;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &src, &dest);
	
}