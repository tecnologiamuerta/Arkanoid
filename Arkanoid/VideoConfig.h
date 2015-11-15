#pragma once
#include <SFML/Graphics.hpp>

class VideoConfig
{
public:
	unsigned int Width;
	unsigned int Height;
	unsigned int BPP;

	sf::Color BackgroundColor;
	VideoConfig();
	~VideoConfig();
};