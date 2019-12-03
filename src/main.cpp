#include <iostream>
#include <string> 

struct point {
    point() : x( 0 ), y( 0 ) {}
    point( int x, int y ) : x( x ), y( y ) {}

    int x;
    int y;
};

struct GameMap{
    //comments
};

struct organismList{

};

class organism{
    organism(int energy, std::string type, point location): energy(energy), location(location), type(type){}

    public:
    int energy; 
    std::string type;
    point location; 

    void move(const point&){
    }
    
    void gainEnergy(){
    }

    void consume(){
    }

};

class plant : organism{

};

class Herbavore : organism{

};

class Omnivore : organism{

};

void gameLoop(){
    //Do game stuff here 
}

int main(){
    int iterations; 
    std::cout << "Welcome to the game! Please input the number of iterations you would like to do.";
    std::cin >> iterations; 
    std::cout << "You've selected: " << iterations << " many iterations, beginning!";

    int n = 0;
    while (n < iterations - 1){
        gameLoop( );
        ++n; 
    }
}