#include "bob.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *hey_bob(char *greeting)
{
    char *response_to_questions = "Sure.";
    char *response_to_yell = "Whoa, chill out!";
    char *response_to_yell_question = "Calm down, I know what I'm doing!";
    char *response_to_nothing = "Fine. Be that way!";
    char *response_to_anything_else = "Whatever.";
    unsigned int upper_letter = 0;
    unsigned int lower_letter = 0;
    unsigned int question_mark = 0;
    unsigned int empty = 0;
    char *response;

    if (greeting != NULL)
    {
        response = response_to_anything_else;

        for (unsigned int i = 0; i < strlen(greeting); i++)
        {
            if (isupper(*(greeting + i)))
            {
                upper_letter++;
            }
            else if (islower(*(greeting + i)))
            {
                lower_letter++;
            }
            else if ((greeting[i] == ' ' && greeting[i + 1] == ' ') ||
                     greeting[i] == '\t' ||
                     greeting[i] == '\n' ||
                     greeting[i] == '\r')
            {
                empty++;
            }
            else if (*(greeting + i) == '?')
            {
                if (i == strlen(greeting) - 1 || greeting[i + 2] == ' ')
                {
                    question_mark++;
                }
            }
        }
    }

    if (strlen(greeting) == 0)
    {
        response = response_to_nothing;
    }
    if (empty >= 2 && !(lower_letter || upper_letter))
    {
        response = response_to_nothing;
    }
    if (question_mark)
    {
        response = response_to_questions;
    }
    if (upper_letter >= 2 && lower_letter == 0)
    {
        if (question_mark)
        {
            response = response_to_yell_question;
        }
        else
        {
            response = response_to_yell;
        }
    }

    return response;
}
