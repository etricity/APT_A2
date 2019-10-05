#include "Tile.h"

Tile::Tile(Colour colour, Shape shape) : colour(colour), shape(shape)
    {}
Tile::Tile(const Tile& other) : colour(other.colour), shape(other.shape)
    {}

Tile::~Tile() {
}

Colour Tile::getColour() {
    return colour;
}
Shape Tile::getShape() {
    return shape;
}
