/*
* Filename      parseConfig.cc
* Date          4/17/20
* Author        Payton Harmon
* Email         pnh170000@utdallas.edu
* Course        CS 3377.502 Spring 2020
* Version       1.0  (or correct version)
* Copyright 2020, All Rights Reserved
*
* Description
*
*     Parses the config file using rude config and intputs and returns a map.
* 
*/

#include "rude/config.h"
#include "program5.h"

map<int,string> parseConfig(string configName)
{
  
  map<int,string> configMap;
  // Instantiate the config object
  rude::Config config;

  if(config.load(configName.c_str()))
  {
    config.setSection("Parameters");

    string verboseStr = config.getStringValue("Verbose");
    string logFileStr = config.getStringValue("LogFile");
    string passwordStr = config.getStringValue("Password");
    string numVerStr = config.getStringValue("NumVersion");
    string watchDirStr = config.getStringValue("WatchDir");

    configMap[VERBOSE] = verboseStr;
    configMap[LOGFILE] = logFileStr;
    configMap[PASSWORD] = passwordStr;
    configMap[NUMVERSION] = numVerStr;
    configMap[WATCHDIR] = watchDirStr;
    
  }
  else
  {
    cerr << "Could not find the config file" << endl;
  }
 
  return configMap;
}
