#pragma once

#include <Arduino.h>

// GPIO.
#define DATA_PIN		D1
#define PWM_PIN			D2
#define LATCH_PIN		D4
#define CLOCK_PIN		D5

#define PWM_MIN_VAL	255
#define PWM_MAX_VAL	0

#define DISPLAY_DIGITS_LEN 18

// Binary encoded digits.
const uint8_t DISPLAY_DIGITS_BITS[] = {
  0x3F,		// 0
  0x06,		// 1
  0x5B,		// 2
  0x4F,		// 3
  0x66,		// 4
  0x6D,		// 5
  0x7D,		// 6
  0x07,		// 7
  0x7F,		// 8
  0x6F,		// 9
  0x77,		// A
  0x7C,		// B
  0x39,		// C
  0x5E,		// D
  0x79,		// E
  0x71,		// F
	0x40,		// '-'
	0x08		// '_'
};

// Segments per digit; DISPLAY_DIGITS_INTENSITIES indexes.
const uint8_t DISPLAY_DIGITS_SEGMENTS[] = {
  6,	// 0
  2,	// 1
  5,	// 2
  5,	// 3
  4,	// 4
  5,	// 5
  6,	// 6
  3,	// 7
  7,	// 8
  6,	// 9
  6,	// A
  5,	// B
  4,	// C
  5,	// D
  5,	// E
  4,	// F
	1,	// '-'
	1		// '_'
};

// Intensity percentages (10Ohm @ 5V).
const uint8_t DISPLAY_DIGITS_INTENSITIES[] = {
  0,		// 0	N/A
  78,		// 1	7.40
  82,		// 2	7.45
  88,		// 3	7.37
  88,		// 4	7.38
  94,		// 5	7.41
  97,		// 6	7.40
  100,	// 7, 7.38 V/led
};
