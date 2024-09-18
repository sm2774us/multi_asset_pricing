# Financial Pricing Library

This library provides pricing models for various financial instruments including interest rate swaps, fixed income futures, interest rate options, and foreign exchange markets.

## Features

- Swap pricing
- Futures pricing
- Option pricing (European call options)
- Foreign exchange forward contract pricing

## Building the Project

To build the project, you need CMake 3.15 or higher and a C++20 compatible compiler. Follow these steps:

```bash
mkdir build
cd build
cmake ..
make
```

## Running Tests

After building the project, you can run the tests with:

```bash
ctest
```

## Running Benchmarks

After building the project, you can run the benchmarks with:

```bash
./benchmarks
```

## Documentation

To generate the documentation, you need Doxygen installed. Run the following command in the project root:

```bash
doxygen
```

The documentation will be generated in the `doc` directory.

## License

This project is licensed under the MIT License - see the LICENSE file for details.