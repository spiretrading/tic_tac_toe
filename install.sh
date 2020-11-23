#!/bin/bash
function print_usage() {
  echo "Usage: install.sh"
}

function install_dependencies() {
  if [ $is_root -eq 1 ]; then
    apt-get update
    apt-get install -y automake cmake g++ gcc gdb git libncurses5-dev \
      libreadline6-dev libtool libxml2 libxml2-dev m4 make nodejs \
      npm parallel python3 python3-dev python3-pip ruby zip
  fi
}

if [ "$EUID" == "0" ]; then
  is_root=1
else
  is_root=0
fi
username=$(echo ${SUDO_USER:-${USER}})

install_dependencies
sudo -u $username ./build.sh
