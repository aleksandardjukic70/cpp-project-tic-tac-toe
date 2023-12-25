#include <iostream>
#include "header.h"

int main()
{   
   

    // live free or die
    display_board();

    while (gameover()) {
        
        player_turn();
        gameover();
    }
    
    endgame();

}

