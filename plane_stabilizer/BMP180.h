// BMP180.h


#ifndef _BMP180_h
#define _BMP180_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SFE_BMP180.h>
#include "sensors.h"


double getPressure();

#endif



