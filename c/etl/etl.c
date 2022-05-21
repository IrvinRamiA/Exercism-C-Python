#include "etl.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static int compare(const void *a, const void *b)
{
    return ((new_map *)a)->key - ((new_map *)b)->key;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
    unsigned char output_length = 0;
    unsigned char output_index = 0;

    /* Calculating output length */
    for (unsigned char i = 0; i < input_len; i++)
    {
        output_length += strlen(input[i].keys);
    }

    /* Memory allocation for output map */
    *output = (new_map *)malloc(output_length * sizeof(new_map));

    /* Checking each character */
    for (unsigned char i = 0; i < input_len; i++)
    {
        for (unsigned j = 0; j < strlen(input[i].keys); j++)
        {
            (*output)[output_index].key = tolower(input[i].keys[j]);
            (*output)[output_index++].value = input[i].value;
        }
    }

    qsort(*output, output_length, sizeof(new_map), compare);

    return output_length;
}

/*
The old system stored a list of letters per score:

    1 point: "A", "E", "I", "O", "U", "L", "N", "R", "S", "T",
    2 points: "D", "G",
    3 points: "B", "C", "M", "P",
    4 points: "F", "H", "V", "W", "Y",
    5 points: "K",
    8 points: "J", "X",
    10 points: "Q", "Z",
*/
/*
"a" is worth 1 point.
"b" is worth 3 points.
"c" is worth 3 points.
"d" is worth 2 points.
*/
