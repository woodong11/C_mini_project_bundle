


## C_binary_parsing_project
C를 이용해 데이터시트를 읽고 파싱하는 예제입니다. 

주어지는 114비트 데이터를 읽고 16비트별로 파싱해서 정보를 10진수로 출력합니다. 

![image](https://github.com/woodong11/C_parsing_project/assets/91379630/fa0622e8-bdb9-473e-82d8-3a1cbf589c64)

## C_minning_project
Thread를 이용해 채굴기를 생성, 삭제할 수 있는 예제입니다. <br>
각 Thread는 0.1초에 1씩 전역변수 "coin"을 증가시킵니다. <br>
coin 접근시 mutex를 추가 활용했습니다.
<br><br>
build:
```
gcc minning.c -o ./gogo -lpthread
```

## C_shell_project
history, date, uptime, ls 기능이 있는 shell 예제입니다. 
