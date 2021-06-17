# Get_Next_Line - @42Born2Codd

### **프로젝트 주제**
---
#### MANDATORY
> BUFFER_SIZE만큼 읽어 들이는 함수를 만들고, 개행을 기준으로 나누어 출력하는 함수 작성.  

> file을 읽을때와 standard input으로 읽을 때 모두 작동.  

> static variable에 대한 이해를 요구.  

#### BONUS
> 1개 이상의 file descriptor가 들어 왔을때 함수가 정상적으로 작동 할 수 있도록 할것.

### Compile
---
Mandatory  

    gcc -Wall -Wextra -Werror -D BUFFER_SIZE = ? get_next_line.c get_next_line_utils.c  
Bonus

    gcc -Wall -Wextra -Werror -D BUFFER_SIZE = ? get_next_line_bonus.c get_next_line_utils_bonus.c 

BUFFER_SIZE에 원하는 값을 넣고 complie  

### **후기**
----
read 함수로 파일을 읽었을때, 읽은 위치를 어떻게 기억을 시켜야하며, 그 부분 부터 어떻게 다시 읽게 해야할 지에 대한 아이디어가 없어서, 한참 고민을 하였는데 다시 한번 꼼꼼하게 man파일과 구글링을 해 보았더니, read 함수 내에서 그 기능을 제공한다는 것을 알고 해결하였다.  
또한, 메모리 할당 실패에 대한 예외처리를 해주지 않아, 디펜스에서 실패를 하였는데, ft_strjoin 이나 ft_strdup함수에서 malloc allocation 실패 시 예외처리까지 처리하였다.    
마지막으로 BUFFER_SIZE에 큰 값이 들어왔을때, 메모리 할당 실패 이슈가 있엇는데, 메모리 영역에 대한 공부를 진행 후, 스택에 저장되어서 그런 문제가 발생한다는 점을 이해하고, malloc을 통하여 heap공간에 할당해 주어 해결하였다.