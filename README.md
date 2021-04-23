# **analogueFreqReader**


A library for Arduino to receive an input analogue signal and read its frequency.

Forked from the AudioFrequencyMeter library by arduino-libraries

Copyright (c) The Eichen Group, 2021. All right reserved.

***

# _Methods_
* begin(uint32_t ulPin, uint32_t sampleRate) : initialize the ADC to sample ulPin at the chosen sample rate. This process works in interrupt using TC5 to start the sampling process. ADC resolution is set to 8 bit

* end() : stops the sampling process disabling both the ADC and TC5 and resetting TC5

* setClippingPin(int pin) : put pin in output to be used as a clipping indicator

* checkClipping : checks if there is a clipping event (converted value equals to the top or the bottom of the ADC dynamic) and drives HIGH the clippingPin

* setAmplitudeThreshold(uint8_t threshold) : sets the threshold for which a detected frequency is considered right or wrong. Default is 30

* setTimerTolerance(int tolerance)  : sets the tolerance for which a sampled signal is considered valid. Default is 10

* setSlopeTolerance(int tolerance) : sets the tolerance for which the slope is valid for the trigger process. Default is 3

* setBandwidth(float minFrequency, float maxFrequency) : set the range of frequencies for which the detected frequency is valid. Default values for now are 60 Hz - 1500 Hz. This must be improved

* getFrequency : return the value of the detected frequency if it is above the threshold defined by setAmplitudeThreshold, else -1
