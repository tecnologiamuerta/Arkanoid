#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "VideoConfig.h"
#include "Starship.h"
#include "Bullet.h"

class Arkanoid
{
public:
	Arkanoid();
	~Arkanoid();
private:
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Clock GlobalClock;
	sf::Time time;
	sf::Time GameTimeElpased;

	VideoConfig videoConfig;
	Starship starship;
	Bullet bullet, bullet2;
};

