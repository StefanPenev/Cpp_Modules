/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:59:09 by stefan            #+#    #+#             */
/*   Updated: 2025/05/04 13:17:04 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat high("HighRank", 1);
        high.signForm(*rrf);
        high.executeForm(*rrf);
        delete rrf;
    }

    AForm* unknown = someRandomIntern.makeForm("unknown form", "Target");
    if (unknown) {
        delete unknown;
    }

    return 0;
}
