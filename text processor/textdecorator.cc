#include <iostream>
#include <string>
#include "textdecorator.h"
using namespace std;

TextDecorator::TextDecorator(TextProcessor *tp): text{tp} {}

TextDecorator::~TextDecorator() {
  delete text;
}
