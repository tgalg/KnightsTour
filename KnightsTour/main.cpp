/**
*	@file main.cpp
*	@author Tom Gallagher
*	@date 03/22/16
* @main method
*/

#include "KnightsTour.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void InvArg()     //helper method
{
  cout << "\nInvalid argument. Try running program again.\n"
  <<      "\nValid Arguments:\n"
  <<      "./prog # # # # (4 integers seperated by spaces)\n";

}

int main(int argc, char** argv)
{

  int m = std::atoi(argv[1]);
  int n = std::atoi(argv[2]);
  int Row = std::atoi(argv[3]);
  int Col = std::atoi(argv[4]);
  if(argc < 4)
  {
    InvArg();
    return 0;
  }

  if((m + n) < 10)
  {
    InvArg();
    return 0;
  }

  if(Row >= m || Col >= n)
  {
    InvArg();
    return 0;
  }

  KnightsTour* go = new KnightsTour(m, n, Row, Col);
    if(go -> Move(m, n, Row, Col, 1))
    {
      cout<< "success!\n";
      go -> printBoard();
    }
    else
    {
      cout<< "failure!\n";
      go -> printBoard();
    }


  return 0;
}
