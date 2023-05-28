#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "tokenizer.h"
#include "global.h"

void initTokenizer(Tokenizer* tokenizer)
{
  tokenizer->ch = ' ';
  tokenizer->ident = ' ';
  tokenizer->intValue = 0;
  tokenizer->token = 0;
}

int getToken(Tokenizer* tokenizer)
{
  while (isspace(tokenizer->ch)) // Ignore whitespace
    tokenizer->ch = getchar();

  if (isalpha(tokenizer->ch))
  {
    tokenizer->ident = tolower(tokenizer->ch); // identifier?
    tokenizer->ch = getchar();
    tokenizer->token = token->letter;
  }
  else if (isdigit(tokenizer->ch))
  {                                            
    tokenizer->intValue = getNumber(tokenizer); // build value
    tokenizer->token = token->number;
  }
  else
  {
    switch (tokenizer->ch)
    { // Looks like an operation
    case ';':
      tokenizer->ch = getchar();
      tokenizer->token = token->semicolon;
      break;

    case '.':
      tokenizer->ch = getchar();
      tokenizer->token = token->period;
      break;

    case '+':
      tokenizer->ch = getchar();
      tokenizer->token = token->plusop;
      break;

    case '-':
      tokenizer->ch = getchar();
      tokenizer->token = token->minusop;
      break;

    case '*':
      tokenizer->ch = getchar();
      tokenizer->token = token->timesop;
      break;

    case '/':
      tokenizer->ch = getchar();
      tokenizer->token = token->divideop;
      break;

    case '%':
      tokenizer->ch = getchar();
      tokenizer->token = token->modop;
      break;

    case '^':
      tokenizer->ch = getchar();
      tokenizer->token = token->powop;
      break;

    case '=':
      tokenizer->ch = getchar();
      tokenizer->token = token->assignop;
      break;

    case '(':
      tokenizer->ch = getchar();
      tokenizer->token = token->lparen;
      break;

    case ')':
      tokenizer->ch = getchar();
      tokenizer->token = token->rparen;
      break;

    default:
      error("Illegal character");
      break;
    }
  }
  return tokenizer->token;
}

int getNumber(Tokenizer* tokenizer)
{
  int result = 0;
  do
  {
    result = result * 10 + (tokenizer->ch - '0');
    tokenizer->ch = getchar();
  } while (isdigit(tokenizer->ch));
  return result;
}

void match(Tokenizer* tokenizer, int which)
{
  tokenizer->token = getToken(tokenizer);
  if (tokenizer->token != which)
  {
    const char* tokenStr = getTokenSpelling(tokenizer->token);
    const char* expectedTokenStr = getTokenSpelling(which);
    char errorStr[100];
    snprintf(errorStr, sizeof(errorStr), "Invalid token %s -- expecting %s", tokenStr, expectedTokenStr);
    error(errorStr);
  }
}

void error(const char* msg)
{
  fprintf(stderr, "%s\n\n\n", msg);
  printf("*** Exiting the program ***\n\n\n\n\n\n");
  exit(1);
}