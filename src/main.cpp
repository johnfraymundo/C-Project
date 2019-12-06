#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>   
#include <set>



struct point {
    point() : x( 0 ), y( 0 ) {}
    point( int x, int y ) : x( x ), y( y ) {}

    int x;
    int y;
};

class thing{
    public:
    thing() : canmove(false), passable(false), label("none"){}
    thing(bool canmove, bool passable) : canmove(canmove), passable(passable){}

    bool passable;
    bool canmove; 
    std::string label; 
};

void parseTxT(std::string input){
    std::ifstream file("input.txt");
    std::string str;
    while (std::getline(file, str)) {
        std::cout << str << "\n";
    }
}

struct GameMap{
    //comments
    //more
    GameMap(point extent, std::vector<std::vector<thing*>> vect): extent(extent), gamemap(vect){}

    public:
    point extent; 
    std::vector<std::vector<thing*>> gamemap;

    void constructMapFromFile(){
        
    }
    
    void changePosition(){

    }

};

class environmentObject : thing{
    environmentObject() : thing(false, false){}

};

class organism : thing{
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

struct OrganismList{
    OrganismList() : orgVector(){} 
    public:
    std::vector<organism> orgVector; 
};

struct OrganismDirectory{
    OrganismDirectory() : odirectory(){}
    public:
    std::set<organism> odirectory; 

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

    //Tests Below 
}