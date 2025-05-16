# Conditioned Random Number Generator in C

This project generates an array of cryptographically secure random integers (0–99) using OpenSSL, applies custom conditioning to ensure values aren't clustered too closely, and then sorts the result.

## Features

- Uses OpenSSL for cryptographically secure randomness
- Applies a conditioning rule to avoid close neighbor values (e.g. `abs(a - b) <= 1`)
- Sorts the generated array
- Portable to macOS and Linux

## Project Structure
.
├── Makefile
├── include
│   └── handlers.h         # Function declarations
└── src
    ├── main.c             # Program entry point
    └── handlers.c         # Logic for generation, conditioning, and sorting

## Prerequisites

- **C compiler** (e.g. `gcc`)
- **OpenSSL development libraries**

## Build Instructions

### ✅ macOS (Homebrew OpenSSL)

```sh
brew install openssl
make
./bin/random_sort
```

### ✅ Linux (Debian/Ubuntu)
```sh
sudo apt install libssl-dev
make PLATFORM=linux
./bin/random_sort
```