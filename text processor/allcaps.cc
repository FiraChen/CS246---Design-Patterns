#include <iostream>
#include <string>
#include <sstream>
#include "allcaps.h"
using namespace std;

Allcaps::Allcaps(TextProcessor *tp): TextDecorator{tp}, source(0) {}

void Allcaps::setSource(istream *in) {
  source = in;
  text->setSource(source);
}

bool Allcaps::isLower(char c) {
  if (97 <= c && c <= 122) {
    return true;
  } else {
    return false;
  }
}

string Allcaps::getWord() {
  string s = text->getWord();
  string caps;
  char c;
  istringstream ss{s};

  while (ss >> c) {
    if (isLower(c)) {
      c -= (97 - 65);
      caps += c;
    } else {
      caps += c;
    }
  }
  return caps;
}
