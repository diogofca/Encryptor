
// have to include this line. Otherwise, 
// Visual Studio won't ever compile!!!
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include "Encryptor.h"

unsigned long int file_size;



char* openFile(char* fileName)
{
	FILE* file;
	char* buffer; // memory where the file will be stored
	// can't dereference this pointer for now
	// can only be stopping here!
	file = fopen(fileName, "rb");
	if (file == NULL)
	{
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	file_size = ftell(file); // file size in bytes (the same as a char)
	rewind(file); /*Have to get back to the beginning of the file*/

	buffer = (char*)malloc(sizeof(char) * file_size);
	if (buffer == NULL)
	{
		fclose(file);
		return NULL;
	}
	// reading the contents of the file to the buffer
	fread(buffer, file_size, 1, file);

	// closing the file after reading its contents!
	fclose(file);
	// returning buffer (still need to free this memory when this
	//  function ends)!
	return buffer;

}


unsigned short int writeFile(char* buffer, char* location)
{
	FILE* file;
	// NEXT LINE: Perhaps it would be good to change the output file
	file = fopen(location, "w");
	
	// there might be errors when opening the file!
	if (file == NULL) {
		return 1;
		
	}

	fwrite(buffer, sizeof(char), file_size, file);

	fclose(file);

	void* to_return =  malloc(sizeof(char)); // need a mechanism to 
	// ensure that there were no errors, so I will just return a
	// pointer that is not NULL.
	return 0;

}