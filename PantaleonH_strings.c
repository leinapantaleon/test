/******************************************************************************
 * README
 * - Please make a copy of this programming exercise template
 * - Rename the file in the following format: LastnameFirstnameInitial_strings.c
 *   - Example: DelaCruzJ_strings.c
 * - Ensure that your code is able to compile with the following command:
 *   - gcc -Wall -std=c99 <filename.c> -o <output>
 *
 * Prepared by
 * - Email  : kristine.kalaw@dlsu.edu.ph
 * - @author: Kristine Kalaw
 *            Department of Software Technology
 *            College of Computer Studies
 *            De La Salle University
 *
 * Kindly inform me if there are any corrections needed for this template
 ******************************************************************************/

/**
 * Topic   : Strings [SOLUTION]
 * Name    : Pantaleon, Heleina
 * Section : S27B
 *
 * ACTIVITY INSTRUCTIONS
 * ---------------------
 * 1. Trace and understand the provided code in the template.
 * 2. Compile and run with input redirection (so you can observe what it does before doing any changes).
 *     - In Mac/Linux: ./EXE_FILE < input/in1.txt
 *     - In Windows: EXE_FILE < input\in1.txt
 * 3. Complete the functions. You may modify main() as needed.
 * 4. Your program must be able to generate the same expected output.
 * 5. If applicable, you may use the included bbtest.c file to streamline the
 *      testing of your program.
 *
 * FOLDER CONTENT
 * --------------
 * - expected/       = The folder containing the expected output text file/s
 * - input/          = The folder containing the input text file/s
 * - bbtest.c        = The source code for facilitating black box testing (compile it first)
 *                       USAGE: bbtest EXPECTED_OUTPUT_FILE ACTUAL_OUTPUT_FILE
 * - io_formats.txt  = A text file detailing the expected input and output file formats
 */

#include <stdio.h>
#include <string.h>

typedef char String20[21]; // char turns to String20[21]
typedef char FormattedName[61]; // char turns to FormattedName[61]

/**
 * [GIVEN] Gets the input string from the user and stores it in `str`
 * @param str The starting address of the string
 * @post The function does not return anything but the input string is stored in `str`
 */
void getInputString(String20 str)
{
  scanf("%s", str);
}

/**
 * [GIVEN / EXAMPLE] Adds an exclamation point at the end of the string
 * @param str The string to add an exclamation point
 * @post The function does not return anything but the updated string is stored in `str`
 */
void addExclamation(String20 str)
{
  int len = strlen(str); // Get the length of str
  str[len] = '!';        // Add an exclamation point at the end
  str[len + 1] = '\0';   // Manually ensure null termination

  /* Below is a single-line alternative implementation. There is no need to
     manually ensure null termination because strcat() automatically handles it.
   */
  // strcat(str, "!");
}

/**
 * Converts a string into lower case. Note that the ASCII value for 'A' is 65,
 * 'Z' is 90, 'a' is 97, and 'z' is 122.
 * @param str The string to convert
 * @post The function does not return anything but the updated string is stored in `str`
 */
void toLowerCase(String20 str)
{
	int i;
	
	for(i = 0; i < strlen(str); i++)
	if(str[i] >= 65 && str[i] <= 90)
	str[i] += 32;
}
/**
 * Converts a string into upper case. Note that the ASCII value for 'A' is 65,
 * 'Z' is 90, 'a' is 97, and 'z' is 122.
 * @param str The string to convert
 * @post The function does not return anything but the updated string is stored in `str`
 */
void toUpperCase(String20 str)
{
	int i;
	
	for(i = 0; i < strlen(str); i++)
	if(str[i] >= 97 && str[i] <= 122)
	str[i] -= 32;
}

/**
 * Reverses the string. For example, "coding" becomes "gnidoc".
 * @param str The string to reverse
 * @post The function does not return anything but the updated string is stored in `str`
 */
void reverseString(String20 str)
{
	char temp;
	int i, length;
	
	length = strlen(str)-1; // "strlen(str)" gets the length of the string and "-1" obtains its last character
	for(i = 0; i < length / 2 + 1; i++)
	{
		temp = str[i];
		str[i] = str[length - i];
		str[length - i] = temp;
	}
}
/**
 * Checks if the input string is a palindrome or not
 * @param str The string to reverse
 * @return 1 if `str` is a palindrome, 0 otherwise
 */
int isPalindrome(String20 str)
{
	int i, length, palindrome = 1;
	
	length = strlen(str);
	for(i = 0; i < length / 2; i++)
		if(str[i] != str[length - i - 1])
			palindrome = 0;
	
	return palindrome;
}

/**
 * Formats the name into `<LastName>, <FirstName> <MiddleInitial>.` and stores it
 * in `name`. For example, the first name is "Jose", middle name is "Garcia",
 * and last name is "Reyes". The formatted name is "Reyes, Jose G."
 * @param fname The first name
 * @param mName The middle name
 * @param lName The last name
 * @param name The string where to store the formatted name
 * @post The function does not return anything but the formatted name is stored in `name`
 */
void formatName(String20 fName, String20 mName, String20 lName, FormattedName name)
{
	char MiddleInitial[3] = {mName[0], '.'};
	
	strcpy(name, lName);
	strcat(name, ", ");
	strcat(name, fName);
	strcat(name, " ");
	strcat(name, MiddleInitial);
}

int main()
{
  /* Modify main() as needed.
     You may only use the following built-in functions in string.h as needed:
     - strlen, strcpy, strcmp, strcat
  */

  String20 word1, word2, word3, word4;
  String20 wordCopy; // use this to keep wordN unchanged

  String20 firstName1, middleName1, lastName1;
  String20 firstName2, middleName2, lastName2;
  FormattedName name1 = "\0", name2 = "\0"; //store the formatted names here later

  getInputString(word1);
  getInputString(word2);
  getInputString(word3);
  getInputString(word4);
  getInputString(firstName1);
  getInputString(middleName1);
  getInputString(lastName1);
  getInputString(firstName2);
  getInputString(middleName2);
  getInputString(lastName2);

//  printf("word1: %s\n", word1);
//  printf("word2: %s\n", word2);
//  printf("word3: %s\n", word3);
//  printf("word4: %s\n", word4);
//  printf("%s %s %s\n", firstName1, middleName1, lastName1);
//  printf("%s %s %s\n", firstName2, middleName2, lastName2);

  // Example flow for printing the output
  strcpy(wordCopy, word1);
  addExclamation(wordCopy);
  printf("addExclamation-word1:%s\n", wordCopy);
  
  strcpy(wordCopy, word1);
  toLowerCase(wordCopy);
  printf("toLower-word1:%s\n", wordCopy);
  
  strcpy(wordCopy, word2);
  toLowerCase(wordCopy);
  printf("toLower-word2:%s\n", wordCopy);
  
  strcpy(wordCopy, word3);
  toUpperCase(wordCopy);
  printf("toUpper-word3:%s\n", wordCopy);
  
  strcpy(wordCopy, word4);
  toUpperCase(wordCopy);
  printf("toUpper-word4:%s\n", wordCopy);
  
  strcpy(wordCopy, word1);
  reverseString(wordCopy);
  printf("reverse-word1:%s\n", wordCopy);
  
  strcpy(wordCopy, word2);
  reverseString(wordCopy);
  printf("reverse-word2:%s\n", wordCopy);
  
  strcpy(wordCopy, word1);
  toLowerCase(wordCopy); // reason why we need to convert strings to lowercase is because, let's say 'A' and 'a',
  						 // have different values in ASCII so the program will read strings such as 'Redder'
  						 // as a non-palindrome (will return 0)
  printf("isPalindrome-word1:%d\n", isPalindrome(wordCopy));
  
  strcpy(wordCopy, word2);
  toLowerCase(wordCopy);
  printf("isPalindrome-word2:%d\n", isPalindrome(wordCopy));
  
  strcpy(wordCopy, word3);
  toLowerCase(wordCopy);
  printf("isPalindrome-word3:%d\n", isPalindrome(wordCopy));
  
  strcpy(wordCopy, word4);
  toLowerCase(wordCopy);
  printf("isPalindrome-word4:%d\n", isPalindrome(wordCopy));
  
  formatName(firstName1, middleName1, lastName1, name1);
  printf("fullName1:%s\n", name1);
  
  formatName(firstName2, middleName2, lastName2, name2);
  printf("fullName2:%s\n", name2);

  return 0;
}
