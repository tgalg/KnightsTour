/**
*	@file KnightsTour.cpp
*	@author Tom Gallagher
*	@date 03/22/16
* @KnightsTour implementation
*/
#include "KnightsTour.h"

const int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
const int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

KnightsTour::KnightsTour(int m, int n, int r, int c)
{
  rsize = m;
  csize = n;

  board = new int*[m];

  for(int i = 0; i < m; i++)
  {
    board[i] = new int[n];
  }


  visited = new bool*[m];
  for(int i = 0; i < m; i++)
  {
    visited[i] = new bool[n];
  }

  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      visited[i][j] = false;
    }
  }
  board[r][c] = 0;
  visited[r][c] = true;

}

KnightsTour::~KnightsTour()
{

}

bool KnightsTour::isSafe(int x, int y)
{
  if((x < 0) || (x >= rsize) || (y < 0) || (y >= csize))
  {
    return false;
  }
  else if(visited[x][y])
  {
    return false;
  }
  else
  {
    return true;
  }
}


bool KnightsTour::Move(int m, int n, int x, int y, int cur)
{


  if(cur == m*n)
  {
    return true;
  }
  else
  {

    for(int i = 0; i < 8; i++)
    {
      if(isSafe(x+xMove[i], y+yMove[i]))
      {
        x = x+xMove[i];
        y = y+yMove[i];
        board[x][y] = cur;
        visited[x][y] = true;
        if(Move(m, n, x, y, cur+1))
        {
          return true;
        }
        else
        {
          visited[x][y] = false;
          x = x-xMove[i];
          y = y-yMove[i];
        }
      }

    }
  }

return false;
}

void KnightsTour::printBoard()
{
    for(int i = 0; i < rsize; i++)
    {
      for(int j = 0; j < csize; j++)
      {
        cout<< "[";
        if(board[i][j] < 10)
        {
          cout<< " ";
        }
        cout << board[i][j] << "] ";
      }
      cout<< "\n";
    }
}
