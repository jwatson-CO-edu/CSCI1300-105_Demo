/* DayAtTheZoo.cpp
 * The simplest possible simulation demonstrating classes and objects
 * CSCI 1300, 2020 Spring */

#include "Wk9_Animals.h"

int main(){

    // 0. Declare vars
    string zooName = "The Zoo!"; // `#include <string>` from "Animals.h"
    Animal zoo[5]; // NOTE: This will automatically create 5 default animals!

    // 1. Create zookeeper
    Animal zookeeper = Animal( "Human" , "Hello World!" , 40.0 , 20.0 );
    cout << endl;

    // 2. Populate the Zoo
    zoo[0] = Animal( "Wolf"     , "Howwwll!" ,  30.0 ,  80.0 );
    zoo[1] = Animal( "Owl"      , "Hoot!"    ,   7.0 ,  15.0 );
    zoo[2] = Animal( "Elephant" , "Toot!"    , 300.0 , 225.0 );
    zoo[3] = Animal( "Panda"    , "Mrrrggh!" ,  70.0 ,   5.0 );
    zoo[4] = Animal();
    cout << endl;

    // 3. Ask the zookeeper to make a sound
    zookeeper.make_sound();

    // 3. Ask all the animals in the zoo to make a sound
    for( int i = 0 ; i < 5 ; i++ ){
        zoo[i].make_sound();
    }

    // 4. Cannot access or assign to private properties
    // zookeeper.name = "Jessica"; // ERROR: member "Animal::name" is inaccessible
    // double zHP = zookeeper.HP; // ERROR: member "Animal::HP" is inaccessible

}