# Get_Next_Line - @42Born2Codd

### **Contents**
------------
> + [프로젝트 주제](#프로젝트-주제)

> + [사전 지식](#사전지식)

> + [후기](#후기)

### **프로젝트 주제**
---
#### MANDATORY
> BUFFER_SIZE만큼 읽어 들이는 함수를 만들고, 개행을 기준으로 나누어 출력하는 함수 작성.  

> file을 읽을때와 standard input으로 읽을 때 모두 작동.  

> static variable에 대한 이해를 요구.  

#### BONUS
> 1개 이상의 file descriptor가 들어 왔을때 함수가 정상적으로 작동 할 수 있도록 할것.

### **사전지식**
---
#### **File Descriptor**
    FD : 시스템으로 부터 할당받은 파일이나 소켓을 대표하는 정수.  
    FD의 0번 부터 2번까지는 고정되어 있다.  
    파일 오픈 or 소켓 생성시 FD는 3부터 시작한다.
    open시 프로세스의 파일 디스크립터 중에 사용하지 않는 가장 작은 정수를 부여 해준다.   
    그 후에 파일 디스크립터를 이용하여 파일을 지칭 할 수 있다.
    FD의 최댓값은 OPEN_MAX라는 값이다.(ulimit -n 명령어로 확인 가능)
| FD | name |  
|:---:|:---:|
| 0 | standard input |
| 1 | standard output |
| 2 | standard error | 

#### **open 함수**
    open 함수 : 이미 존재하는 파일을 열거나, 새로운 파일을 생성하는 System call 함수  
    open (pathname, flags, mode)의 형식으로 이루어져 있다.  
    flags : O_RDONLY, O_WRONLY, O_RDWR 중 하나는 반드시 설정되어야 한다.
    return 0 이상 -> 정상적으로 파일을 열었으며, 열려진 파일의 fd
          -1 -> 오류가 발생

#### **read 함수**
    read 함수 : fd 로부터 데이터를 읽는다.  
    파일을 읽으면 읽은 size만큼 파일의 다음 읽을 위치가 이동된다.
    파일의 끝에 도달하면 더이상 읽을 데이터가 없으니 0을 리턴한다.

    read (fd, buf, count)
    fd : open한 file descriptor
    buf : 읽을 데이터를 저장할 메모리 영역
    count : 읽을 byte수

    return 0보다 큰 수 : 읽은 byte수, 일반적으로 count와 같은 값이지만, EOF에 도달하였거나, 다른상황에서는 count와 다른 값일수 있다.
    return -1 : 오류가 발생한 경우
    return 0 : end of file에 도달하여 더이상 읽을 데이터가 없는 경우.

#### **close 함수**
    close 함수 : open한 파일을 닫는다.

    close (fd)

    return 0 : 정상적으로 파일을 닫은 경우
    return -1 : 오류가 발생한 경우
#### **메모리의 구조**
    메모리 공간은 코드영역, 데이터영역, 힙영역, 스택 영역으로 나누어져 있다.
    
    code 영역 : 실행할 프로그램의 코드가 저장되는 영역.
    프로그램이 시작하고 종료될 때 까지 메모리에 계속 남아있는다.  

    data 영역 : 프로그램의 전역(global)변수와 정적(static)변수가 저장되는 영역이다.
    프로그램의 시작과 함께 할당, 프로그램 종료 시 소멸.

     heap 영역 : 프로그래머가 직접 공간을 할당, 해제하는 메모리 공간.
     malloc()을 통해 메모리를 할당, free()를 통하여 메모리를 해제.
     heap은 FIFO(First In, First Out)의 방식으로 먼저 들어온 데이터가 가장 먼저 인출된다. 위에서 부터 아래 방향으로 데이터가 쌓인다.

     stack 영역 : 프로그램이 자동으로 사용하는 임시 메모리 영역.
     함수 호출시 생성되는 지역변수와 매개변수가 저장되고, 완료되면 사라진다.
     stack은 LIFO(Last In, First Out)의 방식으로 가장 마지막에 들어온 데이터가 가장 먼저 인출된다.
     아래에서부터 위의 방향으로 데이터가 쌓인다.

     *스택 오버플로우, 힙 언더플로우

#### **static 변수**
    c언어에서의 기본적인 변수는 동적(dynamic)변수로, 변수 선언과 동시에 메모리할당, 변수 사용이 끝남과 동시에 메모리가 해제된다.
    static variable은 data 영역에 저장됨으로, 프로그램 시작과 함께 할당되며, 프로그램이 종료되기 전에 메모리 해제가 되지 않는다.

### **후기**
----
read 함수로 파일을 읽었을때, 읽은 위치를 어떻게 기억을 시켜야하며, 그 부분 부터 어떻게 다시 읽게 해야할 지에 대한 아이디어가 없어서, 한참 고민을 하였는데 다시 한번 꼼꼼하게 man파일과 구글링을 해 보았더니, read 함수 내에서 그 기능을 제공한다는 것을 알고 해결하였다.  
또한, 메모리 할당 실패에 대한 예외처리를 해주지 않아, 디펜스에서 실패를 하였는데, ft_strjoin 이나 ft_strdup함수에서 malloc allocation 실패 시 예외처리까지 처리하였다.    
마지막으로 BUFFER_SIZE에 큰 값이 들어왔을때, 메모리 할당 실패 이슈가 있엇는데, 메모리 영역에 대한 공부를 진행 후, 스택에 저장되어서 그런 문제가 발생한다는 점을 이해하고, malloc을 통하여 heap공간에 할당해 주어 해결하였다.