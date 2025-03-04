#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_EMAIL_COUNT 10
#define SHRUNK_EMAIL_COUNT 6
#define MAX_EMAIL_LENGTH 100

int main()
{
    char **emails;
    int i;

    emails = (char **)malloc(INITIAL_EMAIL_COUNT * sizeof(char *));
    if (emails == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < INITIAL_EMAIL_COUNT; i++)
    {
        emails[i] = (char *)malloc(MAX_EMAIL_LENGTH * sizeof(char));
        if (emails[i] == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    printf("Enter 10 email addresses:\n");
    for (i = 0; i < INITIAL_EMAIL_COUNT; i++)
    {
        printf("Email %d: ", i + 1);
        scanf("%99s", emails[i]);
    }

    printf("\nStored Email Addresses:\n");
    for (i = 0; i < INITIAL_EMAIL_COUNT; i++) {
        printf("%d: %s\n", i + 1, emails[i]);
    }

    for (i = SHRUNK_EMAIL_COUNT; i < INITIAL_EMAIL_COUNT; i++)
    {
        free(emails[i]);
    }

    emails = (char **)realloc(emails, SHRUNK_EMAIL_COUNT * sizeof(char *));
    if (emails == NULL)
    {
        printf("Memory reallocation failed\n");
        return 1;
    }

    printf("\nStored Email Addresses (After Shrinking to 6):\n");
    for (i = 0; i < SHRUNK_EMAIL_COUNT; i++)
    {
        printf("%d: %s\n", i + 1, emails[i]);
    }

    for (i = 0; i < SHRUNK_EMAIL_COUNT; i++)
    {
        free(emails[i]);
    }
    free(emails);

    return 0;
}
