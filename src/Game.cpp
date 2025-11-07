#include "Game.hpp"
#include "Classes/GameObject.hpp"

GameObject* player;

Game::Game()
	: m_IsRunning(false), m_Window(nullptr), m_Renderer(nullptr)
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

		m_Renderer = SDL_CreateRenderer(m_Window, NULL);
		if (m_Renderer)
		{
			SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		m_IsRunning = true;
	}
	else
	{
		m_IsRunning = false;

	}

	player = new GameObject("assets/sprites/playerSprite.png", m_Renderer, {100, 100});
	SDL_SetTextureScaleMode(player->GetObjectRenderer(), SDL_SCALEMODE_NEAREST);
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
	player->Update();
}

void Game::Render()
{
	SDL_RenderClear(m_Renderer);
	player->Render();
	SDL_RenderPresent(m_Renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();

	std::cout << "Game Cleaned." << std::endl;
}