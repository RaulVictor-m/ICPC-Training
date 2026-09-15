{name, flags, pkgs}:

pkgs.stdenv.mkDerivation rec {
  pname  = "${name}";
  version = "1.0";
  buildInputs = with pkgs; [ gcc ];
  # hardeningDisable = [ "all" ];

  dontUnpack = true;
  dontBuild = true;
  dontConfigure = true;

  newBitsStdc = ''
  #ifndef MY_STDC_H_INCLUDED
  #define MY_STDC_H_INCLUDED

  // Low-Level C Standard Libraries & Fast I/O
  #include <cstdio>
  #include <cctype>
  #include <cmath>
  #include <cstdlib>
  #include <cstring>
  #include <climits>
  #include <cfloat>
  #include <cassert>
  #include <cstdint>
  #include <cinttypes>
  #include <chrono>

  // Stream I/O
  #include <iostream>
  #include <iomanip>

  // Standard Containers & Dynamic Memory
  #include <vector>
  #include <array>
  #include <deque>
  #include <list>
  #include <queue>
  #include <stack>
  #include <set>
  #include <map>
  #include <unordered_set>
  #include <unordered_map>

  // Utilities, Algorithms, & Math
  #include <algorithm>
  #include <numeric>
  #include <functional>
  #include <utility>
  #include <iterator>
  #include <tuple>
  #include <bitset>
  #include <random>
  #include <limits>
  #include <memory>
  #include <type_traits>
  #include <string>
  #include <string_view>
  #include <optional>
  #include <variant>
  #include <any>
  #include <charconv>

  // ============================================================================
  // Targeted Template Pre-Instantiations (.gch AST Warmers)
  // ============================================================================

  // Pairs
  // template struct std::pair<int, int>;
  // template struct std::pair<long long, long long>;

  // 1D Vectors
  // template class std::vector<int>;
  // template class std::vector<long long>;
  // template class std::vector<std::string>;
  // template class std::vector<std::pair<int, int>>;
  // template class std::vector<std::pair<long long, long long>>;

  // 2D Vectors
  // template class std::vector<std::vector<int>>;
  // template class std::vector<std::vector<long long>>;
  // template class std::vector<std::vector<std::pair<int, int>>>;

  // Requested Trees
  // template class std::set<long long>;
  // template class std::map<long long, long long>;

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
