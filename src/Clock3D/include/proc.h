#pragma once

#include <Arduino.h>
#include <const.h>

void display_clear(){
	analogWrite(PWM_PIN, PWM_MAX_VAL);
	digitalWrite(LATCH_PIN, HIGH);
	shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
	digitalWrite(LATCH_PIN, LOW);
}

void display_write_number(uint8_t num){
	num = constrain(num, 0, DISPLAY_DIGITS_LEN);

	const uint8_t digit = DISPLAY_DIGITS_BITS[num];
	const uint16_t intensity = map(DISPLAY_DIGITS_INTENSITIES[DISPLAY_DIGITS_SEGMENTS[num]], 0, 100, PWM_MIN_VAL, PWM_MAX_VAL);

	analogWrite(PWM_PIN, PWM_MIN_VAL);
	digitalWrite(LATCH_PIN, HIGH);
	shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, digit);
	digitalWrite(LATCH_PIN, LOW);
	analogWrite(PWM_PIN, intensity);
}
