#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_VALUE_STR 32

/*
This will declare the the stuct.

value_str: The value that the command line take in as the type of string
value is: The value that the command line take in as the type of unsigned int
bit_width: The value of bit width
range_start: Range start index
range_end: Range end index
*/
struct nt_info 
{
    char value_str[MAX_VALUE_STR];
    unsigned int value;
    int bit_width;
    int range_start;
    int range_end;
};

/*
This will initialize the struct.
*/
void nt_info_init(struct nt_info *nt_data)
{
    nt_data->value_str[0] = '\0';
    nt_data->value = 0;
    nt_data->bit_width = 32;
    nt_data->range_start = 0;
    nt_data->range_end = 31;
    return;
}

/*
This function will convert value from string to unsigned int (positive version)

Input: The value in the type of string
Return: The value in the type of unsigned int
*/
unsigned int str_to_positive(char *s)
{
    int d[32];
    int i;
    int len;
    unsigned int us_int = 0;
    int factor = 10;

    len = strlen(s);

    for (i = 0; i < len; i++) {
        d[i] = (int) (s[i] - '0');
    }

    for (i = 0; i < len; i++) {
        if (i >= 9) {
            if (i > 9) 
            {
                printf("ERROR: %s cannot fit into 32 bits.\n", s);
                exit(0);
            } else if (i == 9 && us_int > 429496729) {
                printf("ERROR: %s cannot fit into 32 bits.\n", s);
                exit(0);
            } else if (i == 9 && us_int == 429496729 && d[i] >= 6) {
                printf("ERROR: %s cannot fit into 32 bits.\n", s);
                exit(0);
            }
        }
        us_int = us_int * factor;
        us_int = us_int + d[i];
    }      
    return us_int;
}

/*
This function will convert value from string to unsigned int (positive version)

Input: The value in the type of string
Return: The value in the type of unsigned int
*/
unsigned int str_to_negative(char *s)
{
    s++;
    int d[32];
    int i;
    int len;
    unsigned int us_int = 0;
    int factor = 10;

    len = strlen(s);

    for (i = 0; i < len; i++) 
    {
        d[i] = (int) (s[i] - '0');
    }

    for (i = 0; i < len; i++) 
    {
        if (i >= 9) {
            if (i > 9) 
            {
                printf("ERROR: %s cannot fit into 32 bits.\n", s);
                exit(0);
            } else if (i == 9 && us_int > 214748364) {
                printf("ERROR: %s cannot fit into 32 bits.\n", s);
                exit(0);
            } else if (i == 9 && us_int == 214748364 && d[i] > 8) {
                printf("ERROR: %s cannot fit into 32 bits.\n", s);
                exit(0);
            }
        }
        us_int = us_int * factor;
        us_int = us_int + d[i];
    }      
    return us_int * -1;
}

/*
This function will call the previous two functions

Input: The value in the type of string
Return: The value in the type of unsigned int
*/
unsigned int str_to_us_int(char *s)
{
    if(s[0] == '-')
    {
        return str_to_negative(s);
    }else{
        return str_to_positive(s);
    }
}

/*
This function will convert value from unsigned interger string to binary

Input: The value in the type of string
Return: The value in the type of unsigned int (binary)
*/
unsigned int str_to_binary(char* str)
{
    unsigned int binary = 0;
    str += 2;
    while (*str != 0)
    {
        binary *= 2;
        binary += *str - '0';
        str++;
    }
    return binary;
}

/*
This function will convert value from unsigned interger string to hexadecimal

Input: The value in the type of string
Return: The value in the type of unsigned int (hexadecimal)
*/
unsigned int str_to_hex(char* str)
{
    unsigned int hex = 0;
    str += 2;
    while (*str != 0){
        hex *= 16;
        if(*str >= 'A' && *str <= 'F')
        {
            hex += *str - 55;
        } else {
            hex += *str - '0';
        }
        str++;
    }
    return hex;
}

/*
This function will convert value from unsigned interger string to binary string

Input: The value in the type of unsigned int, the str that store the result, the length of this str
*/
void int_to_binary_str(unsigned int n, char* str, int len)
{   
    int  r = 0, i;
    for(i = 0; i < len; i++)
    {
        str[i] = '0';
    } 
    i = len - 1;
    while (i >= 0)
    {   
        r = n & 0b1;
        str[i] = r + '0';
        n >>= 1;
        i--;
    }
    return;
}


/*
This function will convert value from unsigned interger string to hexadecimal string

Input: The value in the type of unsigned int, the str that store the result, the length of this str
*/
void int_to_hex_str(unsigned int n, char* str, int len)
{   
    for(int i = 0; i < len; i++)
    {
        str[i] = '0';
    }
    int digit;
    while(len > 0)
    {   
        digit = n % 16;
        if(digit >= 10 && digit <= 15)
        {
            str[len - 1] = n % 16 + 55;
        }else{
            str[len - 1] = n % 16 + '0';
        }
        
        n = n / 16;
        len--;
    }
    return;   
}

/*
This function will convert value from unsigned interger to unsigned int string

Input: The value in the type of unsigned int, the str that store the result, the bit width
Return: The result string
*/

char* us_int_to_str(unsigned int n, char* str, int width)
{   
    n <<= 32 - width;
    n >>= 32 - width;
    if(n == 0)
    {
        return "0";
    }
    int i = 0;
    while (n !=0 )
    {
        str[i] = n % 10 + '0';
        n = n / 10;
        i++;
    }
    str[i] = '\0'; 
    char temp;
    for (int j = 0; j < i; j++)
    {
        temp = str[j];
        str[j] = str[i - 1];
        str[i - 1] = temp;
        i--;
    }

    return str;
}

/*
This function will convert value from unsigned interger to int string

Input: The value in the type of unsigned int, the str that store the result, the bit width
Return: The result string
*/
char* us_int_to_int_str(int n, char* str, int width)
{   
    int i = 0, neg = 0;
    n <<= 32 - width;
    n >>= 32 - width;

    if(n == 0)
    {
        return "0";
    }
    
    if(n < 0)
    {
        neg = 1;
    }
    while (n != 0)
    {
        if (neg == 1) 
        {
            str[i] = '0' - n % 10;
        } else {
            str[i] = n % 10 + '0';
        }
        
        n = n / 10;
        i++;
    }
    if(neg == 1)
    {
        str[i] = '-';
        i++;
    }
    str[i] = '\0'; 
    char temp;
    for (int j = 0; j < i ; j++)
    {
        temp = str[j];
        str[j] = str[i - 1];
        str[i - 1] = temp;
        i--;
    }
    return str;
}

/*
This function will check if the inputs has a specific flag

Input: flag want to check, commadn line 
Return: 0 for false
        1 for true
*/
int has_flag(char flag, char *cmd)
{
    if(*cmd == '-')
    {
        cmd++;
        if(*cmd == flag)
        {
            return 1;
        }
    }
    return 0;
}

/*
This function will split a string

Input: Original line, the value of start of range, the value of end of range

*/
void split(char* line, char* start_str, char* end_str)
{
    char *str = start_str;
    while (*line != '\0') 
    {
        *str = *line;
        str++;
        line++;
        if (*line == ',') 
        {
            *str = '\0';
            str = end_str;
            line++;
        }
    }
    *str = '\0';
}

/*
This function will check if a line is start with a specific string

Input: Sub string, the string you want to check
Return: 0 for false
        1 for true
*/
int is_starts_with(const char *substr, const char *str)
{
    return strncmp(substr, str, strlen(substr)) == 0;
}

/*
This function will parse the command line
*/
void parse_command_line(int argc, char **argv, struct nt_info *nt_data)
{   
    if(argc == 1)
    {
        printf("ERROR: Invalid input, no number detected.\n");
        exit(0);
    }
    for(int i = 1; i < argc; i++)
    {
        if(has_flag('b',argv[i]))
        {   
            if (str_to_us_int(argv[i + 1]) % 4 == 0 && str_to_us_int(argv[i + 1]) < 32)
            {
                nt_data->bit_width = str_to_us_int(argv[i + 1]);
                i++;
            }else{
                printf("ERROR: Invalid input for flag -b!\n");
                exit(0);
            }
            
        } else if(has_flag('r', argv[i])){
            char start_str[MAX_VALUE_STR + 1];
            char end_str[MAX_VALUE_STR + 1];
            split(argv[i + 1], start_str, end_str);
            nt_data->range_start = str_to_us_int(start_str);
            nt_data->range_end = str_to_us_int(end_str);
            i++;
            if(nt_data->range_start > nt_data->range_end)
            {
                printf("ERROR: Invalid input for flag -r!\n");
                exit(0);
            }
        }else{
            strncpy(nt_data->value_str, argv[i], MAX_VALUE_STR);
        }

    }
    return;
}

/*
This function will normalize the nt data
*/
void normalize_input_value(struct nt_info *nt_data)
{   
    if(is_starts_with("0b",nt_data->value_str) == 1 || is_starts_with("0B",nt_data->value_str) == 1)
    {
        nt_data->value = str_to_binary(nt_data->value_str);
    }else if(is_starts_with("0x",nt_data->value_str) == 1 ||is_starts_with("0X",nt_data->value_str) == 1){
        nt_data->value = str_to_hex(nt_data->value_str);
    }else{
        nt_data->value = str_to_us_int(nt_data->value_str);
    }
    
    if(nt_data->range_start != 0 || nt_data->range_end !=31)
    {
        nt_data->value <<= 31 - nt_data->range_end;
        nt_data->value >>= 31 - nt_data->range_end + nt_data->range_start;
    }

    return;
}
/*
This function will give the out put
*/
void output_conversions(struct nt_info *nt_data)
{
    int count = 0;
    int width = nt_data->bit_width;
    char binary[width + 1];
    binary[width] = '\0';


    int_to_binary_str(nt_data->value, binary,width);
    for(int i = 0; i < width; i++)
    {
       printf("%c",binary[i]);
       count++;
       if(count % 4 == 0)
       {
        printf("%c",' ');
        count = 0;
    }
}
printf("(base 2)\n");
printf("0b%s (base 2)\n",binary);
char hex[(width / 4) + 1];
hex[width / 4] = '\0';
int_to_hex_str(nt_data->value,hex, (width / 4));
printf("0x%s (base 16)\n",hex);
char us_int_str[11];
printf("%s (base 10 unsigned)\n",us_int_to_str(nt_data->value, us_int_str, width));
char int_str[12];
printf("%s (base 10 signed)\n",us_int_to_int_str((int)nt_data->value, int_str, width));
return;
}

int main(int argc, char **argv)
{
    struct nt_info nt_data;
    nt_info_init(&nt_data);
    parse_command_line(argc, argv, &nt_data);
    normalize_input_value(&nt_data);
    output_conversions(&nt_data);

    return 0;
}

