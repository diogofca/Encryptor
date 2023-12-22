// This file is for the encryption and decryption algorithms that
//  the programm will support.


#include "Encryptor.h"
#include <math.h>
#include <stdio.h>

/*
* For now, we shall only support one of the simplest algorithms yet,
* we just add a certain offset to each byte and then mod that to 256
* That way we make sure that there are no byte overflows, which are
* very scary to deal with
*
* Remember to make a lot of tests!
* 
* 
* The difference between the encryption and decryption is very subtle (only a minus and plus sign)!
*/


// here the size is used for testing purposes (there is probably a better way to do this)
void encrypt1(char* writeBuffer, char* readBuffer)
{
	for (unsigned long int i = 0; i<file_size; i++)
	{

		writeBuffer[i] = ~readBuffer[i];

	}
}

void decrypt1(char* writeBuffer, char* readBuffer)
{
	for (unsigned long int i = 0; i < file_size; i++)
	{
		writeBuffer[i] = ~readBuffer[i];
	}
}

// more algos here in teh future
// lets go!!!