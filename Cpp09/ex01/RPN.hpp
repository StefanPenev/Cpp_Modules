#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN {
public:
    static int evaluate(const std::string& expr);

private:
    static bool isOperator(char c);
    static int applyOperator(int a, int b, char op);
};

#endif