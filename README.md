


## C_binary_parsing_project
C를 이용해 데이터시트를 읽고 파싱하는 예제입니다. 

주어지는 114비트 데이터를 읽고 16비트별로 파싱해서 정보를 10진수로 출력합니다. 

![image](https://github.com/woodong11/C_parsing_project/assets/91379630/fa0622e8-bdb9-473e-82d8-3a1cbf589c64)


## C_firmware_person_app_project
C를 이용해 firmware, person app을 만들고 person app에서 signal을 보내 firmware에서 확인하는 예제입니다. <br>
person app 에는 추가로 WDT를 구현해, 자체적으로 alarm signal을 보내고 3초간 입력이 없으면 프로세스를 둘 다 종료합니다. 

<b>build </b>
```
gcc firmware.c -o ./firmware && gcc person.c -o ./person
```
<b>run</b><br>
`./firmware` 실행 후 출력되는 firmware의 pid 확인 <br>
`./person fimeware의PID` 실행 <br>
person에서 1, 2, 3, exit 중 입력 <br>

<br><br>

## C_minning_project
Thread를 이용해 채굴기를 생성, 삭제할 수 있는 예제입니다. <br>
각 Thread는 0.1초에 1씩 전역변수 "coin"을 증가시킵니다. <br>
add 명령 시 채굴기 추가, del 명령 시 오래된 채굴기부터 삭제합니다. <br>
coin 접근시 mutex를 추가 활용했습니다.
<br><br>
<b>build</b>
```
gcc minning.c -o ./gogo -lpthread
```
<br><br>

## C_shell_project
history, date, uptime, ls 기능이 있는 shell 예제입니다. 
