#include <stdio.h>
int arrmin(int[], int);
void main()
{
    int i, j, len, rs[50], frame[10], nf, k, avail, count = 0;
    int access[10], freq = 0, dm;
    printf("Length of Reference string : ");
    scanf("%d", &len);
    printf("Enter reference string :\n");
    for (i = 1; i <= len; i++)
        scanf("%d", &rs[i]);
    printf("Enter no. of frames : ");
    scanf("%d", &nf);
    for (i = 0; i < nf; i++)
        frame[i] = -1;
    j = 0;
    printf("\nRef. str Page frames");
    for (i = 1; i <= len; i++)
    {
        printf("\n%4d\t", rs[i]);
        avail = 0;
        for (k = 0; k < nf; k++)
        {
            if (frame[k] == rs[i])
            {
                avail = 1;
                access[k] = ++freq;
                break;
            }
        }
        if (avail == 0)
        {
            dm = 0;
            for (k = 0; k < nf; k++)
            {
                if (frame[k] == -1) dm = 1;break;
            }
            if (dm == 1)
            {
                frame[k] = rs[i];
                access[k] = ++freq;
                count++;
            }
            else
            {
                j = arrmin(access, nf);
                frame[j] = rs[i];
                access[j] = ++freq;
                count++;
            }
            for (k = 0; k < nf; k++)
                printf("%4d", frame[k]);
        }
    }
    printf("\n\nTotal no. of page faults : %d\n", count);
}
int arrmin(int a[], int n)
{
    int i, min = a[0], idx = 0;
    for (i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            idx = i;
        }
    }
    return idx;
}
