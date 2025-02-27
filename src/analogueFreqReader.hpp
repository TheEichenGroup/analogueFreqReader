/**************************************************************************************************
  analogueFreqReader library for Arduino.
  Copyright (c) 2021 The Eichen Group. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA


  Thanks to Arduino LLC
  for the ArduinoFrequencyMeter library published on GitHub.
**************************************************************************************************/


#include "Arduino.h"
#include "wiring_private.h"

#pragma once

#define DEFAULT_AMPLITUDE_THRESHOLD     30
#define DEFAULT_TIMER_TOLERANCE         10
#define DEFAULT_SLOPE_TOLERANCE         3
#define DEFAULT_MIN_FREQUENCY           60.00
#define DEFAULT_MAX_FREQUENCY           1500.00

bool ADCisSyncing(void);
uint8_t ADCread();

class analogueFreqReader
{
  public:

    analogueFreqReader();

    void begin(uint8_t &pin, uint32_t &sampleRate);
    void end(void);

    void setClippingPin(int pin);
    void checkClipping(void);

    void setAmplitudeThreshold(int threshold);
    void setTimerTolerance(int tolerance);
    void setSlopeTolerance(int tolerance);
    void setBandwidth(float minFrequency, float maxFrequency);

    float getHzA(void);
    inline float getKHzA(void) { return (getHz()/1000); }
    inline float getMHzA(void) { return (getHz()/1000000); }

  private:
    void initializeVariables(void);
    void ADCconfigure();
    void ADCenable(void);
    void ADCdisable(void);
    void ADCsetMux(void);

    void tcConfigure(void);
    bool tcIsSyncing(void);
    void tcEnable(void);
    void tcDisable(void);
    void tcReset(void);

  private:
    int samplePin;           // Pin used to sample the signal
    unsigned int sampleRate; // ADC sample rate

    int amplitudeThreshold;

    float minFrequency;      // Variable to store the minimum frequency that can be applied in input
    float maxFrequency;      // Variable to store the maximum frequency that can be applied in input
};
