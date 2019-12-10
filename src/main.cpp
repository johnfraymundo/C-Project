#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>   
#include <set>


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
    int r; 
    while (std::getline(file, str)) {
        std::cout << str << "\n";
        std::cout << str.length(); 
    }
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

    public:
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

struct TerrainObject : thing{
    TerrainObject() : thing(){}
};

struct organism : thing{
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

struct plant : organism{
    plant(char id, int energy, std::string type, point location, int regrowth, bool passable) : organism(id, energy, type, location), regrow_coeff(regrowth){}

    std::string kind() const override{
        return "plant";
    }

    std::unique_ptr<thing> create( thing_id id, int energy, std::string type, point location, int regrowth ) const 
    {
        return std::make_unique<plant>(id, energy, location, regrowth);
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

struct herbivore : organism{
    herbivore(char id, int energy, std::string type, point location, std::vector<thing_id> prey) : organism(id, energy, type, location){} 

    std::string kind() const override{
        return "herbivore";
    }

    std::unique_ptr<thing> create( thing_id id, int energy, std::string type, point location, std::vector<thing_id> prey) const 
    {
        return std::make_unique<herbivore>(id, energy, type, location, prey);
    } 

    private:
    std::vector<thing_id> prey; 


};

struct omnivore : organism{
    omnivore(char id, int energy, std::string type, point location, std::vector<thing_id> prey) : organism(id, energy, type, location){}
    
    std::string kind() const override{
        return "omnivore";
    }

    std::unique_ptr<thing> create( thing_id id, int energy, std::string type, point location, std::vector<thing_id> prey) const 
    {
        return std::make_unique<omnivore>(id, energy, type, location, prey);
    }  

    private:
    std::vector<thing_id> prey; 

};

struct OrganismList{
    OrganismList() : orgVector(orgVector){} 

    void addToList(std::unique_ptr<organism> org){
        this -> orgVector.push_back(org); 
    }
    void removeHelper(){
        int i = 0; 
        for()
    }
    void removeFromList(point p){
        this -> orgVector.erase(); 
    }
    public:
    std::vector<std::unique_ptr<organism>> orgVector; 
};

struct OrganismDirectory{
    //vector of organism templates 
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
    

    private:
    std::vector<std::unique_ptr<organism>> odirectory; 

};

void gameLoop(){
    //Do game stuff here 
}

int main(){
    int iterations; 
    std::cout << "Welcome to the game! Please input the number of iterations you would like to do.";
    std::cin >> iterations; 
    std::cout << "You've selected: " << iterations << " many iterations, beginning!\n";
    
    parseTxT("mapinput.txt");
    parseTxT("species.txt");
    int n = 0;
    while (n < iterations - 1){
        gameLoop( );
        ++n; 
    }
    //Tests Below 
}