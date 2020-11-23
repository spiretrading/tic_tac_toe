#!/bin/bash
exit_status=0
source="${BASH_SOURCE[0]}"
while [ -h "$source" ]; do
  dir="$(cd -P "$(dirname "$source")" >/dev/null 2>&1 && pwd -P)"
  source="$(readlink "$source")"
  [[ $source != /* ]] && source="$dir/$source"
done
directory="$(cd -P "$(dirname "$source")" >/dev/null 2>&1 && pwd -P)"
root="$(pwd -P)"
if [ "$(uname -s)" = "Darwin" ]; then
  STAT='stat -x -t "%Y%m%d%H%M%S"'
else
  STAT='stat'
fi
if [ -f "cache_files/tic_tac_toe.txt" ]; then
  pt="$($STAT $directory/setup.sh | grep Modify | awk '{print $2 $3}')"
  mt="$($STAT cache_files/tic_tac_toe.txt | grep Modify | awk '{print $2 $3}')"
  if [[ ! "$pt" > "$mt" ]]; then
    exit 0
  fi
fi
cores="`grep -c "processor" < /proc/cpuinfo`"
if [ ! -d "doctest-2.3.6" ]; then
  wget https://github.com/onqtam/doctest/archive/2.3.6.zip --no-check-certificate
  if [ "$?" == "0" ]; then
    unzip 2.3.6.zip
  else
    exit_status=1
  fi
  rm -f 2.3.6.zip
fi
if [ ! -d "boost_1_72_0" ]; then
  wget https://dl.bintray.com/boostorg/release/1.72.0/source/boost_1_72_0.tar.gz -O boost_1_72_0.tar.gz --no-check-certificate
  if [ "$?" == "0" ]; then
    tar xvf boost_1_72_0.tar.gz
    pushd boost_1_72_0
    export BOOST_BUILD_PATH=$(pwd -P)
    ./bootstrap.sh
    ./b2 -j$cores --prefix="$root/boost_1_72_0" cxxflags="-std=c++17 -fPIC" install
    popd
    unset BOOST_BUILD_PATH
  else
    exit_status=1
  fi
  rm -f boost_1_72_0.tar.gz
fi
python3 -c "import git"
if [ "$?" != "0" ]; then
  pip3 install GitPython
fi
echo timestamp > cache_files/tic_tac_toe.txt
exit $exit_status
