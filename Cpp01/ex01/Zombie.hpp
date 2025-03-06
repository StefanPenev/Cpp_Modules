/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:06:11 by stefan            #+#    #+#             */
/*   Updated: 2025/03/06 13:51:43 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
private:
    std::string name;
        
public:
    Zombie(void);
    ~Zombie(void); 
    void setName(std::string name);
    void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif