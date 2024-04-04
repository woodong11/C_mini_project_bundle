


## 1. C_binary_parsing_project
C를 이용해 데이터시트를 읽고 파싱하는 예제입니다. 

주어지는 114비트 데이터를 읽고 16비트별로 파싱해서 정보를 10진수로 출력합니다. 

![image](https://github.com/woodong11/C_parsing_project/assets/91379630/fa0622e8-bdb9-473e-82d8-3a1cbf589c64)

## 2. C_chatroom_project
C socket 통신과 멀티스레드를 이용해 다수의 유저가 서버에 접속 후 채팅할 수 있는 예제입니다. <br>
![11](https://github.com/woodong11/C_mini_project_bundle/assets/91379630/cc7c2223-16d1-47d0-96bf-50ab63d9e560)
<br><br>
<b>build </b>
```
gcc chat_client.c -o ./client -lpthread
gcc chat_server.c -o ./server -lpthread
```
<b>run</b><br>

서버용 터미널을 켜고, 클라이언트로 접속할 PC에서 클라이언트용 터미널을 켭니다. <br>
서버용 터미널:  `./server 사용할PORT` ex) ./server 12345 <br>
클라이언트 터미널들:  `./client 서버의IP주소 사용할PORT 사용자이름` ex) ./client 127.0.0.1  12345 lee<br>
[참고] server가 local일 경우 server IP주소는 127.0.0.1입니다. <br>
이후 클라이언트에서 메시지를 입력하면 모든 클라이언트가 채팅 내용을 확인할 수 있습니다. <br>
<br><br>

## 3. C_firmware_person_app_project
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

## 4. C_minning_project
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

## 5. C_shell_project
history, date, uptime, ls 기능이 있는 shell 예제입니다. 
<br><br>

## 6. C_walkie_talkie_project
socket통신을 이용해 서버와 클라이언트간 무전기를 구현하는 예제입니다. <br>
Server부터 먼저 메시지를 보내야 하고, 그 다음 클라이언트가 보내고 번갈아가면서 메시지를 보냅니다. <br>
문자열메시지는 그대로 출력, 숫자메시지라면 x2해서 출력합니다. <br>
![도전3](https://github.com/woodong11/C_mini_project_bundle/assets/91379630/949f1bed-1d9d-4c65-a179-892b30ec5486)
<br><br>
<b>build </b>
```
gcc client.c -o ./client && gcc server.c -o ./server
```
<b>run</b><br>

open two terminal window <br>
첫 번째 터미널:  `./server 사용할PORT` ex) ./server 12345 <br>
두 번째 터미널:  `./client 서버의IP주소 사용할PORT` ex) ./client 127.0.0.1  12345 <br>
[참고] server가 local일 경우 server IP주소는 127.0.0.1입니다. <br>
server 메시지 입력 후 엔터 -> client 메시지 입력 후 엔터 -> ... 번갈아가며 반복 <br>

<br><br>







