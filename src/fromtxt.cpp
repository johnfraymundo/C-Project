#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int main ()
{
  ifstream myfile ("sequence.txt");
  if (!myfile)
  {
    perror ("File error: ");
    system ("pause");
    exit (EXIT_FAILURE);
  }
  const int NUM_TRUCKS = 5;
  int id = 0, time1 = 0, time2 = 0, i = 0;
  string type;
  while (myfile >> id >> type >> time1 >> time2 && i++ < NUM_TRUCKS)
  {
    // use the input
    cout << id << '\t' << type << '\t' << time1 << '\t' << time2 << '\n';
  }

  system ("pause");
  return 0;
}