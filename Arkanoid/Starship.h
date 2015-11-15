#pragma once
#include <SFML/Graphics.hpp>
#include "VideoConfig.h"

class Starship : public sf::RectangleShape
{
public:
	Starship();
	Starship(VideoConfig &videoConfig);
	~Starship();

	void Update(sf::Time &time);
	void KeyboarEvent(sf::Time &time);

	float Left;
	float Right;
	float Top;
	float Bottom;
	float Speed;
	float BorderWidth;

private:
	VideoConfig videoConfig;

	sf::Color BackgroundColor;
	sf::Color BorderColor;
};

