#include "Game.h"

Game::Game(int width, int height, string title)
{
	_window = new RenderWindow(VideoMode(width, height, 32), title);
    _position = new Vector2f(width / 2, height / 2);
    _velocity = new Vector2f(0.0f, 0.0f);
	_deltaTime = 1.0f / 60.0f;
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

            if (evt.type == Event::KeyPressed)
            {
                if (evt.key.code == Keyboard::Left)
                {
                    _velocity->x -= _acceleration * _deltaTime;
                }
                else if (evt.key.code == Keyboard::Right)
                {
                    _velocity->x += _acceleration * _deltaTime;
                }
            }
            else if (evt.type == Event::KeyReleased)
            {
                if (evt.key.code == Keyboard::Left || evt.key.code == Keyboard::Right)
                {
                    _velocity->x = 0;
                }
            }
        }  

        *_position+= *_velocity * _deltaTime;

        if (_position->x > _window->getSize().x)
            _position->x = 0.0f;
        else if (_position->x < 0.0f)
            _position->x = _window->getSize().x;


        _window->clear();


        CircleShape object(25.0f);
        object.setPosition(*_position);
        object.setOrigin(object.getLocalBounds().height / 2, object.getLocalBounds().width / 2);
        object.setFillColor(Color::Red);
        _window->draw(object);

        _window->display();
    }
}

