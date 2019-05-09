#include <iostream>
#include <string>
#include "dropfirst.h"
using namespace std;

Dropfirst::Dropfirst(TextProcessor *tp, int num): TextDecorator{tp}, source(0), num{num} {}

void Dropfirst::setSource(istream *in) {
  source = in;
  text->setSource(source);
}

string Dropfirst::getWord() {
  string s = text->getWord();
  int length = s.length();
  if (num >= length) {
    throw s;
  }
  length = s.length() - num;
  s = s.substr(num, length);
  return s;
}
