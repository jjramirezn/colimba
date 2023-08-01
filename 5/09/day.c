#include <stdio.h>

int day_of_year(unsigned year, unsigned month, unsigned day);
int month_day(unsigned year, unsigned yearday, unsigned *pmonth, unsigned *pday);

static unsigned char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* Exercise 5-8. There is no error checking in day_of .year or month.day.
 * Remedy this defect.
 */
int main(void)
{
        unsigned year = 2023;
        unsigned month = 7;
        unsigned day = 31;
        printf("Day %d of month %d is the day number %d of the year %d\n",
                        day, month, day_of_year(year, month, day), year);
        month = day = 0;
        month_day(year, 212, &month, &day);
        printf("Day %d of year %d is the day %d of month %d\n"
                        , 212, year, day, month);
        month = 2;
        day = 28;
        printf("Day %d of month %d is the day number %d of the year %d\n",
                        day, month, day_of_year(year, month, day), year);
        day = 29;
        printf("Day %d of month %d is the day number %d of the year %d\n",
                        day, month, day_of_year(year, month, day), year);
        day = 30;
        printf("Day %d of month %d is the day number %d of the year %d\n",
                        day, month, day_of_year(year, month, day), year);
        year = 2000;
        day = 29;
        printf("Day %d of month %d is the day number %d of the year %d\n",
                        day, month, day_of_year(year, month, day), year);
        month = day = 0;
        month_day(year, 366, &month, &day);
        printf("Day %d of year %d is the day %d of month %d\n"
                        , 366, year, day, month);
        month = day = 0;
        year = 2023;
        month_day(year, 366, &month, &day);
        printf("Day %d of year %d is the day %d of month %d\n"
                        , 366, year, day, month);
        month = day = 0;
        month_day(year, 367, &month, &day);
        printf("Day %d of year %d is the day %d of month %d\n"
                        , 367, year, day, month);
        return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(unsigned year, unsigned month, unsigned day)
{
        unsigned leap;
        unsigned char *pmonths;
        if (month < 1 || 12 < month) {
                printf("error:day_of_year: month must be between 1 and 12.\n");
                return -1;
        }
        if (day < 1 || 31 < day) {
                printf("error:day_of_year: day must be between 1 and 31.\n");
                return -1;
        }

        leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
        pmonths = *(daytab + leap);
        if (*(pmonths + month) < day) {
                printf("error:day_of_year: invalid date.\n");
                return -1;
        }
        while (0 < month--) {
                day += *(++pmonths);
        }
        return day;
}

/* month_day: set month, day from day of year */
int month_day(unsigned year, unsigned yearday, unsigned *pmonth, unsigned *pday)
{
        unsigned i, leap;
        unsigned char *pmonths;
        if (yearday < 1 || 366 < yearday) {
                printf("error:month_day: yearday must be between 1 and 366.\n");
                return -1;
        }

        leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
        if (366 == yearday && !leap) {
                printf("error:month_day: yearday must be between 1 and 365 on non-leap years.\n");
                return -1;
        }
        pmonths = *(daytab + leap);
        for (i = 1; *pmonths < yearday; i++) {
                yearday -= *(++pmonths);
        }
        *pmonth = i;
        *pday = yearday;
        return 0;
}
