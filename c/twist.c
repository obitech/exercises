/* AuP WS 2016/17, Bonusaufgabe 3
-------------------------------------------------------------------------------
** Pointers everywhere!
-------------------------------------------------------------------------------
** Task:
* Write a function that reverses a char and swap upcase/downcase
* Restrictions: No loops, no global variables, no library functions,
	no changing main, no changing declaration of twist()
-------------------------------------------------------------------------------
** Main idea: we can change neither our initial string, nor the pointer to it,
* so we have to create new ones: p1 which points to *varg and p2 which
* points to *str2 - str2 will be our new output string.
* Since p2 is not constant, we can use pointer arithmetics and dereferencing 
* to populate a new array with our old values. After that we swap cases through
* the chars's ASCII values.
** Done!
-------------------------------------------------------------------------------
* Recursion sequence of value_swap() with the example "Hallo":
	valueswap(*old, oval, *new, nval, length)				// oval, nval = count var
	value_swap(*p1, (length - 2 ), *p2, 0, length)
	// First char of new string = "last" char of old string
	-> value_swap('H', 4, '', 0, 6)
		*(p2 + nval) = *(p1 + oval)
		*(p2 + 0) = 'o'
	-> value_swap('H', 3, '', 1, 6)
		*(p2 + 1) = 'l'
	-> value_swap('H', 2, '', 2, 6)
		*(p2 + 2) = 'l'
	-> value_swap('H', 1, '', 3, 6)
		*(p2 + 3) = 'a'
	-> value_swap('H', 0, '', 4, 6)
		*(p2 + 4) = 'H'
	-> value_swap('H', -1, 'H', 5 6)
		*(p2 + 4) == *p1
		--> *(p2 + 5) = '\0'
		--> String finished, Recursion terminated
-------------------------------------------------------------------------------				
*/

int printf(const char * restrict, ...);
void *malloc(unsigned long);
  
// Find the number of chars in our initial char array
int str_length(const char *str) {
	if (*str == '\0') 
		return 1;
	else
		return 1 + str_length(str + 1);
}

// Populate new array over pointer arithmetic & dereferencing
// Declaration of new array is done in twist()
void value_swap(const char *old, int oval, char *new, int nval, int length) {
	if (*(new + (length - 2)) == *old){
		*(new  + (length - 1)) = '\0';
	}
	else {
		*(new + nval) = *(old + oval);
		value_swap(old, (oval - 1), new, (nval + 1), length);
	}
} 

// Swapping cases: arithmetic between chars will return ASCII values
// It's a bit hacky, I know...
void case_swap(char* new, int count, int length) {
	if (count == (length - 1)) {
		*(new + (length - 1)) = '\0';
	}
	else {
		// Those are the ASCII ranges for lower case
		if ((*(new + count) >= 97) && (*(new + count) <= 122)) {
			*(new + count) -= 32;
		}
		// Those are the ASCII ranges for upper case
		else if ((*(new + count) >= 65) && (*(new + count) <= 90)) {
			*(new + count) += 32;
		}
		case_swap(new, count + 1, length);
	}
}

// Deklaration der Aufgabenfunktion
// twist takes an argument: a constant pointer (argv), 
// 	which points to a constant char ('H' von Hallo)
// twist is a function that returns a pointer (p2), 
// 	which points to a constant char ('O' von OLLAh)
const char *twist(const char * const str) {

	// Finding out how big (how many chars) initial string is
	int length = str_length(str);

	// Creating our output array and allocating as much memory as needed
	char *str2 = (char*)malloc(length);

	// Defining p1: pointing to varg (which is pointing to beginning of string)
	const char * const *p1;
	p1 = &str;

	// Defining p2: pointing to str2 (which is pointing to output string)
	char **p2;
	p2 = &str2;

	// Swapping chars and cases
	value_swap(*p1, (length - 2), *p2, 0, length);
	case_swap(*p2, 0, length);

	return *p2;
}

int main(int carg, const char **varg){
  if (carg != 2) return -1;                              // ein Parameter uebergeben?
  printf("Die twisted Version von \"%s\" ist \"%s\".\n", // gibt Ergebnis aus
	 varg[1],twist(varg[1]));
  return 0;                                              //  0 bedeutet alles okay
}