#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "lexer.h"

using namespace std;

// Структура узла абстрактного синтаксического дерева (AST)
struct AstNode {
  string type;
  string value;
  vector<AstNode*> children;
};

// Класс для парсинга кода Apple
class Parser {
public:
  Parser(const vector<Token>& tokens) : tokens(tokens), current(0) {}

  AstNode* parse() {
    return parseProgram();
  }

private:
  AstNode* parseProgram() {
    AstNode* program = new AstNode{"program", ""};
    while (current < tokens.size()) {
      AstNode* statement = parseStatement();
      if (statement) {
        program->children.push_back(statement);
      }
    }
    return program;
  }

  AstNode* parseStatement() {
    if (match("pick")) {
      return parsePickStatement();
    } else if (match("func")) {
      return parseFunctionDeclaration();
    } else if (match("var") || match("let")) {
      return parseVariableDeclaration();
    } else if (match("if")) {
      return parseIfStatement();
    } else if (match("for")) {
      return parseForStatement();
    } else if (match("{")) {
      return parseBlock();
    }
    return nullptr;
  }

  AstNode* parsePickStatement() {
    AstNode* pickNode = new AstNode{"pick", ""};
    consume("pick");
    AstNode* identifier = parseIdentifier();
    pickNode->children.push_back(identifier);
    return pickNode;
  }

  AstNode* parseFunctionDeclaration() {
    AstNode* funcNode = new AstNode{"function", ""};
    consume("func");
    AstNode* identifier = parseIdentifier();
    funcNode->children.push_back(identifier);
    consume("(");
    AstNode* parameters = parseParameters();
    funcNode->children.push_back(parameters);
    consume(")");
    AstNode* block = parseBlock();
    funcNode->children.push_back(block);
    return funcNode;
  }

  AstNode* parseParameters() {
    AstNode* parametersNode = new AstNode{"parameters", ""};
    if (match(")")) {
      return parametersNode;
    }
    AstNode* parameter = parseParameter();
    parametersNode->children.push_back(parameter);
    while (match(",")) {
      consume(",");
      parameter = parseParameter();
      parametersNode->children.push_back(parameter);
    }
    return parametersNode;
  }

  AstNode* parseParameter() {
    AstNode* parameterNode = new AstNode{"parameter", ""};
    AstNode* identifier = parseIdentifier();
    parameterNode->children.push_back(identifier);
    consume(":");
    AstNode* type = parseType();
    parameterNode->children.push_back(type);
    return parameterNode;
  }

  AstNode* parseVariableDeclaration() {
    AstNode* declarationNode = new AstNode{"declaration", ""};
    AstNode* kind = parseDeclarationKind();
    declarationNode->children.push_back(kind);
    AstNode* identifier = parseIdentifier();
    declarationNode->children.push_back(identifier);
    consume(":");
    AstNode* type = parseType();
    declarationNode->children.push_back(type);
    consume("=");
    AstNode* value = parseExpression();
    declarationNode->children.push_back(value);
    return declarationNode;
  }

  AstNode* parseDeclarationKind() {
    if (match("var")) {
      return new AstNode{"var", ""};
    } else if (match("let")) {
      return new AstNode{"let", ""};
    }
    return nullptr;
  }

  AstNode* parseIdentifier() {
    if (tokens[current].type == TokenType::Identifier) {
      return new AstNode{"identifier", tokens[current].value};
    }
    return nullptr;
  }

  AstNode* parseType() {
    if (tokens[current].type == TokenType::Identifier) {
      return new AstNode{"type", tokens[current].value};
    }
    return nullptr;
  }

  AstNode* parseIfStatement() {
    AstNode* ifNode = new AstNode{"if", ""};
    consume("if");
    consume("(");
    AstNode* condition = parseExpression();
    ifNode->children.push_back(condition);
    consume(")");
    AstNode* thenBlock = parseBlock();
    ifNode->children.push_back(thenBlock);
    if (match("else")) {
      consume("else");
      AstNode* elseBlock = parseBlock();
      ifNode->children.push_back(elseBlock);
    }
    return ifNode;
  }

  AstNode* parseForStatement() {
    AstNode* forNode = new AstNode{"for", ""};
    consume("for");
    consume("(");
    AstNode* initializer = parseVariableDeclaration();
    forNode->children.push_back(initializer);
    consume(";");
    AstNode* condition = parseExpression();
    forNode->children.push_back(condition);
    consume(";");
    AstNode* increment = parseExpression();
    forNode->children.push_back(increment);
    consume(")");
    AstNode* block = parseBlock();
    forNode->children.push_back(block);
    return forNode;
  }

  AstNode* parseBlock() {
    AstNode* blockNode = new AstNode{"block", ""};
    consume("{");
    while (!match("}")) {
      AstNode* statement = parseStatement();
      if (statement) {
        blockNode->children.push_back(statement);
      }
    }
    consume("}");
    return blockNode;
  }

  AstNode* parseExpression() {
    // ... Логика парсинга выражений ...
    return nullptr;
  }

  bool match(const string& tokenType) {
    if (current < tokens.size() && tokens[current].type == tokenType) {
      return true;
    }
    return false;
  }

  void consume(const string& tokenType) {
    if (match(tokenType)) {
      current++;
    } else {
      // ... Обработка ошибки: токен не найден ...
    }
  }

private:
  vector<Token> tokens;
  int current;
};

int main() {
  // ... Ввод кода Apple ...

  // ... Парсинг кода ...

  return 0;
}
