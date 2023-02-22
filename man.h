#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Man {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedY;
	float speedX;
};
void respawnman(Man& man) {
	sf::Vector2f first{ 140.f, -1500.f };
	sf::Vector2f second{ 390.f, -1900.f };
	sf::Vector2f third{ 140.f, -1770.f };
	sf::Vector2f fourth{ 390.f, -2100.f };
	int choice = rand() % 4 + 1;
	if (choice == 1) { man.sprite.setPosition(first); }
	else if (choice == 2) { man.sprite.setPosition(second); }
	else if (choice == 3) { man.sprite.setPosition(third); }
	else if (choice == 4) { man.sprite.setPosition(fourth); }
}
void manInit(Man& man) {
	man.texture.loadFromFile("man.png");
	man.sprite.setTexture(man.texture);
	respawnman(man);
	man.speedY = 2.f;
	man.speedX = 0.f;
}
void manUpdate(Man& man) {
	man.sprite.move(man.speedX, man.speedY);
	if (man.sprite.getPosition().y >= WINDOW_HEIGHT + 100.f) {
		respawnman(man);
	}
}
void manDraw(sf::RenderWindow& window, const Man& man) {
	window.draw(man.sprite);
}
