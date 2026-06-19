#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Функция для определения дня недели по году, месяцу и дню
// Возвращает: 0 - воскресенье, 1 - понедельник, ..., 6 - суббота
int WEEKSDAY(int year, int month, int day){
    struct tm t ={0};          // Структура для хранения даты и времени
    t.tm_year = year - 1900;    // В структуре год хранится как год - 1900
    t.tm_mon = month -1;        // Месяц в структуре: 0 - январь, 11 - декабрь
    t.tm_mday = day;            // День месяца
    t.tm_hour = 12;             // Устанавливаем полдень, чтобы избежать проблем с переходом на летнее время
    mktime(&t);                 // Преобразует структуру в календарное время и нормализует поля
    return  t.tm_wday;          // Возвращаем день недели (0-6)
}

// Функция для вывода текущего местного времени и даты
void localT(){
    struct tm *local, *gm;      // Указатели на структуры для локального и GMT времени
    time_t t;                   // Переменная для хранения текущего времени
    t = time(NULL);             // Получаем текущее время в секундах с 1 января 1970
    local = localtime(&t);      // Преобразуем в локальное время
    printf("Local: %s", asctime(local)); // Выводим отформатированную дату и время
}

// Функция для печати названия дня недели по числовому значению
void printDWeek(int dayOfWeek) {
    const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    printf("%s\n", days[dayOfWeek]);
}

// Функция для определения количества дней в месяце
int DAYSINMONTH(int year, int month){
    struct tm t = {0};          // Структура для хранения даты
    t.tm_year = year - 1900;    // Год в формате структуры
    t.tm_mon = month;           // Устанавливаем следующий месяц (для вычисления последнего дня текущего)
    t.tm_mday = 1;              // Первое число следующего месяца
    t.tm_hour = 12;             // Устанавливаем полдень
    mktime(&t);                 // Нормализуем структуру
    t.tm_mday = 0;              // Устанавливаем день 0, что означает последний день предыдущего месяца
    mktime(&t);                 // Получаем последний день нужного месяца
    return t.tm_mday;           // Возвращаем количество дней в месяце
}

// Функция для печати календаря на один месяц
void printMONTH(int year, int month){
    const char *MONTHS[] = {"JAN","FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    printf("%s, %d \n", MONTHS[month-1], year); // Выводим название месяца и год
    printf(" Mon Tue Wed Thu Fri Sat Sun\n");   // Заголовки дней недели
    
    int firstDAY = WEEKSDAY(year, month, 1);    // Определяем день недели для 1-го числа
    
    // Вычисляем количество пробелов перед первым днем месяца
    // Формула преобразует воскресенье (0) в 6, понедельник (1) в 0, и т.д.
    int PROBEL = (firstDAY + 6)%7;
    
    int i;
    for(i =0; i<PROBEL; i++){
        printf("    ");         // Печатаем пробелы для выравнивания
    }
    
    int days = DAYSINMONTH(year, month); // Получаем количество дней в месяце
    int day;
    for (day = 1; day<=days;day++){
        printf("%4d", day);      // Печатаем день с шириной 4 символа
        // Если достигли конца недели (суббота), переходим на новую строку
        if ((PROBEL + day)%7 == 0){
            printf("\n");
        }
    }
    printf("\n\n");             // Добавляем пустые строки после календаря
}

// Функция для печати календаря на весь год (все 12 месяцев)
void printYEARCAL(int year){
    int month;
    for (month = 1; month<13; month++){
        printMONTH(year, month); // Печатаем каждый месяц по очереди
    }
}

// Главная функция
int main() {
    // Переменные для хранения года, месяца и дня
    int year, month, day;
    char input[256];            // Буфер для ввода пользователя
    
    // Выводим приглашение с описанием форматов ввода
    printf("CHOOSE:\n yyyy.mm.dd - weekday\n yyyy.mm - month calendar\n yyyy - year calendar\n now - todays date and time\n");
    
    fgets(input, sizeof(input), stdin); // Считываем строку ввода
    input[strcspn(input, "\n")] = 0;    // Удаляем символ новой строки из конца строки
    
    // Подсчитываем количество точек во введенной строке
    int i;
    int dots = 0;
    for (i = 0; input[i]; i++) {
        if (input[i] == '.') dots++;
    }
    
    // Проверяем команду "now" - вывод текущего времени
    if (strcmp(input, "now") == 0){
        localT();
    }
    // Если в строке 2 точки - формат "год.месяц.день" - определяем день недели
    else if (dots == 2){
        sscanf(input, "%d.%d.%d", &year, &month, &day); // Извлекаем числа из строки
        int weekday = WEEKSDAY(year, month, day);       // Вычисляем день недели
        printDWeek(weekday);                            // Выводим название дня
    }
    // Если в строке 1 точка - формат "год.месяц" - выводим календарь месяца
    else if(dots == 1){
        sscanf(input, "%d.%d", &year, &month);  // Извлекаем год и месяц
        printMONTH(year, month);                // Печатаем календарь месяца
    }
    // Если точек нет - формат "год" - выводим календарь на весь год
    else if (dots == 0){
        sscanf(input, "%d", &year);     // Извлекаем только год
        printYEARCAL(year);             // Печатаем календарь на год
    }
    
    return 0;   // Завершаем программу
}