#!/bin/sh

arduino-cli \
	compile \
	--verbose \
	--build-path ./build-micro \
	--fqbn arduino:avr:micro \
	--build-property \
	compiler.cpp.extra_flags="-DCONFIG_PROC_HAVE_LOG=1 -DCONFIG_PROC_INFO_BUFFER_SIZE=100"

