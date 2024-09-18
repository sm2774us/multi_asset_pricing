#include <catch2/catch_test_macros.hpp>
#include "swap_pricer.hpp"
#include "futures_pricer.hpp"
#include "option_pricer.hpp"
#include "fx_pricer.hpp"

TEST_CASE("SwapPricer prices swaps correctly", "[swap_pricer]") {
    SwapPricer pricer;
    
    SECTION("Single swap pricing") {
        double fixedRate = 0.05;
        std::vector<double> floatingRates = {0.04, 0.045, 0.05, 0.055};
        
        double price = pricer.priceSwap(fixedRate, floatingRates);
        
        REQUIRE(price == Approx(0.0025));
    }
}

TEST_CASE("FuturesPricer prices futures correctly", "[futures_pricer]") {
    FuturesPricer pricer;
    
    SECTION("Single future pricing") {
        double spotPrice = 100.0;
        double interestRate = 0.05;
        double timeToMaturity = 1.0;
        
        double price = pricer.priceFuture(spotPrice, interestRate, timeToMaturity);
        
        REQUIRE(price == Approx(105.127));
    }
}

TEST_CASE("OptionPricer prices options correctly", "[option_pricer]") {
    OptionPricer pricer;
    
    SECTION("European call option pricing") {
        double spot = 100.0;
        double strike = 100.0;
        double rate = 0.05;
        double volatility = 0.2;
        double timeToMaturity = 1.0;
        
        double price = pricer.priceEuropeanCall(spot, strike, rate, volatility, timeToMaturity);
        
        REQUIRE(price == Approx(10.450506));
    }
}

TEST_CASE("FXPricer prices forward contracts correctly", "[fx_pricer]") {
    FXPricer pricer;
    
    SECTION("Forward FX contract pricing") {
        double spot = 1.3;
        double domesticRate = 0.02;
        double foreignRate = 0.01;
        double timeToMaturity = 1.0;
        
        double forwardRate = pricer.priceForwardContract(spot, domesticRate, foreignRate, timeToMaturity);
        
        REQUIRE(forwardRate == Approx(1.31302));
    }
}