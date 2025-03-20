/* Assignment 5: The goal of this assignment is to practice using functions in C programming by performing algebraic operations with rational numbers. */
/* Author: Edison Lin */

#include <stdio.h>

int currNum;
int currDen;
int newNum;
int newDen;

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int reducedFormat() 
{
    int div = gcd(currNum, currDen);
    int redNum = currNum / div;
    int redDen = currDen / div;
    if (redDen < 0) 
    {
        redDen = -redDen;
        redNum = -redNum;
    }
    if (redDen == 1) 
    {
        printf("%d\n", redNum);
    } 
    else 
    {
        printf("%d/%d\n", redNum, redDen);
    }
    return 0;
}

int printRational() 
{
    printf("The current result is: ");
    reducedFormat();
    return 0;
}


int inputRational() 
{
    printf("Please input a rational number.\n");
    printf("Numerator: ");
    scanf("%d", &newNum);
    printf("Denominator: ");
    scanf("%d", &newDen);
    if (newDen == 0) 
    {
        printf("ERROR: Denominator cannot be zero!\n");
        inputRational();
    } 
    else 
    {
        if (newDen < 0) 
        {
            newNum = -newNum;
            newDen = -newDen;
        }
        currNum = newNum;
        currDen = newDen;
        reducedFormat();
        printRational();
    }
    return 0;
}

int addRational(int num, int den) 
{
    currNum = currNum * den + currDen * num;
    currDen *= den;
    reducedFormat();
    printRational();
    return 0;
}

int subRational(int num, int den) 
{
    currNum = currNum * den - currDen * num;
    currDen *= den;
    reducedFormat();
    printRational();
    return 0;
}

int multRational(int num, int den) 
{
    currNum *= num;
    currDen *= den;
    reducedFormat();
    printRational();
    return 0;
}

int divRational(int num, int den) 
{
    currNum *= den;
    currDen *= num;
    reducedFormat();
    printRational();
    return 0;
}

int recRational() 
{
    if (currNum == 0) 
    {
        printf("ERROR: Cannot take reciprocal of zero.\n");
    } 
    else 
    {
        int temp = currNum;
        currNum = currDen;
        currDen = temp;
        reducedFormat();
        printRational();
    }
    return 0;
}

int main() 
{
    printf("Welcome to my positive rational number calculator!\n");
    inputRational();
    int choice = 0;
    while (choice != 6) 
    {
        printf("1. Subtract a rational number from the current result;\n");
        printf("2. Add a rational number to the current result;\n");
        printf("3. Multiply the current result by a rational number;\n");
        printf("4. Divide the current result by a rational number;\n");
        printf("5. Take the reciprocal of the current result;\n");
        printf("6. Quit\n");
        printf("Please enter a selection: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Please input a rational number operand.\n");
                printf("Numerator: ");
                scanf("%d", &newNum);
                printf("Denominator: ");
                scanf("%d", &newDen);
                if (newDen == 0) 
                {
                    printf("ERROR: Denominator cannot be zero!\n");
                    break;
                } else 
                {
                    subRational(newNum, newDen);
                }
                break;
            case 2:
                printf("Please input a rational number operand.\n");
                printf("Numerator: ");
                scanf("%d", &newNum);
                printf("Denominator: ");
                scanf("%d", &newDen);
                if (newDen == 0) 
                {
                    printf("ERROR: Denominator cannot be zero!\n");
                    break;
                } else
                {
                    addRational(newNum, newDen);
                }
                break;
            case 3:
                printf("Please input a rational number operand.\n");
                printf("Numerator: ");
                scanf("%d", &newNum);
                printf("Denominator: ");
                scanf("%d", &newDen);
                if (newDen == 0) 
                {
                    printf("ERROR: Denominator cannot be zero!\n");
                    break;
                } else 
                {
                    multRational(newNum, newDen);
                }
                break;
            case 4:
                printf("Please input a rational number operand.\n");
                printf("Numerator: ");
                scanf("%d", &newNum);
                printf("Denominator: ");
                scanf("%d", &newDen);
                if (newDen == 0) 
                {
                    printf("ERROR: Denominator cannot be zero!\n");
                    break;
                } 
                if (newNum == 0) 
                {
                    printf("ERROR: Numerator cannot be zero!\n");
                    break;
                } 
                else
                {
                    divRational(newNum, newDen);
                }
                break;
            case 5:
                recRational(newNum, newDen);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("ERROR: Invalid choice.\n");
                break;
        }
    }
    return 0;
}
