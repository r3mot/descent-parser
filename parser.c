
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "parser.h"
#include "global.h"

/* This program illustrates recursive descent parsing using a
   pure procedural approach.

   statement    = { expression  ";" } "."
   expression   = term { ( "+" | "-" ) term }
   term         = factor { ( "*" | "/" | "%") factor }
   factor       = primary { "^" factor }
   primary      = number | "(" expression ")"

*/

void initParser(Parser* parser, Tokenizer* tokenizer)
{
  parser->tokenizr = *tokenizer;
}

void run(Parser* parser)
{
  getToken(&(parser->tokenizr));
  statement(parser);
}

void statement(Parser* parser)
{
  while (parser->tokenizr.token != token->semicolon)
  {
    int value = expression(parser);
    printf("=> %d\n", value);
    getToken(&(parser->tokenizr)); // flush ;
  }
}

int expression(Parser* parser)
{
  int left = term(parser);
  while (parser->tokenizr.token == token->plusop || parser->tokenizr.token == token->minusop)
  {
    int saveToken = parser->tokenizr.token;
    getToken(&(parser->tokenizr));

    if (saveToken == token->plusop)
      left += term(parser);
    else if (saveToken == token->minusop)
      left -= term(parser);
  }

  return left;
}

int term(Parser* parser)
{
  int left = factor(parser);
  while (parser->tokenizr.token == token->timesop || parser->tokenizr.token == token->divideop || parser->tokenizr.token == token->modop)
  {
    int saveToken = parser->tokenizr.token;
    getToken(&(parser->tokenizr));

    if (saveToken == token->timesop)
      left *= factor(parser);
    else if (saveToken == token->divideop) {
      int tLeft = factor(parser);
      if (tLeft == 0) {
        error("can't divide by zero");
      }
      else {
        left /= tLeft;
      }
    }
    else if (saveToken == token->modop)
      left %= factor(parser);
  }
  return left;
}

int factor(Parser* parser)
{
  int left = primary(parser);
  while (parser->tokenizr.token == token->powop)
  {
    getToken(&(parser->tokenizr));
    int exponent = factor(parser); // recurse
    left = (int)pow(left, exponent);
  }
  return left;
}

int primary(Parser* parser)
{
  int value = 0;
  int pToken = parser->tokenizr.token;

  if (pToken == token->number)
  {
    value = parser->tokenizr.intValue;
    getToken(&(parser->tokenizr));
  }
  else if (pToken == token->lparen)
  {
    getToken(&(parser->tokenizr));
    value = expression(parser);
    if (parser->tokenizr.token != token->rparen)
      error("Missing ')'");
    getToken(&(parser->tokenizr));
  }
  else
  {
    error("Expected number or (");
  }

  return value;
}
