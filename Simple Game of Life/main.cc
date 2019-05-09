#include <iostream>
#include <sstream>
#include <string>
#include "grid.h"
#include "window.h"

using namespace std;

/* The game starts by initializing a n*n grid and then moves through successive generations,
in which cells can either die, come to life, or stay the same, according to the following rules:
a living cell with fewer than two live neighbours or more than three live neighbours dies;
a living cell with two or three live neighbours continues to live
a dead cell with exactly three live neighbours comes to life; otherwise, it remains dead.
*/

int main () {
  string s;
  int n;
  Xwindow *w = new Xwindow(500, 500);
  Grid *g = new Grid(w);

  while (cin >> s) {
    // create a new grid with the given size
    if (s == "new") {
      if (cin >> n) {
        g->init(n);
      }
    }
    // initialize the cell with the given numbers as
    //   position, first number is column and second
    //   number is row
    else if (s == "init") {
      int x;
      int y;
      while (cin >> x >> y) {
        if(x == -1 && y == -1) {
          break;
        }
        g->turnOn(x, y);
      }
    }
    // transforms the grid into the immediately
    //   succeeding generation for one time
    else if (s == "step") {
      g->tick();
    }
    // transforms the grid into the immediately
    //    succeeding generation for given n times
    else if (s == "steps") {
      if (cin >> n) {
        while (n > 0) {
          g->tick();
          --n;
        }
      }
    }
    // print out the current cell status
    else if (s == "print") {
      cout << *g;
    } else {
      cout << "invalid input" << endl;
    }
  }
  delete g;
}
