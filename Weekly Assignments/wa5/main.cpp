#include <iostream>
#include "functions.h"

int main()
{
   printVersion();
   // output the xml header and root element tags
   std::cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
   std::cout << "<document>\n";
   
   // Call some functions [These output xml tags but do little else]
   fn1();
   fn2(1);
   fn3(3.14159);
   fn4("Giraffe");
   // output the xml root closing tag
   std::cout << "</document>\n";
   return 0;
}
