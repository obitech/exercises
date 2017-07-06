/* 
AuP WS 2016/17, Bonusaufgabe 4 
---------------------------------------------------------------------------------------------
* In C, unlike in Python, we don't have a built-in data structure for sets. In this 
* excercise, we will create such a data structure using structs and bitarrays. We will then
* manipulate them through different functions using pointers.
---------------------------------------------------------------------------------------------
* As in natset.h defined, a set of type natset_t contains of two members: array_size and
* bitarray. One bitarray can hold 8 bits and the array_size defines the number of bit
* arrays we can have. Looking at each individual bit in the array, a 1 stands for a
* number represented in the set. For example, with an array_size of 1 we can represent
* 0 to 7 in bitarray[0]. If we want to have 0, 3, 5 represented, the binary value stored in
* bitarray[0] would be 0010 1001.
---------------------------------------------------------------------------------------------
* Different functions allow us to manipulate the data structure. All functions except for
* free return either NSS_OK (= 0) or NSS_ERROR (= -1) depending on if the function has
* been successful. A reason for error could be a NULL pointer being handed or if there
* is not enough memory for a specific operation.
---------------------------------------------------------------------------------------------
**** The following program allows us to:
* Create sets with the help of 8-bit arrays
* Add/Remove elements to/from sets
* Create an intersection between two sets and save it in the first set
* Create an union between two sets and save it in the first set
*
**** Other things that could be implemented in the future:
* A function to convert back from binary arrays to integers (for easier readability)
* Find the complement of two sets
* Find the Cartesian product of two sets
* Instead of overwriting set1, create a new set for each operation 
---------------------------------------------------------------------------------------------
*/

#include "natset.h"
#include <stdlib.h>

/*
Returns a to the power of b
*/
int power(int a, unsigned int b) {
	if (b == 0)
		return 1;
	else
		return a * power(a, b - 1);
}

/*
Initializing struct to which *set points as empty set with possible
values from 0 to largest. Also allocating memory.
*/
ns_status_t ns_init(natset_t *set, unsigned int largest){

	// Proceed if *set isn't a NULL-pointer
	if (set) {

		// Finding highest array_size and highest index, allocating memory for array
		uint16_t size = (largest / 8) + 1;
		set->array_size = size;
		set->bitarray = (uint8_t*)malloc(size * sizeof(uint8_t));
		
		// Initialize set with 0
		for (int i = 0; i < size; i++) {
			set->bitarray[i] = 0;
		}

		return NSS_OK;

	}

 	// If NULL-pointer, return NSSS_ERROR
	else 
		return NSS_ERROR;
}

/*
Freeing memory for bitarray
*/
void ns_free(natset_t *set){
	free(set->bitarray);
}

/*
Adding element to set. If set can't take element, extend memory
*/
ns_status_t ns_add(natset_t *set, unsigned int element){
	int x, y, index, new_size;
	int old_size = set->array_size;

	if (set) {

		// Returns right index for bitarray[]
		index = element / 8;

		//  If element is outside our max border for set, allocate more memory
		if ((index + 1) > set->array_size) {

			new_size = index + 1;
			set->array_size = new_size;

			// Extending memory
			set->bitarray = realloc(set->bitarray, new_size * sizeof(uint8_t));

			// Error handling if realloc fails
			if (set->bitarray == NULL) {
				ns_free(set);
				return NSS_ERROR;
			}

			// Filling new memory with 0
			for (int i = old_size; i <= new_size; i++) {
				set->bitarray[i] = 0;
			}
		}

		// Returns relative position of element in our byte array
		// e.g.: 254 % 8 = 6 -> should be 0010 0000
		x = element % 8;

		// Returns binary value for our array
		// e.g.: 2^6 = 64 -> it now is 0010 0000
		y = power(2, x);

		// Insert element (y) into array thru bitwise comparison
		set->bitarray[index] = (y | set->bitarray[index]);

		return NSS_OK;
	}

	else {
		return NSS_ERROR;
	}

}

/*
Removing element from set but only if it's already in there.
*/
ns_status_t ns_remove(natset_t *set, unsigned int element){
	int index, x, y;
	
	index = element / 8;
	x = element % 8;
	y = power(2, x);

	if (set) {

		// If element is bigger than max value for set, don't change array
		if (index > set->array_size) {
			return NSS_OK;
		}

		// If element is not in array, don't change array
		if ((set->bitarray[index] & y) == 0) {
			return NSS_OK;
		}

		// Remove element from array
		else  if (set->bitarray[index] & y) {
			set->bitarray[index] = (y ^ set->bitarray[index]);

			return NSS_OK;
		}

		// Just in case...
		else {
			return NSS_ERROR;
		}

	}

	else
		return NSS_ERROR;
}

/*
Intersection between set1 and set2.
*/
ns_status_t ns_cut(natset_t *set1, natset_t *set2){
	int i_max;

	if (set1 && set2) {

		// Checking which set has the smallest size, setting value to i_max
		if (set1->array_size >= set2->array_size) {
			i_max = set2->array_size;

			// Setting rest to 0
			for (int i = i_max; i <= (set1->array_size - 1); i++) {
				set1->bitarray[i] = 0;
			}
		}

		else {
			i_max = set1->array_size;
		}

		// Comparing each bitarray[] of set1/set2 for intersections
		for (int i = 0; i < i_max; i++) {
			set1->bitarray[i] = (set1->bitarray[i] & set2->bitarray[i]);
		}

		return NSS_OK;
	}
	
	else {
		return NSS_ERROR;	
	}

}

/*
Union between set1 and set2
*/
ns_status_t ns_join(natset_t *set1, natset_t *set2){
	int old_size, new_size;

	old_size = set1->array_size;
	new_size = set2->array_size;

	if (set1 && set2) {

		// If set1 < set2  ...
		if (old_size < new_size) {

			// ... make set1.array_size as big as set2.array_size
			set1->array_size = new_size;

			// ... extend memory
			set1->bitarray = realloc(set1->bitarray, new_size * sizeof(uint8_t));

			if (set1->bitarray == NULL) {
				ns_free(set1);
				return NSS_ERROR;
			}

			// ... fill new memory with 0
			for (int i = old_size; i <= (new_size - 1); i++) {
				set1->bitarray[i] = 0;
			}

		}

		// If set1  > set2 ...
		else if (old_size > new_size) {

			// ... create union set into set1, stop after max index from set2 is reached
			for (int i = 0; i < old_size; i++) {
				set1->bitarray[i] = (set1->bitarray[i] | set2->bitarray[i]);
			}

			return NSS_OK;
		}

		// If set1 == set2 ...
		for (int i = 0; i < new_size; i++) {

			// ... create union set into set1
			set1->bitarray[i] = (set1->bitarray[i] | set2->bitarray[i]);
		}

	return NSS_OK;
	}

	else {
		return NSS_ERROR;
	}

}
