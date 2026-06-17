pkgs:

pkgs.stdenv.mkDerivation rec {
  pname  = "mktempl";
  version = "1.0";

  dontUnpack = true;
  dontBuild = true;
  dontConfigure = true;

  templateSFile = ''
    #!/usr/bin/env bash
    if [ $# -ne 1 ]; then
      echo "Usage: newproject <name>"
      exit 1
    fi

    cp -r ${./template} "$1"
    chmod +rw "$1" -R
  '';

  installPhase = ''
    mkdir -p $out/bin
    echo '${templateSFile}' > $out/bin/mktempl
    chmod +x $out/bin/mktempl
  '';
}
