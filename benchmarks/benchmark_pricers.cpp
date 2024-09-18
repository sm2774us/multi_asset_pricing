#include <benchmark/benchmark.h>
#include "swap_pricer.hpp"
#include "futures_pricer.hpp"
#include "option_pricer.hpp"
#include "fx_pricer.hpp"

static void BM_SwapPricer(benchmark::State& state) {
    SwapPricer pricer;
    double fixedRate = 0.05;
    std::vector<double> floatingRates(state.range(0), 0.04);
    
    for (auto _ : state) {
        benchmark::DoNotOptimize(pricer.priceSwap(fixedRate, floatingRates));
    }
}

static void BM_FuturesPricer(benchmark::State& state) {
    FuturesPricer pricer;
    double spotPrice = 100.0;
    double interestRate = 0.05;
    double timeToMaturity = 1.0;
    
    for (auto _ : state) {
        benchmark::DoNotOptimize(pricer.priceFuture(spotPrice, interestRate, timeToMaturity));
    }
}

static void BM_OptionPricer(benchmark::State& state) {
    OptionPricer pricer;
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double volatility = 0.2;
    double timeToMaturity = 1.0;
    
    for (auto _ : state) {
        benchmark::DoNotOptimize(pricer.priceEuropeanCall(spot, strike, rate, volatility, timeToMaturity));
    }
}

static void BM_FXPricer(benchmark::State& state) {
    FXPricer pricer;
    double spot = 1.3;
    double domesticRate = 0.02;
    double foreignRate = 0.01;
    double timeToMaturity = 1.0;
    
    for (auto _ : state) {
        benchmark::DoNotOptimize(pricer.priceForwardContract(spot, domesticRate, foreignRate, timeToMaturity));
    }
}

BENCHMARK(BM_SwapPricer)->Range(8, 8<<10);
BENCHMARK(BM_FuturesPricer);
BENCHMARK(BM_OptionPricer);
BENCHMARK(BM_FXPricer);

BENCHMARK_MAIN();