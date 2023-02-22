#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Can {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedY;
	float speedX;
};
void respawncan(Can& can) {
	sf::Vector2f first{ 150.f, -1450.f };
	sf::Vector2f second{ 200.f, -835.f };
	sf::Vector2f third{ 250.f, -1770.f };
	sf::Vector2f fourth{ 300.f, -500.f };
	sf::Vector2f fifth{ 300.f, -630.f };
	sf::Vector2f sixth{ 250.f, -1017.f };
	sf::Vector2f seventh{ 200.f, -1230.f };
	sf::Vector2f eighth{ 150.f, -1560.f };
	int choice = rand() % 8 + 1;
	if (choice == 1) { can.sprite.setPosition(first); }
	else if (choice == 2) { can.sprite.setPosition(second); }
	else if (choice == 3) { can.sprite.setPosition(third); }
	else if (choice == 4) { can.sprite.setPosition(fourth); }
	else if (choice == 5) { can.sprite.setPosition(fifth); }
	else if (choice == 6) { can.sprite.setPosition(sixth); }
	else if (choice == 7) { can.sprite.setPosition(seventh); }
	else if (choice == 8) { can.sprite.setPosition(eighth); }
}

void canInit(Can& can) {
	can.texture.loadFromFile("can.png");
	can.sprite.setTexture(can.texture);
	respawncan(can);
	can.speedY = 2.f;
	can.speedX = 0.f;
}
void canUpdate(Can& can) {
	can.sprite.move(can.speedX, can.speedY);
	if (can.sprite.getPosition().y >= WINDOW_HEIGHT + 100.f) {
		respawncan(can);
	}
}
void canDraw(sf::RenderWindow& window, const Can& can) {
	window.draw(can.sprite);
}