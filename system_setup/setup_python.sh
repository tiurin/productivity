#!/bin/zsh

#prepare pyenv
brew install --quiet pyenv

echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.zshrc
echo '[[ -d $PYENV_ROOT/bin ]] && export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.zshrc
echo 'eval "$(pyenv init -)"' >> ~/.zshrc
echo '
# alias to activate venv with a sensible default of .venv as virtual environment name.
activate() {
    local venv_name=${1:-".venv"}
    source $venv_name/bin/activate
}
' >> ~/.zshrc

source ~/.zshrc

# from https://github.com/pyenv/pyenv/wiki#suggested-build-environment
brew install --quiet openssl readline sqlite3 xz zlib tcl-tk

#install latest python 3 version and set it as global
pyenv install 3
pyenv latest 3 | xargs pyenv global

