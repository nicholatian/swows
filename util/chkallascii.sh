#!/bin/sh
# -*- coding: utf-8 -*-

if [ "$(uname -s)" = 'Darwin' ]; then
	FIND='gfind';
else
	FIND='find';
fi

util/chkascii.py $(${FIND} data/ -type f -name '*.snip') \
	$(${FIND} etc/ -type f) $(${FIND} src/ -type f) \
	$(${FIND} util/ -type f -name '*.py') .clang-format \
	$(${FIND} util/ -type f -name '*.sh') .gitattributes .gitignore COPYING \
	Makefile $(${FIND} data/ -type f -name '*.scrip') \
	$(${FIND} .vscode/ -type f) 3rdparty/README;
