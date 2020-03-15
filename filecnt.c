#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>

void listFiles(DIR *dir, int *numDir, int *numFiles, int *numByte);
void chdir(char argv[]);
//random comment
int main(int arc,char* argv[])
{
    
    int numDir = 0;
    int numFiles = 0;
    int numByte = 0;
    char pathActual [PATH_MAX+1];
    chdir(argv[1]);
    DIR *dir = opendir(argv[1]);//open directory, store in dir
    listFiles(dir, &numDir, &numFiles, &numByte);
    printf("The total number of directories in directory %s is: %d\n", argv[1], numDir);
    printf("The total number of file in directory %s is: %d\n", argv[1], numFiles);
    printf("The total number of bytes occupied by all files in directory %s is: %d\n", argv[1], numByte);
    closedir(dir);//close dir
    return 0;
}
void listFiles(DIR *dir, int *numDir, int *numFiles, int *numByte)// pointer to path
{
    struct stat statbuf;//create stat structure 
    struct dirent *dp;
    if(!dir)
       return;
    if((dp = readdir(dir)) != NULL)//check to make sure not at end of dir
    {

	if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && !stat(dp->d_name, &statbuf))//makes sure not to count the . and .. dir
	{
		(*numByte)+=statbuf.st_size;//increase byte counter
		if(S_ISDIR(statbuf.st_mode))//checks to see if file is dir
		{
		    (*numDir)++;//increase if dir
		}
		else if(S_ISREG(statbuf.st_mode))//checks to see if file is reg file
		{
		    (*numFiles)++;//increase if reg
		}
	}
        listFiles(dir, numDir, numFiles, numByte);//recursion call 
    }
    else
        return;//return if end of file
}


