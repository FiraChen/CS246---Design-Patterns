#include <iostream>
#include <sstream>
#include <string>
#include "expression.h"
#define ZERO 0

using namespace std;

Expr::~Expr() {
  // do nothing
}

// basic constructor for Var class
Var::Var(string s) : name{s}, value{ZERO}, hasValue{false} {}

// basic destructor
Var::~Var() {
  value = ZERO;
  hasValue = false;
}

// create a new Var object and return the pointer
Expr* Var::copy() {
  Var* newVar = new Var(name);
  newVar->value = value;
  newVar->hasValue = hasValue;
  return newVar;
}

// prints out the variable, if it has value, prints out its value,
//    otherwise, prints out its name
string Var::prettyprint() {
  string s;
  if (hasValue) {
    s = to_string(value);
    return s;
  } else {
    s = name;
    return s;
  }
}

// if the given string s matches the variable name,
//      assign int i to its value
void Var::set(string s, int i) {
  if (name == s) {
    hasValue = true;
    value = i;
  }
}

// if the given string s matches the variable name,
//      remove the assigned value
void Var::unset(string s) {
  if (name == s) {
    hasValue = false;
    value = 0;
  }
}

// evaluates the variable, if it has value, returns the associated
//    value, otherwise, shows the warning that the variable has no value
int Var::evaluate() {
  if (hasValue) {
    return value;
  } else {
    throw name;
  }
}

// basic constructor for LoneInt class
LoneInt::LoneInt(int i) : num{i} {}

// basic destructor
LoneInt::~LoneInt() {
  num = ZERO;
}

// create a new LoneInt object and return the pointer
Expr* LoneInt::copy() {
  LoneInt* newLoneInt = new LoneInt(num);
  return newLoneInt;
}

// prints out the integer
string LoneInt::prettyprint() {
  string s = to_string(num);
  return s;
}

void LoneInt::set(string s, int i) {
  // nothing to add here
}

void LoneInt::unset(string s) {
  // nothing to add here
}

// evaluates the integer by returning its num
int LoneInt::evaluate() {
  return num;
}

// basic constructor for Unary class
Unary::Unary(string func, Expr *singleExpr) : Ufunction{func},
          singleExpr{singleExpr} {}

// basic destructor
Unary::~Unary() {
  delete singleExpr;
}

// create a new Unary expression and return the pointer
Expr* Unary::copy() {
  Unary* newUnary = new Unary(Ufunction, singleExpr->copy());
  return newUnary;
}

// prints out the unary function
string Unary::prettyprint() {
  string s;
  if (Ufunction == "ABS") {
    s += "|" + singleExpr->prettyprint() + "|";
  } else if (Ufunction == "NEG") {
    s += "-" + singleExpr->prettyprint();
  }
  return s;
}

// set variable if it's exsiting in the unary expression
void Unary::set(string s, int i) {
  singleExpr->set(s, i);
}

// unset variable if it's exsiting in the unary expression
void Unary::unset(string s) {
  singleExpr->unset(s);
}

// evaluates the unary function
int Unary::evaluate() {
  if (Ufunction == "ABS") {
    // if the result is negative, it should become positive
    //   otherwise, it stays the same
    if (singleExpr->evaluate() < ZERO) {
      return -(singleExpr->evaluate());
    } else {
      return singleExpr->evaluate();
    }
  } else if (Ufunction == "NEG") {
    return -(singleExpr->evaluate());;
  } else {
    return 0;
  }
}

// basic constuctor for Binary class
Binary::Binary(string func, Expr *leftExpr, Expr *rightExpr) : Bfunction{func},
           leftExpr{leftExpr}, rightExpr{rightExpr} {}

// basic destructor
Binary::~Binary() {
  delete leftExpr;
  delete rightExpr;
}

// create a new Binary expression and return the pointer
Expr* Binary::copy() {
  Binary* newBinary = new Binary(Bfunction, leftExpr->copy(), rightExpr->copy());
  return newBinary;
}

// prints out the binary function
string Binary::prettyprint() {
  string s;
  s += "(" + leftExpr->prettyprint() + " " + Bfunction + " " + rightExpr->prettyprint() + ")";
  return s;
}

// set variable if it's exsiting in the binary expression
void Binary::set(string s, int i) {
  leftExpr->set(s, i);
  rightExpr->set(s, i);
}

// unset variable if it's exsiting in the binary expression
void Binary::unset(string s) {
  leftExpr->unset(s);
  rightExpr->unset(s);
}

// evaluates the binary expression
int Binary::evaluate() {
  if (Bfunction == "+") {
    // before evaluate the main function, evaluate the right and
    //  left expressions first
    return leftExpr->evaluate() + rightExpr->evaluate();
  } else if (Bfunction == "-") {
    return leftExpr->evaluate() - rightExpr->evaluate();
  } else if (Bfunction == "*") {
    return leftExpr->evaluate() * rightExpr->evaluate();
  } else if (Bfunction == "/") {
    return leftExpr->evaluate() / rightExpr->evaluate();
  } else {
    return 0;
  }
}
