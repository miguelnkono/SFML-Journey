#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char* argv[])
{
	RenderWindow window(VideoMode(640, 480), "Bouncing mushroom.");

	Texture mushroomTexture;
	mushroomTexture.loadFromFile("images/mushroom.jpeg");
	Sprite mushroom;
	mushroom.setTexture(mushroomTexture);
	Vector2u size = mushroomTexture.getSize();
	//mushroom.setColor(sf::Color(255, 105, 110, 200));
	mushroom.setOrigin(size.x / 2, size.y / 2);
	Vector2f increment(0.4f, 0.4f);

	int cl = 0, cl2 = 0;

	// main loop
	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
		}
		
		// update
		if((mushroom.getPosition().x + (size.x /2) > window.getSize().x && increment.x > 0) || (mushroom.getPosition().x - (size.x/2) < 0 && increment.x < 0))
		{
			// Reverse the X axis
			increment.x = -increment.x;
			cl += 50;
			cl2 += 50;
			mushroom.setColor(sf::Color(cl, 105, cl2, 255));
		}

		if((mushroom.getPosition().y + (size.y /2) > window.getSize().y && increment.y > 0) || (mushroom.getPosition().y - (size.y/2) < 0 && increment.y < 0))
		{
			// Reverse the X axis
			increment.y = -increment.y;
		}

		mushroom.setPosition(mushroom.getPosition() + increment);

		// drawings
		window.clear(Color(16, 16, 16, 255));		// Dark grey
			window.draw(mushroom);			// drawing the sprite
		window.display();
	}

	return 0;
}
