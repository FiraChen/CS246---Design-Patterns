#ifndef __DROPFIRST_H__
#define __DROPFIRST_H__
#include <iostream>
#include <string>
#include "textprocess.h"
#include "textdecorator.h"

class Dropfirst: public TextDecorator {
    std::istream *source;
    int num;

 public:
    Dropfirst(TextProcessor *tp, int num);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
