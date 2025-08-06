#include "RPN.hpp"
#include <sstream>
#include <cctype>

int RPN::evaluate(const std::string& expr) {
    std::stack<int> stack;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            // Operator: need at least two operands
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int res = applyOperator(a, b, token[0]);
            stack.push(res);
        } else if (token.length() == 1 && std::isdigit(token[0])) {
            // Single digit operand
            stack.push(token[0] - '0');
        } else {
            // Invalid token (not a single digit or operator)
            throw std::runtime_error("Invalid token");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    return stack.top();
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator");
}
