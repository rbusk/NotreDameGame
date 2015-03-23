# @(#)Cshrc 1.3 88/02/08 SMI
#################################################################
#
#         .cshrc file
#
#         initial setup file for both interactive and noninteractive
#         C-Shells
#
#################################################################
# 12/13/99 Modified to source /usr/local/Startup/Cshrc only if it exists RKS
#
# Source the System Cshrc 
# DO NOT REMOVE THIS LINE
#
if ( -r /opt/und/Startup/Cshrc ) then
	source /opt/und/Startup/Cshrc
else if (-r /usr/local/Startup/Cshrc) then
	source /usr/local/Startup/Cshrc
endif
#
#         set up search path

#
# Add local entries after $path
#
set path = ( $path )

#*****************************************************
#       ADDED BY JOHN ROCHA FOR NOTREDAMEGAME PROJECT SDL
#       CAN BE REMOVED IF NO LONGER NEEDED
setenv PATH /afs/nd.edu/user14/csesoft/new/bin:$PATH
setenv LD_LIBRARY_PATH /afs/nd.edu/user14/csesoft/new/lib
#*****************************************************

#         cd path

#set lcd = ( )  #  add parents of frequently used directories
#set cdpath = (.. ~ ~/bin ~/src $lcd)

#         set this for all shells

set noclobber

#         aliases for all shells

#alias cd            'cd \!*;echo $cwd'
#alias cp            'cp -i'
#alias mv            'mv -i'
#alias rm            'rm -i'
##alias pwd           'echo $cwd'
#alias del          'rm -i'
#umask 002

#         skip remaining setup if not an interactive shell

if ($?USER == 0 || $?prompt == 0) exit

#          settings  for interactive shells

set history=40
set ignoreeof
#set notify
#set savehist=40
#set prompt="% "
#set prompt="`hostname`{`whoami`}\!: "
#set time=100

#          commands for interactive shells

#date
#pwd

#         other aliases

#alias a            alias
#alias h            'history \!* | head -39 | more'
#alias u            unalias

#alias             clear
#alias list         cat
#alias lock          lockscreen
#alias m             more
#alias mroe          more
#alias type         more

#alias .             'echo $cwd'
#alias ..            'set dot=$cwd;cd ..'
#alias ,             'cd $dot '

#alias dir          ls
#alias pdw           'echo $cwd'
#alias la            'ls -a'
#alias ll            'ls -la'
#alias ls           'ls -F'

#alias pd           dirs
#alias po           popd
#alias pp           pushd

#alias +w            'chmod go+w'
#alias -w            'chmod go-w'
#alias x             'chmod +x'

#alias j             'jobs -l'

#alias bye           logout
#alias ciao          logout
#alias adios         logout

#alias psg           'ps -ax | grep \!* | grep -v grep'
#alias punt          kill

#alias r            rlogin
#alias run          source

#alias nms 'tbl \!* | nroff -ms | more'                  # nroff -ms
#alias tms 'tbl \!* | troff -t -ms >! troff.output &'    # troff -ms
#alias tpr 'tbl \!* | troff -t -ms | lpr -t &'           # troff & print
#alias ppr 'lpr -t \!* &'                                # print troffed

#alias lp1           'lpr -P1'
#alias lq1           'lpq -P1'
#alias lr1           'lprm -P1'

#alias sd           'screendump | rastrepl | lpr -v &'

#alias edit         textedit

#alias help          man
#alias key           'man -k'

#alias mkae          make

# DO NOT REMOVE THIS LINE  -  Until you have increased your AFS volumes quota from 1MB
#
'/afs/nd.edu/sun4x_58/usr/local/Startup/AFS_quota_check'
