#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <memory>
#include <string>
#include <map>
#include <vector>
#include "ast.hpp"

class Interpreter {
public:
  // Выполнение  программы
  void execute(std::shared_ptr<AST::Program> program);

private:
  // Выполнение  инструкции
  void executeStatement(std::shared_ptr<AST::Statement> statement);

  // Выполнение  объявления
  void executeDeclaration(std::shared_ptr<AST::Declaration> declaration);

  // Выполнение  выражения
  std::any executeExpression(std::shared_ptr<AST::Expression> expression);

  // Выполнение  условного  оператора
  void executeIfStatement(std::shared_ptr<AST::IfStatement> ifStatement);

  // Выполнение  цикла  while
  void executeWhileStatement(std::shared_ptr<AST::WhileStatement> whileStatement);

  // Выполнение  цикла  for
  void executeForStatement(std::shared_ptr<AST::ForStatement> forStatement);

  // Выполнение  оператора  return
  std::any executeReturnStatement(std::shared_ptr<AST::ReturnStatement> returnStatement);

  // Выполнение  оператора  print
  void executePrintStatement(std::shared_ptr<AST::PrintStatement> printStatement);

  // ... (добавьте  функции  для  обработки  функций  и  других  элементов  языка Apple)

private:
  // Таблица  переменных
  std::map<std::string, std::any> variables; 
};

#endif 
