#include "board.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    // TODO
    board = new std::vector<std::vector<Cell>>(DEFAULT_BOARD_DIMENSION, std::vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));


}

Board::~Board()
{
    // TODO
    delete board;
}

void Board::load(int boardId)
{
    // TODO
    bool loaded = false;
    while (loaded == false){
    if (boardId == 1) {
        *board = BOARD_1;
        loaded = true;
    } else if (boardId == 2) {
        *board = BOARD_2;
        loaded = true;
    }
    else{
        Helper::printInvalidInput();
        loaded = false;
    }
    }
}




bool Board::placePlayer(Position position)
{
    // TODO

    bool pos = true;
    // Check if the provided position is within the bounds of the board
    if (position.x < 0 || position.x >= DEFAULT_BOARD_DIMENSION || position.y < 0 || position.y >= DEFAULT_BOARD_DIMENSION) {
        pos = false; // Position is outside the bounds of the board
    }

    // Check if the cell at the provided position is BLOCKED
    else if ((*board)[position.y][position.x] == BLOCKED) {
        pos= false; // Cannot place the player on a BLOCKED cell
    }

    else{// Update the cell at the provided position to contain the PLAYER cell
    (*board)[position.y][position.x] = PLAYER;
    }

    return pos; // Player successfully placed on the board
}


PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    {
    // Get the next position the player will move to
    Position nextPosition = player->getNextForwardPosition();

    // Determine the player move based on the conditions
    PlayerMove moveResult;

    // Check if the new position is outside the bounds of the board
    if (nextPosition.x < 0 || nextPosition.x >= DEFAULT_BOARD_DIMENSION || nextPosition.y < 0 || nextPosition.y >= DEFAULT_BOARD_DIMENSION) {
        moveResult = OUTSIDE_BOUNDS;
    }
    // Check if the cell at the new position is BLOCKED
    else if ((*board)[nextPosition.y][nextPosition.x] == BLOCKED) {
        moveResult = CELL_BLOCKED;
    }
    else {
        // Update the board cell at the current player position to EMPTY
        (*board)[player->position.y][player->position.x] = EMPTY;

        // Update the board cell at the new position to PLAYER
        (*board)[nextPosition.y][nextPosition.x] = PLAYER;

        // Update the player's position
        player->updatePosition(nextPosition);

        // Set the move result to PLAYER_MOVED
        moveResult = PLAYER_MOVED;
    }

    // Return the move result
    return moveResult;
}
    
}

    void Board::display(Player* player)
{
    // TODO
     // Display column indices


     if (player == nullptr) {
        std::cout << "Error: Invalid player pointer\n";
        
    }
    else if (!placePlayer(player->position)) {
        std::cout << "Error: Failed to place player on the board TRY AGAIN\n";
        return;
    }
    else{
    std::cout << " "<< LINE_OUTPUT;
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
        std::cout << i << LINE_OUTPUT;
    }
    std::cout << "\n";

    // Display board rows
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
        std::cout << i << LINE_OUTPUT;
        for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j) {
            // Check if the current cell is the player's position
            if (i == player->position.y && j == player->position.x) {
                // Display the player's direction arrow
                player->displayDirection();
            } else {

                //Board states is displayed depending on state
                if ((*board)[i][j] == EMPTY) {
                    std::cout << EMPTY_OUTPUT;
                } else if ((*board)[i][j] == BLOCKED) {
                    std::cout << BLOCKED_OUTPUT;
                }
            }
            std::cout << LINE_OUTPUT;

            }
            //std::cout << LINE_OUTPUT;
            std::cout << "\n";

        }
        std::cout << "\n";
    }
    }


void Board::displayEmptyBoard() {
    // Display column indices
    std::cout << " " << LINE_OUTPUT;
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
        std::cout << i << LINE_OUTPUT;
    }
    std::cout << "\n";

    // Display board rows
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
        std::cout << i << LINE_OUTPUT;
        for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j) {
            // Display empty cell
            std::cout << EMPTY_OUTPUT;
            std::cout << LINE_OUTPUT;

        }
        std::cout << "\n";

    }
}

void Board::display2(Player* player)
{
    // TODO
     // Display column indices


     if (player == nullptr) {
        std::cout << "Error: Invalid player pointer\n";
        return;
    }
    else{
    std::cout << " "<< LINE_OUTPUT;
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
        std::cout << i << LINE_OUTPUT;
    }
    std::cout << "\n";

    // Display board rows
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
        std::cout << i << LINE_OUTPUT;
        for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j) {
            // Check if the current cell is the player's position
             

                //Board states is displayed depending on state
                if ((*board)[i][j] == EMPTY) {
                    std::cout << EMPTY_OUTPUT;
                } else if ((*board)[i][j] == BLOCKED) {
                    std::cout << BLOCKED_OUTPUT;
                }
            
            std::cout << LINE_OUTPUT;

            }
            //std::cout << LINE_OUTPUT;
            std::cout << "\n";

        }
        std::cout << "\n";
    }
    }



