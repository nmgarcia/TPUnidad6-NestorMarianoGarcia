#pragma once
#include "stdafx.h"

class Game
{
	RenderWindow* _window;
	Vector2f* _position;
	Vector2f* _velocity;
	float _deltaTime;

	float _gravity = 0.000098f;
	float _bounceFactor = 0.5f;
	
	public:
		Game(int width, int height, string title);
		void Go();
};

