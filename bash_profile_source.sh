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
alias gitl='git log --oneline -n20'
alias gitp='git pull --rebase --prune'

# Apache Kafka
alias zkstart='sh /opt/kafka_2.11-0.10.1.1/bin/zookeeper-server-start.sh /opt/kafka_2.11-0.10.1.1/config/zookeeper.properties'
alias zkstop='sh /opt/kafka_2.11-0.10.1.1/bin/zookeeper-server-stop.sh'
alias kafkastart0='sh /opt/kafka_2.11-0.10.1.1/bin/kafka-server-start.sh /opt/kafka_2.11-0.10.1.1/config/server.properties'
alias kafkastart1='sh /opt/kafka_2.11-0.10.1.1/bin/kafka-server-start.sh /opt/kafka_2.11-0.10.1.1/config/server-1.properties'
alias kafkastart2='sh /opt/kafka_2.11-0.10.1.1/bin/kafka-server-start.sh /opt/kafka_2.11-0.10.1.1/config/server-2.properties'
alias kafkastop='sh /opt/kafka_2.11-0.10.1.1/bin/kafka-server-stop.sh'


