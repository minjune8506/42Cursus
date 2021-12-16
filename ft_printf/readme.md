# ft_printf - @42Born2Code

### **Contents**
------------
> + [프로젝트 주제](#프로젝트-주제)

> + [Makefile](#Makefile)

> + [함수 구조](#함수구조)

> + [후기](#후기)
### **프로젝트 주제**
---
printf 함수를 재구현하여 libftprintf.a 라이브러리 생성
허용함수 : malloc, free, write, va_start, va_arg, va_copy, va_end
### **Makefile**
---
libftprintf.a 파일 생성

    make

bonus flag 추가 하여 libftprintf.a 생성

    make bonus

*.o 파일 삭제

    make clean

libftprintf.a && *.o 파일 삭제

    make fclean

recompile

    make re


### **함수 구조**
---
    %[flag][width][.precision][length]type

### **후기**
----
- 기존에 if ~ else를 이용하여 malloc없이 구현하려고 했지만, 예외 상황이 한두가지가 아니고 고려야 할점이 너무 많아서, 중간에 구조를 변경하였다.  
- width값에 따라서 출력해야하는 문자열의 길이가 결정된다는 사실을 발견했고, width에 따라 메모리 할당을 해주어 precision을 적용시키는 방향으로 다시 구성하였다.
- 하지만, 동적으로 메모리할당을 했으니 해제를 어떤 경우에서도 하여 leak이 발생하지 않게 해야하는데, 그 부분이 조금 까다로웠다.
