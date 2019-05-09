#include <iostream>
#include <string>
#include <sstream>
#include "count.h"
using namespace std;

Count::Count(TextProcessor *tp, char omit): TextDecorator{tp}, source(0),
                                            omit{omit}, num{1} {}

void Count::setSource(istream *in) {
  source = in;
  text->setSource(source);
}

string Count::getWord() {
  string s = text->getWord();
  string counted;
  char c;
  istringstream ss{s};

  while (ss >> c) {
    if (c == omit) {
      int copynum = num;
      counted += to_string(copynum);
      ++num;
    } else {
      counted += c;
    }
  }
  return counted;
}
