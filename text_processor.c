#include "s21_string.h"
#include <stdio.h>

int input(char *str);
void output_in_lines(char *str, int n);
void printn(char *str, int len);

int main(int argc, char *argv[]) {
    if (argc != 2 || argv[1][0] != '-' || argv[1][1] != 'w') {
        printf("n/a");
        return 1;
    }

    int n;
    char sp;
    if (scanf("%d%c", &n, &sp) != 2 || n <= 0 || sp != '\n') {
        printf("n/a");
        return 1;
    }

    char str[100];
    if (input(str)) {
        printf("n/a");
        return -1;
    }

    output_in_lines(str, n);
    return 0;
}

int input(char *str) {
    int i = 0, _error = 0;
    scanf("%c", &str[i]);

    while (str[i] != '\n' && i < 100) {
        i++;
        scanf("%c", &str[i]);
    }

    if (str[i] != '\n') _error = 1;

    str[i] = '\0';
    return _error;
}

void output_in_lines(char *str, int n) {
    char *word = s21_strtok(str, " ");
    int lenght = -1, is_first = 1;
    int line_len = n;

    while (word) {
        lenght = s21_strlen(word);

        if ((lenght <= line_len && is_first) || (lenght + 1 <= line_len && !is_first)) {
            if (!is_first) {
                printf(" ");
                line_len -= (lenght + 1);
            } else {
                line_len -= lenght;
            }
            printf("%s", word);
            word = s21_strtok(NULL, " ");
            is_first = 0;
        }

        if (lenght > line_len && lenght < n) {
            is_first = 1;
            line_len = n;
        }

        if (lenght > line_len && lenght > n) {
            if ((line_len >= 3 && !is_first)
                || (line_len >= 2 && is_first)) {
                if (!is_first) {
                    printf(" ");
                    line_len--;
                }

                printn(word, line_len - 1);
                printf("-");
                word += (line_len - 1);
            }

            is_first = 1;
            line_len = n;
        }

        if (line_len == 0) {
            word = s21_strtok(NULL, " ");
            is_first = 1;
            line_len = n;
        }

        if (word != NULL && line_len == n) printf("\n");
    }
}

void printn(char *str, int len) {
    for (int i = 0; i < len && str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
}
