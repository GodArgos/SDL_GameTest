#pragma once
#include "Components.hpp"
#include "SDL3/SDL.h"
#include "../Managers/TextureManager.hpp"

class SpriteComponent : public Component
{
private:
	PositionComponent* m_Position;
	SDL_Texture* m_Texture;
	SDL_FRect m_SourceRectangle, m_DestinationRectangle;

public:
	SpriteComponent() = default;

	SpriteComponent(const char* FileName)
	{
		SetTexture(FileName);
	}

	void Init() override
	{
		m_Position = &Entity->GetComponent<PositionComponent>();

		m_SourceRectangle.x = m_SourceRectangle.y = 0;
		m_SourceRectangle.w = m_SourceRectangle.h = 32;
		m_DestinationRectangle.w = m_DestinationRectangle.h = 64;
	}

	void Update() override
	{
		m_DestinationRectangle.x = m_Position->GetPosition().x;
		m_DestinationRectangle.y = m_Position->GetPosition().y;
	}

	void Draw() override
	{
		TextureManager::Draw(m_Texture, m_SourceRectangle, m_DestinationRectangle);
	}

	SDL_Texture* GetTexture() const { return m_Texture; }

	void SetTexture(const char* NewFileName)
	{
		m_Texture = TextureManager::LoadTexture(NewFileName);
	}
};