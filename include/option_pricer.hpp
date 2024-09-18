#pragma once
#ifndef OPTION_PRICER_HPP
#define OPTION_PRICER_HPP

#include <concepts>
#include <cmath>

/**
 * @brief Concept for types that can be used as option parameters
 */
template<typename T>
concept OptionParameter = std::is_floating_point_v<T>;

/**
 * @brief Class for pricing interest rate options
 */
class OptionPricer {
public:
    /**
     * @brief Price a European call option using the Black-Scholes model
     * @param spot The current spot price of the underlying asset
     * @param strike The strike price of the option
     * @param rate The risk-free interest rate
     * @param volatility The volatility of the underlying asset
     * @param timeToMaturity Time to maturity in years
     * @return The price of the call option
     */
    template<OptionParameter T>
    T priceEuropeanCall(T spot, T strike, T rate, T volatility, T timeToMaturity);
};

#endif // OPTION_PRICER_HPP