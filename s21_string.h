#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

int s21_strlen(char *str);
int s21_strcmp(char *str1, char *str2);
char *s21_strcpy(char *dst, char *src);
char *s21_strcat(char *s1, char *s2);
char *s21_strchr(char *s, int c);
char *s21_strstr(char *str, char *sub_str);
char *s21_strtok(char *str, const char *separator);

#endif  // SRC_S21_STRING_H_
