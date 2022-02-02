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
