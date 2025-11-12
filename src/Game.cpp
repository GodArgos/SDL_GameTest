#include "Game.hpp"
#include "Classes/Map.hpp"
#include "ECS/Components.hpp"

Map* map;
SDL_Renderer* Game::Renderer = nullptr;

Manager manager;
auto& Player(manager.AddEntity());

Game::Game()
	: m_IsRunning(false), m_Window(nullptr)
{

}

Game::~Game()
{

}

void Game::Init(const char* title, int width, int height, bool fullscreen)
{
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	
	if (!(SDL_Init(SDL_INIT_VIDEO) == 0))
	{
		std::cout << "Subsytems Initialized!..." << std::endl;

		m_Window = SDL_CreateWindow(title, width, height, flags);

		if (m_Window)
		{
			std::cout << "Window Created" << std::endl;
		}

		Renderer = SDL_CreateRenderer(m_Window, NULL);
		if (Renderer)
		{
			SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		m_IsRunning = true;
	}
	else
	{
		m_IsRunning = false;

	}

	//SDL_SetTextureScaleMode(player->GetObjectRenderer(), SDL_SCALEMODE_NEAREST);
	//map = new Map();

	Player.AddComponent<PositionComponent>();
	Player.AddComponent<SpriteComponent>("assets/sprites/playerSprite.png");
	SDL_SetTextureScaleMode(Player.GetComponent<SpriteComponent>().GetTexture(), SDL_SCALEMODE_NEAREST);
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_EVENT_QUIT:
			m_IsRunning = false;
			break;
		default:
			break;
	}
}

void Game::Update()
{
	manager.Refresh();
	manager.Update();
	std::cout << Player.GetComponent<PositionComponent>().GetPosition() << std::endl;
}

void Game::Render()
{
	SDL_RenderClear(Renderer);
	//map->DrawMap();
	manager.Draw();
	SDL_RenderPresent(Renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();

	std::cout << "Game Cleaned." << std::endl;
}