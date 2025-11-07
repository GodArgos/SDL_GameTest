#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* FileName, SDL_Renderer* Renderer)
{
	SDL_Surface* tmpSurface = IMG_Load(FileName);
	SDL_Texture* tmpTex = SDL_CreateTextureFromSurface(Renderer, tmpSurface);
	SDL_DestroySurface(tmpSurface);

	return tmpTex;
}