#include <iostream>
#include <string>
#include <regex> 
#include <sstream>
#include <fstream>
#include <map>
#include <vector>   
#include <set>
#include <memory>
<<<<<<< HEAD
#include <cassert>
#include <list>
=======
#include <list>

>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e

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

    bool operator ==(point const& other)
    {
        return((x == other.x) && (y == other.y));
    }

    bool operator !=(point const& other)
    {
        return((x != other.x) || (y != other.y));
    }

    int x;
    int y;
};

<<<<<<< HEAD
void parseTxt(std::string fileinput){
=======
void altparseTxt(std::string fileinput){
>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e
    char id; 
    std::string type;
    int regrow;
    char prey; 
    int energy; 

    std::string str; 
<<<<<<< HEAD
=======

>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e
    std::ifstream myfile(fileinput);
    std::ifstream myfile2(fileinput);

    if(!myfile){
        std::cout << "Error, species.txt is not found";
        system("pause");
        exit(EXIT_FAILURE); 
    }

    while (std::getline(myfile2, str)){
<<<<<<< HEAD
       // std::cout << str << "\n"; 
=======
        std::cout << str << "\n"; 
>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e
        
        if(myfile >> type >> id >> regrow >> energy)
        {
            std::cout << type << " ";
            std::cout << id << " ";
            std::cout << regrow << " ";
            std::cout << energy << "\n";  
        }
        if (myfile >> type >> id >> energy){
<<<<<<< HEAD
            std::cout << type << " ";
            std::cout << id << " ";
            std::cout << prey << " ";
=======
            std::cout << type << "\n";
            std::cout << id << "\n";
            std::cout << prey << "\n";
>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e
            std::cout << energy << "\n";  
        }           
        else
        {
            std::cout << "INVALID FORMAT \n";
            continue;   
        }
            
    }


}
<<<<<<< HEAD
=======

>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e

void parseTxT(std::string fileinput){
    std::ifstream file(fileinput);
    std::string str; 
    std::regex reg(R"(?<=\[).+?(?=\])");
    std::smatch matches; 

    std::cout << std::boolalpha;

    while (std::getline(file, str)) {
        std::cout << str << "\n";
        
        std::regex_search(str, matches, reg); 
            std::cout << "is there a match : " << matches.ready() << "\n";
            std::cout << "Are there no matches : " <<  matches.empty() << "\n"; 
            std::cout << "Number of matches : " << matches.size() << "\n";
            std::cout << matches.str(1) << "\n";
            str = matches.suffix().str(); 
            std::cout << "\n\n\n\n";
       
        //std::cout << str << "\n";
        //std::cout << str.length(); 
    }
}

<<<<<<< HEAD
=======


/*
std::vector<char> regexPreyList(std::string str){
    std::regex r("([])");
    std::smatch matches;  

} 
*/

>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e
struct thing{
public:
    using thing_id = char; 
    
    thing() : id_(){}
    thing(thing_id id) : id_(id){}
    thing(thing_id id) : id_(id), type_(""){}
    thing(thing_id id, std::string ty) : type_(ty){}

    virtual ~thing() {
        std::cout << "Destroying thing";
    }

    thing_id  id() const
    {
        return id_;
    }
    
    virtual void write( std::ostream& ) const;

    
    std::shared_ptr<thing> thing_from_stream( std::istream& in ) const
    {
        thing_id id;
        std::string type = "terrain"; 

        if ( in >> id )
            return this->create( id );

        return nullptr;
    }

    std::shared_ptr<thing> create(thing_id id) const
    {
        return std::make_shared<thing>(id);
    }
    
    virtual std::string type() const 
    { 
        return this -> type_; 
    }

    void setID( char id ){
        this ->id_ = id; 
    } 

    public:
    thing_id id_;
    std::string type_;

};

struct GameMap{
    GameMap(): extent(extent), gamemap(gamemap){}

    void constructMapFromFile(){
        parseTxT("mapinput.txt");

    }
    
    void changePosition(point current , point destination )
    {
        std::shared_ptr<thing> curr = this ->gamemap[current.x][current.y];
        std::shared_ptr<thing> dest = this ->gamemap[destination.x][destination.y]; 

        dest = std::move(curr); 
    }

    thing& getat(point p) const{
        return this ->gamemap[p.x][p.y];
    }

    private:
    point extent; 
    std::vector<std::vector<std::shared_ptr<thing>>> gamemap;
};

struct TerrainObject : public thing{
    TerrainObject() : thing(){}

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

};

struct organism : public thing{
    public:
    organism() : thing(), energy(energy), location(location), type(type){}
    organism(thing_id id, int energy, std::string type, point location): energy(energy), location(location), thing(id){}

    int energy; 
    point location;
    std::string type;

    virtual std::shared_ptr<organism> create( std::string type, thing_id id, int energy, std::vector<char> prey) const 
    {
        assert(false); 
        return nullptr;
    } 

    virtual std::shared_ptr<organism> create( std::string type, thing_id id, int energy, std::vector<char> prey, point loction) const 
    {
        assert(false); 
        return nullptr;
    } 

    virtual std::shared_ptr<organism> new_from_stream( std::istream& in ) const 
    {
        std::string type; 
        thing_id id;
        char c;
        int energy;
        int regrowcoef; 
        std::vector<char> food_chain;


        if (in >> type){
            in >> c;  
        }

        if ( in >> id ){
            in >> c;
        }

        if(c == '['){
            in >> c;
            while (c != ']'){
                if (c != ','){
                    food_chain.push_back(c);
                }
                in >> c; 
            }
            if (in >> energy){
                return this -> create(type, id, energy, food_chain); 
            }
        }
        return nullptr;
    }

    virtual std::string kind() const { 
        return type; 
    }

    virtual void move(const point& destination){
        this -> location = destination;
    }
    
    virtual void gainEnergy(int consumed){
        this -> energy += consumed; 
    }

    virtual void consume( organism& org){
        this -> energy += org.energy;
    }

};

struct plant : public organism{
    plant() : organism(), regrow_coeff(regrow_coeff), passable(regrow_coeff) {}
    plant(char id, int energy, std::string type, point location, int regrowth, bool passable) : organism(id, energy, type, location), regrow_coeff(regrowth){}

    std::string kind() const override{
        return "plant";
    }

    std::shared_ptr<organism> create(thing_id id, int energy, std::string type, point location, int regrowth, bool passable) const 
    {
        return std::make_shared<organism>(id, energy, type, location, regrowth, passable);
    }

    std::shared_ptr<organism> create(thing_id id, int energy, std::string type, int regrowth, bool passable) const 
    {
        return std::make_shared<organism>(id, energy, type, location, regrowth, passable);
    }

    std::shared_ptr<organism> new_from_stream( std::istream& in ) const override
    {
        std::string type; 
        thing_id id;
        char c;
        int energy;
        int regrowcoef; 
        bool passable = false; 

        if (in >> type >> id >> regrowcoef >> energy){
            return this -> create(id, energy, type, location, regrowcoef, passable);
        }
        std::cout << "plant creation failed"; 
        return nullptr;
    }

    void regrow(){
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
    herbivore() : organism(), prey(prey){}
    herbivore(char id, int energy, std::string type, point location, std::vector<thing_id> prey) : organism(id, energy, type, location){} 

    std::string kind() const override{
        return "herbivore";
    }

    std::shared_ptr<organism> create( thing_id id, int energy, std::string type, point location, std::vector<thing_id> prey) const 
    {
        return std::make_shared<herbivore>(id, energy, type, location, prey);
    }

    std::shared_ptr<organism> create( thing_id id, int energy, std::string type, std::vector<thing_id> prey) const 
    {
        return std::make_shared<herbivore>(id, energy, type, location, prey);
    }

    std::shared_ptr<organism> new_from_stream( std::istream& in ) const override
    {
        std::string type; 
        thing_id id;
        char c;
        int energy;
        int regrowcoef; 
        std::vector<char> food_chain;


        if (in >> type){
            in >> c;  
        }

        if ( in >> id ){
            in >> c;
        }

        if(c == '['){
            in >> c;
            while (c != ']'){
                if (c != ','){
                    food_chain.push_back(c);
                }
                in >> c; 
            }
            if (in >> energy){
                return this -> create(id, energy, type, food_chain); 
            }
        }
        return nullptr;
    }
 
    private:
    std::vector<thing_id> prey; 

};

struct omnivore : public organism{
    omnivore() : organism(), prey(prey){}
    omnivore(char id, int energy, std::string type, point location, std::vector<thing_id> prey) : organism(id, energy, type, location){}
    
    std::string kind() const override{
        return "omnivore";
    }

    std::shared_ptr<organism> create( thing_id id, int energy, std::string type, point location, std::vector<thing_id> prey) const 
    {
        return std::make_shared<omnivore>(id, energy, type, location, prey);
    } 

    std::shared_ptr<organism> create( thing_id id, int energy, std::string type, std::vector<thing_id> prey) const 
    {
        return std::make_shared<organism>(id, energy, type, location, prey);
    }

    std::shared_ptr<organism> new_from_stream( std::istream& in ) const override
    {
        std::string type; 
        thing_id id;
        char c;
        int energy;
        int regrowcoef; 
        std::vector<char> food_chain;


        if (in >> type){
            in >> c;  
        }

        if ( in >> id ){
            in >> c;
        }

        if(c == '['){
            in >> c;
            while (c != ']'){
                if (c != ','){
                    food_chain.push_back(c);
                }
                in >> c; 
            }
            if (in >> energy){
                return this -> create(id, energy, type, food_chain); 
            }
        }
        return nullptr;
    }

    private:
    std::vector<thing_id> prey; 

};

struct OrganismList{
    OrganismList() : orgLists(orgLists){}

    void addToList(std::string type ,std::shared_ptr<organism> org){
        if(type == "plant"){
            this -> pla.push_back(org);
        }
        else if(type == "herbivore"){

        }
        else if(type == "omnivore"){

        }
        this -> orgLists[type].push_back(org); 
    }

    void removeFromList(std::shared_ptr<organism> org){
        point p = org ->location; 

        for (auto & element : this ->orgLists[org.get() -> kind()]){
            if(element ->location == p){
             //   this -> orgLists[org.get() -> kind()].erase();
            }
        }
    }
    public:
    std::vector<std::shared_ptr<organism>> pla;
    std::vector<std::shared_ptr<organism>> omni;
    std::vector<std::shared_ptr<organism>> herbi;
    std::map<std::string, std::vector<std::shared_ptr<organism>>> orgLists = { std::pair("plant", pla), std::pair("herbivore", herbi), std::pair("omnivore",omni)};

};


//Directory of all species types and their base attributes 
struct OrganismDirectory{
    OrganismDirectory() : odirectory(odirectory){}
    {
        /*
        this -> odirectory.push_back(std::make_shared<plant>());
        this -> odirectory.push_back(std::make_shared<herbivore>()
        this -> odirectory.push_back(std::make_shared<omnivore>());
        */
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
    std::vector<std::vector<std::shared_ptr<organism>>> orgdirectory;
    //std::map<std::string, std::vector<organism>> odir = {{"plant",odirector}}; 

};

void populateSpeciesDirectory(std::string filename, GameMap map, OrganismDirectory orgdir){

}

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
    
    //parseTxT("mapinput.txt");
<<<<<<< HEAD
=======

>>>>>>> a43716de7e240f6e810899d32cc37fe9c3378f9e
    //parseTxT("species.txt");
    altparseTxt("species.txt");

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