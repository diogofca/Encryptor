

/*
* In this file, we will check the parameters to see if they are alright.  If they are not,
* the usage message will be given!
*/

#include "Encryptor.h";
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



char* usage = (char*) "Usage: encryptor [e|d] [1] [filename]";

/*
* If this function returns 0, then sucess, else it means something is wrong with the
* command line arguments
* 
*
*/
int checkUsage(int argc, char* argv[])
{
	char* o[] = { (char*) "e", (char*)"d" };
	char* o2[] = { (char*)"1" };
	if (argc != 4)
	{
		return NumberArgumensError; 
	}
	else if (!str_is_equal_to_array(argv[1], o, 2))
	{
		return OperationTypeError;
	}
	else if (!str_is_equal_to_array(argv[2], o2, 1))
	{
		return EncryptionAlgorithError;
	}
	// file name can really be anything else so no wories
	
	return OK;
	
}

// seems to be working fine
bool str_is_equal_to_array(char* str, char* arr[], unsigned int arr_lenght)
{
	for (unsigned int i = 0; i < arr_lenght; i++)
	{
		if (strcmp(str, arr[i]) == 0)
		{
			return true;
		}
	}
	return false;
}