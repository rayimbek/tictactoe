//
// Created by undefined on 26.10.2021.
//

#include "Environment.h"

char Environment::checkIfEnd() {
    if (table[0][0] == table[0][1] && table[0][1] == table[0][2] && (table[0][1] == 'X' || table[0][1] == 'O')) return table[0][1];

        if(table[1][0] == table[1][1] && table[1][1] == table[1][2] && (table[1][1] == 'X' || table[1][1] == 'O')) return table[1][1];
    if(table[2][0] == table[2][1] && table[2][1]== table[2][2] && (table[2][1] == 'X' || table[2][1] == 'O')) return table[2][1];

    if(table[0][0] == table[1][0] && table[1][0] == table[2][0] && (table[0][0] == 'X' || table[0][0] == 'O')) return table[0][0];
    if(table[0][1] == table[1][1] && table[1][1] == table[2][1] && (table[0][1] == 'X' || table[0][1] == 'O')) return table[0][1];
    if(table[0][2] == table[1][2] && table[1][2] ==  table[2][2] && (table[0][2] == 'X' || table[0][2] == 'O')) return table[0][2];


    if(table[0][0] == table[1][1] && table[1][1] == table[2][2] && (table[0][0] == 'X' || table[0][0] == 'O')) return table[0][0];
    if(table[2][0] == table[1][1] && table[1][1] == table[0][2] && (table[1][1] == 'X' || table[1][1] == 'O')) return table[1][1];

    return false;
}

void Environment::Clear() {
    filled = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            table[i][j]='*';
        }
    }
}

ostream &operator<<(ostream &os, const Environment &environment) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            os << environment.table[i][j] << " ";
        }
        cout << "\n";
    }
    return os;
}

void Environment::Move(Player &player) {
    int x, y;
    if (player.name == "BOT") {
        bool d =0;
        while(!d){
            x = rand()%3;
            y = rand()%3;
            if(table[x][y] == '*'){
                d = 1;
            }
        }
        table[x][y] = player.characterMove;
    } else {
        cout << "Choose the row and column\n";
        bool d =0;
        while(!d){
            cin >> x >> y;
            if(table[x][y] == '*'){
                d = 1;
            }else{
                cout << "Choose another\n";
            }
        }
        table[x][y] = player.characterMove;
    }

}

