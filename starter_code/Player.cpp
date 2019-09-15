#include "Player.h"

Player::Player(string name, string studentId) {
    this->name = name;
    this->studentId = studentId;
    this->email = studentId + "@student.rmit.edu.au";
}

Player::~Player() {
   // clear();
}

string Player::getName() {
    return name;
}

string Player::getStudentId() {
    return studentId;
}

string Player::getEmail() {
    return email;
}

LinkedList Player::getHand() {
    return hand;
}

void Player::clear() {
    
}


