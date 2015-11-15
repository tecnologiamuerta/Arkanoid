#include "Arkanoid.h"
#include <iostream>

Arkanoid::Arkanoid()
{
	starship = Starship(videoConfig);
	bullet = Bullet(videoConfig, starship);
	bullet2 = Bullet(videoConfig, starship);
	// Creamos la ventana
	window.create(sf::VideoMode(videoConfig.Width, videoConfig.Height, videoConfig.BPP), "Arkanoid Beta", sf::Style::Close);
	// Activa la sincronización vertical (60 fps)
	window.setVerticalSyncEnabled(true);
	// Reiniciamos el reloj almacenando el tiempo pasado
	time = clock.restart();
	GlobalClock.restart();
	// Game Loop mientras la ventana esté abierta
	while (window.isOpen())
	{
		// Reiniciamos el reloj almacenando el tiempo pasado
		time = clock.restart();
		window.clear(videoConfig.BackgroundColor);
		// Creamos un objeto evento
		sf::Event event;
		// Procesamos la pila de eventos
		while (window.pollEvent(event))
		{
			// Si el evento es de tipo Closed cerramos la ventana
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Actualizamos los elementos del  juego
		starship.Update(time);
		bullet.Update(time, starship);
		// Dibujamos los elementos del juego
		window.draw(starship);
		window.draw(bullet);
		// Actualizamos la ventana
		window.display();
		GameTimeElpased = GlobalClock.getElapsedTime();
		if (GameTimeElpased.asSeconds() > 29) {
			GameTimeElpased = GlobalClock.restart();
			bullet.PerformSpeed(50);
			float Speed = bullet.GetSpeed();
		}
	}
}

Arkanoid::~Arkanoid()
{
}