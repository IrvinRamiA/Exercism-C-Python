#include "word_count.h"
#include <string.h>
#include <stdio.h>

int count_words(const char *sentence, word_count_word_t *words)
{
    unsigned char total_words = 0;
    unsigned char word_length = 0;
    unsigned char is_not_empty_sentence = 0;
    unsigned char repeated_word = 0;

    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

    while (*sentence != '\0')
    {
        is_not_empty_sentence = 1;

        if (*sentence == ' ' || *sentence == ',')
        {
            if (total_words == 0)
            {
                printf("Inside if\n");
                strncpy(words[total_words++].text, (sentence - (word_length)), word_length);
                words[total_words - 1].count++;
                word_length = 0;
                printf("words[%d].text = %s\n", total_words - 1, words[total_words - 1].text);
                printf("words[%d].count = %d\n", total_words - 1, words[total_words - 1].count);
            }
            else if (total_words >= 1)
            {
                printf("Inside else if\n");
                /* Iterating over the arrays of words */
                for (unsigned char i = 0; i < total_words; i++)
                {
                    printf("Inside for\n");
                    /* If repeated word increment counter */
                    printf("word = %s\n", sentence - (word_length - 1));
                    printf("lenght = %d\n", word_length - 1);

                    if (strncmp(words[i].text, (sentence - (word_length - 1)), word_length - 1) == 0)
                    {
                        repeated_word = 1;
                        printf("Inside if repeated word\n");
                        words[i].count++;

                        printf("words[%d].text = %s\n", total_words - 1, words[total_words - 1].text);
                        printf("words[%d].count = %d\n", total_words - 1, words[total_words - 1].count);
                        break;
                    }
                }
                /* New word */
                if(repeated_word == 0)
                {
                    strncpy(words[total_words++].text, (sentence - (word_length - 1)), word_length - 1);
                    words[total_words - 1].count++;

                    printf("New word\n");
                    printf("words[%d].text = %s\n", total_words - 1, words[total_words - 1].text);
                    printf("words[%d].count = %d\n", total_words - 1, words[total_words - 1].count);
                    break;
                }
                repeated_word = 0;
                word_length = 0;
            }
        }

        word_length++;
        sentence++;
    }

    if (is_not_empty_sentence)
    {
        if (total_words == 0)
        {
            strncpy(words[total_words++].text, (sentence - (word_length)), word_length);
            words[total_words - 1].count++;
        }
        else
        {
            strncpy(words[total_words++].text, (sentence - (word_length - 1)), word_length - 1);
            words[total_words - 1].count++;
        }
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
