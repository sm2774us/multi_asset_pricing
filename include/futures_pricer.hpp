#pragma once
#ifndef FUTURES_PRICER_HPP
#define FUTURES_PRICER_HPP

#include <concepts>
#include <ranges>

/**
 * @brief Concept for types that can be used as futures prices
 */
template<typename T>
concept FuturesPrice = std::is_arithmetic_v<T>;

/**
 * @brief Class for pricing fixed income futures
 */
class FuturesPricer {
public:
    /**
     * @brief Price a fixed income future
     * @param spotPrice The current spot price
     * @param interestRate The risk-free interest rate
     * @param timeToMaturity Time to maturity in years
     * @return The theoretical futures price
     */
    template<FuturesPrice T>
    T priceFuture(T spotPrice, T interestRate, T timeToMaturity);
};

#endif // FUTURES_PRICER_HPP