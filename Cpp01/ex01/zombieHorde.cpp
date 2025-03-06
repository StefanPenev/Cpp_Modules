/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:06:07 by stefan            #+#    #+#             */
/*   Updated: 2025/03/06 14:11:08 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return nullptr;

    Zombie* zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombieHorde[i].setName(name);
    }
    return zombieHorde;
}