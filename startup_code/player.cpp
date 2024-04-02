#include "player.h"

Position::Position() : x(0), y(0) {
    // Default constructor initializes x and y to 0
}

Position::Position(int x, int y) : x(x), y(y) {
    // Constructor initializes x and y with provided values
}

Player::Player() : moves(0) {
    // Constructor initializes moves to 0
}


void Player::initialisePlayer(Position* position, Direction direction)
{
    //TODO
    this->position = *position;
    this->direction = direction;
    this->moves = 0;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO

    
        if (direction ==NORTH){
            direction = (turnDirection == TURN_LEFT) ? WEST : EAST;

        }
        else if (direction == EAST){
            direction = (turnDirection == TURN_LEFT) ? NORTH : SOUTH;

        }
        else if (direction == SOUTH){
            direction = (turnDirection == TURN_LEFT) ? EAST : WEST;

        }
        else if (direction == WEST){
            direction = (turnDirection == TURN_LEFT) ? SOUTH : NORTH;

        }
    

}

Position Player::getNextForwardPosition()
{
    //TODO
    Position nextPosition = position;
    bool Dir = true;
    while(Dir){
        if (direction ==NORTH){
            nextPosition.y--;
            Dir = false;

        }
        else if (direction == EAST){
            nextPosition.x++;
            Dir = false;

        }
        else if (direction == SOUTH){
            nextPosition.y++;
            Dir = false;

        }
        else if (direction == WEST){
            nextPosition.x--;
            Dir = false;

        }
    }

    return nextPosition;

    // return this->position;
}

void Player::updatePosition(Position position)
{
    //TODO
    this->position = position;

}

void Player::displayDirection()
{
//TODO
bool Dir = true;
    while(Dir){
        if (direction ==NORTH){
            std::cout << DIRECTION_ARROW_OUTPUT_NORTH;
            Dir = false;

        }
        else if (direction == EAST){
            std::cout<< DIRECTION_ARROW_OUTPUT_EAST;
            Dir = false;

        }
        else if (direction == SOUTH){
            std::cout<< DIRECTION_ARROW_OUTPUT_SOUTH;
            Dir = false;

        }
        else if (direction == WEST){
            std::cout<< DIRECTION_ARROW_OUTPUT_WEST;
            Dir = false;

        }
    }




    
}
