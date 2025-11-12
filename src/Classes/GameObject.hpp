#pragma once
#include "../Game.hpp"
#include "../DataTypes/Vector2.hpp"

class GameObject
{
private:
	Vector2 m_Position;
	SDL_Texture* m_ObjectTexture;
	SDL_FRect m_SourceRectangle, m_DestinationRectangle;

public:
	GameObject(const char* TextureSheet, Vector2 InitialPosition);

	void Update();

	void Render();

	SDL_Texture* GetObjectRenderer() const { return m_ObjectTexture; }

	~GameObject();
};

