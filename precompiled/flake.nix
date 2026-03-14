{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-25.05";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system; };

    gccPhc = {name, flags}: pkgs.stdenv.mkDerivation rec {
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
    };
  in {

    devShells.x86_64-linux.default = pkgs.mkShell {

      shellHook = ''
        SHELL="${pkgs.fish}/bin/fish";
        exec fish
      '';


      packages = with pkgs; [
        zsh
        gcc
        mold
        (gccPhc {name = "m_gch";       flags = "";})
        (gccPhc {name = "m_gch_O0";    flags = "-O0";})
        (gccPhc {name = "m_gch_O2";    flags = "-O2";})
        (gccPhc {name = "m_gch_17";    flags = "-std=c++17";})
        (gccPhc {name = "m_gch_17_O0"; flags = "-std=c++17 -O0";})
        (gccPhc {name = "m_gch_17_O2"; flags = "-std=c++17 -O2";})
        (gccPhc {name = "m_gch_20";    flags = "-std=c++20";})
        (gccPhc {name = "m_gch_20_O0"; flags = "-std=c++20 -O0";})
        (gccPhc {name = "m_gch_20_O2"; flags = "-std=c++20 -O2";})
      ];

      NIX_CFLAGS_COMPILE = (builtins.getEnv "NIX_CFLAGS_COMPILE") + "-fuse-ld=gold";
    };

  };
}
