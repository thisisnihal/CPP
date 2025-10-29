#include <stdio.h>
#include <string.h>

int arrMinIdx(int[], int);

int main()
{

    int len;
    printf("Enter length of ref string: ");
    scanf("%d", &len);
    int rs[len];
    printf("Enter ref string: ");
    for (int i = 0; i < len; i++)
        scanf("%d", &rs[i]);

    int nf;
    printf("Enter frame size: ");
    scanf("%d", &nf);
    int frame[nf];
    memset(frame, -1, nf * sizeof(int));

    int access[nf], freq = 0, miss = 0;

    for (int i = 0; i < len; i++)
    {
        printf("\n%4d\t", rs[i]);
        int hit = 0;
        for (int j = 0; j < nf; j++)
        {
            if (rs[i] == frame[j])
            {
                hit = 1;
                access[j] = ++freq;
                break;
            }
        }
        if (hit == 0)
        {
            int idx = -1;
            for (int j = 0; j < nf; j++)
            {
                if (frame[j] == -1)
                {
                    idx = j;
                    break;
                }
            }
            if (idx != -1)
            {
                frame[idx] = rs[i];
                access[idx] = ++freq;
                miss++;
            }
            else
            {
                idx = arrMinIdx(access, nf);
                frame[idx] = rs[i];
                access[idx] = ++freq;
                miss++;
            }
        }
        for (int j = 0; j < nf; j++)
        {
            printf("%4d", frame[j]);
        }
    }

    printf("\nTotal no. of page faults : %d\n", miss);
    return 0;
}

int arrMinIdx(int a[], int n)
{
    int mn = a[0], idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (mn > a[i])
        {
            mn = a[i];
            idx = i;
        }
    }
    return idx;
}