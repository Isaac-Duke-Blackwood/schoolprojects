
%{
  #include <stdio.h>
  int yylex(void);
  void yyerror(char *);

  extern int sjpline;
%}

%union
{
  int value;
  char *str;
}

%type <str> IDENTIFIERTOKEN
%type <str> ROMANTOKEN
%type <str> NAMETOKEN
%type <str> JRTOKEN
%type <str> INTTOKEN
%type <str> NAME_INITIAL_TOKEN
%type <str> COMMATOKEN
%type <str> DASHTOKEN
%type <str> HASHTOKEN
%type <str> SRTOKEN 

%token IDENTIFIERTOKEN
%token ROMANTOKEN
%token NAMETOKEN
%token SRTOKEN
%token JRTOKEN
%token EOLTOKEN
%token INTTOKEN
%token NAME_INITIAL_TOKEN
%token COMMATOKEN
%token DASHTOKEN
%token HASHTOKEN

%start postal_addresses

%%
 /*
   make sure the last entry does not have a double new line.
 */

postal_addresses:
		address_block EOLTOKEN {fprintf(stderr, "\n"); } postal_addresses
		| address_block
	;

address_block:
		name_part street_address location_part
	;

name_part:
		personal_part last_name suffix_part EOLTOKEN
		| personal_part last_name EOLTOKEN
		| error EOLTOKEN {printf("Bad name-part ... skipping to new line \n"); }
	;

personal_part:
		NAMETOKEN {fprintf(stderr, "<FirstName>%s</FirstName> \n", yylval); }
		| NAME_INITIAL_TOKEN {fprintf(stderr, "FirstName>%s</FirstName>\n",yylval); }
	;

last_name:
		NAMETOKEN {fprintf(stderr, "<LastName>%s</LastName> \n", yylval); }
	;

suffix_part:
		SRTOKEN {fprintf(stderr, "<Suffix>%s</Suffix> \n", yylval); }
		| JRTOKEN {fprintf(stderr, "<Suffix>%s</Suffix> \n",yylval); }
		| ROMANTOKEN {fprintf(stderr, "<Suffix>%s</Suffix>\n",yylval); }
	;

street_address:
		street_number street_name INTTOKEN {fprintf(stderr, "<AptNum>%d</AptNum> \n",yylval); } EOLTOKEN
		| street_number street_name HASHTOKEN INTTOKEN {fprintf(stderr, "<AptNum>%d</AptNum> \n",yylval); } EOLTOKEN 
		| street_number street_name EOLTOKEN
		| error EOLTOKEN {printf("Bad address-line ... skipping to new line \n"); }
	;

street_number:
		INTTOKEN {fprintf(stderr, "<HouseNumber>%d</HouseNumber> \n",yylval); }
		| IDENTIFIERTOKEN {fprintf(stderr, "<HouseNumber>%s</HouseNumber> \n",yylval); }
	;

street_name:
		NAMETOKEN {fprintf(stderr, "<StreetName>%s</StreetName> \n",yylval); }
	;

location_part:
		town_name COMMATOKEN state_code zip_code EOLTOKEN
		| error EOLTOKEN {printf("Bad location-line ... skipping to new line \n"); }
	;

town_name:
		NAMETOKEN {fprintf(stderr, "<City>%s</City> \n",yylval); }
	;

state_code:
		NAMETOKEN {fprintf(stderr, "<State>%s</State> \n",yylval); }
	;

zip_code:
		zip5 DASHTOKEN INTTOKEN {fprintf(stderr, "<Zip4>%d</Zip4>\n", yylval); }
		| zip5
	;

zip5:
		INTTOKEN {fprintf(stderr, "<Zip5>%d</Zip5>\n",yylval); }
	;

%%
void yyerror(char *s)
{

} 
