#pragma once
#ifndef SWAP_PRICER_HPP
#define SWAP_PRICER_HPP

#include <concepts>
#include <ranges>
#include <vector>
#include <coroutine>

/**
 * @brief Concept for types that can be used as interest rates
 */
template<typename T>
concept InterestRate = std::is_arithmetic_v<T>;

/**
 * @brief Class for pricing interest rate swaps
 */
class SwapPricer {
public:
    /**
     * @brief Price an interest rate swap
     * @param fixedRate The fixed rate of the swap
     * @param floatingRates A range of floating rates
     * @return The price of the swap
     */
    template<InterestRate T, std::ranges::input_range R>
    requires std::same_as<std::ranges::range_value_t<R>, T>
    T priceSwap(T fixedRate, R&& floatingRates);

    /**
     * @brief Asynchronously price multiple swaps
     * @param fixedRates A range of fixed rates
     * @param floatingRates A range of ranges of floating rates
     * @return A coroutine that yields swap prices
     */
    template<InterestRate T, std::ranges::input_range R1, std::ranges::input_range R2>
    requires std::same_as<std::ranges::range_value_t<R1>, T> &&
             std::same_as<std::ranges::range_value_t<R2>, std::vector<T>>
    std::generator<T> priceSwapsAsync(R1&& fixedRates, R2&& floatingRates);
};

#endif // SWAP_PRICER_HPP