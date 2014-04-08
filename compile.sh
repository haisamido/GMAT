#-------------------------------------------------------------------------------
# Script to compile:
#  1) SPICE
#  2) wxGTK-2.8.12
#  3) gmat
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# sudo if you're using sudo
#-------------------------------------------------------------------------------
sudo="sudo"
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Enable epel
#-------------------------------------------------------------------------------
wget http://dl.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm
$sudo rpm -Uvh epel-release-6*.rpm
rm ./epel-release-6*.rpm
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Prerequisites
#-------------------------------------------------------------------------------
$sudo yum install -y  git gcc make cmake binutils automake autoconf csh
#-------------------------------------------------------------------------------
# GTK
#-------------------------------------------------------------------------------
$sudo yum install -y  gtk+-devel gtk2-devel libtiff-devel
#-------------------------------------------------------------------------------
# OpenGL
#-------------------------------------------------------------------------------
$sudo yum install -y  mesa-libGL-devel mesa-libGLU-devel
$sudo yum groupinstall -y "Development Tools"
$sudo yum install -y  compat-libf2c-34
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# f2c : http://pkgs.org/centos-6/atrpms-i386/f2c-20031026-3.0.1.el6.i686.rpm.html 
# http://pkgs.org/centos-6/atrpms-x86_64/f2c-20031026-3.0.1.el6.x86_64.rpm
#-------------------------------------------------------------------------------
wget http://dl.atrpms.net/el6-i386/atrpms/stable/atrpms-repo-6-7.el6.i686.rpm
$sudo rpm -Uvh atrpms-repo*rpm
rm atrpms-repo*rpm
$sudo yum install -y f2c
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# 1) Compile SPICE
#-------------------------------------------------------------------------------
cd ./cspice
mkdir exe
echo "Compiling SPICE in `pwd`" 2>&1 | tee compile.log 
./makeall.csh 2>&1 | tee -a compile.log
echo "Finished compiling SPICE in `pwd`" 2>&1 | tee -a compile.log 
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# 2) Compile wxGTK-2.8.12
#-------------------------------------------------------------------------------
cd ..
cd ./wxGTK/wxGTK-2.8.12
mkdir build-gmat
cd build-gmat
echo "Configuring wxGTK-2.8.12 in `pwd`" | tee compile.log
../configure --prefix=`pwd` --with-opengl 2>&1 | tee -a compile.log 
echo "Compiling wxGTK-2.8.12 in `pwd`"  2>&1 | tee -a compile.log 
make 2>&1 | tee -a compile.log 
echo "Finished compiling wxGTK-2.8.12 in `pwd`" 2>&1 | tee -a compile.log 
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# 3) Compile gmat
#-------------------------------------------------------------------------------
cd ../../../gmat
echo "Compiling gmat in `pwd`" | tee compile.log
make clean 2>&1 2>&1 | tee -a compile.log
make 2>&1 | tee -a compile.log
echo "Finished gmat in `pwd`" 2>&1 | tee -a compile.log 
#-------------------------------------------------------------------------------

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./

# For Later
#export BUILD_64BIT=1
#export PLATFORM=linux

#export USE_SPICE=1
#export CONSOLE_APP=0
#export DEBUG_BUILD=0
#export PROFILE_BUILD=0
#export WX_28_SYNTAX=1
#export USE_STC_EDITOR=0


