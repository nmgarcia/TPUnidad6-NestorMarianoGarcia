#include "Enemy.h"
#include "stdafx.h"

Enemy::Enemy() {
	_enemyTexture.loadFromFile("et.png");
	_enemySprite.setTexture(_enemyTexture);
	_enemySprite.setScale(0.07f,0.07f);
	_isAlive = true;
	_isVisible = false;
	_visibleTime = 2.0f;
	_invisibleTime = 1.0f;
	_isMRUV = SetRandomBool();
	_acceleration = 10.0f;
	_speed = 350.0f;
	_deltaTime = 1.0f / 60.0f;
}

Vector2f Enemy::SetRandomPosition(int y)
{
	Vector2f random(0, (float)(rand() % y));
	_position = random;
	return _position;
}

bool Enemy::IsAlive() {
	return _isAlive;
}

bool Enemy::IsActive() {
	return _isAlive && _isVisible;
}

bool Enemy::CheckCollision(float x, float y) {
	FloatRect bounds = _enemySprite.getLocalBounds();
	bool check = bounds.contains(x, y);
	return check;
}

void Enemy::Kill()
{
	_isVisible = false;
	_isAlive = false;
}

void Enemy::Draw(RenderWindow* window) {
	window->draw(_enemySprite);
}

void Enemy::Update(RenderWindow* window) {
	if (!_isAlive) {
		return;
	}

	if (!IsActive()) {
		
		if (_clock.getElapsedTime().asSeconds() > _visibleTime) {
			_clock.restart();			
			_isVisible = true;
			FloatRect max = _enemySprite.getGlobalBounds();
			_enemySprite.setPosition(SetRandomPosition(window->getSize().y - (max.height / 2)));
		}
	}
	else {
		if (_clock.getElapsedTime().asSeconds() > _visibleTime) {
			_isVisible = false;
			_clock.restart();
		}
	}

	if (_isMRUV) {
		// Movimiento MRUV
		_speed += _acceleration * _deltaTime;
		_position.x += _speed * _deltaTime;
		_enemySprite.setPosition(_position);
	}
	else {
		// Movimiento MRU
		_position.x += _speed * _deltaTime;
		_enemySprite.setPosition(_position);
	}
	
}

bool Enemy::SetRandomBool() {
	static auto randomNum = bind(uniform_int_distribution<>(0, 1), default_random_engine());

	return randomNum();
}