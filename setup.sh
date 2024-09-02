# install homebrew
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# commands homebrew asks to run after install
(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> /Users/$(id -un)/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"

# install ohmyzsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

