# FDF - 42Born2Code

## **MiniLibX**
>	simple Graphical Interface Library for students.

<br>
MacOs Compile Option

	gcc -lmlx -framwork OpenGL -framework Appkit [file]

Minilibx는 X-Window / Cocoa 프로그래밍 지식 없이 그래픽 소프트웨어를 만들기 쉬운 방법중 하나이고, 간단한 창 만들기, 그리기 툴, 이미지 그리고 기본적인 이벤트 관리를 제공한다.

---
### *mlx_init*
	#include <mlx.h>

	void *mlx_init();

- mlx.h 는 MiniLibX API를 사용하기 위하여 반드시 include
- 첫번째로 software와 display 연결을 초기화 하여야 하는데, 한번 연결이 성립되면 다른 함수들 사용이 가능하다.   
- mlx_init()함수는 연결을 만든다, 매개변수는 필요없고, void * 식별자를 리턴한다. 이 식별자는 추후에 라이브러리 함수들을 사용할때 이용된다.
- 연결을 실패할 시, NULL return.

---
### *mlx_new_window*
	void *
	mlx_new_window (void *mlx_ptr, int size_x, int size_y, char *title);

	int
	mlx_clear_window (void *mlx_ptr, void *win_ptr);

	int
	mlx_destroy_window (void *mlx_ptr, void *win_ptr);


- mlx_new_window 
	- 화면에 새로운 window를 만든다.
size_x, size_y 가 크기를 결정하고, title이 window의 title bar에 나타난다. mlx_ptr 매개변수는 mlx_init()함수의 리턴 식별자이다.
	- 다른 MiniLibX 함수들에 사용가능한 void *형 window 식별자를 리턴한다.
	- MiniLibX는 여러개의 window를 다룰 수 있다. 즉, window 식별자는 각각의 window를 구분한다.
	- 실패시 NULL return

- mlx_clear_window, mlx_destroy_window	
	- mlx_clear_window 주어진 window를 clear (in black)
	- mlx_destroy_window 주어진window를 destroy
	- mlx_ptr은 화면 연결 식별자, win_ptr은 window 식별자이다.
	- return Nothing.

---
### *mlx_loop*

	int
	mlx_loop (void *mlx_ptr);

	int
	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);

	int
	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);

	int
	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);

X-window 와 MacOSX 그래픽 시스템은 양방향이다. 한쪽으로는 pixels, images 와 같은 것들을 보여주기 위한 명령을 screen에 보내지만, 다른 한편으로는 화면에 관련된 키보드나 마우스 정보들을 가져온다. 그렇게 하기 위해서 program은 events를 키보드와 마우스에서 받아온다.

- mlx_loop
	- event들을 받아오기위해  mlx_loop를 사용해야 한다. 이 함수는 return하지 않는다. event를 받아오기 위해 무한루프를 돌고 이 event들과 관련된 사용자 정의 함수들을 불러온다.
	- mlx_ptr 매개변수를 필요로 한다.

- mlx_key_hook, mlx_mouse_hook, mlx_loop_hook
	- funct_ptr은 event가 발생하였을때, 불러오고 싶은 함수이다.
	- win_ptr 식별자에 의해 정의된 window에만 해당된다.
	- param은  MiniLibX에서 사용되거나 수정되지 않는다.
	- key와 mouse 이벤트에서, 추가 정보가 전달된다. : keycode (어떤키가 눌렸는지)
	- ( x , y)은 window에서 마우스가 클릭된 좌표이다.
	- button은 어떤 마우스 버튼을 눌렀는지 알려준다.

	---
	### *mlx_new_image*

		void *
		mlx_new_image (void *mlx_ptr, int width, int height)

		char *
		mlx_get_data_addr (void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)

		int
		mlx_put_image_to_window (void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)

		unsigned int
		mlx_get_color_value (void *mlx_ptr, int color)

		void *
		mlx_xpm_to_image (void *mlx_ptr, char **xpm_data, int *width, int *height)

		int
		mlx_destroy_image(void *mlx_ptr, void *img_ptr)

- mlx_new_image
	- 메모리에 새로운 이미지를 만든다.
	- 추후에 이 이미지를 조작하기 위해서 void * 식별자를 리턴한다. 
	- 이미지를 만들기 위해서는 사이즈만 필요하다. width, height
	- mlx_ptr은 연결 식별자
	- error : NULL return
	- return : non-null pointer as an image identifer.

- mlx_put_image_to_window
	- user는 image안에 그릴수 있고, screen에 display하기 위해 언제든지 특정한  window 안에 이미지를 dump할 수 있다.
	- mlx_ptr, win_ptr, img_ptr 과 ( x , y )좌표가 필요하다. (좌표는 window에서 어디에 이미지를 넣을지 결정한다.)

- mlx_get_data_addr
	- 사용자가 수정할 수 있도록, 생성된 이미지에 대한 정보를 리턴한다.
	- img_ptr 매개변수는 사용할 image를 지정한다.
	- bits_per_pexel은 pixel_color를 표현하기 위해 필요한 bits의 수이다. (depth of the image)
	- size_line은 메모리에 있는 이미지의 한 줄을 저장하기 위해서 사용되는 바이트들의 수이다. 이 정보는 이미지에서 다음줄로 이동하기 위해서 필요하다.
	- endian은 이미지에 있는 pixel_color가 little endian 인지 big endian인지 알려준다.
		- little endian == 0
		- big endian == 1
	- 이미지가 저장된 메모리 영역의 시작을 나타내는 char * 주소를 리턴한다.
	- 이 주소를 통해, 처음 bits_per_pixel비트들이 image의 첫 줄의 첫 pixel의 색을 나타낸다
	- 메모리 주소에 size_line을 더해서 다음 줄로 넘어가게 한다.

-   mlx_destroy_image
	- (img_ptr)주어진 이미지를 없앤다.

- mlx_get_color
	-  display에 따라서, 하나의 pixel color 를 저장하기 위한 bit의 수는 바뀔수 잇다. 유저는 보통 RGB mode를 사용하여 색을 표현한다. 각각의 구성요소를 1바이트로.
	- 이것은 이미지의 bits_per_pixel 요구에 맞게 변환되어야 한다. 그리고 graphical system이 색을 이해할 수 있게 만들어야 한다.
	- color param -> standard RGB 를 받아서 unsigned int 값을 리턴한다.
	- LSB(최하위 비트)는 local computer's endian에 달려있다.

---
### mlx_pixel_put

	int
	mlx_pixel_put (void *mlx_ptr, void *win_ptr, int x, int y, int color);

	int
	mlx_string_put (void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

- mlx_pixel_put
	- 지정된 색과 (x, y)좌표를 이용하여 win_ptr window에 지정된 pixel를 그린다. 
	- (0, 0)은 window의 왼족 위의 모서리이다.
	- x, y축은 각각 오른쪽과 아래를 가리킨다.
	- 연결 식별자 mlx_ptr필요.

-  mlx_string_put
	- 위의 매개변수와 동일하다.
	- 간단한 픽셀 대신에, 지정된 string이 (x, y)에 표시된다.

- 두개의 함수 모두, 지정된 window 밖에 어떤것도 표시할 수 없고, 선택된 window 이외에 다른 window에 나타낼 수 없다.

- color매개변수는 정수 타입이다. 모든 표시 가능한 색은 red, green, blue로 이루어져있다. 0 ~ 255 까지의 범위를 가지며, 색을 나타내기 위해서 각각의 요소가 얼마나 섞였는지를 나타낸다. 

- endian 문제를 고려할 것. blue bytes가 항상 LSB여야 한다.

		| 0 | R | G | B |  color integer
		+---+---+---+---+