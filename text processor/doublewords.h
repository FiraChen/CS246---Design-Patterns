#ifndef __DOUBLEWORDS_H__
#define __DOUBLEWORDS_H__
#include <iostream>
#include <string>
#include "textprocess.h"
#include "textdecorator.h"

class Doublewords: public TextDecorator {
  std::istream *source;

 public:
    Doublewords(TextProcessor *tp);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
