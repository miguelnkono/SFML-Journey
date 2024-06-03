#include "../include/Game.hpp"

int main(int argc, char* argv[])
{
	Game game;	// creating the our game objet
	while (!game.GetWindow()->isDone())
	{
		// game loop
		//game.HandleInput();
		game.Update();
		game.Render();
		sf::sleep(sf::seconds(0.02));		//  sleep for 0.2 seconds
		game.RestartClock();
	}
	
}