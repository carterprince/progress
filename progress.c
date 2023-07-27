#include <stdio.h>
#include <time.h>

#define BIRTH_YEAR 2003
#define BIRTH_MONTH 11
#define BIRTH_DAY 7
#define LIFESPAN 80

void print_progress(double progress, const char* label) {
    int filled = progress * 30;
    printf("%s[", label);
    for (int i = 0; i < 30; i++) {
        if (i < filled) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("] %.1f%%\n", progress * 100);
}

int main() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    double day_progress = (tm->tm_hour * 3600.0 + tm->tm_min * 60.0 + tm->tm_sec) / 86400.0;
    double week_progress = (tm->tm_wday + day_progress) / 7.0;
    double month_progress = (tm->tm_mday - 1 + day_progress) / 30.0;
    double year_progress = (tm->tm_yday + day_progress) / 365.0;

    struct tm birth_tm = {0};
    birth_tm.tm_year = BIRTH_YEAR - 1900;
    birth_tm.tm_mon = BIRTH_MONTH - 1;
    birth_tm.tm_mday = BIRTH_DAY;
    time_t birth_t = mktime(&birth_tm);
    double life_progress = difftime(t, birth_t) / (LIFESPAN * 365.24 * 24 * 60 * 60);

    print_progress(day_progress,   "Day   ");
    print_progress(week_progress,  "Week  ");
    print_progress(month_progress, "Month ");
    print_progress(year_progress,  "Year  ");
    print_progress(life_progress,  "Life  ");

	printf("\n");

	return 0;
}
