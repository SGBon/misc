#!/bin/bash
# not actually completely valid ansi because of mixed declarations, so requires extensions which many compilers support
CC=gcc
CFLAGS="-ansi -Wall"
EXE=vectest
LDFLAGS="-o "$EXE
SOURCES="cvector.c vectest.c"
$CC $CFLAGS $SOURCES $LDFLAGS
