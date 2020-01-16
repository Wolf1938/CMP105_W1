#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Green);

	circle.setRadius(50);
	circle.setPosition(sf::Vector2f(1200 / 2 - 50, 675 / 2 - 50));
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);

	for (size_t i = 0; i < 3; i++)
	{
		rects[i].setPosition(sf::Vector2f(600 - 25 * i, (675 / 2) - 25 * i));
		rects[i].setSize(sf::Vector2f(50 + 50 * i, 50 + 50 * i));
	}
	rects[0].setFillColor(sf::Color::Blue);
	rects[1].setFillColor(sf::Color::Green);
	rects[2].setFillColor(sf::Color::Red);

	font.loadFromFile("font/arial.ttf");

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.width / 2, textRect.height / 2);
	text.setPosition(sf::Vector2f(window->getSize().x / 2.0f, 0));
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	rect.setPosition(sf::Vector2f(window->getSize().x - rect.getSize().x, window->getSize().y - rect.getSize().y));
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(circle);

	for (size_t i = 3; i > 0; i--)
	{
		window->draw(rects[i - 1]);
	}

	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}