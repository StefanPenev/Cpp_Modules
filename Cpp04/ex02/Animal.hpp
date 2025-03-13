/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:36:51 by stefan            #+#    #+#             */
/*   Updated: 2025/03/13 13:08:11 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
    std::string type;
public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);

    std::string getType() const;

    // Pure virtual function makes this class abstract
    virtual void makeSound() const = 0;
};

#endif