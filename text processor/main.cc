#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h"
#include "echo.h"
#include "textdecorator.h"
#include "doublewords.h"
#include "dropfirst.h"
#include "allcaps.h"
#include "count.h"

// haveSeperator returns true if the given word s,
//   contains character '|'
bool haveSeperator(string s) {
  char c;
  stringstream ss{s};
  while (ss >> c) {
    if (c == '|') {
      return true;
    }
  }
  return false;
}

// firstString returns the first part of the string,
//    which is before '|'
string firstString(string s) {
  char c;
  int num = 0;
  string first;
  stringstream ss{s};
  while (ss >> c) {
    if (c == '|') {
      ++num;
      break;
    }
    first += c;
    ++num;
  }
  return first;
}

/// secondString returns the second part of the string,
//    which is after '|'
string secondString(string s) {
  char c;
  int num = 0;
  int length;
  string second;
  stringstream ss{s};
  while (ss >> c) {
    if (c == '|') {
      ++num;
      length = s.length() - num;
      second = s.substr(num, length);
      break;
    }
    ++num;
  }
  return second;
}

/* the TextProcessor provides the following functions:
   dropfirst n Drop the first n characters of each word.
      If n is greater than or equal to the length of some
      word, that word is eliminated.
   doublewords Double up all words in the string.
   allcaps All letters in the string are presented
      in uppercase. Other characters remain unchanged.
  count c The first occurrence of the character c in the
      string is replaced with 1. The second is replaced
      with 2, ... the  tenth is replaced with 10, and so on.*/
int main () {
  cin.exceptions(ios::failbit|ios::eofbit);
  string s;

  try {
    while(1) {
      getline(cin,s);
      istringstream iss{s};
      iss.exceptions(ios::failbit);
      string fname;
      iss >> fname;
      istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());
      in->exceptions(ios::failbit|ios::eofbit);

      TextProcessor *tp = new Echo;
      string dec;
      try {
        while (iss >> dec) {
          if (dec == "dropfirst") {
            int n;
            iss >> n;
            tp = new Dropfirst(tp, n);
          }
          else if (dec == "doublewords") {
            tp = new Doublewords(tp);
          }
          else if (dec == "allcaps") {
            tp = new Allcaps(tp);
          }
          else if (dec == "count") {
            char c;
            iss >> c;
            tp = new Count(tp, c);
          }
       }
      }
      catch (ios::failure) {}

      tp->setSource(in);
      string word;

      try {
        int lineNum = 1;
        while (true) {
          try {
            word = tp->getWord();
          }
          catch (string emptyWord) {
            if(emptyWord == "") {
              break;
            } else {
              continue;
            }
          }
          stringstream words{word};
          if (words >> word) {
            if (haveSeperator(word)) {
              cout << lineNum++ << ' ' << firstString(word) << endl;
              cout << lineNum++ << ' ' << secondString(word) << endl;
              continue;
            }
            cout << lineNum++ << ' ' << word << endl;
          } else {
            break;
          }
        }
      }
      catch (ios::failure) {}

      if (in != &cin) delete in;
      delete tp;
    }
  }
  catch (ios::failure) {}
}
