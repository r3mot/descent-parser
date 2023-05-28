#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"

typedef struct
{
  Tokenizer tokenizr;
} Parser;

void initParser(Parser* parser, Tokenizer* tokenizr);
void run(Parser* parser);
void statement(Parser* parser);
int expression(Parser* parser);
int term(Parser* parser);
int factor(Parser* parser);
int primary(Parser* parser);

#endif