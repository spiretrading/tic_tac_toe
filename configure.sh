#!/bin/bash
source="${BASH_SOURCE[0]}"
while [ -h "$source" ]; do
  dir="$(cd -P "$(dirname "$source")" >/dev/null 2>&1 && pwd -P)"
  source="$(readlink "$source")"
  [[ $source != /* ]] && source="$dir/$source"
done
directory="$(cd -P "$(dirname "$source")" >/dev/null 2>&1 && pwd -P)"
root="$(pwd -P)"
if [ ! -f "configure.sh" ]; then
  ln -s "$directory/configure.sh" configure.sh
fi
if [ ! -f "build.sh" ]; then
  ln -s "$directory/build.sh" build.sh
fi
targets="library"
targets+=" application"

for i in $targets; do
  if [ ! -d "$i" ]; then
    mkdir -p "$i"
  fi
  pushd "$i"
  "$directory/$i/configure.sh" -DD="$root/library/Dependencies" "$@"
  popd
done
