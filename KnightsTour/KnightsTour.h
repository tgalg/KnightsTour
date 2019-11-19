/**
*	@file KnightsTour.h
*	@author Tom Gallagher
*	@date 03/22/16
* @KnightsTour header file
*/
#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

#include <iostream>

using namespace std;

class KnightsTour
{
private:
  //tour
  int** board;
  //placement tracker
  bool** visited;
  int rsize;
  int csize;



public:
  /**
*  @pre none
*  @post initilizes dimensions and start location
*  @return bool
*/
  KnightsTour(int m, int n, int r, int c);
  ~KnightsTour();
  /**
*  @pre first move is made
*  @post adjust position for desired path
*  @return bool
*/
  bool Move(int m, int n, int x, int y, int cur);
  /**
*  @pre none
*  @post checks if move is safe
*  @return bool
*/
  bool isSafe(int x, int y);
  /**
*  @pre board init
*  @post prints board
*  @return board
*/
  void printBoard();




};

#endif
