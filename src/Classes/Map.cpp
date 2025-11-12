#include "Map.hpp"
#include "../Managers/TextureManager.hpp"

int lvl1[20][25] = { 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map()
{
	m_Dirt = TextureManager::LoadTexture("assets/sprites/dirt.png");
	m_Grass = TextureManager::LoadTexture("assets/sprites/grass.png");
	m_Water = TextureManager::LoadTexture("assets/sprites/water.png");

	LoadMap(lvl1);

	m_SourceRectangle.x = m_SourceRectangle.y = 0;
	m_SourceRectangle.w = m_DestionationRectangle.w = 32;
	m_SourceRectangle.h = m_DestionationRectangle.h = 32;

	m_DestionationRectangle.x = m_DestionationRectangle.y = 0;
}

Map::~Map()
{

}

void Map::LoadMap(int arr[20][25])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			m_Map[i][j] = arr[i][j];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			type = m_Map[i][j];

			m_DestionationRectangle.x = j * 32;
			m_DestionationRectangle.y = i * 32;

			switch (type)
			{
				case 0: // Water
					TextureManager::Draw(m_Water, m_SourceRectangle, m_DestionationRectangle);
					break;
				case 1: // Grass
					TextureManager::Draw(m_Grass, m_SourceRectangle, m_DestionationRectangle);
					break;
				case 2: // Dirt
					TextureManager::Draw(m_Dirt, m_SourceRectangle, m_DestionationRectangle);
					break;
				default:
					break;
			}
		}
	}
}