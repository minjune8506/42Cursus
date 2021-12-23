# Philisiphers (Function)

From: 42Seoul
분류: Philosophers
작성일시: 2021년 10월 28일 오후 10:09
종류: OS

- memset
    - 메모리의 값을 원하는 크기만큼 특정 값으로 세팅한다.
    
    ```c
    #include <memory.h>
    // or #include <string.h>
    void *memset(void *ptr, int value, size_t num);
    ```
    
    - void * ptr
        - 세팅하고자 하는 메모리의 시작 주소를 가리키고 있는 포인터
    - int value
        - 메모리에 세팅하고자 하는 값
        - 내부적으로 `unsigned char` 으로 처리된다. 'a' 도 처리 가능
    - size_t num
        - 바이트 단위 길이를 의미한다.
        - `sizeof(type)`
    - Return Value
        - 성공 : 첫번째 인자인 ptr 반환
        - 실패 : NULL 반환
- printf
    
    ```c
    #include <stdio.h>
    
    int printf(const char *format, ...);
    ```
    
    - 일련의 데이터를 특정한 형식에 맞추어 `stdout` 에 출력
    - `%[flag][width][.precision][length]specifier`
    - Return Value
        - 출력되는 문자의 개수
    - 이하생략
- malloc
    
    ```c
    #include <stdlib.h>
    
    void *malloc(size_t size);
    ```
    
    - size의 크기만큼 메모리를 할당한다.
    - Return Value
        - 성공 : 할당한 메모리의 첫번째 바이트 주소
        - 실패 : NULL
    - 이하생략.
- free
    
    ```c
    #include <stdlib.h>
    
    void free(void *ptr);
    ```
    
    - 메모리를 해제한다.
    - `ptr` 이 할당되지 않은 메모리를 가르킬시 `undefined behavoir`
    - Retun Value
        - None
    - 이하생략.
- write
    
    ```c
    #include <unistd.h>
    
    ssize_t write(int fd, const void *buf, size_t n);
    ```
    
    - int fd
        - 파일 디스크립터
    - const void *buf
        - 파일에 쓰기를 할 내용을 담은 버퍼
    - size_t n
        - 쓰기할 바이트 개수
    - Return Value
        - 성공 : 쓰기한 바이트 개수
        - 실패 : -1 반환
- usleep
    
    ```c
    #include <unistd.h>
    
    int usleep(useconds_t microseconds);
    
    ```
    
    - 일정 시간 동안 calling 한 쓰레드의 실행을 중지한다.
    - usleep → micro seconds
    - sleep → seconds
    - Return Value
        - 성공 : 0
        - 실패 : -1
            - errno에 저장
- About Time
    - 1 ms (milli second)
        - 1/1000 초 → 0.001초
    - 1 us (micro second)
        - 1/1000 밀리초 → 1/1000000초
        - 0.000001초
- gettimeofday
    
    ```c
    #include <sys/time.h>
    
    int gettimeofday(struct timeval *tv, struct timezone *tz);
    ```
    
    - 1970-01-01 00:00:00 +0000 (UTC) 이후의 현재까지의 경과된 초와 micro초 값을 얻는 함수
    - tz 인자는 잘 쓰지 않는다. 보통 NULL로 설정
    - clock() 함수는 CPU time 을 측정
        - CPU Time : 컴퓨터가 인지하는 시간
    - gettimeofday() 함수는 Wall clock time을 측정
        - Wall clock time : 벽시계시간
    - tv
        - 1970-01-01 00:00:00 +0000 (UTC) 이후 경과된 초(seconds)와 micro초를 저장할 buffer
        
        ```c
        struct timeval {
        	time_t tv_sec; // seconds
        	suseconds_t tv_usec; // microseconds
        };
        ```
        
    - tz
        
        ```c
        struct timezone {
        	int tz_minuteswest; // minutes west of Greenwich
        	int tz_dsttime; // type of DST correction
        }
        ```
        
    - Return value
        - 성공 : 0
        - 실패 : -1
            - errno 전역변수에 설정됨
        - EFAULT
            - tv / tz 의 메모리 영역이 유효하지 않은 영역임
    - Sample code
    
    ```c
    #include <sys/time.h>
    #include <unistd.h>
    #include <stdio.h>
    
    int main(void)
    {
    	struct timeval start;
    	struct timeval end;
    	double diff;
    
    	gettimeofday(&start, NULL);
    	sleep(1);
    	gettimeofday(&end, NULL);
    
    	diff = (end.tv_sec * 1000 + end.tv_usec * 1/1000) - (start.tv_sec * 1000 + end.tv_usec * 1/1000);
    	printf("%f\n", diff);
    	return (0);
    }
    ```
    
- `pthread`
    - Compile
        - `-lpthread` option 필요
    - Header
        - `#include <pthread.h>`
- pthread_create
    
    ```c
    int pthread_create(pthread_t *thread,
    		const pthread_attr_t *attr,
    		void *(start_routine)(void*), void *arg);
    ```
    
    - 호출되는 프로세스에서 새로운 Thread 시작
    - 새로운 Thread는 argument로 전달된 start_routine() 함수를 실행한다.
    - Thread 종료 조건
        - pthread_exit()을 호출하여 리턴값을 지정
        - start_routine() 함수를 리턴
        - pthread_cancel() 함수에 의한 쓰레드 취소
        - 어떤 Thread에서 `exit`을 호출하거나, main Thread에서 `return` 하는 경우 `모든 Thread 종료`
    - Parameter
        - pthread *thread
            - pthread 식별자로  thread가 성공적으로 생성되면 thread 식별값이 주어진다.
        - const pthread_attr_t *attr
            - pthread 속성(옵션), 기본적인 thread 속성 → NULL
            - pthread_attr_init과 관련 함수로 초기화한다.
        - void *funcname
            - pthread로 분기할 함수
            - 함수
                - 반환값 : void *
                - 매개변수 : void *
        - void *arg
            - 분기할 함수로 넘겨줄 인자값
            - void 형으로 넘겨주고, 함수 내에서 type casting 해서 사용
    - Return Value
        - 성공 : 0
        - 실패 : error number 리턴
            - EAGAIN
                - 현재 리소스가 없거나, 최대 쓰레드 개수 초과
            - EINVAL
                - attr 아규먼트가 유효하지 않음
            - EPERM
                - Scheduling policy를 설정할 수 있는 권한이 없을 경우
- pthread_detach
    
    ```c
    int pthread_detach(pthread_t thread);
    ```
    
    - 특정 쓰레드를 분리시킨다.
    - 분리된 쓰레드가 종료되면, 다른 쓰레드가 종료된 쓰레드에 join 할 필요 없이 자원은 자동으로 시스템에 반환된다.
    - 한번 detached 되면,  다시 join이 불가능하다.
    - Return value
        - 성공 : 0
        - 실패 : error number 리턴
            - EINVAL
                - Thread가 join 가능한 Thread가 아니다.
            - ESRCH
                - Thread ID 를 찾을수 없을때
- pthread_join
    
    ```c
    int pthread_join(pthread_t thread, void **retval);
    ```
    
    - thread 인자로 들어온 쓰레드를 종료시키기 위해 기다린다.
    - thread가 이미 종료 되었으면, pthread_join()은 즉시 리턴
    - thread는 joinable 해야한다.
    - retval 이 NULL이 아니면, target thread의 종료 상태를 retval 포인터에 저장한다.
    - target thread 가 canceled 이면, retval의 포인터가 가리키는 곳이 pthread_canceled() 로 대체된다.
    - 여러 쓰레드가 동시에 같은 쓰레드를 join 하려고 시도하면
        - 결과는 `undefined`
    - pthread_join() 을 호출한 쓰레드가 cancled 되면, target thread는 joinable 하다.
    - 성공적으로 pthread_join()을 수행 한후, caller는 쓰레드의 종료 이후에 행동들이 필요하다. (메모리 해제, target thread 에 할당되어 있는 자원 해제 등)
    - 이미 join한 쓰레드에 join → `undefined behavior`
    - joinable한 쓰레드레 join을 실패하면, "zombie thread"가 생성된다. 좀비 쓰레드가 쌓이면 새로운 쓰레드들을 만들 수 없음.
    - Return Value
        - 성공 : 0
        - 실패 : error number
            - EDEADLK
                - 교착상태가 감지됐을때 (e.g. 두 쓰레드가 서로 join 하려고 할때)
                - 자기 자신을 join 하려 할 때
            - EINVAL
                - thread 가 joinable 하지 않을때
            - EINVAL
                - thread를 join 하려고 다른 쓰레드가 기다리고 있을 때
            - ESRCH
                - Thread ID 를 찾을수 없을때
- pthread_mutex_init
    
    ```c
    int pthread_mutex_init(pthread_mutex_t *restrict mutex,
    	const pthread_mutexattr_t *restrict attr);
    
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    ```
    
    - initialize a mutex, with attributes specified by attr
    - pthread_mutex_t *mutex
        - 초기화 할 mutex 객체
    - const phtrad_mutex_attr_t *restrict attr
        - mutex 특성을 변경할 수 있다.
        - "fast", "recursive", "error checking"
        - fast
            - 하나의 쓰레드가 하나의 잠금을 얻을 수 있다.
        - recursive
            - 잠금을 얻은 쓰레드가 다시 잠금을 얻을 수 있다.
            - 잠금에 대한 count 증가
        - 기본 특성 → NULL (fast)
    - 성공적으로 초기화가 되면, mutex는 `initialized`, `unlocked`
    - 이미 초기화된 mutex 를 다시 초기화 → `undefined behavior`
    - Return Value
        - 성공 : 0
        - 실패 : error number 리턴
            - EAGAIN
                - 시스템이 필수 지원이 부족하여 초기화 불가능
            - ENOMEM
                - mutex 초기화를 위한 메모리가 부족
            - EPERM
                - caller가 연산을 할 권한이 없을 때
- pthread_mutex_destroy
    
    ```c
    int pthread_mutex_destroy(pthread_mutex_t *mutex);
    ```
    
    - destroy the mutex object referenced by mutex
    - mutex object는 사실상 uninitialized
    - Return Value
        - 성공 : 0
        - 실패 : error number 리턴
            - EAGAIN
                - 시스템이 필수 지원이 부족하여 초기화 불가능
            - ENOMEM
                - mutex 초기화를 위한 메모리가 부족
            - EPERM
                - caller가 연산을 할 권한이 없을 때
    
- pthread_mutex_lock
    
    ```c
    int pthread_mutex_lock(pthread_mutex_t *mutex);
    ```
    
    - 임계영역에 진입하기 위해 mutex 잠금 요청
    - 만약 mutex 최근 상태가 unlocked라면, 쓰레드는 잠금을 얻고, 임계영역에 진입하게 되고 리턴한다.
    - 다른 쓰레드가 뮤텍스 잠금을 얻은 상태라면, 잠금을 얻을 수 있을 때까지 기다린다.
- pthread_mutex_unlock
    
    ```c
    int pthread_mutex_unlock(pthread_mutex_t *mutex);
    ```
    
    - 뮤텍스 잠금을 되돌려줌
    - 만약  fast 뮤텍스라면, pthread_mutex_unlock()은 언제나 unlocke 상태로 되돌려주고, recursive 뮤텍스라면, 잠겨있는 뮤텍스의 수를 감소시키고 이 수가 0이 되면 뮤텍스 잠금을 되돌려줌