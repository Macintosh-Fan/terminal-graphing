#ifndef GRAPHING_GRAPHING_HPP
#define GRAPHING_GRAPHING_HPP

#ifndef _LIBCPP_IOSTREAM
#include <iostream>
#endif

namespace Graphing {
    class Graph {
    public:
        double(*f) (double);
        uint64_t printWidth;
        uint64_t printHeight;
        double minX;
        double maxX;
        double minY;
        double maxY;

        const char* emptySquare = "□";
        const char* fillSquare = "■";

        Graph(double(*f) (double), uint64_t printWidth, uint64_t printHeight, double minX, double maxX, double minY, double maxY);

        std::string getResult();
    };
}

#endif
