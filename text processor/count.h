#ifndef __COUNT_H__
#define __COUNT_H__
#include <iostream>
#include <string>
#include "textprocess.h"
#include "textdecorator.h"

class Count: public TextDecorator {
    std::istream *source;
    char omit;
    int num;

 public:
    Count(TextProcessor *tp, char omit);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
