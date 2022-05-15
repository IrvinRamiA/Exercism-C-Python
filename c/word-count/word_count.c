#include "word_count.h"
#include <string.h>
#include <stdio.h>

// int count_words(const char *sentence, total_words_word_t *words)
// {
//     unsigned char total_words = 0;
//     unsigned char word_length = 0;
//     unsigned char index = 0;
//     unsigned char is_not_empty_sentence = 0;

//     memset(words, 0, sizeof(total_words_word_t) * 20);

//     while (*sentence != '\0')
//     {
//         is_not_empty_sentence = 1;
//         printf("Inside loop\n");

//         if (*sentence == ' ' || *sentence == '\0')
//         {
//             printf("Inside if\n");

//             if (index == 0)
//             {
//                 strncpy(words[index++].text, (sentence - word_length), word_length);
//                 words->count = index;
//                 word_length = 0;
//                 total_words++;
//             }

//             printf("-- PREVIOUS WORD --\n");
//             printf("-- prev-word = %s --\n", words[index - 1].text);
//             char current_word[MAX_WORD_LENGTH];
//             memset(current_word, 0, MAX_WORD_LENGTH);
//             strncpy(current_word, (sentence - word_length), word_length);
//             printf("-- curr-word = %s --\n", current_word);
//             printf("Comparison result = %d\n", strncmp(words[index - 1].text, (sentence - word_length), word_length));

//             if (strncmp(words[index - 1].text, (sentence - word_length), word_length) != 0 && index != 1)
//             {
//                 strncpy(words[index++].text, (sentence - word_length), word_length);
//                 words->count = index;
//                 word_length = 0;
//                 total_words++;
//             }

//             printf("word[%d]: %s\n", index - 1, words[index - 1].text);
//             printf("word count: %d\n", words->count);
//             printf("word count: %d\n", total_words);
//         }

//         word_length++;
//         sentence++;
//     }

//     printf("-- ONLY ONE WORD OR FINAL WORD --\n");
//     printf("word_length: %d\n", word_length);
//     /* Only one word or final word*/
//     if (is_not_empty_sentence)
//     {
//         if (strncmp(words[index - 1].text, (sentence - word_length), word_length) != 0 && index != 1)
//         {
//             strncpy(words[index++].text, (sentence - word_length), word_length);
//             words->count = index;
//             word_length = 0;
//             total_words++;
//         }

//         printf("word[%d]: %s\n", index - 1, words[index - 1].text);
//         printf("word count: %d\n", words->count);
//         printf("word count: %d\n", total_words);
//     }

//     printf("-- Printing words --\n");
//     for (unsigned char i = 0; i < words->count; i++)
//     {
//         printf("words[%d] = %s\n", i, words[i].text);
//     }

//     return total_words;
// }

/* First try*/
int count_words(const char *sentence, word_count_word_t *words)
{
    unsigned char total_words = 0;
    unsigned char word_length = 0;
    unsigned char is_not_empty_sentence = 0;

    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

    while (*sentence != '\0')
    {
        is_not_empty_sentence = 1;

        if (*sentence == ' ')
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
                    if (strncmp(words[i].text, (sentence - (word_length)), word_length) == 0)
                    {
                        printf("Inside if repeated word\n");
                        words[i].count++;

                        printf("words[%d].text = %s\n", total_words - 1, words[total_words - 1].text);
                        printf("words[%d].count = %d\n", total_words - 1, words[total_words - 1].count);
                        break;
                    }
                    /* New word */
                    else
                    {
                        strncpy(words[total_words++].text, (sentence - (word_length - 1)), word_length - 1);
                        words[total_words - 1].count++;

                        printf("New word\n");
                        printf("words[%d].text = %s\n", total_words - 1, words[total_words - 1].text);
                        printf("words[%d].count = %d\n", total_words - 1, words[total_words - 1].count);
                        break;
                        
                    }
                }
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
