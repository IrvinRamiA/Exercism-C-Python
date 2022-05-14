#include "grade_school.h"
#include <string.h>
#include <stdio.h>

static roster_t roster = {0};
static unsigned char index = 0;

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

    printf("roster.count = %d\n", roster.count);
    printf("roster.student[%d].grade = %d\n", roster.count - 1, roster.students[roster.count - 1].grade);
    printf("roster.student[%d].name = %s\n", roster.count - 1, roster.students[roster.count - 1].name);
}

roster_t get_roster(void)
{
    return roster;
}

roster_t get_grade(uint8_t desired_grade)
{
    if (desired_grade)
    {
    }
    return roster;
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
