/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:37:20 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/21 21:35:14 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#define FD_MAX 256

static int	check_newline(char *buff) // 개행이 있는지 검사하는 함수
{
	int index;

	index = 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

static int	sep_line(char **line, char **store, int new_line)
{
	char	*temp;

	(*store)[new_line] = '\0'; //개행을 '\0' 로 바꾼다.
	if (!(*line = ft_strdup(*store))) //line에 store을 복제해 넣는다.
		return (-1);
	if (!(temp = ft_strdup(*store + new_line + 1))) //temp에 개행 다음 위치의 주소를 복제해 넣는다.
		return (-1);
	free(*store); //store할당 해제
	*store = temp; //store에 temp를 대입함으로써, store의 위치는 개행 다음의 문자를 가리킨다.
	return (1);
}

static int	remain_content(char **line, char **store, int read_size)
{
	int i;

	if (read_size < 0) //read_size < 0 인경우 -> read에서 에러가 났을 경우
	{
		if (*store)
			free(*store);
		return (-1);
	}
	if (*store && (i = check_newline(*store)) >= 0) //store에 내용이 들어있고, 개행이 남아있을 경우
		return (sep_line(line, store, i)); //개행처리를 한번 더 해준다.
	else if (*store) //store에 내용이 남아있고 마지막인 경우
	{
		*line = *store; //line에 저장
		*store = NULL; //store null로 초기화
		return (0);
	}
	if (!(*line = ft_strdup(""))) //빈 파일이 들어왔을경우 빈 문자열 저장
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buff; //read로 읽어온 데이터를 저장할 버퍼
	static char	*store[FD_MAX];
	int			new_line; //개행의 인덱스 위치를 저장할 변수
	int			read_size; //read의 return값을 저장할 변수

	if ((fd < 0) || (BUFFER_SIZE <= 0) || !line || (FD_MAX <= fd))
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0) //개행을 만나면 return, 만나지못하면 반복
	{
		buff[read_size] = '\0'; //read_size위치에 '\0' 을 넣어줌으로써 널 종료 보장
		if (!(store[fd] = ft_strjoin(store[fd], buff)))
			return (-1); //store[fd]에 읽어온 데이터(buf)를 '\0' 종료 처리후 이어 붙임
		new_line = check_newline(store[fd]); //개행이 있으면 0이상의 값, 없으면 -1 저장
		if (new_line >= 0) //개행이 있을경우
		{
			free(buff); //할당 해제
			return (sep_line(line, &store[fd], new_line));
		}
	}
	free(buff);
	return (remain_content(line, &store[fd], read_size)); //EOF처리
}
