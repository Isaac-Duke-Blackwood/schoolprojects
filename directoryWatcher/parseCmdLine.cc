/*                                                                                                                                                                                                                 * Filename      parseCmdLine.cc
 * Date          4/14/20
 * Author        Payton Harmon
 * Email         pnh170000@utdallas.edu
 * Course        CS 3377.502 Spring 2020
 * Version       1.0  (or correct version)
 * Copyright 2020, All Rights Reserved
 *
 * Description
 *
 *     A function that uses the tclap library to parse the command line arguments and returns
 *     them in a map indexed by an enumeration.
 */

#include "program5.h"
#include "tclap/CmdLine.h"

map<int,string> initMap(int argc, char* argv[])
{
  
  map<int,string> argMap; // init the map

  try{

  // Creates the cmd parser
  TCLAP::CmdLine cmd("caseconvert.cc", ' ', "1.0");
  
  // Declare the Tclap objects for each commandline input.
  TCLAP::SwitchArg daemon("d", "daemon", "Run in daemon mode (forks to run as a daemon)", cmd, false);
  TCLAP::UnlabeledValueArg<string> config("config", "The config file name.", true, "xcs3377dirmond.conf", "Config filename", false);
  cmd.add(config);

  // Parse the inputs into the tclap objects.
  cmd.parse(argc,argv);

  // Gets the values of each tclap object
  string configFile = config.getValue();
  bool daemonBool = daemon.getValue();

  // Converts the bool values into strings for the map.
  string daemonStr = daemonBool ? "1" : "0";
  
  // Pass values into the map.
  argMap[DAEMON] = daemonStr;
  argMap[CONFIG] = configFile;

  }

  catch(TCLAP::ArgException &e)
  {
    cerr << "Yikes" << endl;
  }
  
  return argMap;
}
