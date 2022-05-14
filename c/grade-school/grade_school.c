#include "grade_school.h"
#include <string.h>
#include <stdio.h>

static roster_t roster = {0};
static unsigned char index = 0;

static void order_names_in_ordered_by_grade_roster(roster_t *roster_to_order)
{
    char aux_name[MAX_NAME_LENGTH];

    for (unsigned char i = 0; i < roster_to_order->count; i++)
    {
        for (unsigned char j = i + 1; j < roster_to_order->count; j++)
        {
            if (roster_to_order->students[i].grade == roster_to_order->students[j].grade)
            {
                if (strcmp(roster_to_order->students[i].name, roster_to_order->students[j].name) > 0)
                {
                    strcpy(aux_name, roster_to_order->students[i].name);
                    strcpy(roster_to_order->students[i].name, roster_to_order->students[j].name);
                    strcpy(roster_to_order->students[j].name, aux_name);
                }
            }
        }
    }
}

static void order_by_grade(roster_t *roster_to_order)
{
    char aux_grade;
    char aux_name[MAX_NAME_LENGTH];

    for (unsigned char i = 0; i < roster_to_order->count; i++)
    {
        for (unsigned char j = i + 1; j < roster_to_order->count; j++)
        {
            if (roster_to_order->students[i].grade > roster_to_order->students[j].grade)
            {
                aux_grade = roster_to_order->students[i].grade;
                strcpy(aux_name, roster_to_order->students[i].name);
                roster_to_order->students[i].grade = roster_to_order->students[j].grade;
                strcpy(roster_to_order->students[i].name, roster_to_order->students[j].name);
                roster_to_order->students[j].grade = aux_grade;
                strcpy(roster_to_order->students[j].name, aux_name);
            }
        }
    }
}

void add_student(char *name_buffer, uint8_t grade)
{
    for (unsigned char i = 0; i < index + 1; i++)
    {
        if (strncmp(roster.students[i].name, name_buffer, MAX_NAME_LENGTH) == 0)
        {
            return;
        }
    }

    index = roster.count++;
    strcpy(roster.students[index].name, name_buffer);
    roster.students[index].grade = grade;

    order_by_grade(&roster);
    order_names_in_ordered_by_grade_roster(&roster);
}

roster_t get_roster(void)
{
    return roster;
}

roster_t get_grade(uint8_t desired_grade)
{
    roster_t roster_by_grade = {0};

    for (unsigned char i = 0; i < index + 1; i++)
    {
        if (roster.students[i].grade == desired_grade)
        {
            roster_by_grade.count++;
            roster_by_grade.students[roster_by_grade.count - 1].grade = roster.students[i].grade;
            strcpy(roster_by_grade.students[roster_by_grade.count - 1].name,
                   roster.students[i].name);
        }
    }

    order_names_in_ordered_by_grade_roster(&roster_by_grade);

    return roster_by_grade;
}

void clear_roster(void)
{
    for (unsigned char i = 0; i < MAX_STUDENTS; i++)
    {
        roster.count = 0;
        roster.students[i].grade = 0;
        memset(roster.students[i].name, 0, MAX_NAME_LENGTH);
    }
}
