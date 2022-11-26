#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarySearch(int arr[], int size, int search)
{
    int low = 0, mid, high = size - 1, flag = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2; // to avoid overflow
        if (arr[mid] == search)
        {
            flag = 1;
            break;
        }
        else if (arr[mid] < search)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (flag == 1)
    {
        printf("Found the item!");
    }
    else
    {
        printf("Not found");
    }
}

int main()
{
    int i, j, flag, temp, random, searchValue;
    int list[20];

    srand(time(NULL)); // for generating random numbers

    printf("List before sorting\n");
    for (i = 0; i < 20; i++)
    {
        random = rand() % 100; // generating random value between 0 to 100
        list[i] = random;
        printf("%d\n", list[i]);
    }

    // sorting the list

    for (i = 0; i < 19; i++)
    {
        flag = 0;
        for (j = i; j < 20; j++)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            flag = 1;
        }
        if (flag == 0)
        {
            break;
        }
    }

    printf("List after sorting\n");
    for (i = 0; i < 20; i++)
    {
        printf("%d\n", list[i]);
    }

    printf("Enter a no to search\n");
    scanf("%d", &searchValue);

    binarySearch(list, 20, searchValue);
}