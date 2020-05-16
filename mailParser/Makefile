#!/usr/bin/make -f
#
# Filename      Makefile
# Date          4/5/20
# Author        Payton Harmon
# Email         pnh170000@utdallas.edu
# Course        CS 3377.502 Spring 2020
# Version       1.0  (or correct version)
# Copyright 2020, All Rights Reserved
#
# Description
#
#     Creats a project executable from parse.y scan.l and myproject.c
#       
#

#
# Flags for the C++ implicit rules
CC = gcc
CCFLAGS = -Wall
CPPFLAGS = 

# Flags for the Lex implicit rules
#
# Implicit Makefile rule to use Lex for C programs
#
#   n.c is made automatically from n.l by running Lex. The actual recipe is
#	$(LEX) $(LFLAGS)
LEX = /bin/flex
LFLAGS = 

# Implicit Makefile rule to use YACC for C programs
#
#   n.c is made automatically from n.y by running Yacc with the recipe
#       $(YACC) $(YFLAGS)
YACC = /bin/bison
YFLAGS = -dy

#
# PROJECTNAME is a descriptive name used for the backup target
# This should not contain spaces or special characters
PROJECTNAME = CS3377.Lex.Example

EXECFILE = project

OBJS = parse.o scan.o myproject.o

# Because we are insane, keep the intermediate files so we can look at
# them If we comment this out (or remove it), the intermediate scan.c
# file is automatically deleted.
.PRECIOUS: scan.c

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *~ \#* scanner parser scan.c y.tab.h

$(EXECFILE):	$(OBJS)
	$(CC) -o $@ $(OBJS)
	ln -fs ./$@ scanner
	ln -fs ./$@ parser

backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
