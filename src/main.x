#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 450), "Shape");
	window.setFramerateLimit(60);

	// Formes de bases
	//sf::CircleShape cercle(50.f);
	CircleShape triangle(80.f, 3);
	//sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));

	while(window.isOpen())
	{
		sf::Event event;
		while(window.waitEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		// update
		//rectangle.setFillColor(Color(100, 250, 150));
		//cercle.setOutlineThickness(10.f);
		//cercle.setOutlineColor(Color(250, 150, 100));

		// windows clear with a color
		window.clear(Color::Black);
			window.draw(triangle);
		// affichage du contenu
		window.display();
	}

	return 0;
}
