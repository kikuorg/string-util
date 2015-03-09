#include <stdio.h>
#include "string.h"

int main()
{
    string_t* str1 = string_new_text("TesTinG");
    string_t* str2 = string_new_text("fork");
    str_prepend_string(str1, str2);
    printf("%s\n", str1->str);
    string_destroy(str1);
    string_destroy(str2);
    
    return 0;
}
