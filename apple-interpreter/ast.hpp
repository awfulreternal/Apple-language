#ifndef AST_HPP
#define AST_HPP

#include <memory>
#include <string>
#include <vector>

namespace AST {

enum class TokenType {
  // ... (определение  типов  токенов)
};

struct Token {
  TokenType type;
  std::string value;
};

struct Program {
  std::vector<std::shared_ptr<Statement>> statements;
};

struct Declaration {
  TokenType type;
  std::string identifier;
  std::shared_ptr<Expression> expression;
};

struct Expression {
  // ... (определение  классов  для  разных  типов  выражений,  например,  `BinaryExpression`,  `FunctionCallExpression`  и  т. д.)
};

struct Statement {
  // ... (определение  классов  для  разных  типов  инструкций)
};

// ... (определение  классов  для  остальных  элементов  AST)

}

#endif 
