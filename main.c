#include<stdio.h>
#include<stdint.h>

int main(){
	FILE* fp = fopen("binary", "r");

	// 문제의 데이터시트에 몸무게는 16Bit, 유니크 ID는 96Bit다.
	// 16 + 96 = 112 bit -> 14 Byte
	uint8_t buf[14];
	fread(buf, 1, 14, fp);
	fclose(fp);

	// 제일 처음 Address 설정
	uint8_t* startAddress = &buf;


	// weight 읽기
	uint8_t* baseAddress = startAddress + 0x00;
	uint16_t weight = baseAddress[0] | (baseAddress[1] << 8);

	// 첫 번째 UniqueID 읽기
	baseAddress = startAddress + 0x02;
	uint16_t pass = baseAddress[0] | (baseAddress[1] << 8);

	// 두 번째 UniqueID 읽기
	baseAddress = startAddress + 0x04;
	uint16_t salary = baseAddress[0] | (baseAddress[1] << 8);

	// 세 번째 UniqueID 읽기
	baseAddress = startAddress + 0x06;
	uint16_t food = baseAddress[0] | (baseAddress[1] << 8);

	// 네 번째 UniqueID 읽기
	baseAddress = startAddress + 0x08;
	uint16_t drink = baseAddress[0] | (baseAddress[1] << 8);


	// 출력
	printf("weight : %u KG \n", weight);
	printf("password : %u \n", pass);
	printf("salary : %u $ \n", salary);
	printf("food number: %u \n", food);
	printf("drink number: %u \n", drink);


	return 0;
}
