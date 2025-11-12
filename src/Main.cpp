#include "Game.hpp";

Game* game = nullptr;

int main(int arg, const char* argv[])
{
	const unsigned int FPS = { 60 };
	const unsigned int frameDelay { 1000 / FPS };
	
	Uint32 frameStart;
	int frameTime; // Time in ms that took n loop (handle, update, render, etc)
	
	game = new Game();
	game->Init("Title", 800, 640, false);

	while (game->IsRunning())
	{
		frameStart = SDL_GetTicks();
		
		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameDelay;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Clean();

	return 0;
}