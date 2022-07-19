#include <stddef.h>
#include <stdio.h>

int s21_strlen(char *str) {
    int n = 0;
    if (!str) n = -1;

    while (n != -1 && str[n] != '\0') {
        n++;
    }

    return n;
}

int s21_strcmp(char *str1, char *str2) {
    int _res;
    if (str1 != NULL && str2 != NULL) {
        int n1 = 0, n2 = 0, i = -1;
        do {
            i++;
            n1 = (n1 + str1[i]);
            n2 = (n2 + str2[i]);
        } while (str1[i] != '\0' && str2[i] != '\0');

        _res = n1 - n2;

        if (_res == 0) {
            for (int k = 0; !_res && k < i; k++) {
                if (str1[k] < str2[k]) _res = -1;
                if (str1[k] > str2[k]) _res = 1;
            }
        }

        if (_res == -2) _res = -1;
    } else {
        _res = -2;
    }

    return _res;
}

char *s21_strcpy(char *dst, char *src) {
    char *res = NULL;

    if (dst != NULL && src != NULL) {
        int i = -1;
        do {
            i++;
            dst[i] = src[i];
        } while (src[i] != '\0');

        res = dst;
    }

    return res;
}

char *s21_strcat(char *s1, char *s2) {
    char *res = NULL;

    if (s1 != NULL && s2 != NULL) {
        int i;
        for (i = 0; s1[i] != '\0'; i++) {}

        int k;
        for (k = 0; s2[k] != '\0'; k++) {
            s1[i + k] = s2[k];
        }
        s1[i + k] = '\0';

        res = s1;
    }

    return res;
}

char *s21_strchr(char *s, int c) {
    char *res = NULL;

    if (s != NULL) {
        int i;
        for (i = 0; s[i] != '\0' && s[i] != c; i++) {}

        if (s[i] != '\0') res = s + i;
        else if (s[i] == '\0' && c == '\0') res = s + i;
    }

    return res;
}

char *s21_strstr(char *str, char *sub_str) {
    char *res = NULL;

    if (str != NULL && sub_str != NULL) {
        if (sub_str[0] == '\0') res = str;

        int i;
        for (i = 0; !res && str[i] != '\0'; i++) {
            if (str[i] == sub_str[0]) {
                int check = 1;
                for (int k = 0; check && sub_str[k] != '\0'; k++) {
                    if (str[i + k] == '\0') check = 0;
                    else if (str[i + k] != sub_str[k]) check = 0;
                }
                if (check) {
                    res = str + i;
                }
            }
        }
    }

    return res;
}

int check_char(char c, const char *mc) {
    int _res = 0;
    for (int i = 0; !_res && mc[i] != '\0'; i++) {
        if (c == mc[i]) _res = 1;
    }

    return _res;
}

char *s21_strnchr(char *s, const char *c) {
    char *res = NULL;

    if (s != NULL) {
        int i;
        for (i = 0; s[i] != '\0' && !check_char(s[i], c); i++) {}

        if (s[i] != '\0') res = s + i;
        else if (s[i] == '\0' && check_char('\0', c)) res = s + i;
    }

    return res;
}

char *s21_strtok(char *str, const char *separator) {
    static char *point = NULL;

    if (str) point = str;
    else if (!point) return NULL;
    if (separator == NULL) return NULL;

    int i;
    for (i = 0; check_char(point[i], separator) && point[i] != '\0'; i++) {}
    str = point + i;

    point = s21_strnchr(str, separator);
    if (point == NULL) return str;
    if (point == str) return NULL;
    if (*point == '\0') {
        point = NULL;
    } else {
        *point = '\0';
        point++;
    }

    return str;
}
