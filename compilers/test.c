#include <stdio.h>

void main()
{
    // char *numbers[] = {"One", "Two", "Three", ""}, **n;
    char *myStrings[] = { "one", "two", "three", "four", "123456789abcdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };

    size_t i = 0;
    printf("%ld\n", sizeof(myStrings));
    printf("%d\n", sizeof(myStrings[0]));
    printf("String: %s\n", myStrings[4]);
    printf("%d\n", sizeof(int));
    for( i = 0; i < sizeof(myStrings) / sizeof(myStrings[0]); i++)
    {
        printf("%s\n", myStrings[i]);
    }
    // n = numbers;
    // printf("%d\n", *n);
    // while (*n != "") {
    //   printf ("%s\n",  *n++);
    // }
    return;
}
