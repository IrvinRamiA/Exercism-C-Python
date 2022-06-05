#include "matching_brackets.h"
#include <stdint.h>
#include <stdio.h>

bool is_paired(const char *input)
{
    bool result = false;
    bool correct_order = true;
    uint8_t initial_round = 0;
    uint8_t initial_square = 0;
    uint8_t initial_curly = 0;
    uint8_t final_round = 0;
    uint8_t final_square = 0;
    uint8_t final_curly = 0;
    char last_initial_bracket;
    bool is_first_initial_bracket = true;

    while (*input != 0)
    {
        switch (*input)
        {
        case '(':
            initial_round++;
            last_initial_bracket = '(';
            break;
        case '[':
            initial_square++;
            last_initial_bracket = '[';
            break;
        case '{':
            initial_curly++;
            last_initial_bracket = '{';
            break;
        case ')':
            final_round++;
            if (initial_round < final_round ||
                (last_initial_bracket != '(' && is_first_initial_bracket))
            {
                correct_order = false;
            }
            if (is_first_initial_bracket)
            {
                is_first_initial_bracket = false;
            }
            break;
        case ']':
            final_square++;
            if (initial_square < final_square ||
                (last_initial_bracket != '[' && is_first_initial_bracket))
            {
                correct_order = false;
            }
            if (is_first_initial_bracket)
            {
                is_first_initial_bracket = false;
            }
            break;
        case '}':
            final_curly++;
            if (initial_curly < final_curly ||
                (last_initial_bracket != '{' && is_first_initial_bracket))
            {
                correct_order = false;
            }
            if (is_first_initial_bracket)
            {
                is_first_initial_bracket = false;
            }
            break;
        default:
            break;
        }

        input++;
    }

    if (initial_round == final_round &&
        initial_square == final_square &&
        initial_curly == final_curly &&
        correct_order)
    {
        result = true;
    }

    return result;
}
