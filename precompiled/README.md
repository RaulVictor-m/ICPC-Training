# Precompiled

This is just a nix flake to help with compiling speed of cpp lib
keep in mind it has nothing special on it
it just makes a subset of the bits/stdc++.h lib
and precompiles that with the same name as the original lib
so it compiles faster

to use just type:
```
nix develop .
```
or if you are the project root dir:
```
nix develop precompiled
```
