#include <iostream>
#include <vector>
#include "grid.h"
#ifndef ZERO
#define ZERO 0
using namespace std;

Grid::Grid(Xwindow *xw) : size{ZERO}, xw{xw} {}

Grid::~Grid() {
  theGrid.clear();
  delete xw;
}

void Grid::clearGrid() {
  theGrid.clear();
}

void Grid::init(int n) {
  clearGrid();
  size = n;
  theGrid.resize(n, vector<Cell> (n));
  // set neighbours based on current position, the neighbour
  //    must not be at a row and coloumn that is smaller than 0 or greater
  //    than the current size
  int dim = 500 / size;
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        theGrid[i][j].setCoords(j * dim, i * dim, dim, dim, xw);
      }
    }
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if ((i - 1) >= 0 && (j - 1) >= 0) {
          theGrid[i][j].addNeighbour(&theGrid[i - 1][j - 1]);
        }
        if ((i - 1) >= 0 && j >= 0 ) {
          theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
        }
        if ((i - 1) >= 0 && (j + 1) >= 0 && (j + 1) < size) {
          theGrid[i][j].addNeighbour(&theGrid[i - 1][j + 1]);
        }
        if (i >= 0 && (j - 1) >= 0) {
          theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
        }
        if (i >= 0 && (j + 1) >= 0 && (j + 1) < size) {
          theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
        }
        if ((i + 1) >= 0 && (i + 1) < size && (j - 1) >= 0) {
          theGrid[i][j].addNeighbour(&theGrid[i + 1][j - 1]);
        }
        if ((i + 1) >= 0 && (i + 1) < size && j >= 0) {
          theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
        }
        if ((i + 1) >= 0 && (i + 1) < size && (j + 1) >= 0 && (j + 1) < size) {
          theGrid[i][j].addNeighbour(&theGrid[i + 1][j + 1]);
        }
      }
    }
}

void Grid::tick() {
  // let all the cells alert their neighbours their current status
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        theGrid[i][j].alertNeighbours();
      }
   }
   // after altering neighbours, recalculate their status
   for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
         theGrid[i][j].recalculate();
       }
    }
}

void Grid::turnOn(int i, int j) {
  theGrid[j][i].setLiving();
}

ostream& operator<<(ostream &out, const Grid &g) {
  for (auto i = g.theGrid.begin(); i != g.theGrid.end(); ++i) {
      for (auto j = i->begin(); j != i->end(); ++j) {
        out << *j;
      }
      out << endl;
    }
    return out;
}

#endif
