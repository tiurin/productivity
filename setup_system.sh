#!/bin/zsh

# set less space between icons in menu bar so that they all fit before notch starts. don't want to use a separate app just to be able to fit all the icons
# https://apple.stackexchange.com/questions/406316/can-the-spacing-of-menu-bar-apps-be-modified-in-macos-big-sur-and-later/465674#465674

defaults -currentHost write -globalDomain NSStatusItemSpacing -int 6
defaults -currentHost write -globalDomain NSStatusItemSelectionPadding -int 3
