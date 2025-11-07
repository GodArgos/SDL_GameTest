#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

class Game
{
	private:
		bool m_IsRunning;
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
	public:
		Game();
	
		~Game();

		void Init(const char* title, int width, int height, bool fullscreen);

		void HandleEvents();
	
		void Update();

		void Render();

		void Clean();

		bool IsRunning() const { return m_IsRunning; }
};