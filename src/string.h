#ifndef STRING_H
#define STRING_H

#define str_upper(S) str_case_convert(S, CC_UPPER)
#define str_lower(S) str_case_convert(S, CC_LOWER)

typedef enum
{
    CC_UPPER,
    CC_LOWER
} case_conversion;

typedef struct
{
    unsigned long len;
    char* str;
} string_t;

// Initialisation/Destruction
string_t* string_new();
string_t* string_new_text(const char* str);
void      string_destroy(string_t* strn);

// String utilities
int       string_match(string_t* str1, string_t* str2);
string_t* string_append_string(string_t* str1, string_t* str2);
string_t* string_append_raw(string_t* str1, char* str2);
string_t* string_prepend_string(string_t* str1, string_t* str2);
string_t* string_prepend_raw(string_t* str1, char* str2);
string_t* string_case_convert(string_t* str, case_conversion cc);
string_t* string_clear(string_t* str);
string_t* string_fill(string_t* str, char c);
void	  string_swap(string_t* str1, string_t* str2);
void	  string_copy(string_t* src, string_t* dest);

// Raw string utilities
unsigned long string_length_raw(const char* str);

#endif
