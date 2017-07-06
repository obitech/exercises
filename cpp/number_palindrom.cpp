#include <iostream>
#include <stdlib.h>

using namespace std;

int check_palindrom(int num) {
   int length = 0, i = 0;

   // Find length;
   int temp = num;
   while (temp != 0) {
      length++;
      temp /= 10;
   }

   temp = num;
   // Create array with digits
   int* digits = new int[sizeof(int)];
   while (temp != 0) {
      digits[i] = temp % 10;
      temp /= 10;
      i++;
   }
   
   // Check array for palindrom
   for (int i = 0; i <= (length - 1)/2; i++) {
      if (digits[i] != digits[length - 1- i]) {
         return 0;
      }
   }

   return 1;
}

int main(int argc, char const *argv[])
{
   if (argc != 2) {
      cout << "Falsche Parameter.\n";
   }

   int a = atoi(argv[1]);

   cout << "palindrom(" << a << ")? -> " << check_palindrom(a) << endl;

   return 0;
}