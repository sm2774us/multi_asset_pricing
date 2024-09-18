cmake_minimum_required(VERSION 3.15)
project(FinancialPricingLibrary VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main library
add_library(financial_pricing
    src/swap_pricer.cpp
    src/futures_pricer.cpp
    src/option_pricer.cpp
    src/fx_pricer.cpp
)

target_include_directories(financial_pricing PUBLIC include)

# Main executable
add_executable(pricing_app src/main.cpp)
target_link_libraries(pricing_app PRIVATE financial_pricing)

# Testing
enable_testing()
find_package(Catch2 3 REQUIRED)
add_executable(tests tests/test_pricers.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain financial_pricing)

# Benchmarking
find_package(benchmark REQUIRED)
add_executable(benchmarks benchmarks/benchmark_pricers.cpp)
target_link_libraries(benchmarks PRIVATE benchmark::benchmark financial_pricing)