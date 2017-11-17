#!/usr/bin/env bash
set +h  # command turns off bash's hash function. 
umask 022
unset CFLAGS

export TK=/data/dp/r3ptoolchain
echo "TK=${TK}"

export TK_HOST=$(echo ${MACHTYPE} | sed -e 's/-[^-]*/-cross/')
echo "TK_HOST=${TK_HOST}"

export TK_TARGET="mipsel-xiaomi-linux-uclibc"
echo "TK_TARGET=${TK_TARGET}"

export CC="${TK_TARGET}-gcc"
export CXX="${TK_TARGET}-g++"
export AR="${TK_TARGET}-ar"
export AS="${TK_TARGET}-as"
export RANLIB="${TK_TARGET}-ranlib"
export LD="${TK_TARGET}-ld"
export STRIP="${TK_TARGET}-strip"

export PATH=${TK}/toolchain/bin:$PATH

export LC_ALL=POSIX

export LDFLAGS="-L${TK}/lib"
export CFLAGS="-w"	
export CPPFLAGS="-I${TK}/include"
export CXXFLAGS=$CFLAGS

export PREFIX=/data/dp/r3ptoolchain

