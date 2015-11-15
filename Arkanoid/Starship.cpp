#include "Starship.h"

Starship::Starship() {
}

Starship::Starship(VideoConfig &videoConfig) : sf::RectangleShape()
{
	this->videoConfig = videoConfig;
	Speed = 600.0;
	BorderWidth = -2;
	BackgroundColor = sf::Color(255,255,255);
	BorderColor = sf::Color(0,0,0);

	setSize(sf::Vector2f(100, 18));
	setOrigin(50, 9);
	setFillColor(BackgroundColor);
	setOutlineColor(BorderColor);
	setOutlineThickness(BorderWidth);

	setPosition(videoConfig.Width / 2, videoConfig.Height - 40);
}

void Starship::Update(sf::Time &time) {
	sf::FloatRect Bounds = getGlobalBounds();
	Top = Bounds.top;
	Bottom = Bounds.top - Bounds.height;
	Left = Bounds.left;
	Right = Bounds.left + Bounds.width;

	KeyboarEvent(time);
}

void Starship::KeyboarEvent(sf::Time &time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Left > 0) {
		move(-time.asSeconds() * Speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Right < videoConfig.Width) {
		move(time.asSeconds() * Speed, 0);
	}
}

Starship::~Starship()
{
}