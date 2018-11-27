#include <iostream>
#include "SimpleModel.h"
#include <vector>

int main() {
    std::vector<std::vector<double>> data;
    int data_size = 10;
    double x = 0,y = 0;
    for (int i = 0; i < data_size; ++i) {
        std::cout << "Enter:\n";
        std::cin >> x >> y;
        data.push_back({x,y});
    }
    SimpleModel simpleModel = SimpleModel(0.1,0.1);
    simpleModel.train(data,data_size);
    std::cout << "model trained\n";

    for (int j = 0; j < 10; ++j) {
        std::cin >> x;
        std::cout << "Prediction: " << simpleModel.predict(x);
    }

    return 0;
}