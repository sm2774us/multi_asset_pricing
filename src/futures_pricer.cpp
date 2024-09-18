#include "futures_pricer.hpp"
#include <cmath>

template<FuturesPrice T>
T FuturesPricer::priceFuture(T spotPrice, T interestRate, T timeToMaturity) {
    return spotPrice * std::exp(interestRate * timeToMaturity);
}