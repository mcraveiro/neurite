#!/bin/sh

sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq

# clang
if [ "$CXX" == "clang++" ]; then
    sudo sh -c "echo 'deb http://llvm.org/apt/precise/ llvm-toolchain-precise-3.7 main' >> /etc/apt/sources.list"
    sudo sh -c "echo 'deb http://llvm.org/apt/precise/ llvm-toolchain-precise main' >> /etc/apt/sources.list"
    wget -O - http://llvm.org/apt/llvm-snapshot.gpg.key | sudo apt-key add -
    sudo apt-get update -qq

    # clang 3.7
    sudo apt-get install --allow-unauthenticated -qq clang-3.7
    which clang-3.7
    export CXX="clang++-3.7" CC="clang-3.7"
fi

# g++
if [ "$CXX" = "g++" ]; then
    sudo apt-get install -qq g++-5
    export CXX="g++-5" CC="gcc-5" GCOV="gcov-5"
fi

# ninja
sudo apt-get install ninja-build

# eigen
sudo apt-get install libeigen3-dev

# cgal
sudo apt-get install libcgal-dev

# deps
version=8
wget --no-check-certificate https://dl.dropboxusercontent.com/u/541873/packages/dogen_deps_gcc_5.3_linux_amd64_v${version}.bz2 -O /tmp/dogen_deps_gcc_5.3_linux_amd64_v${version}.bz2
mkdir /tmp/dogen_deps
tar -xaf /tmp/dogen_deps_gcc_5.3_linux_amd64_v${version}.bz2 -C /tmp/dogen_deps

# cmake
wget --no-check-certificate https://cmake.org/files/v3.4/cmake-3.4.1-Linux-x86_64.tar.gz -O /tmp/cmake-3.4.1-Linux-x86_64.tar.gz
tar xf /tmp/cmake-3.4.1-Linux-x86_64.tar.gz -C /tmp
sudo cp -r /tmp/cmake-3.4.1-Linux-x86_64/* /usr

# coverage
sudo pip install cpp-coveralls
