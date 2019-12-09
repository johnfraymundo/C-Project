#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class to define the properties
class Contestant {
public:
// Instance variables
char Name[50] = {};
int Age, Ratings;
Contestant() {};
~Contestant() {};
// Function declaration of input() to input info
int input();
void setName(std::string in);
// Function declaration of output_highest_rated() to
// extract info from file Data Base
int output_highest_rated();
};
void Contestant::setName(std::string in) {
memset(Name, 0, sizeof(Name));
if (in.size() < 50) {
memcpy(Name, in.c_str(), in.size());
}
else {
memcpy(Name, in.c_str(), sizeof(Name) -1);
}

}
// Function definition of input() to input info
int Contestant::input()
{
// Object to write in file
ofstream file_obj;

// Opening file in append mode
file_obj.open("Input.txt", ios::app);

// Object of class contestant to input data in file
Contestant obj;

// Feeding appropriate data in variables
string str = "Micheal";
int age = 18, ratings = 2500;

// Assigning data into object
obj.setName(str);
obj.Age = age;
obj.Ratings = ratings;

// Writing the object's data in file
file_obj.write((char*)&obj, sizeof(obj));

// Feeding appropriate data in variables
str = "Terry";
age = 21;
ratings = 3200;

// Assigning data into object
obj.setName(str);
obj.Age = age;
obj.Ratings = ratings;

// Writing the object's data in file
file_obj.write((char*)&obj, sizeof(obj));

return 0;
}

// Function definition of output_highest_rated() to
// extract info from file Data Base
int Contestant::output_highest_rated()
{
// Object to read from file
ifstream file_obj;

// Opening file in input mode
file_obj.open("Input.txt", ios::in);

// Object of class contestant to input data in file

// max to store maximum ratings
int max = 0;

// Highest_rated stores the name of highest rated contestant
string Highest_rated;
bool keeplooping = true;
// Checking till we have the feed
while (keeplooping) {
Contestant obj;

// Reading from file into object "obj"
file_obj.read((char*)&obj, sizeof(obj));
if (!file_obj.eof()) {
// Assigning max ratings
if (obj.Ratings > max) {
max = obj.Ratings;
Highest_rated = obj.Name;
}
}
else {
keeplooping = false;
}
}

// Output is the highest rated contestant
std::cout << Highest_rated;
return 0;
}

// Driver code
int main()
{
// Creating object of the class
Contestant object;

// Inputting the data
object.input();

// Extracting the max rated contestant
object.output_highest_rated();

return 0;
}