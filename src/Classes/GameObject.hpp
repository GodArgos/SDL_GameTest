#pragma once
#include "../Game.hpp"
#include "../DataTypes/Vector2.hpp"

class GameObject
{
private:
	Vector2 m_Position;
	SDL_Texture* m_ObjectTexture;
	SDL_FRect m_SourceRectangle, m_DestinationRectangle;

	SDL_Renderer* Renderer;
public:
	GameObject(const char* TextureSheet, SDL_Renderer* Renderer, Vector2 InitialPosition);

	void Update();

	void Render();

	SDL_Texture* GetObjectRenderer() const { return m_ObjectTexture; }

	~GameObject();
};

