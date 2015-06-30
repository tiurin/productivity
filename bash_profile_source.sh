export PATH=/usr/local/bin:$PATH
export PATH=/usr/local/sbin:$PATH

source ~/workspaces/git/contrib/completion/git-prompt.sh
source ~/workspaces/git/contrib/completion/git-completion.bash

# Custom bash prompt via kirsle.net/wizards/ps1.html
export GIT_PS1_SHOWDIRTYSTATE=1
export PS1='\u@\h: \[$(tput bold)\]\w\[$(tput setaf 5)\]$(__git_ps1)\[$(tput setaf 1)\]\n$\[$(tput sgr0)\] '
alias ll='ls -l'
alias la='ls -la'
alias gits='git status'
alias gitac='git add --all && git commit'
alias gitds='git diff --staged'
