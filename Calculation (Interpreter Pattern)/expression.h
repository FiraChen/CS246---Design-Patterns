#ifndef _EXPRESSION_H
#define _EXPRESSION_H

// the main expression class, Expr, which derives Var, LoneInt, Binary
//   and Unary classes
class Expr {
public:
  virtual ~Expr() = 0;
  virtual Expr* copy() = 0;
  virtual std::string prettyprint() = 0;
  virtual void set(std::string, int) = 0;
  virtual void unset(std::string) = 0;
  virtual int evaluate() = 0;
};

// subclass Var, each object has a name and a corresponding value, cannot be one
//   of ABS, NEG or done
class Var : public Expr {
  std::string name;
  int value;
  bool hasValue;

public:
  Var(std::string);
  ~Var() override;
  Expr* copy() override;
  std::string prettyprint() override;
  void set(std::string, int) override;
  void unset(std::string) override;
  int evaluate() override;
};

// subclass LoneInt, each object has a integer value
class LoneInt : public Expr {
  int num;

public:
  LoneInt(int);
  ~LoneInt() override;
  Expr* copy() override;
  std::string prettyprint() override;
  void set(std::string, int) override;
  void unset(std::string) override;
  int evaluate() override;
};

// subclass Unary has operator Neg and Abs as function, denoting negation and absolute value,
//    applied to an expression
class Unary : public Expr {
  std::string Ufunction;
  Expr *singleExpr;

public:
  Unary(std::string, Expr*);
  ~Unary() override;
  Expr* copy() override;
  std::string prettyprint() override;
  void set(std::string, int) override;
  void unset(std::string) override;
  int evaluate() override;
};

// subclass Unary has Add, Substract, Multiply and Divide as oprator called
//    function and applied these binary functions to expressions
class Binary : public Expr {
  std::string Bfunction;
  Expr *leftExpr;
  Expr *rightExpr;

public:
  Binary(std::string, Expr*, Expr*);
  ~Binary() override;
  Expr* copy() override;
  std::string prettyprint() override;
  void set(std::string, int) override;
  void unset(std::string) override;
  int evaluate() override;
};

#endif
