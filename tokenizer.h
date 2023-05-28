#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef struct
{
  char ch;
  char ident;
  int intValue;
  int token;
} Tokenizer;

void initTokenizer(Tokenizer* tokenizer);
int getToken(Tokenizer* tokenizer);
int getNumber(Tokenizer* tokenizer);
void match(Tokenizer* tokenizer, int which);
void error(const char* msg);

#endif