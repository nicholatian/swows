#!/bin/bash
#

dir=graphics/battle_transitions
pre=btl_tx_

function single() {
files=$(find ${dir} -type f -name '*.png');
for f in ${files}; do
	_f=${f##*/};
	_f=${_f%%.*};
	mv ${f} gfx/${pre}${_f}.4tn.ip.png;
done

files=$(find ${dir} -type f -name '*.bin');

for f in ${files}; do
	_f=${f##*/};
	_f=${_f%%.*};
	mv ${f} gfx/${pre}${_f}.tmap.bin;
done

files=$(find ${dir} -type f -name '*.pal');

for f in ${files}; do
	_f=${f##*/};
	_f=${_f%%.*};
	mv ${f} gfx/${pre}${_f}.jasc;
done
}

function multi() {
anims=$(find ${dir} -type d);

for a in ${anims}; do
	files=$(find ${a} -type f -name '*.png');
	for f in ${files}; do
		_f=${f##*/};
		_f=${_f%%.*};
		mv ${f} gfx/${pre}${a##*/}_${_f}.4tn.ip.png;
	done

	files=$(find ${a} -type f -name '*.bin');

	for f in ${files}; do
		_f=${f##*/};
		_f=${_f%%.*};
		mv ${f} gfx/${pre}${a##*/}_${_f}.tmap.bin;
	done

	files=$(find ${a} -type f -name '*.pal');

	for f in ${files}; do
		_f=${f##*/};
		_f=${_f%%.*};
		mv ${f} gfx/${pre}${a##*/}_${_f}.jasc;
	done
done

}

unset _f f a anims files pre dir;
