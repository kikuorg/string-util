#include <stdlib.h>
#include <stdio.h>
#include "../include/string.h"

string_t* string_new()
{
    string_t* strn = malloc(sizeof(string_t));
    if (strn == NULL)
	return NULL;
    strn->str = malloc(1);
    if (strn == NULL) {
        free(strn);
        return NULL;
    }
    strn->str[0] = '\0';
    strn->len = 0;

    return strn;
}

string_t* string_new_text(const char* str)
{
    /* Allocate space for the string */
    string_t* strn = malloc(sizeof(string_t));
    if (strn == NULL)
        return NULL;
    unsigned long len = string_length_raw(str);
    strn->str = malloc(len);
    if (strn->str == NULL) {
        free(strn);
        return NULL;
    }

    /* Copy str into strn */
    for (unsigned long l = 0; l < len; l++)
	strn->str[l] = str[l];

    strn->len = len;

    return strn;
}

void string_destroy(string_t* strn)
{
    if (strn != NULL) {
        free(strn->str);
        free(strn);
    }
    strn = NULL;
}

int string_match(string_t* str1, string_t* str2)
{
    if (str1->len != str2->len || str1 == NULL || str2 == NULL) return 0;

    for (unsigned long l = 0; l < str1->len; l++)
	if (str1->str[l] != str2->str[l]) return 0;

    return 1;
}

string_t* string_append_string(string_t* str1, string_t* str2)
{
    /* Resize str1 to accomodate for both str1 and str2 */
    str1->str = realloc(str1->str, str1->len + str2->len);
    
    for (unsigned long l = str1->len; l < str1->len + str2->len; l++)
	str1->str[l] = str2->str[l - str1->len];

    /* Update the size */
    str1->len += str2->len;
    
    return str1;
}

string_t* string_append_raw(string_t* str1, char* str2)
{
    string_t* temp = string_new_text(str2);
    string_append_string(str1, temp);
    string_destroy(temp);

    return str1;
}

string_t* string_prepend_string(string_t* str1, string_t* str2)
{
    string_t* result = string_new();
    string_copy(str2, result);
    string_append_string(result, str1);
    string_swap(str1, result);

    return str1;
}

string_t* string_prepend_raw(string_t* str1, char* str2)
{
    string_t* temp = string_new_text(str2);
    string_prepend_string(str1, temp);
    string_destroy(temp);

    return str1;
}

string_t* string_case_convert(string_t* str, case_conversion cc)
{
    switch (cc)
    {
	case CC_UPPER:
	    for (unsigned long l = 0; l < str->len; l++)
		if (str->str[l] >= 'a' && str->str[l] <= 'z') str->str[l] -= 32;

	    break;

	case CC_LOWER:
	    for (unsigned long l = 0; l < str->len; l++)
		if (str->str[l] >= 'A' && str->str[l] <= 'Z') str->str[l] += 32;

	    break;
    }

    return str;
}

string_t* string_clear(string_t* str)
{
    str->str = realloc(str->str, 1);
    str->str[0] = '\0';
    str->len = 0;

    return str;
}

string_t* string_fill(string_t* str, char c)
{
    for (unsigned long l = 0; l < str->len; l++)
	str->str[l] = c;

    return str;
}

void string_swap(string_t* str1, string_t* str2)
{
    string_t* temp = string_new();
    string_copy(str1, temp);
    string_copy(str2, str1);
    string_copy(temp, str2);
    string_destroy(temp);
}

void string_copy(string_t* src, string_t* dest)
{
    dest->str = realloc(dest->str, src->len);
    dest->len = src->len;

    for (unsigned long l = 0; l < dest->len; l++)
	dest->str[l] = src->str[l];
}

size_t string_length(string_t* str)
{
    return strlen(str->str);
}

string_t* string_revert(string_t* str)
{
    unsigned long len = str->len;

    for (unsigned long l = 0; l < len/2; l++)
	str->str[l] = str->str[len-i-1];

    return str;
}
