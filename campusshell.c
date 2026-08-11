/* CampusShell - Smart University Computing Lab Management System
   A Simple Unix Shell Implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

/* Function to parse command line arguments */
void parse_command(char *input, char *args[])
{
    int i = 0;
    args[i] = strtok(input, " \n");
    while (args[i] != NULL)
    {
        i++;
        args[i] = strtok(NULL, " \n");
    }
}
int main()
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    printf("\n=====================================\n");
    printf("      CampusShell Started\n");
    printf(" Smart University Computing Lab Shell\n");
    printf(" Type 'exit' to terminate the shell.\n");
    printf("=====================================\n");

    while (1)
    {
        printf("\nCampusShell> ");
        fflush(stdout);
        /* Read user input */
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }
        /* Ignore empty input */
        if (strcmp(input, "\n") == 0)
        {
            continue;
        }
        /* Exit command */
        if (strncmp(input, "exit", 4) == 0)
        {
            printf("Exiting CampusShell...\n");
            break;
        }
        /* Parse the command */
        parse_command(input, args);
        /* Create child process */
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("Fork Failed");
            continue;
        }
        /* Child Process */
        if (pid == 0)
        {
            if (execvp(args[0], args) < 0)
            {
                perror("Command Execution Failed");
                exit(EXIT_FAILURE);
            }
        }
        /* Parent Process */
        else
        {
            wait(NULL);
        }
    }

    return 0;
}
