#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {

   if (argc != 3) {
      cout << "Falsche Parameter.\n";
      return -1;
   }

   int a = atoi(argv[1]), b = atoi(argv[2]);
   int prod = 0;
   for (int i = 0; i < sizeof(int) * 8; i++) {
      if ((1 << i) & b) {
         prod += a << i;
      }
   }

   cout << argv[1] << " * " << argv[2] << " = " << prod << endl;

}