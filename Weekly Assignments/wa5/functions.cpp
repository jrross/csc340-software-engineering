#include "functions.h"

void printVersion()
{
   #ifdef DEBUG
   std::cout << "|| DEBUG ||\n\n" << std::endl;
   #elif RELEASE
   std::cout << "|| RELEASE ||\n\n" << std::endl;
   #endif
}

void fn1()
{
   std::cout << "<fn1>\n";
   std::cout << "</fn1>\n";
}

void fn2(int value)
{
   std::cout << "<fn2>\n";
   std::cout << value << std::endl;
   fn1();
   std::cout << "</fn2>\n";
}

int fn3(double value)
{
   std::cout << "<fn3>\n";
   std::cout << value << std::endl;
   fn2((int)value);
   std::cout << "</fn3>\n";
   return 0;
}

char fn4(const char *str)
{
   std::cout << "<fn4>\n";
   std::cout << str << std::endl;
   fn3(strlen(str));
   std::cout << "</fn4>\n";
   return 0;
}
