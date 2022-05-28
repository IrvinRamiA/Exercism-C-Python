#include "anagram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

static void convert_string_to_lower_case(char *sentence)
{
    for (unsigned char i = 0; i < strlen(sentence); i++)
    {
        *(sentence + i) = tolower(*(sentence + i));
    }
}

void find_anagrams(char *subject, struct candidates *candidates)
{
    unsigned char coincidences_counter = 0u;
    unsigned char subject_length = strlen(subject);

    convert_string_to_lower_case(subject);

    for (unsigned char i = 0u; i < candidates->count; i++)
    {
        convert_string_to_lower_case(candidates->candidate[i].word);
        if (subject_length == strlen(candidates->candidate[i].word) &&
            strncmp(subject, candidates->candidate[i].word, subject_length) != 0u)
        {
            while (*subject != '\0')
            {
                for (unsigned char j = 0u; j < strlen(candidates->candidate[i].word); j++)
                {
                    if (*subject == candidates->candidate[i].word[j])
                    {
                        coincidences_counter++;
                        break;
                    }
                }
                subject++;
            }
            subject -= subject_length;
        }

        if (coincidences_counter == subject_length)
        {
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
        }
        else
        {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        }

        coincidences_counter = 0u;
    }
}
