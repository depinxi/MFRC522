#if !defined(__MFRC522BASE_H__)
#define __MFRC522BASE_H__

// Enable integer limits
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include "deprecated.h"

// Platform & devices

#define MFRC522_DEVICE_ARDUINO 	0x01

#define MFRC522_DEVICE_RASPBERRYPI 0x02
#define MFRC522_DEVICE_NANOPI 		0x04

#define MFRC522_DEVICE_FAMILY_PI	(MFRC522_DEVICE_RASPBERRYPI | MFRC522_DEVICE_NANOPI)

// C++11 backward compatibility
#if __cplusplus < 201103L
#	define MFRC522_ENUM_TYPE(name, type) typedef type name; enum name ## _values
#	if !defined (nullptr)
#		define nullptr NULL
#	endif
#	if !defined (override)
#		define override
#	endif
#else
#	define MFRC522_ENUM_TYPE(name, type) enum name : type
#endif

#if !defined(MFRC522_DEVICE)
#	define MFRC522_DEVICE MFRC522_DEVICE_ARDUINO
#endif

#if (MFRC522_DEVICE == MFRC522_DEVICE_ARDUINO)
#	include <Arduino.h>
#	include <SPI.h>
#	define MFRC522_STRING_TYPE 			__FlashStringHelper *
#	define MFRC522_STRING 				F
#	define MFRC522_CSTRING 				F
#	define MFRC522_SERIALPRINTF 			Serial.print
#	define MFRC522_SERIALPRINTF_LN(...) 	Serial.println(__VA_ARGS_)

#elif (MFRC522_DEVICE & MFRC522_DEVICE_FAMILY_PI)
#	include <string>
#	define MFRC522_STRING_TYPE 			::std::string
#	define MFRC522_STRING 				::std::string
#	define MFRC522_CSTRING
#	define MFRC522_SERIALPRINTF 			printf
#	define MFRC522_SERIALPRINTF_LN(...) 	{ printf("" __VA_ARGS__); printf ("\n"); }
#	include <string>
#	if !defined (PROGMEM)
#		define PROGMEM
#	endif
#	include <stdint.h>
typedef uint8_t byte;
typedef uint16_t word;

#else
#	error No platform defined
#endif

#endif // __MFRC522BASE_H__
