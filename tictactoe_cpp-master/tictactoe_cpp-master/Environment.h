//
// Created by undefined on 26.10.2021.
//

#ifndef ASSIGNMENT5_ENVIRONMENT_H
#define ASSIGNMENT5_ENVIRONMENT_H

#include <ostream>
#include "Player.h"

class Environment {
public:
    friend ostream &operator<<(ostream &os, const Environment &environment);
    char table[3][3];
    int filled;
    char checkIfEnd();
    void Move(Player &player);
     void Clear();
};


#endif //ASSIGNMENT5_ENVIRONMENT_H
