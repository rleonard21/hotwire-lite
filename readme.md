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
3. The circuit was erroneously running at 244Hz PWM and 14Hz PID rates and took several seconds to settle.

## Filtering
The PID controller needs to know the average current running through the
wire to effectively control the power output. The output is really a square
wave, so there needs to be some filtering to find the average. The original
controller did this in hardware with an expensive and bulky RC filter network.
The new circuit performs this in a clever manner. Instead of free running the ADC
and measuring the entire signal, the ADC is trigged only on the rising edge of the 
PWM signal. Therefore, the ADC only ever measures the maximum current in the circuit.
Multiplying this number by the duty cycle results in the average current. 
This operation is be performed much faster than the old circuit (1KHz vs. 14Hz).

## Component Optimization
Being the first circuit I ever made, the original controller was
over-engineered a bit. It used expensive components with great specifications,
even if the circuit didn't really need it. The new controller uses the
right components, trading off unused performance for lower cost.

## UART Data Output Format
The circuit continuously streams its current and voltage measurements over UART at a 1MHz buad. 
The format of the data is a comma-separated list formatted like so: `voltage,current,power,duty_cycle`.
The units are `mV,mA,mW,%*1000`.

## Calibration 
### Calibration Interface
The circuit can be calibrated over UART using a very basic, lightweight interface.

```
C00-C99: calibrate the voltage divider to account for resistor tolerance. C50 is for ideal resistors.
P00-P99: set the power output, where the two digit number is the output in watts (P15 = 15W output).
```
### Resistor Calibration Calculation
The resistor calibration is performed by measuring the true output voltage, reading the measured voltage over UART,
and performing the following calculation:

```
resistor_divider = vcc_true / vcc_measured / 3
C_value = round(resistor_divider - 2.50, 2) * 100

calibration command = "C{C_value}"
```

#### Calibration Example:
```
vcc_true = 13.993		// the voltage as measured by the multimeter
vcc_measured = 13.881	// the voltage as output over UART
resistor_divider = 13.993 / 13.881 / 3 = 3.024
C_value = round(3.024 - 2.50, 2) * 100 = 52

calibration command: "C52"
```
