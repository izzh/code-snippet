#include <stdio.h>
#include <string.h>

#define MAX_C_LINE_CHARACTER 128
#define MAX_C_FILE_CHARACTER 8192

int main(int argc, char const *argv[])
{
    char input_file[MAX_C_FILE_CHARACTER];
    char input_line[MAX_C_LINE_CHARACTER];
    int input_file_len = 0;
    while (fgets(input_line, MAX_C_LINE_CHARACTER, stdin) != NULL)
    {
        if (strncmp(input_line, ":wq", 3) == 0) {
            break;
        }
        int line_len = strlen(input_line);
        strncpy(input_file+input_file_len, input_line, line_len);
        input_file_len += line_len;
    }
    printf("len: %d\n", input_file_len);
    printf("%s\n", input_file);
    int i = 0;
    /*{++, }--*/
    int count = 0, flag = 0;
    /*ignore string:"" and comment:// || \/**\/*/
    while (i<input_file_len) {
        // case 1 ignore string:"{}"
        if (input_file[i] == '"') {
            i++;
            while (i<input_file_len && input_file[i++] != '"') {
                ;
            }
            continue;
        }
        // case 2, ignore // || /**/
        if (input_file[i] == '/') {
            i++;
            if (i<input_file_len && input_file[i] == '/') {
                i++;
                while (i<input_file_len && input_file[i++] != '\n') {
                    ;
                }
            } else if (i<input_file_len && input_file[i] == '*') {
                i++;
                while (i < input_file_len) {
                    if (input_file[i++] == '*') {
                        if (i < input_file_len && input_file[i] == '/') {
                            i++;
                            break;
                        }
                    }
                }
            } else {
                i--;
            }
            continue;
        }
        if (input_file[i] == '{') {
            count++;
            flag++;
        } else if (input_file[i] == '}') {
            flag--;
        }
        i++;
    }
    
    if (count > 0 && flag == 0) {
        printf("count:%d, flag:%d, Valid C programming file.\n", count, flag);
    } else {
        printf("count:%d, flag:%d, Invalid C programming file.\n", count, flag);
    }

    return 0;
}
