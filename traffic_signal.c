// #include<reg51.h>
// sbit red = P2^0;
// sbit yellow = P2^1;
// sbit green = P2^2;
// void delay(int time);
// void main()
// {
// 	red = yellow = green = 0;
// 	while(1)
// 	{
// 		red = 1;
// 		delay(1000);
// 		red = 0;

// 		yellow = 1;
// 		delay(200);
// 		yellow = 0;

// 		green = 1;
// 		delay(1000);
// 		green = 0;
		
// 		yellow = 1;
// 		delay(200);
// 		yellow = 0;
// 	}
// }

// void delay(int time)
// {
// 	int i, j;
// 	for(i = 0; i < time; i++)
// 	{
// 		for(j = 0; j < 1000; j++)
// 		{
// 		}
// 	}
// }



#include <reg51.h>

sbit R1 = P1^0;   // Red light for Road 1
sbit Y1 = P1^1;   // Yellow light for Road 1
sbit G1 = P1^2;   // Green light for Road 1

sbit R2 = P1^3;   // Red light for Road 2
sbit Y2 = P1^4;   // Yellow light for Road 2
sbit G2 = P1^5;   // Green light for Road 2

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

void main() {
    while(1) {
        // Road 1: Green, Road 2: Red
        G1 = 1; Y1 = 0; R1 = 0;
        G2 = 0; Y2 = 0; R2 = 1;
        delay(300); // Green ON for Road 1

        // Road 1: Yellow, Road 2: Red
        G1 = 0; Y1 = 1; R1 = 0;
        G2 = 0; Y2 = 0; R2 = 1;
        delay(100); // Yellow ON for Road 1

        // Road 1: Red, Road 2: Green
        G1 = 0; Y1 = 0; R1 = 1;
        G2 = 1; Y2 = 0; R2 = 0;
        delay(300); // Green ON for Road 2

        // Road 1: Red, Road 2: Yellow
        G1 = 0; Y1 = 0; R1 = 1;
        G2 = 0; Y2 = 1; R2 = 0;
        delay(100); // Yellow ON for Road 2
    }
}
