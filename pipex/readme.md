# Pipex - @42Born2Codd

### **프로젝트 주제**
---
#### MANDATORY
> < infile cmd1 | cmd2 > outfile 의 명령어를 처리하는 함수를 만들어라.

> ./pipex infile cmd1 cmd2 outfile의 형식으로 인자를 받으며 파이프와 리다이렉션을 이용하여 구현한다.

#### BONUS
> ./pipex here_doc LIMITER cmd1 cmd2 out 의 형식으로 실행시켰을시 Stdin으로 내용을 받아 처리하여라.   
cmd1 << LIMITER | cmd2 >> out의 형식으로 처리된다.

> 다중 파이프를 구현하라   
i.e. < infile cmd1 | cmd2 | cmd 3 | ... | cmdn > outfile

### Compile
---
Mandatory  

	make

Bonus

	make bonus
 
### **후기**
----
fork() pipe() 등 처음 보는 함수들을 이용하여 프로세스를 처리하는 과정을 배웠고, 그 부분에서 부모, 자식 프로세스, 파이프 fd등에 대한 생소한 개념으로 이해하는데 어려움이 있었다.   
부모 자식 프로세스, 리다이렉션, 어떻게 파이프를 이용하여 부모와 자식프로세스가 정보를 교환하는지에 대한 개념을 익혀 추후 minishell 과제에서 유용하게 사용할 수 있을 것 같다.   

---
### **개선해야 할 점**
1. envp를 사용하여 환경변수를 받아와 처리하지 않고, 하드코딩으로 경로를 하나씩 찾아보도록 하였는데, 개선이 필요하다.
2. outfile을 먼저 만들고 자식프로세스를 wait해야 ls -l 같은 명령어를 실행하였을 때 결과값이 달라지지 않는다.
3. 명령어 사이에 awk, find 와 같은 복잡한 인자가 들어오는 명령어, single quote 나 regular expression에 대한 처리를 따로 안하였는데, 그 부분도 신경써서 추후에 minishell과제를 하면 좋을 것 같다.
4. 부모 자식 프로세스 모두 마지막에 execve명령어를 사용하여서 종료되는데, execve 명령어는 자식 프로세스에서만 실행되고 부모 프로세스는 남아있는게 올바른 처리 방법이라는 feedback을 받았는데, 그 부분에 공감하여 추후에 추가해 보면 좋을것 같다.