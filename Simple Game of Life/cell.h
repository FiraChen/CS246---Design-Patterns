#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "window.h"

const int maxNeighbours = 8;

class Cell {
  bool isAlive;
  int numNeighbours;
  int aliveNeighbours; // store the number of neighbours that are alive
  Cell *neighbours[maxNeighbours];
  int xCor;
  int yCor;
  int width;
  int height;
  Xwindow *xw;

 public:
  Cell();  // Default constructor
  ~Cell(); // Destructor

  void setLiving();         // Explicitly sets me to living.

  void addNeighbour(Cell *neighbour);  // Adds a pointer to one of my
                            // neighbours to my array.

  void neighbourIsAlive();  // My neighbours will call this, to let me know
                            // they're alive.

  void alertNeighbours();   // Tell all of my neighbours that I am alive
                            // (if I'm alive).

  void recalculate();       // Reassess my living-or-dead status, based on
                            // info from neighbours.

  void setCoords(int x, int y, int w, int h, Xwindow *window); //setCoords set the cell's x, y
                                              //  coordinates and its width and height

  void draw();

  void undraw();

  friend std::ostream& operator<<(std::ostream &out, const Cell &c);
};

std::ostream& operator<<(std::ostream &out, const Cell &c);

#endif
