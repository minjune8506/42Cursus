# Libft library
## Part.1
## ft_memset
    void    *ft_memset(void *s, int c, size_t n)

- return : s
- 메모리의 내용을 원하는 크기만큼 특정 값으로 설정 가능하다.

- s포인터에 지정된 메모리 블록의 n 바이트 만큼을 지정된 value(c)로 채운다.

- memset 함수 내부에서 value(c)는 (unsigned char)로 다루어 진다.

- int형 값을 넣을때 원하는대로 옮겨지지 않는다.(주의)

-----
## ft_bzero
    void    ft_bzero(void *s, size_t n)
- return : x

- s가 가르키는 메모리 영역을 n 바이트만큼 0으로 초기화 한다.

---
## ft_memcpy
    void    *ft_memcpy(void *dest, const void *src, size_t n)

- return value : dest

- src의 메모리를 dest로 n만큼 복사한다.

- 메모리 영역은 겹치지 않아야한다. (겹치면 memmove함수를 사용.) 

- memcpy는 NULL-종료를 보장하지 않는다.

- 정확히 n 바이트 만큼만 복사한다.

---
## ft_memccpy
    void    *ft_memccpy(void *dest, const void *src, int c, size_t n)

- return : dest에서 복제가 끝난 다음 주소 return
c를 만나지 않았다면 -> n바이트 복제, NULL 리턴

- src에서 dest로 n Byte만큼 데이터 복제, c 를 만나면 c 까지 복제 후 종료

---
## ft_memmove
    void    *ft_memmove(void *dest, const void *src, size_t n)

- return : dest

- src에서 dest로 n바이트 만큼 복사
- memcpy와 다른점은??

    memcpy -> 다른곳을 거치지 않고 복사
    
    memmove -> 복사할 것을 버퍼에 복사, 버퍼를 dest에 붙여넣음

- dest <= src / dest > src 고려

---
## ft_memchr
    void    *ft_memchr(const void *s, int c, size_t n)

- return : c와 일치하는 값이 있을때 -> 그곳의 주소 / 
    없으면 NULL 리턴

- 메모리 블럭에서 문자를 찾는다.

---

## ft_memcmp
    int ft_memcmp(const void *s1, const void *s2, size_t n)

- return : 두 메모리 블럭이 같을떄 : 0 리턴
            
    다를때 : 두 메모리의 차이를 리턴

- 두개의 메모리 블럭을 비교한다.

---

## ft_strlen
    size_t  ft_strlen(const char *s)

- return : 문자열의 길이

---

## ft_strlcpy
    size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)

- return : 만드려고 시도한 문자열의 총 길이(src)
- 크기 제한 문자열 복사
- 목적지 버퍼 전체 크기를 차지, 공간이 있으면 NULL 보자
- dstsize 가 0이 아닌경우 (dstsize - 1)만큼 문자를 복사
---

## ft_strlcat
    size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)

- return : dst의 초기 글자 수 + src의 초기 글자 수

- dst 끝에 src 문자를 덧붙인다.

- 최대 (dstsize - strlen(dst) - 1)만큼의 문자열을 붙인다.

---
## ft_strchr
    char    *ft_strchr(const char *s, int c)

---
## ft_strrchr
    char    *ft_strrchr(const char *s, int c)

---
## ft_strnstr
    char    *ft_strnstr(const char *haystack, const char *needle, size_t len)

---
## ft_strncmp
    int	ft_strncmp(const char *s1, const char *s2, size_t n)

---
## ft_atoi
    int			ft_atoi(const char *str)

---
## ft_isalpha
    int	ft_isalpha(int c)

---
## ft_isdigit
    int	ft_isdigit(int c)

---
## ft_isalnum
    int	ft_isalnum(int c)

---
## ft_isascii
    int	ft_isascii(int c)

---
## ft_isprint
    int	ft_isprint(int c)

## ft_toupper
    int	ft_toupper(int c)

---
## ft_tolower
    int	ft_tolower(int c)

---

## Part.2
## ft_substr
    char	*ft_substr(char const *s, unsigned int start, size_t len)

---
## ft_strjoin
    char	*ft_strjoin(char const *s1, char const *s2)
    
---
## ft_strtrim
    char	*ft_strtrim(char const *s1, char const *set)

---
## ft_split
    char	**ft_split(char const *s, char c)

---
## ft_itoa
    char    *ft_itoa(int n)

---
## ft_strmapi
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

---
## ft_putchar_fd
    void	ft_putchar_fd(char c, int fd)
    
---
## ft_putstr_fd
    void	ft_putstr_fd(char *s, int fd)

---
## ft_putendl_fd
    void	ft_putendl_fd(char *s, int fd)

---
## ft_putnbr_fd
    void	ft_putnbr_fd(int n, int fd)

---
## Bonus
## ft_lstnew
    t_list		*ft_lstnew(void *content)

---
## ft_lstadd_front
    void	ft_lstadd_front(t_list **lst, t_list *new)

---
## ft_lstsize
    int	ft_lstsize(t_list *lst)

---
## ft_lstlast
    t_list	*ft_lstlast(t_list *lst)

---
## ft_lstadd_back
    void	ft_lstadd_back(t_list **lst, t_list *new)

---
## ft_lstdelone
    void    ft_lstdelone(t_list *lst, void (*del)(void *))

---
## ft_lstclear
    void    ft_lstclear(t_list **lst, void (*del)(void *))

---
## ft_lstiter
    void    ft_lstiter(t_list *lst, void (*f)(void *))

---
## ft_lstmap
    t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))

---