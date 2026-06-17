{name, flags, pkgs}:

pkgs.stdenv.mkDerivation rec {
  pname  = "${name}";
  version = "1.0";
  buildInputs = with pkgs; [ gcc ];

  dontUnpack = true;
  dontBuild = true;
  dontConfigure = true;

  newBitsStdc = ''
    #ifndef my_stdc_h_INCLUDED
    #define my_stdc_h_INCLUDED
    #include <iostream>
    #include <iomanip>
    #include <sstream>

    #include <algorithm>
    #include <numeric>
    #include <functional>
    #include <utility>
    #include <iterator>
    #include <bitset>

    #include <list>
    #include <queue>
    #include <stack>
    #include <vector>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

    #include <string>
    #include <cstring>

    #include <cmath>
    #include <cstdlib>
    #include <random>

    #include <limits>
    #include <climits>

    #endif my_stdc_h_INCLUDED
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
