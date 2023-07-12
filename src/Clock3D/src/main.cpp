#include <Arduino.h>

#include <const.h>
#include <proc.h>

uint8_t num = 0;

void setup(){
	Serial.begin(115200);
	Serial.println("\n");

	pinMode(DATA_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);

	display_clear();
	delay(500);
}

void loop(){
	for(int i=0; i<DISPLAY_DIGITS_LEN; i++){
		display_write_number(i);
		delay(500);
	}
}
