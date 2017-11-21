#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 512

int main(void)
{
    /*Буффер для вводимых строк*/
    char buf[BUFF_SIZE];

    /*Указатель на указатель для организации массива строк*/
    char **strArr = 0;

    /*Счётчик для количества строк*/
    int strCount = 0;

    /*i для for в стиле Си ;) */
    int i = 0;

    /*Запрашиваем ввод строки и записывает в массив buf*/
    printf("Вводи строку: ");
    scanf("%s", buf);

    /*Вывод введённой строки и длины строки*/
    printf("Ты ввёл: %s\n", buf);
    printf("Длинной: %i\n", strlen(buf));

    /*Выделяем место под указатель для строки (он же массив символов)*/
    if(strArr = (char *)malloc(sizeof(char *)))
        strCount++;
    else{
        printf("Память не выделена!");
        return 1;
    }

    /*Выделяем место под массив символов и присваеваем указатель указателю в массиве strArr*/
    if( strArr[0] = (char *)calloc(strlen(buf) + 1, sizeof(char)) )
        memcpy(strArr[0], buf, strlen(buf) + 1);
    else{
        printf("Память не выделена!");
        return 1;
    }

    /*Проверяем, что скопировалось в strArr[0]*/
    printf("В strArr скопировано: %s\n\n", strArr[0]);

    /*Запускаем цикл по считыванию строк*/
    while(!feof(stdin)){

        printf("Вводи строку: ");
        scanf("%s", buf);
        printf("Ты ввёл: %s\n", buf);
        printf("Длинной: %i\n", strlen(buf));

        /*Начинаем повторять, что сделали до цикла*/
        /*Расширяем количество памяти на которую указывает массив strArr*/
        if( strArr = (char **)realloc(strArr, (sizeof(char *) * (strCount + 1))) ){
        strArr[strCount] = (char *)malloc(sizeof(char *));
        strCount++;
        }
        else{
            printf("Недостаточно памяти!");
            return 1;
        }

        /*Выделяем память под строку*/
        /*Копируем строку из буфера в массив на который указывает указатель из strArr*/
        if( strArr[strCount - 1] = (char *)calloc(strlen(buf) + 1, sizeof(char)) ){
            memcpy(strArr[strCount - 1], buf, strlen(buf) + 1);
        }
        else{
            printf("Недостаточно памяти!");
            return 1;
        }

        printf("В strArr скопировано: %s\n\n", strArr[strCount - 1]);
    }

    printf("\n");

    /*Выводим строки из массива strArr*/
    for(i = 0; i < strCount; i++)
        printf("В strArr содержится: %s\n", strArr[i]);

    /*Освобождаем память*/
    for(i = 0; i < strCount; i++)
        free(strArr[i]);

    free(strArr);

    return 0;
}
