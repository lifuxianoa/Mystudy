# .bashrc

# User specific aliases and functions

alias rm='rm -i'
alias cp='cp -i'

alias mv='mv -i'
alias vi='vim'
# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

export KERNELMODE=n
#export MODE=proxy
export PLATFORM=97405
export BCHP_VER=C0
export SMP=y
export DEBUG=y

export MEDIA_ASF_SUPPORT=y
export MEDIA_AVI_SUPPORT=y
export RAP_AC3_SUPPORT=y
export RAP_WMA_SUPPORT=y

#export astm_enabled=y
export LD_LIBRARY_PATH=/opt/refsw/src/nexus/player/player_bcm_1.0/plugins

export PATH=~/Build/bcm7405/bin:$PATH
export PKG_CONFIG_PATH=~/Build/bcm7405/lib/pkgconfig
#export ARCH=mipsel-linux-uclibc

source ~/.git-completion.bash
