#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "lexer.h"

using namespace std;

// Словарь ключевых слов языка Apple
const map<string, TokenType> keywords = {
  {"pick", TokenType::Pick},
  {"func", TokenType::Func},
  {"var", TokenType::Var},
  {"let", TokenType::Let},
  {"if", TokenType::If},
  {"else", TokenType::Else},
  {"for", TokenType::For},
  {"in", TokenType::In},
  {"return", TokenType::Return},
  {"true", TokenType::True},
  {"false", TokenType::False},
  {"null", TokenType::Null},
  {"print", TokenType::Print},
  {"import", TokenType::Import},
  {"as", TokenType::As},
  {"from", TokenType::From},
  {"with", TokenType::With},
  {"class", TokenType::Class},
  {"extends", TokenType::Extends},
  {"new", TokenType::New},
  {"this", TokenType::This},
  {"super", TokenType::Super},
  {"constructor", TokenType::Constructor},
  {"prototype", TokenType::Prototype},
  {"static", TokenType::Static},
  {"private", TokenType::Private},
  {"protected", TokenType::Protected},
  {"public", TokenType::Public},
  {"interface", TokenType::Interface},
  {"implements", TokenType::Implements},
  {"abstract", TokenType::Abstract},
  {"enum", TokenType::Enum},
  {"const", TokenType::Const},
  {"default", TokenType::Default},
  {"break", TokenType::Break},
  {"continue", TokenType::Continue},
  {"try", TokenType::Try},
  {"catch", TokenType::Catch},
  {"finally", TokenType::Finally},
  {"throw", TokenType::Throw},
  {"await", TokenType::Await},
  {"async", TokenType::Async},
  {"module", TokenType::Module},
  {"export", TokenType::Export},
  {"import", TokenType::Import},
  {"from", TokenType::From},
  {"as", TokenType::As},
  {"global", TokenType::Global},
  {"nonlocal", TokenType::Nonlocal},
  {"yield", TokenType::Yield},
  {"raise", TokenType::Raise},
  {"assert", TokenType::Assert},
  {"del", TokenType::Del},
  {"pass", TokenType::Pass},
  {"with", TokenType::With},
  {"lambda", TokenType::Lambda},
  {"not", TokenType::Not},
  {"and", TokenType::And},
  {"or", TokenType::Or},
  {"xor", TokenType::Xor},
  {"is", TokenType::Is},
  {"in", TokenType::In},
  {"not", TokenType::Not},
  {"is", TokenType::Is},
  {"in", TokenType::In},
};

// Класс лексического анализатора
class Lexer {
public:
  Lexer(const string& code) : code(code), current(0) {}

  vector<Token> tokenize() {
    vector<Token> tokens;
    while (current < code.size()) {
      char ch = code[current];
      if (isspace(ch)) {
        current++;
      } else if (isalpha(ch) || ch == '_') {
        tokens.push_back(lexIdentifier());
      } else if (isdigit(ch)) {
        tokens.push_back(lexNumber());
      } else if (ch == '"') {
        tokens.push_back(lexString());
      } else if (isOperator(ch)) {
        tokens.push_back(lexOperator());
      } else if (ch == '(') {
        tokens.push_back(Token{TokenType::LeftParen, "("});
        current++;
      } else if (ch == ')') {
        tokens.push_back(Token{TokenType::RightParen, ")"});
        current++;
      } else if (ch == '{') {
        tokens.push_back(Token{TokenType::LeftBrace, "{"});
        current++;
      } else if (ch == '}') {
        tokens.push_back(Token{TokenType::RightBrace, "}"});
        current++;
      } else if (ch == '[') {
        tokens.push_back(Token{TokenType::LeftBracket, "["});
        current++;
      } else if (ch == ']') {
        tokens.push_back(Token{TokenType::RightBracket, "]"});
        current++;
      } else if (ch == ',') {
        tokens.push_back(Token{TokenType::Comma, ","});
        current++;
      } else if (ch == '.') {
        tokens.push_back(Token{TokenType::Dot, "."});
        current++;
      } else if (ch == ':') {
        tokens.push_back(Token{TokenType::Colon, ":"});
        current++;
      } else if (ch == ';') {
        tokens.push_back(Token{TokenType::Semicolon, ";"});
        current++;
      } else {
        // ... Обработка ошибок лексического анализа ...
        current++;
      }
    }
    return tokens;
  }

private:
  Token lexIdentifier() {
    string value;
    while (current < code.size() && (isalnum(code[current]) || code[current] == '_')) {
      value += code[current];
      current++;
    }
    if (keywords.count(value)) {
      return Token{keywords.at(value), value};
    } else {
      return Token{TokenType::Identifier, value};
    }
  }

  Token lexNumber() {
    string value;
    while (current < code.size() && isdigit(code[current])) {
      value += code[current];
      current++;
    }
    return Token{TokenType::Number, value};
  }

  Token lexString() {
    string value;
    current++;
    while (current < code.size() && code[current] != '"') {
      value += code[current];
      current++;
    }
    current++;
    return Token{TokenType::String, value};
  }

  Token lexOperator() {
    string value;
    value += code[current];
    current++;
    return Token{TokenType::Operator, value};
  }

  bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=' || ch == '!' || ch == '<' || ch == '>' || ch == '&' || ch == '|' || ch == '^' || ch == '?' || ch == '~');
  }

  string code;
  int current;
};
