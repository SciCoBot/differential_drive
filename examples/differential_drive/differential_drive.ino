/***********************************************************************************
 *  @file       differential_drive.ino
 *  Project     Motor-Control
 *  @brief      Arduino Due library for controlling two DC motors
 *
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug 		 No known bugs.
 *  License     GNU Affero General Public License v3.0
 *
 *  @section License
 *
 *  Copyright (c) 2021 Otavio
 *
 * This file is part of Motor-Control.

 *	Motor-Control is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version.

 * Motor-Control is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with Motor-Control. If not, see <https://www.gnu.org/licenses/>
 **********************************************************************************/
#include <differential_drive.h>

PwmValues pwm;

DifferentialValues differential;

void move(float v, float w)
{
  if((w==-1) && (v==0))
  {
    //gira em torno de si para a direita
  }
  else if((w==1) && (v==0))
  {
    //gira em torno de si para a esquerda
  }
  else if((w==0) && (v==0.5))
  {
    //frente
  }
  else if((w==0) && (v==-0.5))
  {
    //ré
  }
  else if((w==1) && (v==0.5))
  {
    //frente inclinado para esquerda
  }  
  else if((w==-1) && (v==0.5))
  {
    //frente inclinado para direita
  }  
  else if((w==1) && (v==-0.5))
  {
    //ré inclinado para direita
  }  
  else if((w==-1) && (v==-0.5))
  {
    //ré inclinado para esquerda
  }  
    
}

void setup() 
{
  Serial.begin(9600);
  
  pwm._pwmLeft = 0;
  pwm._pwmRight = 0;
  
  differential._wheelLeft = 0;
  differential._wheelRight = 0;
  
  convertDifferential(1, 0, differential);
  Serial.print("Differential left");
  Serial.println(differential._wheelLeft);
  Serial.print("Differential right ");
  Serial.println(differential._wheelRight);
  
  differentialForPWM(differential, pwm);
  Serial.print("PWM left ");
  Serial.println(pwm._pwmLeft);
  Serial.print("PWM right ");
  Serial.println(pwm._pwmRight);  
}

void loop() 
{
  

}
