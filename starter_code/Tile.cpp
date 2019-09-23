#include "Tile.h"

Tile::Tile(Colour colour, Shape shape) : colour(colour), shape(shape)
    {}
Tile::Tile(const Tile& other) : colour(other.colour), shape(other.shape)
    {}
char Tile::getColour() {
    return colour;
}
int Tile::getShape() {
    return shape;
}
