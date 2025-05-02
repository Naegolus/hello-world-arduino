#!/bin/sh

avr-nm \
	-SC \
	--size-sort \
	build-micro/sketch_may02a.ino.elf \
	| grep -E ' [DdBb] '

