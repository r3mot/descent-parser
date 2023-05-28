#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "global.h"
#include "tokenizer.h"
#include "parser.h"

const Token TOKENS = {
    .semicolon = 0,
    .period = 1,
    .plusop = 2,
    .minusop = 3,
    .timesop = 4,
    .divideop = 5,
    .modop = 6,
    .powop = 7,
    .assignop = 8,
    .lparen = 9,
    .rparen = 10,
    .letter = 11,
    .number = 12,
    .spelling = {
        ";",
        ".",
        "+",
        "-",
        "*",
        "/",
        "%",
        "^",
        "=",
        "(",
        ")",
        "letter",
        "number",
    } };

Token* token = &TOKENS;
void dumpTitle();

int main()
{

  dumpTitle();
  Tokenizer t;
  initTokenizer(&t);
  Parser parser;
  initParser(&parser, &t);
  run(&parser);

  return 0;
}

const char* getTokenSpelling(int i)
{
  if (i >= 0 && i < sizeof(TOKENS.spelling) / sizeof(TOKENS.spelling[0]))
    return TOKENS.spelling[i];
  else
    return " ";
}

