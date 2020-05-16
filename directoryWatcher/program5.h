/*                                                                                                                                                                                                               \
 * Filename      program5.h
 * Date          4/14/20
 * Author        Payton Harmon
 * Email         pnh170000@utdallas.edu
 * Course        CS 3377.502 Spring 2020
 * Version       1.0  (or correct version)
 * Copyright 2020, All Rights Reserved
 *
 * Description
 *
 *     Header file initializes mapping functions and enums.
 *
 */

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <csignal>

using namespace std;

#ifndef PROGRAM5_H
#define PROGRAM5_H
enum TclapArgs
  {
    DAEMON,
    CONFIG
  };

enum ConfigArgs
  {
    VERBOSE,
    LOGFILE,
    PASSWORD,
    NUMVERSION,
    WATCHDIR
  };


map<int,string> initMap(int argc, char* argv[]);
map<int,string> parseConfig(string configName);

#endif
