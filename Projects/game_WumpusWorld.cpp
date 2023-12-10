#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// returns a random number for the upper and lower bounds provided
int generate_random_number(int lowerBound, int upperBound){
    // srand(time(0));
    return (rand()%(upperBound - lowerBound + 1) + lowerBound);

    // srand(time(0));
    // for (int i=0; i<100; i++)
    // cout<<(rand()%4 + 0)<<" ";
}

// position constraints
int check_position_validity(int value_x, int value_y, int invalid[][2], int size){
    if (size==0){
        return 1;
    }
    // cheking for each position that are already occupied by --> player, wumpus, pits
    for (int i=0; i<size; i++){
        if (invalid[i][0] == value_x && invalid[i][1] == value_y){
            return 0;
        }
    }
    return 1;
}

typedef struct {
    int sensonrs[5]; // stench, breeze, glitter, bump, scream --> 0 or 1
    int exists[3]; // empty, wumpus, pit, player --> 0 or 1
} Cell;

typedef struct {
    int arrowsLeft; // 0 or 1
    int direction[4]; // left, top, right, down --> 3 zeroes and one 1
} Player;

int main(){
    // variables and other...
    srand(time(0));
    int world_count_pits = 3;
    int world_count_wumpus = 1;
    int world_count_player = 1; // single player game
    int world_parameters_x = 4; 
    int world_parameters_y = 4;
    int world [world_parameters_x][world_parameters_y] ;
    int positions_wumpus_x, positions_wumpus_y;
    int positions_player_x=0, positions_player_y=0;
    int world_count_all = world_count_player + world_count_wumpus + world_count_pits;
    int world_positions_occupied [world_count_all][2];

    // generates random positions for wumpus and the pits
    while (1){
        positions_wumpus_x = generate_random_number(0, world_parameters_x);
        positions_wumpus_y = generate_random_number(0, world_parameters_y);
        int position_status = check_position_validity (positions_wumpus_x, positions_wumpus_y, world_positions_occupied, world_count_all);
        if (position_status == 1) {
            break;
        }
    }
    for (int i=0; i<100; i++)
        cout <<" "<<generate_random_number(0,3);
}