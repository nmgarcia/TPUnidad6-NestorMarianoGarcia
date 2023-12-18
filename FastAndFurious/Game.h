#pragma once
#include "stdafx.h"

class Game
{
	RenderWindow* _window;
	Vector2f* _position;
	float _initialSpeed;
	float _currentSpeed;
	float _speedIncrement;
	float _deltaTime;

	public:
		Game(int height, int width, string title);
		void Go();
};

