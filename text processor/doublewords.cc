#include <iostream>
#include <string>
#include <sstream>
#include "doublewords.h"
using namespace std;

Doublewords::Doublewords(TextProcessor *tp): TextDecorator{tp}, source(0) {}

void Doublewords::setSource(istream *in) {
  source = in;
  text->setSource(source);
}

string Doublewords::getWord() {
  string s = text->getWord();
  if (s == "") {
    return s;
  }
  s += "|" + s;
  return s;
}
