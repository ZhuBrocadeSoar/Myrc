# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

alias ll='ls -lh'

alias elec='cd /home/soar/Electiic/;java -jar /home/soar/Electiic/electricBinary-9.06.jar'

export PS1="\[\033[0;32m\]┌┼─┼─ \[\033[0m\033[0;32m\]\u\[\033[0m\] @ \[\033[0;36m\]\h\[\033[0m\033[0;32m\] ─┤├─ \[\033[0m\]\t \d\[\033[0;32m\] ─┤├─ \[\033[0;31m\]\w\[\033[0;32m\] ─┤ \n\[\033[0;32m\]└┼─\[\033[0m\033[0;32m\]\$\[\033[0m\033[0;32m\]─┤▶ \[\033[0m\]"

#export PATH="$PATH:/home/soar/bin/"

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
