/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:49:02 by stefan            #+#    #+#             */
/*   Updated: 2025/03/07 15:22:54 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif