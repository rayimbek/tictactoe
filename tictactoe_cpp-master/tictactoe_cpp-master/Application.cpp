//
// Created by undefined on 26.10.2021.
//

#include <bits/stdc++.h>
#include "Application.h"
#include "Player.h"
#include "Environment.h"
using namespace std;



void Application::start() {
    cout << "Hello there\n";
    cout << "1) Play against user\n";
    cout << "2) Play against bot\n";
    cout << "3) Quit";
    int choice;
    cin >> choice;

    if(choice == 1){
        game(1);
    } else if(choice == 2){
            game(0);
    } else {
        exit(0);
    }
}

bool Application::game(bool play) {
    if(play){
        cout<<"Write the name of second user\n";
        string name;
        cin >> name;
        Player *first = new Player("Akzhol");
        Player *second = new Player(name);
        Environment game1 ;
        first->characterMove='X';
        second->characterMove ='O';
        game1.Clear();
        for(int i = 1;i <= 9; ++i){
            cout << game1;
            if(i % 2 ==1){
                cout << "Turn of first player\n";
                game1.Move(*first);
            }else{

                cout << "Turn of second player\n";
                game1.Move(*second);
            }
            if(game1.checkIfEnd() == 'X'){
                cout << first->name << " Win the game\n";
                cout << game1;

                exit(0);
            }else if(game1.checkIfEnd() == 'O'){
                cout << second->name << " Win the game\n";
                cout << game1;
                exit(0);
            }
        }
        if(!game1.checkIfEnd()){
            cout << "It is draw\n";
            cout << game1;
            exit(0);
        }

    }else{
        cout<<"Here you will play with bot\n";
        string name = "BOT";
        Player *first = new Player("Akzhol");
        Player *second = new Player(name);
        Environment game1 ;
        first->characterMove='X';
        second->characterMove ='0';
        game1.Clear();
        for(int i = 1;i <= 9; ++i){
            cout << game1;
            if(i % 2 ==1){

                cout << "Turn of first player\n";
                game1.Move(*first);
            }else{
                cout << "Turn of second player\n";
                game1.Move(*second);
            }
            if(game1.checkIfEnd() == 'X'){
                cout << first->name << " Win the game\n";
                cout << game1;
                exit(0);
            }else if(game1.checkIfEnd() == 'X'){
                cout << second->name << " Win the game\n";
                cout << game1;
                exit(0);
            }
        }
        if(!game1.checkIfEnd()){
            cout << "It is draw\n";
            cout << game1;
            exit(0);
        }
    }

}
