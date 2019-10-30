pkgname='wbfs-merge-cli'
licence=('GPL')
pkgver=1.0
pkgrel=1
arch=("x86_64")
pkgdesc="CLI tool to merge WBFS and WBF1 files into a single WBFS file"
#source=("https://github.com/SamuelLira99/wbfs-merge-cli.git")
#md5sums=("SKIP")
install="$pkgname.install"

build() {
    git clone https://github.com/SamuelLira99/wbfs-merge-cli.git
    cd $pkgname
    ./configure
    make
}

package() {
    cd $pkgname
    sudo make install
}
