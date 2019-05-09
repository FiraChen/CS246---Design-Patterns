#include <iostream>
#include <vector>
#include "cell.h"
#define ZERO 0
using namespace std;

Cell::Cell() : isAlive{false}, numNeighbours{ZERO}, aliveNeighbours{ZERO}, neighbours{nullptr},
              xCor{0}, yCor{0}, width{0}, height{0}, xw{nullptr} {}

Cell::~Cell() {
  isAlive = false;
  numNeighbours = ZERO;
  aliveNeighbours = ZERO;
}

void Cell::setLiving() {
  isAlive = true;
  draw();
}

void Cell::addNeighbour(Cell *neighbour) {
  neighbours[numNeighbours] = neighbour;
  ++numNeighbours;
}

void Cell::neighbourIsAlive() {
  // if the neighbour is called, it means there is an alive
  //    neighbour around it, thus, increase the aliveNeighbours number
  ++aliveNeighbours;
}

void Cell::alertNeighbours() {
  if (isAlive) {
    // if the current cell is alive, alert all of its neighbours
    for (int i = 0; i < numNeighbours; ++i) {
      neighbours[i]->neighbourIsAlive();
    }
  }
}

void Cell::recalculate() {
  // a living cell with two or three live neighbours continues to live
  if (isAlive == true && (aliveNeighbours == 2 || aliveNeighbours == 3)) {
    isAlive = true;
  }
  // a dead cell with exactly three live neighbours comes to life; otherwise,
  //     it remains dead
  else if (isAlive == false && aliveNeighbours == 3) {
    isAlive = true;
    draw();
  }
  // a living cell with fewer than two live neighbours or
  //     more than three live neighbours dies
  else if (isAlive == true && (aliveNeighbours < 2 || aliveNeighbours > 3)) {
    isAlive = false;
    undraw();
  }
  // after recalculating, set the aliveNeighbours to 0, waiting for next tick
  aliveNeighbours = 0;
}

void Cell::setCoords(int x, int y, int w, int h, Xwindow *window) {
  xCor = x;
  yCor = y;
  width = w;
  height = h;
  xw = window;
}

void Cell::draw() {
  xw->fillRectangle(xCor, yCor, width, height, Xwindow::Black);
}

void Cell::undraw() {
  xw->fillRectangle(xCor, yCor, width, height, Xwindow::White);
}

ostream& operator<<(ostream &out, const Cell &c) {
  if (c.isAlive) {
    out << "X";
  } else {
    out << "_";
  }
  return out;
}
