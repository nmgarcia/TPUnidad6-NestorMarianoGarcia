#pragma once
#include "stdafx.h"

class Game{

	RenderWindow* _window;
	float _deltaTime;
	Vector2f* _position;
	Vector2f* _velocity;
	float _acceleration = 5.0f;
	
	public:
		Game(int height, int width, string title);
		void Go();
};

