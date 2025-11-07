#include "GameObject.hpp"
#include "../Managers/TextureManager.hpp"

GameObject::GameObject(const char* TextureSheet, SDL_Renderer* _Renderer, Vector2 InitialPosition)
	: Renderer(_Renderer),
	m_ObjectTexture(TextureManager::LoadTexture(TextureSheet, _Renderer)),
	m_Position(InitialPosition),
	m_SourceRectangle{ 0.f, 0.f, 0.f, 0.f },
	m_DestinationRectangle{ 0.f, 0.f, 0.f, 0.f }
{

}

void GameObject::Update()
{
	m_SourceRectangle.h = 32;
	m_SourceRectangle.w = 32;
	m_SourceRectangle.x = 0;
	m_SourceRectangle.y = 0;

	m_DestinationRectangle.x = m_Position.x;
	m_DestinationRectangle.y = m_Position.y;
	m_DestinationRectangle.h = m_SourceRectangle.h * 2;
	m_DestinationRectangle.w = m_SourceRectangle.w * 2;
}

void GameObject::Render()
{
	SDL_RenderTexture(Renderer, m_ObjectTexture, &m_SourceRectangle, &m_DestinationRectangle);
}

GameObject::~GameObject()
{

}