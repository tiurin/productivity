#!/bin/zsh

brew install --quiet pyenv

# from https://github.com/pyenv/pyenv/wiki#suggested-build-environment
brew install openssl readline sqlite3 xz zlib tcl-tk

pyenv install 3

