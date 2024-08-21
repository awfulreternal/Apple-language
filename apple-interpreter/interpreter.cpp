#include <iostream>
#include "interpreter.hpp"

void Interpreter::execute(std::shared_ptr<AST::Program> program) {
  for (auto& statement : program->statements) {
    executeStatement(statement);
  }
}

void Interpreter::executeStatement(std::shared_ptr<AST::Statement> statement) {
  if (auto declaration = std::dynamic_pointer_cast<AST::Declaration>(statement)) {
    executeDeclaration(declaration);
  } else if (auto expressionStatement = std::dynamic_pointer_cast<AST::ExpressionStatement>(statement)) {
    executeExpression(expressionStatement->expression);
  } else if (auto ifStatement = std::dynamic_pointer_cast<AST::IfStatement>(statement)) {
    executeIfStatement(ifStatement);
  } else if (auto whileStatement = std::dynamic_pointer_cast<AST::WhileStatement>(statement)) {
    executeWhileStatement(whileStatement);
  } else if (auto forStatement = std::dynamic_pointer_cast<AST::ForStatement>(statement)) {
    executeForStatement(forStatement);
  } else if (auto returnStatement = std::dynamic_pointer_cast<AST::ReturnStatement>(statement)) {
    executeReturnStatement(returnStatement);
  } else if (auto printStatement = std::dynamic_pointer_cast<AST::PrintStatement>(statement)) {
    executePrintStatement(printStatement);
  } 
}

void Interpreter::executeDeclaration(std::shared_ptr<AST::Declaration> declaration) {
  // ... (реализовать  создание  переменной  и  присваивание  значения)
}

std::any Interpreter::executeExpression(std::shared_ptr<AST::Expression> expression) {
  if (auto identifier = std::dynamic_pointer_cast<AST::Identifier>(expression)) {
    // ... (получить  значение  переменной  по  имени)
  } else if (auto integerLiteral = std::dynamic_pointer_cast<AST::IntegerLiteral>(expression)) {
    return integerLiteral->value;
  } else if (auto stringLiteral = std::dynamic_pointer_cast<AST::StringLiteral>(expression)) {
    return stringLiteral->value;
  } else if (auto binaryExpression = std::dynamic_pointer_cast<AST::BinaryExpression>(expression)) {
    // ... (выполнить  арифметическую  или  логическую  операцию)
  } else if (auto assignmentExpression = std::dynamic_pointer_cast<AST::AssignmentExpression>(expression)) {
    // ... (присвоить  значение  переменной)
  } else if (auto functionCallExpression = std::dynamic_pointer_cast<AST::FunctionCallExpression>(expression)) {
    // ... (вызвать  функцию)
  }
  return std::any(); // Возврат  пустого  значения 
}

void Interpreter::executeIfStatement(std::shared_ptr<AST::IfStatement> ifStatement) {
  // ... (реализовать  проверку  условия  и  выполнение  соответствующей  инструкции)
}

void Interpreter::executeWhileStatement(std::shared_ptr<AST::WhileStatement> whileStatement) {
  // ... (реализовать  проверку  условия  и  выполнение  цикла)
}

void Interpreter::executeForStatement(std::shared_ptr<AST::ForStatement> forStatement) {
  // ... (реализовать  инициализацию,  проверку  условия  и  инкремент  в  цикле)
}

std::any Interpreter::executeReturnStatement(std::shared_ptr<AST::ReturnStatement> returnStatement) {
  // ... (реализовать  возврат  значения  из  функции)
}

void Interpreter::executePrintStatement(std::shared_ptr<AST::PrintStatement> printStatement) {
  // ... (реализовать  вывод  значения  на  консоль)
}

// ... (добавьте  функции  для  обработки  функций  и  других  элементов  языка Apple)
