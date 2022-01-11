/***********************************************************************************
 *  @file       differential_drive.h
 *  Project     differential_drive
 *  @brief      Arduino Due library for differential control.
 *
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug 		 No known bugs.
 *  License     MIT
 *
 *  @section License
 *
 * Copyright (c) 2021 SciCoBot
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**********************************************************************************/

 #ifndef DIFFERENTIAL_DRIVE_H
#define DIFFERENTIAL_DRIVE_H

 #include <Arduino.h>
#include <simple_motor_dc.h>

#define DIFFERENTIAL_DRIVE_DEBUG 0 // Debug mode

#if DIFFERENTIAL_DRIVE_DEBUG == 1
 	#include "../include/serial_debug/src/serial_debug.h"
#endif

//Pins Motor
#define IN1_A 7
#define IN2_A 6

//Pins Motor
#define IN2_B 5
#define IN1_B 4

class DifferentialDrive
{
	public:
		void init(uint8_t IN_1_A = IN1_A, uint8_t IN_2_A = IN2_A, 
					uint8_t IN_1_B = IN1_B, uint8_t IN_2_B = IN2_B);
		void differentialForPWM(float linear, float angular);
		float getLinearValue();
		float getAngularValue();
	
	private:
		float _linear;
		float _angular;
		
		SimpleMotor motorRight;
		SimpleMotor motorLeft;
};
#endif //DIFFERENTIAL_DRIVE_H

