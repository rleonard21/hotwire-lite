# Hotwire Lite
## Overview
My original hotwire controller was relatively expensive per unit (~$60!).
After using the circuit extensively in the shop, I realized that the cost
could be reduced in several ways. The goal of this project is to build
the cheapest controller without compromising the original constant-power
functionality.

## Observations
1. The power, LCD, and PID settings were never changed after finding the
right values.
2. The rotary encoder was a bit delicate when wearing gloves.
3. The circuit was erroneously running at 244Hz PWM and 14Hz PID rates.

## Filtering
The PID controller needs to know the average current running through the
wire to effectively control the power output. The output is really a square
wave, so there needs to be some filtering to find the average. The original
controller did this in hardware with an expensive and bulky RC filter network.
The new controller will do this in hardware using a skipping average algorithm,
where ADC samples are only averaged when they are above a certain value. This
algorithm saves the cost of using a physical filter network.

## Component Optimization
Being the first circuit I ever made, the original controller was
over-engineered a bit. It used expensive components with great specifications,
even if the circuit didn't really need it. The new controller will use the
right component, trading off unused performance for lower cost.

## UART Data Output Format
The circuit continuously streams its current and voltage measurements over UART at a 1MHz buad. 
The format of the data is a comma-separated list formatted like so: `voltage,current,power`.
The units are `mV,mA,mW`.

## Calibration 
The circuit can be calibrated over UART using a very basic, lightweight interface.

```
C00-C30: calibrate the voltage divider to account for resistor tolerance. C15 is for ideal resistors.
P00-P99: set the power output, where the two digit number is the output in watts (P15 = 15W output).
```
