/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:42:48 by stefan            #+#    #+#             */
/*   Updated: 2025/03/12 17:27:38 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- Creating ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");

    std::cout << "\n--- Creating ScavTrap ---" << std::endl;
    ScavTrap scav("Scavy");

    std::cout << "\n--- Creating FragTrap ---" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n--- Testing ClapTrap ---" << std::endl;
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    scav.attack("Target2");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n--- Testing FragTrap ---" << std::endl;
    frag.attack("Target3");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n--- End of Simulation ---" << std::endl;
    return 0;
}
