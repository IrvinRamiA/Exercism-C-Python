#include "anagram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void find_anagrams(const char *subject, struct candidates *candidates)
{
    unsigned char coincidences_counter = 0u;
    unsigned char subject_length = strlen(subject);

    for (unsigned char i = 0u; i < candidates->count; i++)
    {
        printf("Candidate: %d\n", i);
        printf("Candidate: %s\n", candidates->candidate[i].word);
        printf("Candidate length = %d\n", strlen(candidates->candidate[i].word));
        printf("Subject length = %d\n", subject_length);
        if (subject_length == strlen(candidates->candidate[i].word))
        {
            printf("Inside if\n");
            while (*subject != '\0')
            {
                for (unsigned char j = 0u; j < strlen(candidates->candidate[i].word); j++)
                {
                    // printf("*subject = %c\n", *subject);
                    // printf("word[j] = %c\n", candidates->candidate[i].word[j]);
                    if (tolower(*subject) == tolower(candidates->candidate[i].word[j]))
                    {
                        // printf("-- TESTING - START --\n");
                        printf("subject char: %c\n", *subject);
                        printf("candidate char: %c\n", candidates->candidate[i].word[j]);
                        printf("COINCIDENCE j = %d\n", j);
                        // printf("-- TESTING - END --\n");
                        coincidences_counter++;
                        break;
                    }
                }
                subject++;
            }
            subject -= subject_length;
        }

        printf("subject_length = %d\n", subject_length);
        printf("coincidences_counter = %d\n", coincidences_counter);
        if (coincidences_counter == subject_length)
        {
            printf("%s is anagram\n", candidates->candidate[i].word);
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
        }
        else
        {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        }

        coincidences_counter = 0u;
    }
}
