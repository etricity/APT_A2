#include "Player.h"

Player::Player(string name) {
    this->name = name;
    this->score = 0;
    this->hand = new LinkedList();
}

Player::~Player() {
   // clear();
}

string Player::getName() {
    return name;
}

int Player::getScore() {
    return score;
}

void Player::addToScore(int points) {
    this->score += points;
}

LinkedList * Player::getHand() {
    return hand;
}

void Player::clear() {
    
}


