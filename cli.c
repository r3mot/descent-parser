#include "cli.h"
#include <stdio.h>
#include <stdlib.h>

void dumpTitle()
{
  puts(
    "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n"
    "*     ____  ____  ___  _  _  ____  ____  __  _  _  ____    ____  ____  ____   ___  ____  __ _  ____     * \n"
    "*    (  _ \\(  __)/ __)/ )( \\(  _ \\/ ___)(  )/ )( \\(  __)  (    \\(  __)/ ___) / __)(  __)(  ( \\(_  _)    * \n"
    "*     )   / ) _)( (__ ) \\/ ( )   /\\___ \\ )( \\ \\/ / ) _)    ) D ( ) _) \\___ \\( (__  ) _) /    /  )(      * \n"
    "*    (__\\_)(____)\\___)\\____/(__\\_)(____/(__) \\__/ (____)  (____/(____)(____/ \\___)(____)\\_)__) (__)     *\n"
    "*                                                                                                       * \n"
    "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n"
    "A simple recursive descent parser capable of handling basic mathematical operations.\n"
    "Expressions will only be evaluated if followed by a ; \n"
    "Accepted Tokens: - + * / % ^ ( ) \n\n"
    "Your expression: "
  );
}