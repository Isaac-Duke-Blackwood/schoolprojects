# Directory Watcher

## Description
This program creates a daemon process that will watch a folder and respond to its modification. When it detects a modification, the program will story a copy of that change in a .versions subfolder and log it.

## Dependencies
You'll probably have to edit the makefile to refelct where you installed these dependencies.
- rudeconfig
- tclap

## Usage

```

./dirmond [-d] [--] [--version] [-h] <config filename>

Where:
-d, --daemon
	Run in daemon mode (forks to run as a daemon).

--, --ignore_rest
	Ignores the rest of the labeled arguments following this flag.

--version
	Displays version information and exits.

-h, --help
	Displays usage information and exits.

<config filename>
	The name of the configuration file. Defaults to cs3377dirmond.conf
 
 dirmond Directory Monitor Daemon
 ```
