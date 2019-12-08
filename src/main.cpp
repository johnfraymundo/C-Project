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


void parseTxT(std::string fileinput){
    std::ifstream file(fileinput);
    std::string str; 
    int r; 
    while (std::getline(file, str)) {
        std::cout << str << "\n";
        std::cout << str.size(); 
    }
}

class thing{
public:
    using thing_id = char; 
    
    thing(thing_id id) : id_(id){}
    virtual ~thing() {}

    thing_id  id() const
    {
        return id_;
    }
    
    virtual std::string type() const 
    { 
        return ""; 
    }

    virtual void write( std::ostream& ) const;

    virtual std::unique_ptr<thing> new_from_stream( std::istream& in ) const
    {
        thing_id id;
        if ( in >> id )
            return this->create( id );

        return nullptr;
    }

    virtual std::unique_ptr<thing> create( thing_id id ) const
    {
        return nullptr;
    }

    thing_id id_; 
};

struct GameMap{
    GameMap(): extent(extent), gamemap(gamemap){}


    void constructMapFromFile(){
    }
    
    void changePosition(){
    }

    private:
    point extent; 
    std::vector<std::vector<thing*>> gamemap;
};

class TerrainObject : thing{
    TerrainObject() : thing('t'){}
    
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
    
    parseTxT("mapinput.txt");
    parseTxT("species.txt");
    int n = 0;
    while (n < iterations - 1){
        gameLoop( );
        ++n; 
    }
    //Tests Below 
}