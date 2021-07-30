# push_swap - day 01.

현재 고려할 점
- parsing 고려사항
  - 정수 이외의 값이 있으면 error
  - int 범위를 벗어난 값이 있으면 error
  - 배열에 중복된 값이 있으면 error
  - 매개변수가 1개만 들어올 경우는?? 
  - 오름차순으로 정렬된 값이 들어올 경우에는??
  - "1 2 3 4 5" 형식으로 들어올 경우는??
- 매개변수를 어떻게 저장할 것인가?
- 스택을 어떻게 구현할 것인가?
- 어떤 정렬 알고리즘을 사용할 것인가?
  
---

- ### *subject 내용 확인* (v)

A,  B 라는 두개의 스택을 이용한다.   
A 는 중복없이 양수 / 음수 임의의 숫자를 가지고 있다.   
B 는 비어있다.   
최종 목표는 오름차순으로 정렬하여 A 스택에 저장하는 것이다.   

sa : swap a - stack a의 맨위 두개의 element의 순서를 바꾼다. (element가 없거나 한개밖에 없을 경우 아무것도 하지 않는다)   
sb : swap b - stack b의 맨위 두개의 element의 순서를 바꾼다. (element가 없거나 한개밖에 없을경우 아무것도 하지 않는다)   
ss : sa와 sb를 동시에 수행한다.   
pa : push a - b의 제일 위에 있는 element를 pop하고 a의 맨위에 push (b가 비어있으면 아무것도 하지 않는다)   
pb : push b - a의 제일 위에 있는 element를 pop하고 b의 맨위에 push (a가 비어있으면 아무것도 하지 않는다)   
ra : rotate a - 모든 element 를 하나씩 위로 올린다. 맨위의 element는 맨 밑의 element가 된다.   
rb : rotate b - 모든 element 를 하나씩 위로 올린다. 맨위의 element는 맨 밑의element가 된다.   
rr : ra와 rb를 동시에 수행한다.   
rra : reverse rotate a - 모든 element를 하나씩 아래로 내린다. 맨밑의 element는 맨위의 element가 된다.   
rrb : reverse rotate b - 모든 element를 하나씩 아래로 내린다. 맨밑의 element는 맨위의 element가 된다.   
rrr : rra 와 rrb 를 동시에 수행한다.   

- ### *Makefile 만들기* (v)
  
- ### *double linked list를 이용해서 stack 구현해보기* (v)
  