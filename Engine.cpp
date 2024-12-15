#include "Engine.h" 
#include "Particle.h" 
#include "Matrices.h" 
#include <SFML/Graphics.hpp> 
#include <SFML/System.hpp>   
#include <iostream>          
#include <vector>            
#include <cstdlib>           
#include <ctime>             
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

Engine::Engine()
{
	m_Window.create(VideoMode::getDesktopMode(), "Particle");
}
void Engine::run()
{
	Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		input();
		update(dt);
		draw();
	}
}
void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event)) {
		if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
			m_Window.close();
		}
		
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
		{
			for (int i = 0; i < 5; i++)
			{
				int numPoints = rand() % 25 + 25;
				m_particles.emplace_back(m_Window, numPoints, Mouse::getPosition(m_Window));
			}
		}
	}
}
void Engine::update(float dt)
{
	vector<Particle>::iterator it = m_particles.begin();
	while (it != m_particles.end())
	{
		if (it->getTTL() > 0.0f)
		{
			it->update(dt);
			++it;
		}
		else
		{
			it = m_particles.erase(it);
		}
	}
}
void Engine::draw()
{
	m_Window.clear();
	for (vector<Particle>::iterator it = m_particles.begin(); it != m_particles.end(); ++it)
	{
		m_Window.draw(*it);
	}
	m_Window.display();
}
