/*
 * Filename      myproject.c
 * Date          4/5/20
 * Author        Payton Harmon
 * Email         pnh170000@utdallas.edu
 * Course        CS 3377.502 Spring 2020
 * Version       1.0  (or correct version)
 * Copyright 2020, All Rights Reserved
 *
 * Description
 *
 *     Operates in two modes. If called with scanner link it will spit out the tokens and their values.
 *     If called with parser it will parse the file and output errors in stdout and xml result in stderr
 *     Defulat call of executable runs in parser mode.
 */

#include <stdio.h>             /* needed for printf() */
#include "y.tab.h"             /* Needed for tokens */
#include <string.h>            /* Needed for string manipulation */


/* 
 * Manually insert prototype and extern declarations for the
 * stuff in the flex/bison output file.
 */
int yylex(void);
int yyparse();
extern char *yytext;

void scan();

int main(int argc, char *argv[])
{
  // if argv[0] is scanner run scanner
  // else run parse
  
  char scanLink[] = "./scanner";
  char parseLink[] = "./parser";

  

  if(strcmp(scanLink, argv[0]) == 0)
  {
    scan();
  }
  if(strcmp(parseLink, argv[0]) == 0)
  {
    yyparse();
  }
  else
  {
    yyparse();
  }
  return 0;
}

/* Scanner mode
 *
 * Repeatedly calls yylex then outputs the token it received w/ its value.
 *
 */
void scan()
{
  
    int token;
  
    token = yylex();

    while(token != 0)
      {
	printf("yylex returned ");
	switch(token)
	  {
	  case NAMETOKEN:
	    printf("NAMETOKEN");
	    break;
	  case IDENTIFIERTOKEN:
	    printf("IDENTIFIERTOKEN");
	    break;
	  case NAME_INITIAL_TOKEN:
	    printf("NAME_INITIAL_TOKEN");
	    break;
	  case ROMANTOKEN:
	    printf("ROMANTOKEN");
	    break;
	  case SRTOKEN:
	    printf("SRTOKEN");
	    break;
	  case JRTOKEN:
	    printf("JRTOKEN");
	    break;
	  case EOLTOKEN:
	    printf("EOLTOKEN");
	    break;
	  case INTTOKEN:
	    printf("INTTOKEN");
	    break;
	  case COMMATOKEN:
	    printf("COMMATOKEN");
	    break;
	  case DASHTOKEN:
	    printf("DASHTOKEN");
	    break;
	  case HASHTOKEN:
	    printf("HASHTOKEN");
	    break;
	  default:
	    printf("UNKNOWN");
	  }
	printf(" token (%s)\n", yytext);
	token = yylex();
      }
  
    printf("Done\n");
}
