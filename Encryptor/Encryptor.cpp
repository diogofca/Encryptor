// Encryptor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Encryptor.h"

int main(int argc, char* argv[])
{
    /*
    
    printf("%i\n", argc);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    printf("%s\n", argv[3]);
    */
    // deal with parameters (check if they are alright)
    unsigned int result = checkUsage(argc, argv);
    // see the file for more
    if (result != OK)
    {
        printf("Invalid Usage\n");
        printf("%s\n", usage);
        return 1;
    }

    // load the file into memory

    char* fileBuffer = openFile(argv[3]);
    // need to have error handeling
    if (fileBuffer == NULL)
        {
        printf("Troubles reading the file and loading it onto memory\n");
            return 1;
        }
    // remember, the file size is stored in the global variable file_size
    // look in the header file for more information!!!
    printf("Encrypting the following:\n");
    for (int i = 0; i < file_size; i++)
    {
        printf("%c", fileBuffer[i]);
    }
    printf("\n");

    char* writeBuffer = (char*)malloc(sizeof(char) * file_size);


    // encrypt / decrypt the file (there will be variuos methods available)
    // printf("%c", argv[1][0]);
    switch (argv[1][0])
    {
    case 'e':
        encrypt1(writeBuffer, fileBuffer);
    case 'd':
        decrypt1(writeBuffer, fileBuffer);
    }

    // printf("\n");
    // write to the file
    unsigned short int writeResult = writeFile(writeBuffer, argv[3]);
    // need to have error handeling
    if (writeResult == 1)
    {
        printf("Troubles writing to the file!!!\n");
        free(fileBuffer);
        free(writeBuffer);
        return 1;
    }
    else if (writeResult == 0)
    {
        free(fileBuffer);
        free(writeBuffer);
        printf("Success");
    }
    
    return 0;




}

// NOTE TO SELF. DONT FORGET TO FREE THE MEMORY!!!

