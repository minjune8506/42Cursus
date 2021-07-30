# push_swap - day 02.

- ### *parsing*
	- 어떤 자료구조에 파싱한 데이터를 저장?
    	- double-linked list stack(구현 o)
        	- init_stack()
        	- init_node(int data)
        	- push (t_stack *stack, int data)
        	- push_back (t_stack *stack, int data)
        	- pop (t_stack *stack)
        	- pop_back (t_stack *stack)
        	- print_stack(t_stack *stack)
  	- char *형식으로 데이터가들어온다. 어떻게 int형으로 변환??
    	- 한개의 char *형 데이터가 하나의 정수만 포함하고 있지 않을떄는?
    	- ex) "1 2 3 4 5"
    - 숫자가 아닌 값 처리 (숫자 or '-' or ' ' 이외에 error)
    - 배열에 매개변수 저장
      - 정수인지 검사.
    - 중복된 값 처리
    - int 범위를 벗어난 값 처리
      - -2147483648 ~ 2147483647

- ### *고려할 점*
  - parsing 고려사항
    - 매개변수가 1개 들어올 경우는?? 
    - 매개변수가 2개 들어올 경우는??
    - 매개변수가 3개 들어올 경우는?? 
    - 오름차순으로 정렬된 값이 들어올 경우에는??
  - 어떤 정렬 알고리즘을 사용할 것인가?