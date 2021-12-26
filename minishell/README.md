# Minishell
 > Contributor : keokim, minjkim2
### **Contents**
------------
> [Subject](#-subject)

> [Functions](#-Functions)

> [Makefile](#-makefile)
 
> [Commit-Rule](#-commit-message-rule)

> [후기](#후기)
 ### **Subject**
 ---
 Bash와 유사한 나만의 Minishell을 만들어보자.   

 ### **Functions**
 ---
 - History
 - Search and launch the right executable (based on the PATH variable or by using relative or absolute path)
 - implement the builtin
   - `echo` with option -n
   - `cd` relative / absolute path
   - `pwd` with no options
   - `export` with no options
   - `unset` with no options
   - `env` with no options
   - `exit` with no options
- ’ inhibit all interpretation of a sequence of characters.
- " inhibit all interpretation of a sequence of characters except for $.
- Redirections (<, <<, >, >>)
- Pipes ( | ), Multi-Pipes
- Environment variables should expand to their values.
- $? exit status
- Ctrl-C, Ctrl-D, Ctrl-\ work like in bash

### **Makefile**
---
Readline 라이브러리 설치

	brew install readline

minishell 파일 생성 & 하위 라이브러리 make

    make

*.o 파일 삭제

    make clean

### **Commit Message Rule**
---
- `Type : 내용` 형식으로 작성할 것.
- Add : 파일 , 폴더 추가
- Feat : 새로운 기능 추가
- Remove : 필요 없는 코드, 기능 제거
- Refactor : 변수, 함수 이름 수정, 코드 최적화
- Docs : 문서 파일 수정
- Fix : Norm, bug 수정
- etc : 기타 업무

### **후기**
- 지금까지 혼자 Repository를 관리하며 프로젝트를 해왔는데, 이번에는 팀과제로 하게 되어서 어떻게 하면 같이 효율적으로 작업을 할 수 있을 지 고민을 많이 하였다.
- 깃헙 이슈, 풀 리퀘스트, 포크 등 많은 기능을 공부해보는 계기가 되었고, 우리가 선택한 방법은 pair 프로그래밍이었다. 진행속도는 느릴지 몰라도, 같이 코드를 만지며 토론을 하는 과정에서 배우는 점이 많았다.
- 풀리퀘스트, 이슈, 커밋 룰 등 협업을 할때 중요한 점들을 많이 배우는 과제였다.
- 프로세스, fd, 파이프, 리다이렉션, 빌트인함수들을 구현하면서 bash reference를 많이 참고했는데, 그 과정에서 bash에 대해 조금 더 깊은 이해를 할 수 있엇던 프로젝트였다. 
