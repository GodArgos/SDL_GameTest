#pragma once
#include "Components.hpp"
#include "../DataTypes/Vector2.hpp"

class PositionComponent : public Component
{
private:
	Vector2 m_Position;

public:
	PositionComponent(const Vector2& InitialPosition)
		: m_Position(InitialPosition)
	{

	}

	PositionComponent()
		: m_Position({ 0, 0 })
	{

	}

	void Update() override
	{
		m_Position.x++;
		m_Position.y++;
	}

	Vector2 GetPosition() const { return m_Position; }

	void SetPosition(const Vector2& position) { m_Position = position; }
};