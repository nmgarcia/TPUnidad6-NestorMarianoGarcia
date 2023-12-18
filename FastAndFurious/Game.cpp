#include "Game.h"

Game::Game(int width, int height, string title)
{
    _window = new RenderWindow(VideoMode(width, height, 32), title);
    _position = new Vector2f(width/2, height/2);
    _initialSpeed = 2.0f;
    _currentSpeed = _initialSpeed;
    _speedIncrement = 2.0f;
    _deltaTime = 1.0f / 60.0f;
    _finalSpeed = 20.0f;
}

void Game::Go()
{
    while (_window->isOpen())
    {
        Event evt;
        while (_window->pollEvent(evt))
        {
            if (evt.type == Event::Closed)
                _window->close();
        }

        _position->x += _currentSpeed * _deltaTime;

       
        if (_position->x >= _window->getSize().x)
        {
            if (_currentSpeed <= _finalSpeed) {
                _currentSpeed += _speedIncrement;
            }
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