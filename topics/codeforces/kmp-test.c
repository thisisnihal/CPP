#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int kmp(char* txt, char* pat);
void compute_lps(int* lps, char* pat);

int main()
{

    char* txt = "adsgwadsxdsgwadsgz";
    char* pat = "dsgwadsgz";

    int position = kmp(txt, pat);
    if (position == -1) {
        printf("Pattern Not Found!\n");
    } else {
        printf("Pattern Found at %d index\n", position);
    }

    return 0;
}

int kmp(char *txt, char *pat)
{
    int n = strlen(txt);
    int m = strlen(pat);
  
    int *lps = (int *)malloc(m * sizeof(int));
    compute_lps(lps, pat);
    
    int i = 0, j = 0;
    while (j < m && i < n) {
        
        if (pat[j] == txt[i]) {
            j++; i++;
        } else {
            if (j == 0) i++;
            else j = lps[j-1];
        }
    }
    if (j == m) return i-j;
    else return -1;
}

void compute_lps(int* lps, char* pat) {
    int m = strlen(pat);
    lps[0] = 0;
    int j = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[j]) {
            lps[i] = j + 1;
            i++; j++;
        } else {
            if (j == 0) lps[i] = 0, i++;
            else j = lps[j-1];
        }
    }
}






/*

    for (int i = 0; i < strlen(pat); i++) printf("%c ", pat[i]);
    printf("\n");
    for (int i = 0; i < strlen(pat); i++) printf("%d ", lps[i]);
    printf("\n");




    ABABABCABABABCABABABC
    ABABAC

*/