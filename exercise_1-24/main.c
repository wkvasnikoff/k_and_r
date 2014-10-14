#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char c, prev;
    enum state {NORMAL, STRING, COMMENT, CHAR};
    int state = NORMAL;

    int stack[30];
    int pos = 0;

    if(argc != 2) {
        printf("./run file\n");
        exit(0);
    }

    FILE* file = fopen(argv[1], "r");

    while((c = fgetc(file)) != EOF) {
        if(state == NORMAL) {
            if(prev == '/' && c == '*') {
                state = COMMENT;
            } else if(c == '"') {
                state = STRING;
                printf("string\n");
            } else if(c == '\'') {
                state = CHAR;
            }

            prev = c;
            continue;
        } else if(state == STRING) {
            if(prev == '\\' && c == '\\') {
                prev = 0;
            } else if(c == '"') {
                if(prev != '\\') {
                    state = NORMAL;
                }
            }
        } else if(state == COMMENT) {
            if(prev == '*' && c == '/') {
                prev = 0;
                state = NORMAL;
            }
        } else if(state == CHAR) {
            if(prev == '\\' && c == '\\') {
                prev = 0;
            } else if(c == '\'' && prev != '\\') {
                state = NORMAL;
            }
        }

        prev = c;
    }

    fclose(file);

    if(state == STRING) {
        printf("Unterminated String\n");
    } else if(state == COMMENT) {
        printf("Unterminated String\n");
    }

    exit(0);
}
