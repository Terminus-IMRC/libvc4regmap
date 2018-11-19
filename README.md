# `libvc4regmap`

A library for accessing peripherals (V3D etc.) on Raspberry Pi.

The register definitions are derived from
<code>[Brcm_Android_ICS_Graphics_Stack](https://docs.broadcom.com/docs/12358546)/brcm_usrlib/dag/vmcsx/vcinclude/bcm2708_chip/</code>.


## Installation

```
$ git clone https://github.com/Terminus-IMRC/libvc4regmap.git
$ cd libvc4regmap/
$ cmake .
$ make package
$ sudo dpkg -i libvc4regmap-x.y.z-system.deb
```


## Running tests

```
$ make
$ sudo ctest -V
```
