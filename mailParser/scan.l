/*
* Filename      scan.l
* Date          4/5/20
* Author        Payton Harmon
* Email         pnh170000@utdallas.edu
* Course        CS 3377.502 Spring 2020
* Version       1.0  (or correct version)
* Copyright 2020, All Rights Reserved
*
* Description
*
*     Generates tokens based off of regex rules.
*     
*/

%option noyywrap
%option nounput
%option noinput

%{
  #include <stdlib.h>
  #include "y.tab.h"

  extern YYSTYPE yylval;
%}

%%



[ \t\r]+			{ /* eat up whitespace */ }
[a-zA-Z]+[0-9]+|[0-9]+[a-zA-Z]+ {yylval.str = yytext; return IDENTIFIERTOKEN; }
IX|IV|V?I{0,3}                  {yylval.str = yytext; return ROMANTOKEN; }
[a-zA-Z][a-zA-Z]+               {yylval.str = yytext; return NAMETOKEN; }
"Sr."				{yylval.str = yytext; return SRTOKEN; }
"Jr."				{yylval.str = yytext; return JRTOKEN; }
"\n"                            {yylval.str = yytext; return EOLTOKEN; }
[0-9]+                          {yylval.value = atoi(yytext); return INTTOKEN; }
[a-zA-Z]\.?                     {yylval.str = yytext; return NAME_INITIAL_TOKEN; }
","                             {yylval.str = yytext; return COMMATOKEN; }
"-"                             {yylval.str = yytext; return DASHTOKEN; }
"#"                             {yylval.str = yytext; return HASHTOKEN; }


%%

/* 
 * This section is empty on purpose.
 *    DO NOT PUT YOUR main() routine here.
 *    
 * Put your main routine in a separate file.
 */
