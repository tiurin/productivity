#!/bin/zsh

# install homebrew
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# commands homebrew asks to run after install
(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> /Users/$(id -un)/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"

# install terminal programs
brew install --quiet git
brew install --quiet gh 
brew install --quiet htop
brew install --quiet jq
brew install --quiet tree
brew install --quiet rename

# install containers
brew install --quiet lima
brew install --quiet orbstack
brew install --quiet --cask docker
brew install --quiet localstack-cli

# install apps
brew install --quiet --cask iterm2

brew install --quiet --cask 1password
brew install --quiet 1password-cli
brew install --quiet --cask appcleaner

brew install --quiet --cask google-chrome
brew install --quiet --cask brave-browser
brew install --quiet --cask firefox

brew install --quiet --cask font-jetbrains-mono
brew install --quiet --cask pycharm
brew install --quiet --cask visual-studio-code

brew install --quiet --cask rectangle-pro
brew install --quiet --cask vlc 
brew install --quiet --cask surfshark

