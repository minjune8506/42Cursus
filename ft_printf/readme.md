# ft_printf - @42Born2Code

### **Contents**
------------
> + [프로젝트 주제](#프로젝트-주제)

> + [Makefile](#Makefile)

> + [함수 구조](#함수구조)

> + [후기](#후기)
### **프로젝트 주제**
---
printf 함수를 재구현하여 만들어라.  
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
기존에 if ~ else를 이용하여 memory할당 없이 구현하려고 했지만, 예외 상황이 한두가지가 아니고 고려야 할점이 너무 많아서, 중간에 구조를 변경하였다.  
width값에 따라서 출력해야하는 문자열의 길이가 결정된다는 사실을 알았고, 메모리 할당을 해주어 precision을 적용시키는 방향으로 다시 구성했는데, 그 방법으로 조금 더 편리하게 구현한 것 같다. 하지만, memory할당을 했으니 해제를 어떤 경우에서도 해주게 하여야하는데, 그 부분이 조금 까다로웠다.
두명에서 1주일 동안 열심히 달리니 끝낼수 있엇는데, 그 부분에서 혼자 와 둘의  차이, 집단지성의 힘...을 느낄수 있엇다.