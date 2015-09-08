**ELKS**, the Embeddable Linux Kernel Subset

This is a project to write a Linux-like operating system for ancient
computers running an Intel 8086-compatible processor. To build ELKS, you
will need to obtain a copy of Dev86, currently available at:

https://github.com/jbruchon/dev86

When you build dev86, you need to move, copy, or symlink to it in the
ELKS source code root. For a Dev86 source at /usr/src/dev86 do this:

user:/usr/src/elks$ ln -s /usr/src/dev86 dev86

A script that attempts to automate the build process and make it easier
for ELKS newbies has been provided. Simply run:

./build.sh

If you want to clean everything up afterwards, run './build.sh clean'
and it will run 'make clean' in the build directories for you.

The general build procedure for ELKS is as follows:

* Build Dev86, usually with default options

* Make sure 'dev86' is beside 'elks' 'elkscmd' etc.

* 'cd elks'

* 'make menuconfig' and configure the kernel

* Run 'make' to build the kernel

* 'cd ../elkscmd'

* 'make' (builds the core command line utilities and network stack)

* As root, run 'make [imagetype]' where image type is one of these:

  - full3: 1.44MB 3.5" floppy image, all-inclusive

  - full1680: same as full3 but on a 1.68MB 3.5" "extended format" floppy

  - full5: 1.2MB 5.25" floppy image, all-inclusive

  - comb: 720K floppy image, ELKS kernel plus minimal root filesystem

  - comb_net: Same as 'comb' but with network components included

  - comb360: 360K bootable floppy image with very minimal root filesystem

  - boot: 360K floppy image, ELKS kernel only

  - root: 360K floppy image, minimal root filesystem only

  - images: make all images but don't create an archive of them
  - images.zip: make all images, pack into a Zip-compress archive
  - images.tar.gz: make all images, pack into Gzip-compressed tar archive
  - images.tar.xz: make all images, pack into XZ-compressed tar archive

Questions? Problems? Patches? Join and email the Linux-8086 mailing list at
linux-8086@vger.kernel.org or email the maintainer at jody@jodybruchon.com

* Note: official Dev86 is hosted at https://github.com/lkundrak/dev86
