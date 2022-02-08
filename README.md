# InsertSortedStringArray
An example algorithm to insert strings in the correct position in an alphabetically-sorted string array.

# Example
Modified example from the code posted in the repo:
```c
int main()
{
    size_t n = 5;

    char** strarr = malloc(sizeof(char*) * n);
    strarr[0] = strdup("john");
    strarr[1] = strdup("zach");
    strarr[2] = strdup("katherine");
    strarr[3] = strdup("jennifer");
    strarr[4] = strdup("ashton");

    qsort(strarr, n, sizeof(*strarr), cmp);

    printf("Before Insertion:\n================\n");

    for (size_t i = 0; i < n; ++i)
        printf("%s\n", strarr[i]);

    insert(&strarr, &n, "jim");
    insert(&strarr, &n, "bill");

    printf("\n\nAfter Insertion:\n================\n");

    for (size_t i = 0; i < n; ++i)
        printf("%s\n", strarr[i]);

    free_memory(strarr, n);

    return 0;
}
```
Output:
```
Before Insertion:
================
ashton
jennifer
john
katherine
zach


After Insertion:
================
ashton
bill
jennifer
jim
john
katherine
zach
```
