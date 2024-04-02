#include "game.h"
#include "helper.h"

using std::string;

using std::endl;


//student Info constructor
void showStudentInformation(string name, string id, string email){
    // TODO
    std::cout << "Student Information:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Email: " << email << "\n";
}

int main()
{   /*DECLARED STUDENT INFO*/
    std::string name = "Walid Feki";
    std::string id = "s3972717";
    std::string email = "s3972717@student.rmit.edu.au.com";

    std::cout<< "Welcome to Vacuum Cleaning Game!"<<endl;
    std::cout<< "--------------------"<<endl;
    std::cout<< "1. Play Game"<<endl;
    std::cout<< "2. Show student information"<<endl;
    std::cout<< "3. Quit"<<endl;
    std::cout<<endl;

    bool running = true;
    while(running){
        std::cout<< "Please enter your choice:"<<endl;
        int choice;
        std::cin >> choice;

    if (choice == 1){
        std::cout<<"You can use the following commands to play the game:"<<endl;
        std::cout<<"load <g>"<<endl;
        std::cout<<"   g: number of the game board to load"<<endl;
        std::cout<<"init <x>,<y>,<direction>"<<endl;
        std::cout<<"   x: horizontal position of the vacuum cleaner in the room (between 0 & 9)"<<endl;
        std::cout<<"   y: vertical position of the vacuum cleaner in the room (between 0 & 9)"<<endl;
        std::cout<<"   direction: direction of the vacuum cleaner’s movement (north, east, south, west)"<<endl;
        std::cout<<endl;
        std::cout<<"forward (or f)"<<endl;
        std::cout<<"turn_left (or l)"<<endl;
        std::cout<<"turn_right (or r)"<<endl;
        std::cout<<"quit"<<endl;
    
        std::cout<<"Press enter to continue...";
            std::cin.ignore(); // Wait for the user to press Enter
            std::cin.get();
            //loads empty board
            Board emptyBoard;
            emptyBoard.displayEmptyBoard();
         std::cout<<endl;
        
       
    
        
            Game game;
            game.start();
            running = false;
    }

      
    

    
    else if(choice == 2){
        std::cout<<"-----------------------------------"<<endl;
        showStudentInformation(name,id,email);
        std::cout<<"-----------------------------------"<<endl;

    }
    else if (choice ==3){
        running = false;
    }
    else{
         // Create an instance of the Helper class
    //TODO implement the printINvalidmethod from helper
     continue;
    }
    }

    std::cout << "Good bye!\n\n";

    return EXIT_SUCCESS;
}

