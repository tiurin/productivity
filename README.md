# Various tweaks, scripts, utils I use

## Bash command prompt tweak

###### Description

Adds the following:

1. Extends PATH with brew formulas locations
1. Adds git prompt and git completion (see https://github.com/git/git/tree/master/contrib/completion) 
1. Adds colorized branch name and staged changes indicator after user@host plus full path
1. Moves prompt to the new line after info to allow more space for commands while still showing full path
1. Adds `ll` and `la` shortcuts for `ls -l` and `ls -la` respectively
1. Adds `gits` and `gitac` shortcuts for *show repository status* and *add all and commit*.

###### Usage

Add the following to your .bash_profile file:
```
source <PATH_TO_THIS_REPO>/bash_profile_source.sh
```
