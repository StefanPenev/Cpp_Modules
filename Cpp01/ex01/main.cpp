/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:05:24 by stefan            #+#    #+#             */
/*   Updated: 2025/03/06 14:13:14 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;

    Zombie* horde = zombieHorde(N, "HordeZombie");
    if (!horde) {
        std::cerr << "Failed to create a zombie horde!" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    std::cout << "\nDestroying the horde..." << std::endl;
    delete[] horde;

    return 0;
}