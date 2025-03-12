/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:05:15 by stefan            #+#    #+#             */
/*   Updated: 2025/03/12 10:38:06 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void testPoint(Point const &a, Point const &b, Point const &c, Point const &p, std::string label) {
    bool result = bsp(a, b, c, p);
    std::cout << label << " (" << p.getX() << ", " << p.getY() << "): "
              << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main() {
    // Define triangle vertices
    Point a(0, 0), b(5, 0), c(2.5, 5);

    // Test cases
    Point inside(2.5, 2);
    Point outside(6, 6);
    Point edge(2.5, 0);
    Point vertex(0, 0);
    Point nearEdge(2.5, 0.01);

    std::cout << "Triangle vertices: A(0,0), B(5,0), C(2.5,5)" << std::endl;
    std::cout << "-------------------------" << std::endl;

    testPoint(a, b, c, inside, "Inside point");
    testPoint(a, b, c, outside, "Outside point");
    testPoint(a, b, c, edge, "Edge point");
    testPoint(a, b, c, vertex, "Vertex point");
    testPoint(a, b, c, nearEdge, "Near edge point");

    return 0;
}
