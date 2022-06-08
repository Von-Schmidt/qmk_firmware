# CRKBD layout used by mom

Layout is programmed to use with the czech language, but works with a normal english layout as well.

It is a work in progress.

Other crkbd keymaps used as inspiration.

To flash the halves use:

```
#left side
make crkbd:mom-corne:dfu-split-left
#right side, with RGB matrix fix
make crkbd:mom-corne:dfu-split-right RGB_MATRIX_SPLIT_RIGHT=yes
```
