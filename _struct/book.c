#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);

#define MAXTITL 41  // max length of book title
#define MAXAUTL 31 // max length of author name

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};

int main (void) {
  struct book library;

  printf("Please enter the book title.\n");
  s_gets(library.title, MAXTITL);
  printf("Now enter the author.\n");
  s_gets(library.author, MAXAUTL);
  printf("Now enter the value.\n");
  scanf("%f", &library.value);
  printf("%s: by %s: $%.2f\n", library.title, library.author, library.value);
  printf("%s: \"%s\" ($%.2f\n)", library.author, library.title, library.value);
  printf("Done.\n");
  return 0;
}

char * s_gets(char * st, int n) {
  char * ret_val;
  char * find;

  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n');  // 查找换行符
    if (find)
      *find = '\0';           // 如果地址不是NULL, 在此处防止一个空字符
    else
      while (getchar() != '\n')
        continue;             // 处理输入行中剩余的字符
  }
  return ret_val;
}