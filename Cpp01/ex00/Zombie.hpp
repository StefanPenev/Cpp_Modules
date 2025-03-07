/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:29:57 by stefan            #+#    #+#             */
/*   Updated: 2025/03/07 15:34:56 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;
	
public:
	Zombie(std::string name);
	~Zombie(void); 
	void announce(void);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif