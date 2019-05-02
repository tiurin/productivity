export PATH=/usr/local/bin:$PATH
export PATH=/usr/local/sbin:$PATH
export LANG=en_US.UTF-8
export GPG_TTY=$(tty)
# To go back to Java 8 automatically after playing with Java 9
export JAVA_HOME=`/usr/libexec/java_home -v 1.8`
export BAT_THEME='Monokai Extended Light'
source ~/workspaces/tiurin/git/contrib/completion/git-prompt.sh
source ~/workspaces/tiurin/git/contrib/completion/git-completion.bash

# Custom bash prompt via kirsle.net/wizards/ps1.html
export GIT_PS1_SHOWDIRTYSTATE=1
export PS1='\u@\h: \[$(tput bold)\]\w\[$(tput setaf 5)\]$(__git_ps1)\[$(tput setaf 1)\]\n$\[$(tput sgr0)\] '
alias ll='ls -l'
alias la='ls -la'
alias gits='git status'
alias gitac='git add --all && git commit'
alias gitds='git diff --staged'
alias gitl='git log --oneline -n20'
alias gitp='git pull --rebase --prune'

