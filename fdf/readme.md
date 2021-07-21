# FDF - @42Born2Code

### **Contents**
------------
> + [Subject](#Subject)

> + [Makefile](#Makefile)

> + [후기](#후기)

![image](./fdf_img.png)

### **Subject**
---
MANDATORY   

- MinilibX를 사용하여 주어진 map을 parsing하고, isometric projection을 이용하여 화면에 그리기.  

BONUS
- zoom in, zoom out, shift
- rotate
- other projection.
  
### **Makefile**
---
fdf 파일 생성 && 하위 라이브러리 make

    make

*.o 파일 삭제

    make clean

### **후기**
----
어려웠던 점
- isometric projection과 회전에 대하여 검색하면서 공식은 구글링으로 찾을 수 있엇지만, 어떻게 해서 회전이 되는것이며, 이 공식은 어떻게 도출이 되었는가? 에 관한 고민.
- pixel을 찍는 것과, img 주소에 pixel을 미리 찍어놓고 한꺼번에 image로 출력을 하는 방법 과 그렇게 했을때, 화면을 벗어나는 부분들이 반대쪽에서 튀어나오는 문제.
- zoom in, zom out을 하였을때 segmentation fault가 뜨는 문제.
  
후기
- 첫번째 graphic과제 였던만큼 생소한 분야였고, 수학에 대해서 공부를 많이했던 과제였다.
- 공식이 도출되는 과정을 회전행렬을 통해서 해결하였고, 궁금증을 해결 할 수 있었다.
- 과제를 제출할때는, pixel로 찍어서 제출했지만 평가 종료후 img로 찍어서 출력하게 개선을 하였다.

개선한 부분
- img를 사용하여 화면에 출력을 하였다. -> 크기가 큰 파일들도 확대 축소, 회전, 이동을 하였을때 퍼포먼스가 잘 나왔다.
- 키보드를 눌렀을때, 기능들이 작동하게 하였는데, user guide를 왼쪽에 만들었다.