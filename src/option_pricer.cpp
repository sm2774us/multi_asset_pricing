#include "option_pricer.hpp"
#include <cmath>

template<OptionParameter T>
T OptionPricer::priceEuropeanCall(T spot, T strike, T rate, T volatility, T timeToMaturity) {
    T d1 = (std::log(spot / strike) + (rate + volatility * volatility / 2) * timeToMaturity) / (volatility * std::sqrt(timeToMaturity));
    T d2 = d1 - volatility * std::sqrt(timeToMaturity);
    
    T Nd1 = 0.5 * (1 + std::erf(d1 / std::sqrt(2)));
    T Nd2 = 0.5 * (1 + std::erf(d2 / std::sqrt(2)));
    
    return spot * Nd1 - strike * std::exp(-rate * timeToMaturity) * Nd2;
}