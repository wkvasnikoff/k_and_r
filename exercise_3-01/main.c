/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only one
 * test inside the loop and measure the difference in run-time
 */

#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, mid, high, save;
    low = 0;
    high = n - 1;
    save = -1;

    while (low < high) {
        mid = (low + high) / 2;
        save = mid;
        if (v[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (v[mid] == x) {
        return mid;
    }

    return -1;
}

int main()
{
    int x = 21;
    int v[] = {2,5,7,8,9,10,14,21,23};
    int len = sizeof(v) / sizeof(int);

    printf("search for %d\nIn [", x);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");

    printf("%d\n", binsearch(x, v, len));

}
