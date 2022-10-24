# Philosophers

식사하는 철학자 문제를 해결하는 프로그램을 작성해 보자.   

### Contents
Deadlock이란 무엇이고 피하기 위한 방법은?   
Data Race를 피하기 위해서는 어떻게 해야하는가?   
- Critical Section이란?
- Mutex
- Semaphore

### Usage
``` Bash
# Compile
make

# Execute
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Rules
- `time_to_die` : 철학자가 마지막 식사나 simulation 시작 이후 time_to_die 시간이 지날때까지 식사를 하지 않으면 죽게 된다.

- `time_to_eat` : 철학자가 식사를 하는데 소요되는 시간, 식사하는 동안은 2개의 포크를 들고 있어야 한다.

- `time_to_sleep` : 철학자가 자는데 소요하는 시간

- `number_of_times_each_philosopher_must_eat` : optional, 모든 철학자가 이 수만큼 식사를 하면 시물레이션은 종료된다. 명시되어 있지 않으면, 시물레이션은 철학자가 죽을 때까지 계속 진행된다.

- 철학자들은 원형 테이블에 앉아있으며, 철학자들의 수만큼 포크가 놓여있다. 

- 철학자가 식사, 생각, 잠을 자거나, 죽는 경우 로그를 출력해야 한다.
