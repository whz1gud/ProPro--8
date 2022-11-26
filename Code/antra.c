#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *getFileName(int argc, char *argv[], int *longestName);

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int bytes;
        const char *filename = getFileName(argc, argv, &bytes);
        if (bytes != 0)
        {
            printf("Longest (*.txt) file name is %d bytes\nFile name '%s'\n", bytes, filename);
        }
        else
        {
            printf("No *.txt file found!\n");
        }
    }
    else
        printf("No files found!\n");

    return 0;
}

const char *getFileName(int argc, char *argv[], int *longestName)
{
    int longest = 0, index = 0;
    for (int i = 1; i < argc; ++i)
    {
        int currentFileLength = strlen(argv[i]);
        if (strcmp(".txt", argv[i] + currentFileLength - 4) == 0)
        {
            if (strlen(argv[i]) > longest)
            {
                longest = strlen(argv[i]);
                index = i;
            }

            for (int j = i + 1; j < argc; ++j)
            {
                int nextFileLength = strlen(argv[j]);
                if (strcmp(".txt", argv[j] + nextFileLength - 4) == 0)
                {
                    if (strlen(argv[j]) > longest)
                    {
                        longest = strlen(argv[j]);
                        index = j;
                    }
                }
            }
            break;
        }
    }
    *longestName = longest;
    if (longest != 0 && index != 0)
    {
        return argv[index];
    }
    else
    {
        return NULL;
    }
}