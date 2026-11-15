
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 300

int task1(void) 
{
    int i, j;

    printf("\nПолная таблица умножения:\n\n");

    printf("    ");
    for (j = 1; j <= 9; j++) 
    {
        printf("%4d", j);
    }
    printf("\n");

    for (i = 1; i <= 9; i++) 
    {
        printf("%3d ", i);

        for (j = 1; j <= 9; j++) 
        {
            printf("%4d", i * j);
        }

        printf("\n");
    }

    printf("\nЛевая нижняя часть таблицы Пифагора:\n\n");

    for (i = 1; i <= 9; i++) 
    {
        for (j = 1; j <= 9; j++) 
        {
            if (j <= i) 
            {
                printf("%4d", i * j);
            } 
            else 
            {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("\nИндивидуальный вариант 4:\n\n");

    for (i = 1; i <= 5; i++) 
    {
        for (j = 1; j <= i; j++) 
        {
            printf("%4d", 5);
        }
        printf("\n");
    }

    return 0;
}

int task2(void) 
{
    char number[MAX_DIGITS + 1];
    char answer;

    do 
    {
        int i, len, valid = 1;

        int count3 = 0;
        int lastDigitRepeats = 0;
        int evenCount = 0;
        int greater5Count = 0;
        int oddSum = 0;
        int sumAtLeast7 = 0;
        int evenSumWithoutLast = 0;
        int equalAdjacentPairs = 0;

        int firstHalfSum = 0;
        int secondHalfSum = 0;

        int oddPositionSum = 0;
        int evenPositionSum = 0;

        int lastDigit;

        long double nonZeroProduct = 1.0L;
        long long productTwoDigits = 0;

        printf("Введите положительное целое число (до 300 цифр): ");
        scanf("%300s", number);

        len = (int)strlen(number);

        for (i = 0; i < len; i++) {
            if (number[i] < '0' || number[i] > '9') 
            {
                valid = 0;
                break;
            }
        }

        if (!valid) 
        {
            printf("Ошибка! Вводите только цифры от 0 до 9.\n");
        } 
        else 
        {

            lastDigit = number[len - 1] - '0';

            for (i = 0; i < len; i++) 
            {

                int digit = number[i] - '0';
                int positionFromRight = len - i;

                if (digit == 3)
                    count3++;

                if (digit % 2 == 0)
                    evenCount++;

                if (digit > 5)
                    greater5Count++;

                if (digit % 2 != 0)
                    oddSum += digit;

                if (digit >= 7)
                    sumAtLeast7 += digit;

                if (digit != 0)
                    nonZeroProduct *= digit;

                if (i > 0 && number[i] == number[i - 1])
                    equalAdjacentPairs++;

                if (positionFromRight % 2 == 0)
                    evenPositionSum += digit;
                else
                    oddPositionSum += digit;
            }

            for (i = 0; i < len - 1; i++) 
            {
                if (number[i] - '0' == lastDigit)
                    lastDigitRepeats++;
            }

            if (len >= 2) 
            {
                int secondDigit = number[1] - '0';
                int penultimateDigit = number[len - 2] - '0';

                productTwoDigits =
                    (long long)secondDigit * penultimateDigit;
            }

            for (i = 0; i < len - 1; i++) 
            {
                int digit = number[i] - '0';

                if (digit % 2 == 0)
                    evenSumWithoutLast += digit;
            }

            for (i = 0; i < len / 2; i++)
                firstHalfSum += number[i] - '0';

            for (i = len - len / 2; i < len; i++)
                secondHalfSum += number[i] - '0';


            printf("\n===== РЕЗУЛЬТАТЫ АНАЛИЗА =====\n");

            printf("1. Количество цифр 3: %d\n", count3);

            printf("2. Повторы последней цифры (%d): %d\n",
                   lastDigit, lastDigitRepeats);

            printf("3. Количество четных цифр: %d\n", evenCount);

            printf("4. Количество цифр больше, чем 5: %d\n",
                   greater5Count);

            printf("5. Сумма нечётных цифр: %d\n", oddSum);

            printf("6. Сумма цифр >= 7: %d\n", sumAtLeast7);

            printf("7. Произведение ненулевых цифр: %.0Lf\n",
                   nonZeroProduct);

            if (len >= 2) 
            {
                printf("8. Произведение второй и предпоследней цифр: %lld\n",
                       productTwoDigits);
            } 
            else 
            {
                printf("8. Недостаточно цифр.\n");
            }

            printf("9. Сумма чётных цифр без последней: %d\n",
                   evenSumWithoutLast);

            printf("10. Количество смежных равных пар: %d\n",
                   equalAdjacentPairs);

            printf("    Равные пары: ");

            if (equalAdjacentPairs == 0) 
            {
                printf("ничего");
            } 
            else 
            {
                for (i = 1; i < len; i++) 
                {
                    if (number[i] == number[i - 1])
                        printf("%c%c ", number[i - 1], number[i]);
                }
            }

            printf("\n");

            printf("11. Сумма за первую половину: %d\n", firstHalfSum);
            printf("    Сумма за вторую половину: %d\n", secondHalfSum);

            if (firstHalfSum == secondHalfSum)
                printf("    Суммы равны.\n");
            else
                printf("    Суммы не равны.\n");

            if (len % 2 != 0)
                printf("    Средняя цифра исключается.\n");

            printf("12. Произведение сумм нечётных и чётных позиций: %lld\n",
                   (long long)oddPositionSum * evenPositionSum);

            printf("    Сумма нечётных позиций: %d\n", oddPositionSum);
            printf("    Сумма четных позиций: %d\n", evenPositionSum);
        }

        printf("\nПроанализировать еще одно число? (y/n): ");
        scanf(" %c", &answer);

    } 
    while (answer != 'n' && answer != 'N');

    return 0;
}

int task3(void) 
{
    int radius;
    char symbol, answer;

    do 
    {
        int i, j;

        printf("Прямоугольный треугольник, вписанный в окружность.\n");

        printf("Введите символ рисования: ");
        scanf(" %c", &symbol);

        printf("Введите радиус R (3-25): ");

        if (scanf("%d", &radius) != 1) 
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

        if (radius < 3 || radius > 25) 
        {
            printf("Ошибка! Радиус должен быть от 3 до 25.\n");
        } 
        else 
        {

            int rows = 2 * radius;
            int columns = 4 * radius;

            printf("\n");

            for (i = 0; i <= rows; i++) 
            {

                double y = 1.0 - (double)i / radius;

                for (j = 0; j <= columns; j++) 
                {

                    double x = ((double)j - 2.0 * radius)
                               / (2.0 * radius);

                    int inTriangle =
                        (y >= 0.0 && y <= 1.0 - fabs(x));

                    int onCircle =
                        (fabs(x * x + y * y - 1.0)
                         <= 1.2 / radius);

                    if (inTriangle || onCircle) 
                    {
                        putchar(symbol);
                    } 
                    else 
                    {
                        putchar(' ');
                    }
                }

                putchar('\n');
            }
        }

        printf("\nНарисовать еще одну фигуру? (y/n): ");
        scanf(" %c", &answer);

    } while (answer != 'n' && answer != 'N');

    return 0;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    task1(void); task2(void); task3(void);
} 
