/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:24:28 by stefan            #+#    #+#             */
/*   Updated: 2025/03/07 11:24:31 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedReplace.hpp"

bool SedReplace::replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2) {
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return false;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Unable to open file '" << filename << "'." << std::endl;
        return false;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: Unable to create output file '" << outputFilename << "'." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string newLine;
        size_t pos = 0;
        while (pos < line.length()) {
            size_t found = line.find(s1, pos);
            if (found == std::string::npos) {
                newLine += line.substr(pos);
                break;
            }
            newLine += line.substr(pos, found - pos) + s2;
            pos = found + s1.length();
        }
        outputFile << newLine << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return true;
}