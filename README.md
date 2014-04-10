On the Linux CentOS 6.5 (x86_64) command line execute the below four lines:
```bash
export GMAT_BRANCH="x86_64.Linux.CentOS_6.5"
wget https://github.com/haisamido/GMAT/archive/${GMAT_BRANCH}.zip
unzip ${GMAT_BRANCH}.zip
cd ${GMAT_BRANCH}
./compile.sh
```
To execute GMAT follow these steps:
```bash
cd gmat/application/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
./GMAT
```

IGNORE WHAT IS BELOW FOR NOW
```bash
#-------------------------------------------------------------------------------
# Compilation attempt of svn co https://svn.code.sf.net/p/gmat/code/trunk gmat on Centos 6.5 *(x86_64)*
# GMAT Compilations Instructions: http://gmatcentral.org/display/GW/Building+on+Linux
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Setup
#-------------------------------------------------------------------------------
export PROJECT_DIR="${HOME}/Development"
export GMAT_DIR="${PROJECT_DIR}/GMAT"
export GMAT_DOWNLOADS="${GMAT_DIR}/downloads"
export BUILD_ARCH="linux64"
mkdir -p "${GMAT_DOWNLOADS}"
cd "${GMAT_DOWNLOADS}"
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Prerequisites
#-------------------------------------------------------------------------------
sudo yum install -y  gcc make cmake binutils automake autoconf gtk+-devel gtk2-devel libtiff-devel csh
sudo yum groupinstall "Development Tools"
sudo yum install -y  compat-libf2c-34
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# wxGTK 2.8.12
#-------------------------------------------------------------------------------
#-------------------------------------------------------------------------------
# OpenGL headers needed by WxGTK
#-------------------------------------------------------------------------------
sudo yum install -y  mesa-libGL-devel mesa-libGLU-devel
#-------------------------------------------------------------------------------
cd "${GMAT_DOWNLOADS}"
wget http://tinyurl.com/wxGTK-2-8-12-tar-gz
mv wxGTK-2-8-12-tar-gz wxGTK-2-8-12.tar.gz
tar zxvf wxGTK-2-8-12.tar.gz

cd ./wxGTK-2.8.12
chmod a+x ./configure
mkdir build-gmat
cd build-gmat
../configure --prefix=`pwd` --with-opengl
make
sudo make install
cd ./lib
ln -s libwx_base-2.8.so.0 libwx_base-2.8.so
cd "${GMAT_DOWNLOADS}"

#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# f2c : http://pkgs.org/centos-6/atrpms-i386/f2c-20031026-3.0.1.el6.i686.rpm.html 
# http://pkgs.org/centos-6/atrpms-x86_64/f2c-20031026-3.0.1.el6.x86_64.rpm
#-------------------------------------------------------------------------------
wget http://dl.atrpms.net/el6-i386/atrpms/stable/atrpms-repo-6-7.el6.i686.rpm
sudo rpm -Uvh atrpms-repo*rpm
sudo yum install -y  f2c
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# SPICE (64bit)
#-------------------------------------------------------------------------------
cd "${GMAT_DOWNLOADS}"
wget  http://naif.jpl.nasa.gov/pub/naif/toolkit//C/PC_Linux_GCC_64bit/packages/cspice.tar.Z
gunzip cspice.tar.Z
tar xvf cspice.tar
cd cspice
./makeall.csh
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# PCRE
#-------------------------------------------------------------------------------
sudo yum install -y  pcre pcre-devel
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# GMAT
#-------------------------------------------------------------------------------
cd "${GMAT_DOWNLOADS}" 
svn co https://svn.code.sf.net/p/gmat/code/trunk gmat
cd gmat
export PLATFORM=linux
cp ./build/linux64/BuildEnv.mk ./src/
```
