#!/usr/bin/env bash

# give user vagrant access to /dev/ttyUSB0
sudo usermod -a -G dialout vagrant

# install necessary ubuntu packages
sudo apt-get update
sudo apt-get install -y  make unrar autoconf automake libtool gcc g++ gperf \
  flex bison texinfo gawk ncurses-dev libexpat-dev python python-serial sed \
  git unzip usbutils linux-image-extra-virtual picocom

# clone esp-open-sdk
su vagrant <<'EOF'
git clone --recursive https://github.com/pfalcon/esp-open-sdk.git
cd esp-open-sdk
make STANDALONE=y # default, but make it explicit

echo -e '\n\nexport PATH=/home/vagrant/esp-open-sdk/xtensa-lx106-elf/bin:$PATH' >> ~/.profile
EOF
