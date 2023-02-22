#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Textobj {
	sf::Text text;
	sf::Font font;
};
void TextobjInit(Textobj& textobj, std::string str, sf::Vector2f position, int font) {
	textobj.font.loadFromFile("DS-DIGIB.ttf");
	textobj.text.setFont(textobj.font);
	textobj.text.setString(str);
	textobj.text.setCharacterSize(font);
	textobj.text.setPosition(position);
	textobj.text.setFillColor(sf::Color::Cyan);
}
void TextobjUpdate(Textobj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}
void textDraw(sf::RenderWindow& window, const Textobj& textobj) {
	window.draw(textobj.text);
}