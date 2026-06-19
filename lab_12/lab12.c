#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int WEEKSDAY(int year, int month, int day){
	struct tm t ={0};
	t.tm_year = year - 1900;
	t.tm_mon = month -1;
	t.tm_mday = day;
	t.tm_hour = 12;
	mktime(&t);
	return  t.tm_wday;
}

void localT(){
	struct tm *local, *gm;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	printf("Local: %s", asctime(local));
}
void printDWeek(int dayOfWeek) {
    const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    printf("%s\n", days[dayOfWeek]);
}
int DAYSINMONTH(int year, int month){
	struct tm t = {0};
	t.tm_year = year - 1900;
	t.tm_mon = month;
	t.tm_mday = 1;
	t.tm_hour = 12;
	mktime(&t);
	t.tm_mday = 0;
	mktime(&t);
	return t.tm_mday;
}
void printMONTH(int year, int month){
	const char *MONTHS[] = {"JAN","FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	printf("%s, %d \n", MONTHS[month-1], year);
	printf(" Mon Tue Wed Thu Fri Sat Sun\n");
	int firstDAY = WEEKSDAY(year, month, 1);
	
	int PROBEL = (firstDAY + 6)%7;
	int i;
	for(i =0; i<PROBEL; i++){
		printf("    ");
	}
	int days = DAYSINMONTH(year, month);
	int day;
	for (day = 1; day<=days;day++){
		printf("%4d", day);
		if ((PROBEL + day)%7 == 0){
			printf("\n");
		}
	}
	printf("\n\n");
	
}
void printYEARCAL(int year){
	int month;
	for (month = 1; month<13; month++){
		printMONTH(year, month);
	}
}


int main() {
	/*int weekday = WEEKSDAY(2026, 5, 14);
	printf("Weekday: %d\n", weekday);
	printDWeek(weekday);
	printMONTH(2026, 5);
	localT();
	
	printYEARCAL(2026);*/
	int year, month, day;
	char input[256];
	printf("CHOOSE:\n yyyy.mm.dd - weekday\n yyyy.mm - month calendar\n yyyy - year calendar\n now - todays date and time\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;
	int i;
	int dots = 0;
        for (i = 0; input[i]; i++) {
            if (input[i] == '.') dots++;
        }
	if (strcmp(input, "now") == 0){
		localT();
	}
    //printf("Íàéäåíî òî÷åê: %d\n", dots);
	else if (dots == 2){
		sscanf(input, "%d.%d.%d", &year, &month, &day);
		int weekday = WEEKSDAY(year, month, day);
		printDWeek(weekday);
	}
	else if(dots == 1){
		sscanf(input, "%d.%d", &year, &month);
		printMONTH(year, month);
	}
	
	else if (dots == 0){
		sscanf(input, "%d", &year);
		printYEARCAL(year);
	}
	
	
	return 0;
	
}