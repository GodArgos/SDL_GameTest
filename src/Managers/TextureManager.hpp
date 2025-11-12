#pragma once
#include "../Game.hpp"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* FileName);
	static void Draw(SDL_Texture* Texture, SDL_FRect SourceRect, SDL_FRect DestinationRect);
};