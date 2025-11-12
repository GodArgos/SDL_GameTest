#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* FileName)
{
	SDL_Surface* tmpSurface = IMG_Load(FileName);
	SDL_Texture* tmpTex = SDL_CreateTextureFromSurface(Game::Renderer, tmpSurface);
	SDL_DestroySurface(tmpSurface);

	return tmpTex;
}

void TextureManager::Draw(SDL_Texture* Texture, SDL_FRect SourceRect, SDL_FRect DestinationRect)
{
	SDL_RenderTexture(Game::Renderer, Texture, &SourceRect, &DestinationRect);
}
