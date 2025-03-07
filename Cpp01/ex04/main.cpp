/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:25:08 by stefan            #+#    #+#             */
/*   Updated: 2025/03/07 11:25:10 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedReplace.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (!SedReplace::replaceInFile(filename, s1, s2)) {
        return 1;
    }

    std::cout << "Replacement completed: " << filename << ".replace" << std::endl;
    return 0;
}