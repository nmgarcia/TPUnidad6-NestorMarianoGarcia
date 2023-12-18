#include "Game.h"

Game::Game(int height, int width, string title)
{
	_window = new RenderWindow(VideoMode(800, 600, 32), "Wild Gunman Gang");
	SetBackground();
}

void Game::Go()
{
	// Main Loop
	while (_window->isOpen())
	{
		ProcessEvent();
		ProcessCollisions();
		UpdateGame();
		
		_window->clear();
		DrawGame();		
		_window->display();
	}
}

void Game::ProcessEvent()
{
	Event evt;
	while (_window->pollEvent(evt)) {

		switch (evt.type)
		{
		case Event::Closed:
			_window->close();
			break;
		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left) {
				
			}
			break;
		}
	}
}

void Game::UpdateGame()
{
}

void Game::DrawGame()
{
	
	//Draw Scene
	_window->draw(_backgroundSprite);

	
}

void Game::SetUI()
{
}

void Game::SetBackground()
{
}

void Game::ProcessCollisions()
{
}

Game::~Game()
{
	delete _window;
}