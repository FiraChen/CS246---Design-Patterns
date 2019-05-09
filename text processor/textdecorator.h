#ifndef __TEXTDECORATOR_H__
#define __TEXTDECORATOR_H__
#include <iostream>
#include <string>
#include "textprocess.h"

class TextDecorator : public TextProcessor {
  protected:
    TextProcessor *text;

  public:
    TextDecorator(TextProcessor *tp);
    virtual ~TextDecorator();
};

#endif
