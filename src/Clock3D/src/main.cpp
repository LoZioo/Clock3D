#include <Arduino.h>

#include <const.h>
#include <proc.h>

int num = 1234;
uint8_t digits[DISPLAY_SEGMENTS];

void setup(){
	Serial.begin(115200);
	Serial.println("\n");

	pinMode(DATA_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);

	display_clear();
	delay(500);

	float copy = num;
	for(int i=DISPLAY_SEGMENTS-1; i>=0; i--){
		copy /= 10;
		digits[i] = (copy - floor(copy)) * 10;
		copy = floor(copy);
	}
}

void loop(){
	for(int i=0; i<DISPLAY_SEGMENTS; i++){
		display_write_number(digits[i], i);
		delay(8);
	}
}
