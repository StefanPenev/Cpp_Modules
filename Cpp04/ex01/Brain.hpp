/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:31:30 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 10:31:32 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif