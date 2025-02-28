/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:45:08 by stefan            #+#    #+#             */
/*   Updated: 2025/02/28 09:04:08 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
            std::cout << (char)std::toupper(argv[i][j]);
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}