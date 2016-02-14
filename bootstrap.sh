#!/usr/bin/env bash

# install necessary ubuntu packages
apt-get update
apt-get install -y  make unrar autoconf automake libtool gcc g++ gperf \
  flex bison texinfo gawk ncurses-dev libexpat-dev python python-serial sed \
  git unzip

# clone esp-open-sdk
git clone --recursive https://github.com/pfalcon/esp-open-sdk.git
cd esp-open-sdk
make STANDALONE=y # default, but make it explicit

echo -e '\n\nexport PATH=/home/vagrant/esp-open-sdk/xtensa-lx106-elf/bin:$PATH' >> ~/.profile
