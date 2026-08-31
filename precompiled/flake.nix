{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-25.05";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system; };

    gccPhc  = import ./gccPhc.nix;
    mktempl = import ./mktempl.nix;
  in {

    devShells.x86_64-linux.default = pkgs.mkShell {

      shellHook = ''
        SHELL="fish";
        exec fish
      '';


      packages = with pkgs; [
        valgrind
        zsh
        gcc
        mold

        (mktempl (pkgs))
        (gccPhc {pkgs = pkgs; name = "m_gch";       flags = "";})
        (gccPhc {pkgs = pkgs; name = "m_gch_g";     flags = "-g";})
        (gccPhc {pkgs = pkgs; name = "m_gch_O0";    flags = "-O0";})
        (gccPhc {pkgs = pkgs; name = "m_gch_O2";    flags = "-O2";})
        (gccPhc {pkgs = pkgs; name = "m_gch_17";    flags = "-std=gnu++17";})
        (gccPhc {pkgs = pkgs; name = "m_gch_17_g";  flags = "-std=gnu++17 -g";})
        (gccPhc {pkgs = pkgs; name = "m_gch_17_O0"; flags = "-std=gnu++17 -O0";})
        (gccPhc {pkgs = pkgs; name = "m_gch_17_O2"; flags = "-std=gnu++17 -O2";})
        (gccPhc {pkgs = pkgs; name = "m_gch_20";    flags = "-std=gnu++20";})
        (gccPhc {pkgs = pkgs; name = "m_gch_20_g";  flags = "-std=gnu++20 -g";})
        (gccPhc {pkgs = pkgs; name = "m_gch_20_O0"; flags = "-std=gnu++20 -O0";})
        (gccPhc {pkgs = pkgs; name = "m_gch_20_O2"; flags = "-std=gnu++20 -O2";})
        (gccPhc {pkgs = pkgs; name = "m_gch_23";    flags = "-std=gnu++23";})
        (gccPhc {pkgs = pkgs; name = "m_gch_23_g";  flags = "-std=gnu++23 -g";})
        (gccPhc {pkgs = pkgs; name = "m_gch_23_O0"; flags = "-std=gnu++23 -O0";})
        (gccPhc {pkgs = pkgs; name = "m_gch_23_O2"; flags = "-std=gnu++23 -O2";})
      ];

      NIX_CFLAGS_COMPILE = (builtins.getEnv "NIX_CFLAGS_COMPILE") + "-fuse-ld=gold";
    };

  };
}
