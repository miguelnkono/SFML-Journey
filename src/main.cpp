#include "../include/Game.hpp"

int main(int argc, char* argv[])
{
	Game game;	// creating the our game objet
	while (!game.GetWindow()->isDone())
	{
		// game loop
		game.HandleInput();
		game.Update();
		game.Render();
	}
	
}