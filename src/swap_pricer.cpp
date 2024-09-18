#include "swap_pricer.hpp"
#include <numeric>

template<InterestRate T, std::ranges::input_range R>
requires std::same_as<std::ranges::range_value_t<R>, T>
T SwapPricer::priceSwap(T fixedRate, R&& floatingRates) {
    T sum = std::accumulate(floatingRates.begin(), floatingRates.end(), T{});
    T avgFloatingRate = sum / std::ranges::distance(floatingRates);
    return fixedRate - avgFloatingRate;
}

template<InterestRate T, std::ranges::input_range R1, std::ranges::input_range R2>
requires std::same_as<std::ranges::range_value_t<R1>, T> &&
         std::same_as<std::ranges::range_value_t<R2>, std::vector<T>>
std::generator<T> SwapPricer::priceSwapsAsync(R1&& fixedRates, R2&& floatingRates) {
    auto fixedIt = fixedRates.begin();
    auto floatingIt = floatingRates.begin();

    while (fixedIt != fixedRates.end() && floatingIt != floatingRates.end()) {
        co_yield priceSwap(*fixedIt, *floatingIt);
        ++fixedIt;
        ++floatingIt;
    }
}