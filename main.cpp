#include <iostream>

#include "graphing.hpp"

void example1();
void example2();

int main() {
    example1();
    example2();
    
    return 0;
}

void example1() {
    // Creating the graph (f, printWidth, printHeight, minX, maxX, minY, maxY)
    Graphing::Graph graph([](double x) {return std::sin(x)/(x);}, 149, 8, -8 * M_PI, 8 * M_PI, -1, 1);

    // Printing the graph
    std::cout << graph.getResult();
}

// A piecewise function
double f(double x) {
    if (x >= 1) {
        return cos(x);
    } else if (x > -1) {
        return -x;
    } else {
        return (x + 3) * (x + 3);
    }
}

void example2() {
    // Creating the graph (f, printWidth, printHeight, minX, maxX, minY, maxY)
    Graphing::Graph graph(f, 149, 16, -4, 4 * M_PI, -1, 2);

    // Overriding default settings
    graph.emptySquare = " ";
    graph.fillSquare = "•";

    // Printing the graph
    std::cout << graph.getResult();
}
