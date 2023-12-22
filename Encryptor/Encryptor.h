#pragma once



// things from ArgsChecking.cpp
bool str_is_equal_to_array(char* str, char* arr[], unsigned int arr_lenght);
int checkUsage(int argc, char* argv[]);
extern char* usage;

enum usageErrors {
	OK, NumberArgumensError, OperationTypeError, EncryptionAlgorithError,
};


// End of things from ArgsChecking.cpp

// things from disk.cpp
char* openFile(char* fileName);
extern unsigned long int file_size;

unsigned short int writeFile(char* buffer, char* location);

// End of things from Disk.cpp


// Things from EncryptionAlgos.cpp

void encrypt1(char* writeBuffer, char* readBuffer);
void decrypt1(char* buffer, char* readBuffer);

// End of things from EncryptionAlgos.cpp
