/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:28:20 by stefan            #+#    #+#             */
/*   Updated: 2025/03/06 12:53:15 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* zombieHeap = newZombie("zombieHeap");
    zombieHeap->announce();
    delete zombieHeap;

    randomChump("zombieStack");

    return (0);
}