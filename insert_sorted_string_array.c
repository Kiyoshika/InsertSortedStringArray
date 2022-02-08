#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_memory(char** strarr, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        free(strarr[i]);
    free(strarr);
}

void insert(char*** strarr, size_t* n, const char* text)
{
    char** space = realloc(*strarr, sizeof(char*) * ((*n) + 1));
    if (space != NULL)
    {
        *strarr = space;
        (*strarr)[*n] = NULL;
    }
    else
    {
        printf("Failed trying to reallocate space for strings!\n");
        free_memory(*strarr, *n);
        exit(-1);
    }
        
    size_t i;
    for (i = (*n) - 1; (i >= 0 && strcmp((*strarr)[i], text) > 0); i--)
    {
        free((*strarr)[i + 1]);
        (*strarr)[i + 1] = strdup((*strarr)[i]);
    }
    free((*strarr)[i + 1]);
    (*strarr)[i + 1] = strdup(text);
        
    (*n) += 1;
}

int cmp(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    
    size_t n = 5;
    
    char** strarr = malloc(sizeof(char*) * n);
    strarr[0] = strdup("john");
    strarr[1] = strdup("zach");
    strarr[2] = strdup("katherine");
    strarr[3] = strdup("jennifer");
    strarr[4] = strdup("ashton");
    
    qsort(strarr, n, sizeof(*strarr), cmp);
    
    insert(&strarr, &n, "jim");
    insert(&strarr, &n, "bill");
    
    for (size_t i = 0; i < n; ++i)
        printf("%s\n", strarr[i]);

    free_memory(strarr, n);

    return 0;
}
