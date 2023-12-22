#include "pch.h"
#include "CppUnitTest.h"
#include "..\Encryptor\Encryptor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// some of these imports might not be necessary, but it is just to future proof the tests

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	// No tests for the encryption algos 

	// NOTE FOR THE FUTURE: These tests might be failing because the path is wrong!!!
	// read the tests and you will understand what I mean!
	TEST_CLASS(DiskOperations)
	{
	public:
		TEST_METHOD(openFile1)
		{
			
			char* p = openFile("C:\\Users\\kdiog\\source\\repos\\Encryptor\\Test\\myFile.txt");
			Assert::IsTrue(p != NULL);
		}
		TEST_METHOD(openFile2)
		{

			char* p = openFile("Random file"); // write here a file that does not exist
			Assert::IsTrue(p == NULL);
		}

		TEST_METHOD(openFile3)
		{

			char* p = openFile("C:\\Users\\kdiog\\source\\repos\\Encryptor\\Test\\myFile.txt");
			char* contents = "This."; // one has to check the contents of the file to make sure!
			for (unsigned int i = 0; i < 5; i++)
			{
				// has to pass all these asserts
				Assert::AreEqual(p[i], contents[i]);
			}
		}
		TEST_METHOD(writeFile1)
		// Note: You might not see the entirety of the file when you ran this test
		// That will depend on how big the fike for the test above is (the test of the
		// file reading)
		{
			char* to_write = "Diogo Almeida. My name is Diogo Almeida";
			unsigned short lala = writeFile(to_write, (char*) "C:\\Users\\kdiog\\source\\repos\\Encryptor\\Test\\outfile.txt");
		}
	};
	TEST_CLASS(ArgsCheccking)
	{
	public:
		
		TEST_METHOD(str_is_equal_to_array1)
		{
			char* a[3] = {
				"Diogo",
				"Almeida",
				"Castro",
			};
			bool result = str_is_equal_to_array("Diogo", a, 3);
			Assert::IsTrue(result);
		}
		TEST_METHOD(str_is_equal_to_array2)
		{
			char* a[3] = {
				"Diogo",
				"Almeida",
				"Castro",
			};
			bool result = str_is_equal_to_array("Filipe", a, 3);
			Assert::IsTrue(!result);
		}
		TEST_METHOD(checkUsage1)
		{
			// invalid number of arguments
			char* argv[] = { "eu", "sou" };
			unsigned int result = checkUsage(2, argv);
			Assert::IsTrue(result == NumberArgumensError);
			// now we are talking!!!
			
		}

		TEST_METHOD(checkUsage2)
		{
			// invalid number of arguments
			char* argv[] = { "programm name",
			"hbfla", "1", "myFile"};
			unsigned int result = checkUsage(4, argv);
			Assert::IsTrue(result == OperationTypeError);
			// now we are talking!!!

		}
		TEST_METHOD(checkUsage3)
		{
			// invalid number of arguments
			char* argv[] = { "programm name",
			"e", "5", "myFile" };
			unsigned int result = checkUsage(4, argv);
			Assert::IsTrue(result == EncryptionAlgorithError);
			// now we are talking!!!
		}
		TEST_METHOD(checkUsage4)
		{
			// invalid number of arguments
			char* argv[] = { "programm name",
			"e", "1", "myFile" };
			unsigned int result = checkUsage(4, argv);
			Assert::IsTrue(result == OK);
			// now we are talking!!!

		}
		TEST_METHOD(checkUsage5)
		{
			// invalid number of arguments
			char* argv[] = { "programm name",
			"d", "1", "myFile" };
			unsigned int result = checkUsage(4, argv);
			Assert::IsTrue(result == OK);
			// now we are talking!!!

		}
	};
}
