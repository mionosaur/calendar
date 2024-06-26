#include <stdio.h>

int is_bissextile(int year)
{
    int return_value = 0;
    if (year > 1582) // Gregorian calendar
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            return_value = 1;
        }
    }
    else // Julian calendar
    {
        if (year % 4 == 0)
        {
            return_value = 1;
        }
    }
    return return_value;
}

int weekday(int day, int month, int year)
{
    int day_index = 4; // The day before the 01/01/0001, if it make sens

    // Day
    day_index += day;

    // Month
    day_index += 31 * (month - 1);

    switch (month)
    {
        case 12:
            day_index--;
        case 11:
        case 10:
            day_index--;
        case 9:
        case 8:
        case 7:
            day_index--;
        case 6:
        case 5:
            day_index--;
        case 4:
        case 3:
            if (is_bissextile(year))
            {
                day_index -= 2;
            }
            else
            {
                day_index -= 3;
            }
            break;
    }

    // Year
    day_index += 365*(year-1);
    if (year > 1582)
    {
        day_index += (year-1) / 4;
        day_index -= (year-1) / 100;
        day_index += (year-1) / 400;
        day_index += 2;
    }
    else
    {
        day_index += (year-1)/4;
    }

    day_index %= 7;
    return day_index;
}

int check_date(int day, int month, int year)
{
    if (year < 1)
    {
        fprintf(stderr, "Year %d is not valid.\n", year);
        return 0;
    }

    if (month < 1 || month > 12)
    {
        fprintf(stderr, "Month %d does not exist.\n", month);
        return 0;
    }

    if (day < 1)
    {
        fprintf(stderr, "Day must be greater than 0.\n");
        return 0;
    }

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 31)
            {
                fprintf(stderr, "Month %d only have 31 days.\n", month);
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 31)
            {
                fprintf(stderr, "Month %d only have 30 days.\n", month);
                return 0;
            }
            break;
        case 2:
            if (is_bissextile(year))
            {
                if (day > 29)
                {
                    fprintf(stderr, "Month %d only have 29 days.\n", month);
                    return 0;
                }
            }
            else
            {
                if (day == 29)
                {
                    fprintf(stderr, "%d is a not a leap year. February only have 28 days.\n", year);
                    return 0;
                }
                else if (day > 29)
                {
                    fprintf(stderr, "Month %d only have 28 days.\n", month);
                    return 0;
                }
            }
    }
    return 1;
}

int day_in_month(int month, int year)
{
    int nb_days = 0;
    switch (month)
    {
        case 1:
            nb_days = 31;
            break;
        case 2:
            if (is_bissextile(year))
            {
                nb_days = 29;
            }
            else
            {
                nb_days = 28;
            }
            break;
        case 3:
            nb_days = 31;
            break;
        case 4:
            nb_days = 30;
            break;
        case 5:
            nb_days = 31;
            break;
        case 6:
            nb_days = 30;
            break;
        case 7:
            nb_days = 31;
            break;
        case 8:
            nb_days = 31;
            break;
        case 9:
            nb_days = 30;
            break;
        case 10:
            nb_days = 31;
            break;
        case 11:
            nb_days = 30;
            break;
        case 12:
            nb_days = 31;
            break;
    }
    return nb_days;
}

void month_name(int month, char **name)
{
    switch (month)
    {
        case 1:
            *name = "January";
            break;
        case 2:
            *name = "February";
            break;
        case 3:
            *name = "March";
            break;
        case 4:
            *name = "April";
            break;
        case 5:
            *name = "May";
            break;
        case 6:
            *name = "June";
            break;
        case 7:
            *name = "July";
            break;
        case 8:
            *name = "August";
            break;
        case 9:
            *name = "September";
            break;
        case 10:
            *name = "October";
            break;
        case 11:
            *name = "November";
            break;
        case 12:
            *name = "December";
            break;
    }
}