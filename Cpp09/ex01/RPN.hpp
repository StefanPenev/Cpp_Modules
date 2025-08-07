/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:41:56 by spenev            #+#    #+#             */
/*   Updated: 2025/08/07 11:41:57 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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