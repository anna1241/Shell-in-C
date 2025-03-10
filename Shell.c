#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void tokenize(char *cmd, char **token) 
{
    int i = 0;
    token[i] = strtok(cmd, " \t\n");
    while (token[i] != NULL) 
    {
        i++;
        token[i] = strtok(NULL, " \t\n");
    }
}
int main() 
{
    char cmd[5000];
    char *token[100];
    while (1) 
    {
        printf("Enter command: ");
        fgets(cmd, sizeof(cmd), stdin); // to get input
        tokenize(cmd, token);
        if (token[0] == NULL)
            continue; // Empty input, continue to the next iteration
        if (strcmp(token[0], "exit") == 0)
            exit(0);
        pid_t id = fork();
        int x;
        if (id == 0) // if child
        { 
            if (execvp(*token, token) < 0) 
            {
                printf("Failed execvp\n");
                return 1;
            }
        } 
        else if (id > 0) 
        { // if parent
            wait(NULL);
        } 
        else 
        {
            printf("Invalid id\n");
        }
    }
    return 0;
}
