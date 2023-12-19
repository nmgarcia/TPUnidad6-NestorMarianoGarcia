#pragma once
#include "stdafx.h"
#include <random>
#include <functional>

class Enemy{

	Texture _enemyTexture;
	Sprite _enemySprite;
	bool _isAlive;
	bool _isVisible;
	bool _isMRUV;
	float _speed;
	float _acceleration;
	Clock _clock;
	float _visibleTime;
	float _invisibleTime;
	float _deltaTime;
	Vector2f _position;

	Vector2f SetRandomPosition(int windowHeight);

public:
	
	Enemy();
	bool IsAlive();
	bool IsActive();
	bool CheckCollision(float x, float y);
	void Kill();
	void Draw(RenderWindow* window);
	void Update(RenderWindow* window);
	bool SetRandomBool();
};

