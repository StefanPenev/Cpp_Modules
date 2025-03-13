/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:36:51 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 09:36:58 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);

    std::string getType() const;
    virtual void makeSound() const;
};

#endif