#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

class Level{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;

	sf::RectangleShape rect;
	sf::CircleShape circle;
	sf::RectangleShape rects[3];

	sf::Font font;
	sf::Text text;
};