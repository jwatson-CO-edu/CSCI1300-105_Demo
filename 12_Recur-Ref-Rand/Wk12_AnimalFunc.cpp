// g++ -std=c++11 Wk12_AnimalFunc.cpp Wk12_Animals.cpp 1300_101_helpers.cpp

#include "1300_101_helpers.h"
#include "Wk12_Animals.h"

void random_encounter_BAD( Animal a ){
    // Flip a coin to see if Animal has a good day or a bad day
    if( rand_01() <= 0.5 ){
        // Bad ending: Animal takes up to full HP damage
        double prevHP = a.get_HP();
        double aftrHP = a.take_damage(  a.get_max_HP() * rand_01()  );
        cout << "There was a great BATTLE, the " << a.get_name() << " lost " 
             << prevHP - aftrHP << " HP,\n but did it *survive*!? " << TF( a.is_alive() ) 
             << endl;
    }else{
        // Good ending: Animal takes up to full HP nutrition
        double prevHP = a.get_HP();
        double aftrHP = a.eat(  a.get_max_HP() * rand_01()  );
        cout << "There was a great FEAST, the " << a.get_name() << " gained " 
             << aftrHP - prevHP << " HP. How fortunate!" << endl;
    }
}

void random_encounter_GOOD( Animal& a ){
    // Identical to the above, with one key difference
    if( rand_01() <= 0.5 ){
        // Bad ending: Animal takes up to full HP damage
        double prevHP = a.get_HP();
        double aftrHP = a.take_damage(  a.get_max_HP() * rand_01()  );
        cout << "There was a great BATTLE, the " << a.get_name() << " lost " 
             << prevHP - aftrHP << " HP,\n but did it *survive*!? " << TF( a.is_alive() ) 
             << endl;
    }else{
        // Good ending: Animal takes up to full HP nutrition
        double prevHP = a.get_HP();
        double aftrHP = a.eat(  a.get_max_HP() * rand_01()  );
        cout << "There was a great FEAST, the " << a.get_name() << " gained " 
             << aftrHP - prevHP << " HP. How fortunate!" << endl;
    }
}

int main(){
    srand( time(NULL) ); // init random

    Animal lion( "Lion" , "Roar!" ,  60.0 , 160.0 );
    lion.take_damage( 30.0 ); // The lion starts the game in a rough spot, 30 HP
    cout << lion.get_name() << " starts with " << lion.get_HP() << " HP, and then..." 
         << endl << endl;

    random_encounter_BAD( lion );
    cout << "HP after encounter: " << lion.get_HP() << endl << endl;

    random_encounter_GOOD( lion );
    cout << "HP after encounter: " << lion.get_HP() << endl;

    return 0;
}

// g++ -std=c++11 Wk12_AnimalFunc.cpp Wk12_Animals.cpp 1300_101_helpers.cpp