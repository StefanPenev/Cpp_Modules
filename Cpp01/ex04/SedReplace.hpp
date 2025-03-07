/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:23:24 by stefan            #+#    #+#             */
/*   Updated: 2025/03/07 11:23:43 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDREPLACE_HPP
#define SEDREPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class SedReplace {
public:
    static bool replaceInFile(const std::string &filename, const std::string &s1,
        const std::string &s2);
};

#endif