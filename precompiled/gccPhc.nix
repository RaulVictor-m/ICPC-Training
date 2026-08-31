{name, flags, pkgs}:

pkgs.stdenv.mkDerivation rec {
  pname  = "${name}";
  version = "1.0";
  buildInputs = with pkgs; [ gcc ];

  dontUnpack = true;
  dontBuild = true;
  dontConfigure = true;

  newBitsStdc = ''
    #ifndef MY_STDC_H_INCLUDED
    #define MY_STDC_H_INCLUDED

    // ============================================================================
    // C++17 Baseline
    // ============================================================================
    // Low-Level C Standard Libraries & Fast I/O
    #include <cstdio>         // getchar_unlocked, fread, fwrite, printf, scanf
    #include <cctype>         // isdigit, isalpha, tolower, toupper
    #include <cmath>          // pow, sqrt, log2, abs
    #include <cstdlib>        // malloc, free, abs, exit
    #include <cstring>        // memset, memcpy, strlen
    #include <climits>        // INT_MAX, LLONG_MAX
    #include <cfloat>         // DBL_MAX, LDBL_MAX
    #include <cassert>        // assert
    #include <cstdint>        // int64_t, uint64_t, int32_t
    #include <cinttypes>      // PRId64, PRIu64 formatting macros
    #include <chrono>         // High-resolution timers for bench/random seeds

    // Stream I/O
    #include <iostream>
    #include <iomanip>
    #include <sstream>
    #include <fstream>

    // Standard Containers & Dynamic Memory
    #include <vector>
    #include <array>
    #include <deque>
    #include <list>
    #include <forward_list>   // Memory-efficient singly-linked list
    #include <queue>          // std::queue, std::priority_queue
    #include <stack>
    #include <set>
    #include <map>
    #include <unordered_set>
    #include <unordered_map>
    #include <memory_resource> // std::pmr (Ultra-fast arena/bump allocation)

    // Utilities, Algorithms, & Math
    #include <algorithm>
    #include <numeric>        // gcd, lcm, iota, accumulate
    #include <functional>     // std::function, std::greater, std::hash
    #include <utility>        // std::pair, std::move, std::swap
    #include <iterator>
    #include <tuple>
    #include <bitset>
    #include <complex>        // FFT and 2D Geometry
    #include <valarray>       // Slice operations and array math
    #include <random>         // mt19937, mt19937_64
    #include <limits>
    #include <memory>
    #include <type_traits>
    #include <string>
    #include <string_view>
    #include <regex>          // Pattern matching
    #include <optional>
    #include <variant>
    #include <any>
    #include <charconv>       // std::to_chars, std::from_chars

    // ============================================================================
    // C++20 Additions
    // ============================================================================
    #if __cplusplus >= 202002L
    #include <concepts>
    #include <ranges>
    #include <span>
    #include <bit>            // std::popcount, std::countl_zero, std::has_single_bit
    #include <numbers>        // std::numbers::pi
    #include <compare>        // <=> operator
    #include <version>
    #include <source_location>

    #if defined(__has_include)
      #if __has_include(<format>)
        #include <format>
      #endif
    #endif
    #endif

    // ============================================================================
    // C++23 Additions
    // ============================================================================
    #if __cplusplus >= 202302L
    #include <expected>

    #if defined(__has_include)
      #if __has_include(<flat_map>)
        #include <flat_map>
      #endif
      #if __has_include(<flat_set>)
        #include <flat_set>
      #endif
      #if __has_include(<print>)
        #include <print>
      #endif
      #if __has_include(<generator>)
        #include <generator>
      #endif
      #if __has_include(<stdfloat>)
        #include <stdfloat>    // std::float128_t, std::float64_t
      #endif
      #if __has_include(<mdspan>)
        #include <mdspan>
      #endif
      #if __has_include(<stacktrace>)
        #include <stacktrace>
      #endif
    #endif
    #endif

    #endif // MY_STDC_H_INCLUDED
  '';

  installPhase = ''
    # version=$(gcc -dumpversion)
    # g++ ${flags} -x c++-header -o stdc++.h.gch \
    # ${pkgs.gcc-unwrapped}/include/c++/$version/x86_64-unknown-linux-gnu/bits/stdc++.h

    # g++ ${flags} -x c++-header -o iostream.gch \
    # ${pkgs.gcc-unwrapped}/include/c++/$version/iostream

    echo "${newBitsStdc}" > stdc++.h
    g++ ${flags} -x c++-header -o stdc++.h.gch ./stdc++.h
    mkdir -p $out/include/bits/
    mv stdc++.h.gch $out/include/bits
  '';
}
