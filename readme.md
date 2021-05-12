# Libft - @42Born2Code

### **Contents**
------------
> + [프로젝트 주제](#프로젝트-주제)

> + [Makefile](#Makefile)

> + [함수 목록](#함수-목록)

> + [후기](#후기)
### **프로젝트 주제**
---
자주 사용하는 기존의 C언어 함수들을 재정의 하고, 자주 사용하는 함수들을 정의하여 나만의 C 라이브러리를 만들자.
### **Makefile**
---
libft.a 파일 생성

    make

bonus(list functions) libft.a에 추가

    make bonus

*.o 파일 삭제

    make clean

libft.a && *.o 파일 삭제

    make fclean

recompile

    make re


### **함수 목록**
---
|Part.1|Part.1|Part.2|Bonus|
|:----:|:----:|:----:|:----:|
|ft_memset|ft_strrchr|ft_substr|ft_lstnew|
|ft_bzero|ft_strnstr|ft_strjoin|ft_lstadd_front|
|ft_memcpy|ft_strncmp|ft_strtrim|ft_lstsize|
|ft_memccpy|ft_atoi|ft_split|ft_lstlast|
|ft_memmove|ft_isalpha|ft_itoa|ft_lstadd_back|
|ft_memchr|ft_isdigit|ft_strmapi|ft_lstdelone|
|ft_memcmp|ft_isalnum|ft_putchar_fd|ft_lstclear|
|ft_strlen|ft_isascii|ft_putstr_fd|ft_lstiter|
|ft_strlcpy|ft_isprint|ft_putendl_fd|ft_lstmap|
|ft_strlcat|ft_toupper|ft_putnbr_fd|-|
|ft_strchr|ft_tolower|-|-|

### **후기**
----
Part1의 정의되어 있는 함수들을 재 정의하는 것은 기존 함수들을 테스트 해보며 할 수 있어서 수월하게 진행할 수 있엇지만,

Part2 와 Bonus 함수들을 정의하면서 어떤 예외처리를 해 주어야 하는지, malloc 에 실패했을시, 메모리 누수가 생기지 않게 free를 꼼꼼히 함수 차원에서 해주는 것에 신경을 많이 써서 구현을 하였다.

Piscine 과정에서 남은 기간이 얼마 되지않아 list를 자세히 공부하지 못하였는데, Linked-list에 대해서 조금더 자세히 알수 있엇다.

추후에 많이 쓰이는 함수들을 구현하면 library에 추가하여 용이하게 쓸수 있도록 할 예정이다.
