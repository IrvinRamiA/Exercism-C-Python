#include "word_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int count_words(const char *sentence, word_count_word_t *words)
{
    unsigned char input_len = strlen(sentence);
    char *copy_sentence = (char *)malloc((input_len + 1) * sizeof(char));
    const char *delimiters = " ,.-\n:!!&@$%^&\"";
    char *token;
    unsigned char total_words = 0;
    unsigned char repeated_word = 0;
    unsigned char index = 0;

    // strncpy(copy_sentence, sentence, strlen(sentence) + 1);

    for (index = 0; index < strlen(sentence); index++)
    {
        copy_sentence[index] = tolower(sentence[index]);
    }

    copy_sentence[index] = '\0';

    printf("-- Input sentence = %s\n", copy_sentence);

    token = strtok(copy_sentence, delimiters);

    printf("-- Current token = %s\n", token);

    /* walk through other tokens */
    while (token != NULL)
    {
        if (('\'' == token[0]) && ('\'' == token[strlen(token) - 1]))
        {
            token[strlen(token) - 1] = '\0';
            token++;
        }

        if (total_words == 0)
        {
            printf("-- First word\n");
            strncpy(words[total_words++].text, token, strlen(token));
            words[total_words - 1].count++;
        }
        else
        {
            for (unsigned char i = 0; i < total_words; i++)
            {
                if (strncmp(words[i].text, token, strlen(token) + 1) == 0)
                {
                    printf("-- Repeated word\n");
                    printf("-- words[%d].text = %s\n", i, words[i].text);
                    words[i].count++;
                    repeated_word = 1;
                    break;
                }
            }

            printf("-- --\n");

            if (repeated_word == 0)
            {
                printf("-- Non repeated\n");
                strncpy(words[total_words++].text, token, strlen(token));
                words[total_words - 1].count++;
            }
            repeated_word = 0;
        }

        token = strtok(NULL, delimiters);
        printf("-- Current token = %s\n", token);
    }

    /* Checking values */
    printf("-- Final check --\n");
    printf("total_words = %d\n", total_words);
    for (unsigned char i = 0; i < MAX_WORDS; i++)
    {
        printf("words[%d].text = %s\n", i, words[i].text);
        printf("words[%d].count = %d\n", i, words[i].count);
    }

    return total_words;
}
