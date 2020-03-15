#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])//get arguments from command
{	
	int choice = 0;//choice int
	char line[100];//line
	int n = 0;//counter
	if(strcmp("-d",argv[1])==0)//checks to see if argument is -d
		choice =1;
	if(strcmp("-f",argv[1])==0)//checks to see if argument is -f
		choice =2;
	if(strcmp("-b",argv[1])==0)//checks to see if argument is -b
		choice =3;
	while(n<choice)//loop until n=choice, continue to get line from input until correct line
	{
		n++;
		gets(line);//get line
	}
	printf("%s\n",line);//print out line
	return 0;
}
