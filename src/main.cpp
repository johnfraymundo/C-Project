#include <iostream>
#include <string>
#include <regex> 
#include <sstream>
#include <fstream>
#include <map>
#include <vector>   
#include <set>
#include <memory>


struct point {
    point() : x( 0 ), y( 0 ) {}
    point( int x, int y ) : x( x ), y( y ) {}

    point& operator+=( point const& other )
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    point& operator-=( point const& other ) 
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    int x;
    int y;
};


void parseTxT(std::string fileinput){
    std::ifstream file(fileinput);
    std::string str; 
    std::regex r("([])");
    while (std::getline(file, str)) {
        std::cout << str << "\n";
        std::cout << str.length(); 
    }
}

std::vector<char> regexPreyList(std::string str){
    std::regex r("([])");

} 

struct thing{
public:
    using thing_id = char; 
    
    thing() : id_(){}
    thing(thing_id id) : id_(id){}

    virtual ~thing() {
        std::cout << "Destroying thing";
    }

    thing_id  id() const
    {
        return id_;
    }
    
    virtual std::string type() const 
    { 
        return ""; 
    }

    virtual void write( std::ostream& ) const;

    virtual std::shared_ptr<thing> new_from_stream( std::istream& in ) const
    {
        thing_id id;
        if ( in >> id )
            return this->create( id );

        return nullptr;
    }

    virtual std::shared_ptr<thing> create( thing_id id ) const
    {
        return nullptr;
    }

    public:
    thing_id id_; 
};

struct GameMap{
    GameMap(): extent(extent), gamemap(gamemap){}

    void constructMapFromFile(){
        parseTxT("species.txt");

    }
    
    void changePosition(point current , point destination )
    {
        std::shared_ptr<thing> curr = this ->gamemap[current.x][current.y];
        std::shared_ptr<thing> dest = this ->gamemap[destination.x][destination.y]; 

        dest = std::move(curr); 
    }

    private:
    point extent; 
    std::vector<std::vector<std::shared_ptr<thing>>> gamemap;
};

struct TerrainObject : public thing{
    TerrainObject() : thing(){}
};

struct organism : public thing{
    public:
    organism(thing_id id, int energy, std::string type, point location): energy(energy), location(location), thing(id){}

    int energy; 
    point location;
    thing_id id;
    std::string type;

    virtual std::string kind() const { 
        return type; 
    }

    void move(const point& destination){
        this -> location = destination;
    }
    
    void gainEnergy(){
    }

    virtual void consume( organism& org){
        this -> energy += org.energy;
    }

};

struct plant : public organism{
    plant(char id, int energy, std::string type, point location, int regrowth, bool passable) : organism(id, energy, type, location), regrow_coeff(regrowth){}

    std::string kind() const override{
        return "plant";
    }

    std::shared_ptr<thing> create( thing_id id, int energy, std::string type, point location, int regrowth ) const 
    {
        return std::make_shared<plant>(id, energy, location, regrowth);
    }

    void gainEnergy(){
        int reg = regrow_coeff;
        while (reg != 0){
            --reg;
        }

        this -> passable = true;     
    } 

    public:
    int regrow_coeff;
    bool passable;

};

struct herbivore : public organism{
    herbivore(char id, int energy, std::string type, point location, std::vector<thing_id> prey) : organism(id, energy, type, location){} 

    std::string kind() const override{
        return "herbivore";
    }

    std::shared_ptr<thing> create( thing_id id, int energy, std::string type, point location, std::vector<thing_id> prey) const 
    {
        return std::make_shared<herbivore>(id, energy, type, location, prey);
    } 

    private:
    std::vector<thing_id> prey; 


};

struct omnivore : public organism{
    omnivore(char id, int energy, std::string type, point location, std::vector<thing_id> prey) : organism(id, energy, type, location){}
    
    std::string kind() const override{
        return "omnivore";
    }

    std::shared_ptr<thing> create( thing_id id, int energy, std::string type, point location, std::vector<thing_id> prey) const 
    {
        return std::make_shared<omnivore>(id, energy, type, location, prey);
    }  

    private:
    std::vector<thing_id> prey; 

};

struct OrganismList{
    OrganismList() : orgVector(orgVector){} 

    void addToList(std::shared_ptr<organism> org){
        this -> orgVector.push_back(org); 
    }
    void removeHelper(){
    }
    void removeFromList(point p){
        //this -> orgVector.erase(); 
    }
    public:
    std::vector<std::shared_ptr<organism>> orgVector; 
};


//Directory of all species types
struct OrganismDirectory{
    OrganismDirectory()
    {
        this -> odirectory.push_back(std::make_unique<plant>());
        this -> odirectory.push_back(std::make_unique<herbivore>());
        this -> odirectory.push_back(std::make_unique<omnivore>());
    }

    organism* find( std::string const& d ) const
    {
        for ( auto& org : this->odirectory )
            if ( org->kind() == d )
                return org.get();

        return nullptr;
    }

    void add(std::shared_ptr<organism> org){
        this -> odirectory.push_back(org); 
    }
    
    private:
    std::vector<std::shared_ptr<organism>> odirectory; 

};

void populateMap(){

}

void gameLoop(){
    //Do game stuff here 
}


/*
GAME RUNTIME ORDER::
1. Build species directory
2. Build Terrain list/directory 
3. Build game map and alive organism list using location of chars in each row
4. Run Game iteration 
4a include all organism functions 1.plants 2.animals
5. Iterate through 4 for n many iterations.  
*/ 

int main(){
    int iterations; 
    std::cout << "Welcome to the game! Please input the number of iterations you would like to do.";
    std::cin >> iterations; 
    std::cout << "You've selected: " << iterations << " many iterations, beginning!\n";
    
    parseTxT("mapinput.txt");
    parseTxT("species.txt");

    GameMap map; 
    OrganismDirectory orgd;
    OrganismList orgl; 

    int n = 0;
    while (n < iterations - 1){
        gameLoop( );
        ++n; 
    }
    //Tests Below 
}