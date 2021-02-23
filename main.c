#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* OWO:
 * Program to take any command line string of characters
 * and ruin them.
 */ 

#define STRING_BUFFER 100
const char * ERR_GENERAL = "Oopsie woopsie you made a fucky wucky!! A wittle fucko boingo!\n";

int main(int argc, char* argsv[])
{
	if(argc > 2)
	{
		printf("%s",ERR_GENERAL);
		return -1;
	}

	char * THE_QUOTE = "Epstein didn't kill himself.";
	char * str = !argsv[1] ? THE_QUOTE : argsv[1];

	char * toReturn = malloc(sizeof(char) * STRING_BUFFER);			
	if(!toReturn)
	{
		printf("%s",ERR_GENERAL);
		return -1;
	}

	int iterSync = 0;
	for(int iter = 0; iter < strlen(str); iter++)
	{

		//printf("%d\n",str[iter] == 'i' || str[iter] == 'e');

		if(str[iter] == 'i' || str[iter] == 'e')
		{	
			toReturn[iter + iterSync] = 'w'; 
			iterSync++;
		}

		toReturn[iter + iterSync] = str[iter];
		
		//printf("%s\n",toReturn);
	}

	char * toAdd = " OwO";
	strncat(toReturn,toAdd,STRING_BUFFER);
	
	printf("%s\n",toReturn);
	free(toReturn);

	return 0;
}


