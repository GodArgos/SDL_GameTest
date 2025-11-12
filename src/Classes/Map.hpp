#pragma once
#include "../Game.hpp"
class Map
{
private:
	SDL_FRect m_SourceRectangle, m_DestionationRectangle;
	SDL_Texture* m_Dirt;
	SDL_Texture* m_Grass;
	SDL_Texture* m_Water;

	int m_Map[20][25];

public:
	Map();

	~Map();

	void LoadMap(int arr[20][25]);

	void DrawMap();
};

