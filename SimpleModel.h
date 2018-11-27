#include <ostream>
#include <vector>
#include <cmath>

#pragma once

class SimpleModel {
    typedef std::vector<std::vector<double>> vector;
public:
    SimpleModel(double precision, double step);

    SimpleModel(const SimpleModel &simpleModel);

    ~SimpleModel();

    SimpleModel &operator=(const SimpleModel &simpleModel);

    /**
     * @param train_data - A 2 dimensional array width N rows and 2 columns,
     * first column is the input value (x), second output value (y)
     */
    void train(vector train_data, int &data_size);

    double predict(double &x) const;

    vector get_train_data() const;

private:
    double precision;
    double step;
    double w;
    double b;
    vector train_data;
    int train_data_size;
};
