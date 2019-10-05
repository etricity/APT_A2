#ifndef TILE_H
#define TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:
    Tile(Colour colour, Shape shape);
    Tile(const Tile& tile);
    ~Tile();
    
    Colour getColour();
    Shape getShape();
    
private:
    Colour colour;
    Shape shape;
};

#endif //TILE_H
