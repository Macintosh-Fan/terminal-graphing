#include "graphing.hpp"

using namespace Graphing;

Graph::Graph(double(*f) (double), uint64_t printWidth, uint64_t printHeight, double minX, double maxX, double minY, double maxY) {
    this->f = f;
    this->printWidth = printWidth;
    this->printHeight = printHeight;
    this->minX = minX;
    this->maxX = maxX;
    this->minY = minY;
    this->maxY = maxY;
}

std::string Graph::getResult() {
    if (printWidth == 0 || printHeight == 0) {
        return "";
    }

    double squareYValues[printWidth];
    double x;
    for (uint64_t i = 0; i < printWidth; i++) {
        if (printWidth == 1) {
            x = (minX + maxX) / 2;
        } else {
            x = minX + i * (maxX - minX) / (printWidth - 1);
        }
        squareYValues[i] = f(x);
    }

    std::string resultString;
    double upperY, lowerY;
    for (uint64_t height = 0; height < printHeight; height++) {
        upperY = maxY - height * (maxY - minY) / printHeight;
        lowerY = maxY - (height + 1) * (maxY - minY) / printHeight;

        for (uint64_t width = 0; width < printWidth; width++) {
            if (squareYValues[width] >= lowerY && squareYValues[width] <= upperY) {
                resultString.append(fillSquare);
            } else {
                resultString.append(emptySquare);
            }
        }
        resultString.append("\n");
    }
    
    return resultString;
}
