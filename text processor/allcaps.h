#ifndef __ALLCAPS_H__
#define __ALLCAPS_H__
#include <iostream>
#include <string>
#include "textprocess.h"
#include "textdecorator.h"

class Allcaps: public TextDecorator {
    std::istream *source;
    bool isLower(char c);

 public:
    Allcaps(TextProcessor *tp);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
