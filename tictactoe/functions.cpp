#include <iostream>

// NIZ ZA TABLU
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

int choise;
int row, column;
char turn = 'X';
bool draw = false;

void display_board() {

    std::cout << "   |   |   \n";
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    std::cout << "___|___|___\n";
    std::cout << "   |   |   \n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    std::cout << "___|___|___\n";
    std::cout << "   |   |   \n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    std::cout << "   |   |   \n";

}

void player_turn() {


    if (turn == 'X') {
        std::cout << "Player - 1 [X] turn : \n";
    }
    else if (turn == 'O') {
        std::cout << "Player - 2 [O] turn : \n";
    }

    std::cin >> choise;

    switch (choise) {
    
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;

    default: std::cout << "Bad input, try again.\n";
        break;

    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        std::cout << "Box is already filled !\n Please choose another! \n";
        player_turn();
    }

    display_board();
}

bool gameover() {
    
    for (int i = 0; i < 3; i++) {

        

        // PROVERA POBEDE VERTIKALNO I HORIZONTALNO
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }

        // PROVERA POBEDE DIJAGONALNO
        else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return false;
        } 

        else {
            // PROVERITI OVAJ DEO KODA
            for (int j = 0; j < 3; j++) {

                if (board[i][j] != 'X' && board[i][j] != 'O') {

                    return true;
             
                }
             }
           
        }
    }

}

void endgame() {

if (turn == 'X' && draw == false){
        std::cout<<"Congratulations!Player with 'O' has won the game";
        display_board();
    }
    else if(turn == 'O' && draw == false){
        std::cout<<"Congratulations!Player with 'X' has won the game";
    }
    else {
    std::cout << "GAME DRAW!!!";
}
} 
