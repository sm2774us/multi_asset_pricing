#pragma once
#ifndef FX_PRICER_HPP
#define FX_PRICER_HPP

#include <concepts>

/**
 * @brief Concept for types that can be used as exchange rates
 */
template<typename T>
concept ExchangeRate = std::is_arithmetic_v<T>;

/**
 * @brief Class for pricing foreign exchange instruments
 */
class FXPricer {
public:
    /**
     * @brief Price a forward foreign exchange contract
     * @param spot The current spot exchange rate
     * @param domesticRate The domestic interest rate
     * @param foreignRate The foreign interest rate
     * @param timeToMaturity Time to maturity in years
     * @return The forward exchange rate
     */
    template<ExchangeRate T>
    T priceForwardContract(T spot, T domesticRate, T foreignRate, T timeToMaturity);
};

#endif // FX_PRICER_HPP