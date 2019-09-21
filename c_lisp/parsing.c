#include<stdio.h>
#include "mpc.h"
static char buffer[2048];

char *readline(char* prompt) {
	fputs(prompt,stdout);
	fgets(buffer,2048,stdin);
	char *cpy = molloc(strlen(buffer) + 1);
	strcpy(cpy,buffer);
	cpy[strlen(cpy) - 1] = '\0';
	return cpy;
}
void add_history(char * unused){}

int main() {
	//define our polish language
	mpc_parser_t * Number = mpc_new("number");
	mpc_parser_t * Operator = mpc_new("operator");
	mpc_parser_t * Expr = mpc_new("expr");
	mpc_parser_t * Lispy = mpc_new("lispy");
	mpca_lang(MPCA_LANG_DEFAULT,
			"number : /-?[0-9]+;"
			"operator : '+' | '-' | '*' | '\';"
			"expr : <number> | '('  <expr> " )
	return 0;
}