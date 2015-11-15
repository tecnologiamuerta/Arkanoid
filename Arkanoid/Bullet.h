#pragma once
#include <SFML\Graphics.hpp>
#include "VideoConfig.h"
#include "Starship.h"

class Bullet : public sf::CircleShape
{
public:
	Bullet();
	Bullet(VideoConfig &videoConfig, Starship &starship);
	~Bullet();

	void Update(sf::Time &time, Starship &starship);
	void SetSpeed(float x, float y);
	void PerformSpeed(float vel);
	float GetSpeed();
private:
	float Radio;
	float BorderWidth;
	float Left, Right, Top, Bottom;
	float Velocidad;
	bool InsideMe;
	bool IsBegin;

	sf::Vector2f Speed;
	sf::Color BackgroundColor;
	sf::Color BorderColor;

	VideoConfig videoConfig;
	//Starship starShip;
};

