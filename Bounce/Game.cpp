#include "Game.h"

Game::Game(int width, int height,  string title)
{
	_window = new RenderWindow(VideoMode(width, height, 32), title);
	_position = new Vector2f(width/2, height/2);
	_velocity= new Vector2f(0.0f, 0.0f);
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

        _velocity->y += _gravity;
        *_position += *_velocity;

        if (_position->y > _window->getSize().y)
        {
            _position->y = _window->getSize().y;
            _velocity->y = -_velocity->y * _bounceFactor;
        }

        _window->clear();

        CircleShape object(20.0f);
        object.setFillColor(Color::Blue);
        object.setOrigin(object.getLocalBounds().width/2, object.getLocalBounds().height);
        object.setPosition(*_position);
        _window->draw(object);
        _window->display();
    }

    /*Event evt;
    while (_window->pollEvent(evt))
    {
        if (evt.type == Event::Closed)
            _window->close();
    }

    _velocity->y += _gravity;

    *_position += *_velocity;

    if (_position->y > 600.0f)
    {
       _position->y = 600.0f;
       _velocity->y = -_velocity->y * _bounceFactor;
    }

    _window->clear();

    CircleShape object(25.0f);
    object.setPosition(*_position);
    object.setOrigin(object.getLocalBounds().height / 2, object.getLocalBounds().width / 2);
    object.setFillColor(Color::Blue);
    _window->draw(object);

    _window->display();*/
}
