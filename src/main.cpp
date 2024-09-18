#include "swap_pricer.hpp"
#include "futures_pricer.hpp"
#include "option_pricer.hpp"
#include "fx_pricer.hpp"
#include <iostream>
#include <vector>

int main() {
    // Swap Pricing
    SwapPricer swapPricer;
    std::vector<double> fixedRates = {0.02, 0.025, 0.03};
    std::vector<std::vector<double>> floatingRates = {
        {0.018, 0.019, 0.02},
        {0.022, 0.023, 0.024},
        {0.028, 0.029, 0.03}
    };

    std::cout << "Swap Prices:\n";
    for (auto price : swapPricer.priceSwapsAsync(fixedRates, floatingRates)) {
        std::cout << price << "\n";
    }

    // Futures Pricing
    FuturesPricer futuresPricer;
    double spotPrice = 100.0;
    double interestRate = 0.05;
    double timeToMaturity = 1.0;

    std::cout << "\nFutures Price: " 
              << futuresPricer.priceFuture(spotPrice, interestRate, timeToMaturity) << "\n";

    // Option Pricing
    OptionPricer optionPricer;
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.2;
    timeToMaturity = 1.0;

    std::cout << "\nEuropean Call Option Price: " 
              << optionPricer.priceEuropeanCall(spot, strike, rate, volatility, timeToMaturity) << "\n";

    // FX Pricing
    FXPricer fxPricer;
    double fxSpot = 1.3;
    double domesticRate = 0.02;
    double foreignRate = 0.01;
    timeToMaturity = 1.0;

    std::cout << "\nForward FX Rate: " 
              << fxPricer.priceForwardContract(fxSpot, domesticRate, foreignRate, timeToMaturity) << "\n";

    return 0;
}