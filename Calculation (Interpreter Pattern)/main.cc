#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "expression.h"

using namespace std;

// You will need to write your own test harness

// Read and construct expression object. Returns a pointer to a heap-allocated
// object (caller must delete it).
istream &operator>>(istream &in, Expr *&e) {
  string s;
  vector<Expr *> exprs;
  while (in >> s) {
    istringstream ss(s);
    int n;
    if (ss >> n) {
      // if it's a int, simply push to the back
      exprs.push_back(new LoneInt(n));
    }
    else if (s == "NEG" || s == "ABS") {
      // create a pointer to the last expression
      Expr *expression = exprs.back();
      exprs.pop_back();
      // push a new Unary expression to the back
      exprs.push_back(new Unary(s, expression));
    }
    else if (s == "+" || s == "-" || s == "*" || s == "/") {
      Expr *right = exprs.back();
      exprs.pop_back();
      Expr *left = exprs.back();
      exprs.pop_back();
      // push a new Binary expression to the back
      exprs.push_back(new Binary(s, left, right));
    }
    else if (s == "done") {
      e = exprs.front();
      cout << e->prettyprint() << endl;
      break;
    }
    else {
      // if it's a variable, simply push it to the back
      exprs.push_back(new Var(s));
    }
  }
  return in;
}

int main () {
  string s;

  Expr *e;
  cin >> e;

  // Command interpreter
  while (cin >> s) {
    if (s == "eval") {
      // if there exsits a variable that has no value,
      //   cout no value warning
      try {
        cout << e->evaluate() << endl;
      } catch (string name) {
        cout << name << " has no value." << endl;
      }
    }
    // set the variable to a certain value inside the expression
    else if (s == "set") {
      int n;
      string name;
      if (cin >> name >> n) {
        e->set(name ,n);
      }
    }
    // unset the value of variable with given input as name
    else if (s == "unset") {
      string name;
      if (cin >> name) {
        e->unset(name);
      }
    }
    // print out the current expression
    else if (s == "print") {
      cout << e->prettyprint() << endl;
    }
    // create a deep copy of the current expression
    else if (s == "copy") {
      Expr *theCopy = e->copy();
      cout << theCopy->prettyprint() << endl;
      theCopy->set("x", 1);
      cout << theCopy->prettyprint() << endl;
      try { cout << theCopy->evaluate() << endl; }
      catch(string name) { cout << name << " has no value." << endl; }
      delete theCopy;
    }
  }
  delete e;
}
