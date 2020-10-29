#include<stdio.h>
#include<string.h>

#define MAX_VALUE_STR_LEN 32

struct nt_info {
    char value_str[MAX_VALUE_STR_LEN];
    unsigned int value;
    int bit_width;
    int range_start;
    int range_end;
};

void nt_info_init(struct nt_info *nt_data)
{
    nt_data->value_str[0] = '\0';
    nt_data->value = 0;
    nt_data->bit_width = 32;
    nt_data->range_start = 0;
    nt_data->range_end = 31;
    return;
}

void nt_info_print(struct nt_info *nt_data)
{
    printf("nt_data->value_str   = %s\n", nt_data->value_str);
    printf("nt_data->value       = %u\n", nt_data->value);
    printf("nt_data->bit_width   = %d\n", nt_data->bit_width);
    printf("nt_data->range_start = %d\n", nt_data->range_start);
    printf("nt_data->range_end = %d\n", nt_data->range_end);
    return;
}

int str_to_int(char *s)
{
    int d[32];
    int i;
    int len;
    int sum = 0;
    int factor = 10;

    len = strlen(s);

    for (i = 0; i < len; i++) {
        d[i] = (int) (s[i] - '0');
    }

    for (i = 0; i < len; i++) {
        sum = sum * factor;
        sum = sum + d[i];
    }
        
    return sum;
}

void parse_command_line(int argc, char **argv, struct nt_info *nt_data)
{
    strncpy(nt_data->value_str, argv[argc -1], MAX_VALUE_STR_LEN);
    return;
}

void normalize_input_value(struct nt_info *nt_data)
{
    nt_data->value = str_to_int(nt_data->value_str);
    return;
}

void print_conversions(struct nt_info *nt_data)
{
    printf("%d (base 10 signed)\n", nt_data->value);
    return;
}

int main(int argc, char **argv)
{
    struct nt_info nt_data;

    nt_info_init(&nt_data);
    nt_info_print(&nt_data);
    
    parse_command_line(argc, argv, &nt_data);

    nt_info_print(&nt_data);

    normalize_input_value(&nt_data);

    print_conversions(&nt_data);
    
    return 0;
}
