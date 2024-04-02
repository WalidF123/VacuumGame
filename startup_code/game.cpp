#include "game.h"
using std::string;

using std::endl;

// Game::Game()
// {
//     // TODO
// }
// Game::Game() : board(), player() {
//     // Additional initialization if needed
// }
Game::Game() : board(new Board()), player(new Player()) {
    // Additional initialization if needed
}
Game::~Game()
{
    // TODO
    delete board;
    delete player;
}


void Game::start()
{
    //TODO
    if (loadBoard()) { // Attempt to load the board
        if (initializePlayer()) { // Attempt to initialize the player
             // Start the game
                play();

        } else {
            std::cout << "Failed to initialize player. Exiting the game.\n";
        }
    } else {
        std::cout << "Failed to load the board. Exiting the game.\n";
    }
}




//FINISHED
bool Game::loadBoard()
{
    
    //looped incase user inputs incorrect input will ask him to input again
    bool loaded = false;
    while (!loaded) {
        //commands
        std::cout<<"At this stage of the program, only two commands are acceptable:"<<endl;
        std::cout<<"load <g>"<<endl;
        std::cout<<"quit"<<endl;

        //Using helper function to ask for input
        std::string input = Helper::readInput();
        std::vector<std::string> tokens;
        Helper::splitString(input, tokens," ");

        if (tokens.size() != 2 || tokens[0] != "load" || (tokens[1] != "1" && tokens[1] != "2")) {
        // Display error message for invalid input format
        std::cout << "Invalid input format. Please enter 'load <g>' where <g> is either 1 or 2." << std::endl;
        }
        else if (tokens[0] == "quit"){
            loaded = false;
        }

        else{
            std::string command = tokens[0]; // Extract the command part
            std::string numberToken = tokens[1]; // Extract the number part
            // Convert the number token to an integer
            int number = std::stoi(numberToken);
            int boardId = number;
            // Call the load function of the Board class with the desired board ID
            board->load(boardId);
            loaded = true;
            board->display2(player);
           
    }    
    // Check if the entered board ID is valid
}
    return loaded;
}






bool Game::initializePlayer()
{
    bool init = false;
    
    while (!init){
            board->display2(player);
    std::cout<<"At this stage of the program, only three commands are acceptable:"<<endl;
    std::cout<<"load <g>"<<endl;
    std::cout<<"init <x>,<y>,<direction>"<<endl;
    std::cout<<"quit"<<endl;
    //TODO
    std::string command = Helper::readInput();


    if (command.substr(0, 4) == "init") { // Check if the command starts with "init3"
        // Extracting parameters from the command
        std::string params = command.substr(5); // Remove "init "
    std::vector<std::string> tokens;
    Helper::splitString(params, tokens,",");
        if (tokens.size() == 3) {
            std::string directionStr = tokens[2];
            // Convert direction string to Direction enum
            Direction initialDirection;
            if (directionStr == "east") {
                initialDirection = EAST;
                init = true;
            } else if (directionStr == "west") {
                initialDirection = WEST;
                init = true;
            } else if (directionStr == "north") {
                initialDirection = NORTH;
                init = true;
            } else if (directionStr == "south") {
                initialDirection = SOUTH;
                init = true;
            } else {
                std::cout << "Invalid direction. Permitted directions = [east,west,north,south]" << std::endl;
            }
            int x, y;
            bool conversionError = true; // Flag to track conversion errors

            try {
                x = std::stoi(tokens[0]);
                y = std::stoi(tokens[1]);
            } catch (const std::invalid_argument&) {
                conversionError = false;
            }
           if (init && conversionError) {
                // Initialize player with extracted parameters
                Position initialPosition(x, y);
                player->initialisePlayer(&initialPosition, initialDirection);
                board->display(player);

            }
             else if(!conversionError) {
            std::cout << "Invalid types. init (coordintate),(coordinate),(direction)" << std::endl;
            init = false;
            }
            else {
                init = false;
            }
            
            }


            // Initialize player with extracted parameters
            
        
        else {
            std::cout << "Invalid number of parameters. Please use the format: init <x>,<y>,<direction>\n" << std::endl;
            
        }
    }
    
    else if (command.substr(0, 4) == "quit"){
        init = true;
    }
    else{
        std::cout << "Invalid Input. Please use the format: init <x>,<y>,<direction>\n\n" << std::endl;
    }
    }
    return init; // feel free to revise this line.
}

void Game::play()
{
    //TODO
    bool gameOver = false;

    while (!gameOver) {
        
        std::cout<<"\nAt this stage of the program, only four commands are acceptable:"<<endl;
        std::cout<<"forward (or f)"<<endl;
        std::cout<<"turn_left (or l)"<<endl;
        std::cout<<"turn_right (or r)"<<endl;
        std::cout<<"quit"<<endl;

        std::string command = Helper::readInput();

        //case 1 command = forward
        if (command == "forward" || command == "f") {
            PlayerMove moveResult = board->movePlayerForward(player);
            if (moveResult == PLAYER_MOVED) {
                board->display(player);     }
            else if (moveResult == CELL_BLOCKED) {
                std::cout << "Unable to move cell is blocked.\n" << std::endl;
                board->display(player);}     
            else if (moveResult == OUTSIDE_BOUNDS) {
                std::cout << "Unable to move outside bounds.\n" << std::endl;
                board->display(player);}
            else {
                std::cout << "Invalid Input\n" << std::endl;
                board->display(player);
            }
        } 
        else if (command == "turn_left" || command == "l") {
            player->turnDirection(TURN_LEFT);
            board->display(player);

        } 
        else if (command == "turn_right" || command == "r") {
            player->turnDirection(TURN_RIGHT);
                            board->display(player);     
        }
         else if (command == "quit") {
            gameOver = true;
        } else {
            std::cout << "Invalid command. Please enter one of the valid commands." << std::endl;
        }
        


        


    }


        
 
}