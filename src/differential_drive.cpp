/***********************************************************************************
 *  @file       differential_drive.cpp
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
#include "differential_drive.h"

void DifferentialDrive::init(uint8_t IN_1_A, uint8_t IN_2_A, uint8_t IN_1_B, uint8_t IN_2_B)
{
  motorRight.init(IN_1_A, IN_2_A);
  motorLeft.init(IN_1_B, IN_2_B) ;
}


void DifferentialDrive::differentialForPWM(float linear, float angular)
{
  _linear = linear;
  _angular = angular;
  
  if((angular==0) && (linear<0))
  {
    //backward
    motorLeft.backward(255);
    motorRight.backward(255); 
    
    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("backward");
    #endif
  }
  else if((angular==0) && (linear>0))
  {
    //forward
    motorLeft.forward(255);
    motorRight.forward(255);
    
    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("forward");
    #endif
  }
  else if((angular==-1) && (linear==0))
  {
    //turn left
    motorLeft.forward(255);
    motorRight.backward(255);
    
    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("turn left");
    #endif
  }
  else if((angular==1) && (linear==0))
  {
    //turn right
    motorRight.forward(255);
    motorLeft.backward(255);

    #if DEBUG_ENABLE ==1 
    debugObj.DEBUGLN("turn right");
    #endif
  }
  else if((angular==-1) && (linear>0))
  {
    //forward left
    motorRight.forward(255);
    motorLeft.forward(200);   
    
    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("forward left");
    #endif
  }
  else if((angular==1) && (linear>0))
  {
    //forward right
    motorLeft.forward(255);
    motorRight.forward(200); 

    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("forward right");
    #endif
  }
  else if((angular==-1) && (linear<0))
  {
    //backward left
    motorRight.backward(255);
    motorLeft.backward(200);  
    
    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("backward left"); 
    #endif  
  }
  else if((angular==1) && (linear<0))
  {
    //backward right    
    motorLeft.backward(255);
    motorRight.backward(200); 

    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("backward right ");       
    #endif 
  }
  else
  {
    motorRight.stop();
    motorLeft.stop();

    #if DEBUG_ENABLE ==1 
      debugObj.DEBUGLN("stop");
    #endif 
  }

}

float DifferentialDrive::getLinearValue()
{
	return _linear;
}

float DifferentialDrive::getAngularValue()
{
	return _angular;
}


