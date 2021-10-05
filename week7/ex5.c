# include <stdio.h>

int main (void) {
    char ** s = malloc(sizeof(char*));
    /// s hadn't allocated memory, so now I allocated memory for s
    char foo[] = " Hello World " ;
    *s = foo;
    printf ("s is %s \n" , *s); /// s is a pointer to a string(a pointer points to a string)
    s[0] = foo;
    printf ( "s[0] is %s\n ", s[0]);
    return (0);
}

