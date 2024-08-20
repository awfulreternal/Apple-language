#include "parser.h"

// ... Парсер кода Apple ...

AstNode* parse(const string& code) {
  // 1. Лексический анализ (lexical analysis)
  Lexer lexer(code);
  vector<Token> tokens = lexer.tokenize();

  // 2. Синтаксический анализ (syntactic analysis)
  Parser parser(tokens);
  return parser.parse();
}
