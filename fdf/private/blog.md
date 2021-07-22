# FDF - @42Born2Code

### **Contents**
------------
> + [Subject](#Subject)

> + [사전 지식](#사전-지식)

<br>

![image](../fdf_img.png)

### *Subject*
---
MANDATORY   

>   MinilibX를 사용하여 주어진 map을 parsing하고, isometric projection을 이용하여 화면에 그리기.  

BONUS
- zoom in, zoom out, shift   
- rotate   
- other projection.   
  
### *사전 지식*
---
#### *MiniLibX*

MiniLibX를 사용하여 화면에 나타내야 하기 떄문에, MiniLibX의 man 파일이 주어지는데, 그것을 우선으로 익혀야 한다.   

>	MiniLibX   
>   https://velog.io/@minjune8506/MiniLibX
 
---

#### *isometric projection*
isometric projection이란 등축투영법으로 3차원 물체를 2차원에 표현하기위한 투영법중에 하나이다. x, y, z 좌표축이 이루는 각도가 모두 같거나 120도를 이루는 특성을 지닌다.

<img src = "https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Perspective_isometrique_cube_gris.svg/1200px-Perspective_isometrique_cube_gris.svg.png" width = "200" height = "200"> 출처 : 위키백과

이 그림과 같이 x, y 축을 30도씩 회전시켜 3차원 물체를 2차원으로 표현한 것이라고 보면 된다.

---
#### *회전변환 행렬*

- 2D
  
    x' = x$\cos$($\theta$) - y$\sin$($\theta$)   
    y' = x$\sin$($\theta$) + y$\cos$($\theta$)   

x. y축을 30도씩 돌리기 위하여 회전변환행렬을 사용하려고하는데, 2D에서 x' y' 의 좌표는 저 공식과 일치한다. 단위원의 반지름, $\cos$ $\sin$ 값과 삼각함수의 덧셈정리를 이용하여 공식을 유도 할 수 있으며, 한번쯤 유도를 해 보는것이 좋을 것 같다.

- 3D

	x축을 기준으로 회전   
	x' = x   
	y' = y$\cos$($\theta$) - z$\sin$($\theta$)   
	z' = y$\sin$($\theta$) + z$\cos$($\theta$)

	y축을 기준으로 회전   
	x' = x$\cos$($\theta$) + z$\sin$($\theta$)   
	y' = y   
	z' = -x$\sin$($\theta$) + z$\cos$($\theta$)

	z축	을 기준으로 회전   
	x' = x$\cos$($\theta$) - y$\sin$($\theta$)   
	y' = x$\sin$($\theta$) + y$\cos$($\theta$)   
	z' = z   

2D에서의 회전 변환행렬을 3차원으로 확장한 행렬의 곱셈을 수행하면 위와 같이 정리 할 수 있다. 이 공식을 사용하여 축을 기준으로 회전을 할 것이고, 위의 2D 에서의 회전 행렬을 사용하여 축을 회전시켜 isometric projection을 구현할 것이다.

위의 공식을 유도할때 필요한 수학적 지식들의 링크이다.

[위키피디아 : 회전변환행렬](https://ko.wikipedia.org/wiki/%ED%9A%8C%EC%A0%84%EB%B3%80%ED%99%98%ED%96%89%EB%A0%AC)    
[위키피디아 : 삼각함수의 덧셈정리](https://ko.wikipedia.org/wiki/%EC%82%BC%EA%B0%81%ED%95%A8%EC%88%98%EC%9D%98_%EB%8D%A7%EC%85%88%EC%A0%95%EB%A6%AC)   
[위키피디아 : 행렬 곱셈](https://ko.wikipedia.org/wiki/%ED%96%89%EB%A0%AC_%EA%B3%B1%EC%85%88)
