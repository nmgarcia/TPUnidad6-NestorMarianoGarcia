#include "Game.h"

Game::Game(int width, int height, string title)
{
    _window = new RenderWindow(VideoMode(width, height, 32), title);
    _position = new Vector2f(width/2, height/2);
    _initialSpeed = 1.0f;
    _currentSpeed = _initialSpeed;
    _speedIncrement = 5.0f;
    _deltaTime = 1.0f / 60.0f;
}

void Game::Go()
{
    while (_window->isOpen())
    {
        Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                _window->close();
        }

        _position->x += _currentSpeed * _deltaTime;

        if (_position->x >= _window->getSize().x)
        {
            _currentSpeed += _speedIncrement;
            _position->x = 0.0f;            
        }

        _window->clear();


        CircleShape object(25.0f);
        object.setPosition(*_position);
        object.setOrigin(object.getLocalBounds().height / 2, object.getLocalBounds().width / 2);
        object.setFillColor(Color::Blue);
        _window->draw(object);

        _window->display();
    }
}