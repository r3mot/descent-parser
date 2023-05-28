#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct
{
  int semicolon;
  int period;
  int plusop;
  int minusop;
  int timesop;
  int divideop;
  int modop;
  int powop;
  int assignop;
  int lparen;
  int rparen;
  int letter;
  int number;
  const char* spelling[13];
} Token;

extern Token* token;
extern const char* getTokenSpelling(int i);


#endif