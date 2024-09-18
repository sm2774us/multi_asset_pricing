#include "fx_pricer.hpp"
#include <cmath>

template<ExchangeRate T>
T FXPricer::priceForwardContract(T spot, T domesticRate, T foreignRate, T timeToMaturity) {
    return spot * std::exp((domesticRate - foreignRate) * timeToMaturity);
}