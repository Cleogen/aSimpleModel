#include "SimpleModel.h"

SimpleModel::SimpleModel(double precision, double step)
: precision(precision)
, step(step)
, w(42)
, b(0)
, train_data(0)
, train_data_size(0)
{}

SimpleModel::SimpleModel(const SimpleModel &simpleModel)
: precision(simpleModel.precision)
, step(simpleModel.step)
, w(simpleModel.w)
, b(simpleModel.b)
, train_data(simpleModel.train_data)
, train_data_size(0)
{}

SimpleModel::~SimpleModel() = default;

SimpleModel &SimpleModel::operator=(const SimpleModel &simpleModel) = default;

void SimpleModel::train(vector train_data, int &data_size) {
    int i = 0,limit = 0;
    double x = 0,y = 0,y_pred = 0;
    while (i < data_size){
        y = train_data[i][1];
        x = train_data[i][0];
        this->train_data.push_back({x,y});
        limit = 10000;
        while (fabs(y - y_pred) > precision && limit > 0){
            --limit;
            y_pred = predict(x);
            w -= (y_pred - y)*step;
            b = y - w*x;
        }
        ++i;
    }
    this->train_data_size += data_size;
}

double SimpleModel::predict(double &x) const{
    return (w*x + b);
}

SimpleModel::vector SimpleModel::get_train_data() const{
    return this->train_data;
}
