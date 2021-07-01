# Pipex - @42Born2Code

## allowed functions
---
### **access**

	#include <unistd.h>

	int access(const char *pathname, int mode);
	성공시 0, 실패시 -1 반환
pathname : 체크하고자 할 디렉토리 또는 파일명   
mode : mask값
|mask값| 내용|
|:---:|:---:|
| R_OK | 파일 존재 여부, 읽기 권한 여부|
| W_OK | 파일 존재 여부, 쓰기 권한 여부|
| X_OK | 파일 존재 여부, 실행 권한 여부|
| F_OK | 파일 존재 여부|
* 오류에 대해서는 errno에 세팅된다.
---
### **unlink**
	#include <unistd.h>

	int unlink(const char *pathname);
	정상적으로 파일 또는 link 삭제 시 0 반환
	오류 발생시 -1 반환 (상세 내용 errno에 저장)

pathname : 파일을 삭제할 파일명 (절대 경로 or 상대 경로)   
파일을 삭제하는 systemcall 함수, hard link의 이름을 삭제하고 hard link가 참조하는 count를 1 감소시킨다. count가 0이 되면 disk space 를 free 하여 사실상 파일이 삭제된다.   
open으로 파일이 열려진 상태에서 unlink 호출 시, count가 0이 되어도 directory entry에서 파일 이름등의 정보는 삭제 되지만, disk space는 해제되지 않는다.   
OS는 hard link count가 0이고, file open count가 0일때 disk space를 해제.

---
### **fork**

	#include <unistd.h>

	pid_t fork(void);
	성공시 pid 반환
	- 부모 프로세스 : 자식프로세스의 pid 반환
	- 자식 프로세스 : 0 반환
	실패시 -1 반환

실행중인 프로세스의 복사본을 생성한다. fork함수를 호출한 프로세스를 복사 한 후, 두 프로세스 모두 fork함수의 호출 이후 문장을 실행하게 된다.   
완전히 동일한 프로세스 이므로, 메모리 영역까지 동일하게 복사하기 때문에, 이후 프로그램의 흐름은 fork함수의 반환값을 기준으로 나뉘도록 만들어야 한다.
[![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbtO6G2%2FbtqxtqAZJY8%2FyJ5VXkMbcGXG1np7pKtthK%2Fimg.png)](https://codingdog.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-fork-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4%EB%A5%BC-%EC%83%9D%EC%84%B1%ED%95%9C%EB%8B%A4)

자식 프로세스 생성시, 스택, 힙, 데이터 영역과 같은 메모리 공간은 공유하지 않는다.   
* 자식 프로세스 종료시 부모프로세스 실행시 필요한 함수가 wait, waitpid 함수이다.

---
### **wait**
	#include <sys/types.h>
	#include <sys/wait.h>

	pid_t wait(int *wstatus);
	wstatus는 종료상태, 필요 없을시 NULL
	성공시 프로세스의 pid를 반환한다.
	오류 발생시 -1 반환.

fork() 를 이용하여 자식 프로세스르르 생성했을때 주로 사용한다. wait() 를 쓰면 자식 프로세스가 종료할때까지 해당 영역에서 부모 프로세스가 sleep()모드로 기다리게 된다. 자식 프로세스가 고아 프로세스(pid 1)가 되는 걸 방지하기 위한 목적이다.   
만약 자식 프로세스가 종료되었다면 함수는 즉시 리턴되며, 자식이 사용한 모든 시스템 자원을 해제한다.

---
### **waitpid**
	#include <sys/types.h>
	#include <sys/wait.h>

	pid_t waitpid(pid_t pid, int *status, int options);
	pid : wait할 자식 프로세스의 유형
	status : return된 자식 프로세스의 상태 변경값을 저장하는 변수
	option : 0또는 상수의 조합으로 설정된다.
	성공시 -> pid, 오류시 -> -1, 그외의 경우 0 리턴
|pid|의미|
|:---:|:---:|
|-1 > pid|그룹 id가 절대값과 같은 자식 프로세스를 기다린다.|
|-1 == pid|아무 자식 프로세스 id라도 기다린다.|
|0 == pid|자신과 같은  프로세스 그룹 id를 가진 자식 프로세스를 기다린다.|
|0 < pid |넘겨진 pid의 자식 프로세스만 기다린다.|

---
### **pipe**
	#include <unistd.h>
	int pipe(int fildes[2]);

pipe() 함수는 데이터 스트림 두개를 연다.   
fd 3 -> fd[0] : 파이프의 읽는 쪽   
fd 4 -> fd[1] : 파이프의 쓰는 쪽   
자식 프로세스가 부모 프로세스에 데이터를 보내야 하므로, 자식 프로세스의 표준 출력과 부모 프로세스의 표준 입력에 연결된 파이프가 필요하다. 파이프는 pipe() 함수로 생성한다.

자식 프로세스에서는 파이프의 읽는 쪽인 fd[0]을 닫고, 표준 출력을 fd[1] 디스크립터가 가리키는 스트림을 가리키게 변경한다.

	// 자식 프로세스는 파이프로부터 읽지 않기 때문에 읽는 쪽을 닫는다.
	// 자식 프로세스는 표준 출력을 파이프의 쓰는 쪽으로 연결한다.
	close(fd[0]);
	dup2(fd[1], 1); // Stdout : 1

자식 프로세스가 표준 출력으로 보내는 모든 데이터가 파이프에 쓰여진다.

	//부모 프로세스는 표준 입력을 파이프의 읽는 쪽으로 리다이렉션한다.
	dup2(fd[0], 0); // Stdin : 0
	close(fd[1]);

이제 자식 프로세스가 스는 모든 데이터를 부모 프로세스의 표준 입력을 통해 읽을 수 있다.

---
### **dup, dup2**

	#include <unistd.h>

	int dup(int fd);
	int dup2(int fd, int fd2);

dup는 fd로 전달받은 파일 디스크립터를 복제하여 반환한다. fd는 가장 낮은 값으로 반환한다. 성공시 새로운 fd, 오류시 -1 리턴.

dup2는 fd의 값을 fd2로 지정한다. 만일 fd2가 이미 열려있다면 fd2를 닫은 후 복제가 된다. 성공시 새로운 fd, 오류시 -1 리턴.

---
### **execve**

	#include <unistd.h>

	int execve(const char *filename, char *const argv[], char *const envp[]);
	리턴 값이 있을시 오류가 난 상황. -1이 리턴된다.
	errno에 오류가 담긴다.

path에 지정한 경로명의 파일을 실행하며, arg0 ~ argn과 envp를 인자로 전달한다. envp에는 새로운 환경변수를 설정할 수 있다. arg0 ~ argn을 포인터로 지정하므로, 마지막 값은 NULL 포인터로 지정해야한다. Envp는 포인터 배열이다. 이 배열의 마지막에는 NULL 문자열을 저장해야한다.

---
### **perror**

	#include <stdio.h>

	void	perror(const char *str);
오류 메세지를 출력한다.   
전역 변수 errno 의 값을 해석하여 이에 해당하는 시스템 오류 메시지를 표준 오류 출력 스트림(stderr)에 출력한다. 또한 추가적으로 전달하고자 하는 사용자 정의 메세지를 str인자에 담아 출력할 수도 있다.
* errno는 정수형 변수로 이전의 라이브러리 함수에 의해 발생한 오류에 대한 정보를 가지고 있다.   

str이 null 포인터가 아니라면 두개의 메세지는 ":"로 구분된다. 마지막에는 개행문자가 출력된다.

---
### **strerror**

	#include <string.h>

	char *strerror(int errnum);

오류 메세지 문자열을 가리키는 포인터를 얻어온다. errnum의 값을 통해 발생하였던 오류에 알맞은 오류 메세지를 가리키는 포인터를 리턴한다. 