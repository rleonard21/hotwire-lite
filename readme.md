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

## Project Results

| Cost (single)     | Original Hotwire | Hotwire Lite |
|-------------------|------------------|--------------|
| PCB               | $5 (ALLPCB)      | $5 (PCBWay)  |
| Electrical        | ~$38             | $5.18        |
| Mechanical        | ~$20             | $0           |
| Total cost        | ~$63             | $10.18       |
| Bulk cost  (100)  | ?                | $3.71        |
| PCB assembly time | 1-1.5 hour       | <20 minutes  |
| Machining time    | 2-3 hours        | N/A          |

| Manufacturing Ease | Original Hotwire | Hotwire Lite |
|--------------------|------------------|--------------|
| # SMD              | 33               | 19           |
| # PTH              | 8                | 0            |
| Screws             | Yes              | No           |
| Machining required | Yes              | No           |

| Performance            | Original Hotwire | Hotwire Lite       |
|------------------------|------------------|--------------------|
| Output accuracy        | 0.5W             | 0.01W (calibrated) |
| Settling time          | seconds          | milliseconds       |
| PWM frequency          | 244Hz            | 1024Hz             |
| Control loop frequency | 14Hz             | 1KHz               |
| Calibration            | No               | Yes                |
| Data output            | No               | Yes                |

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
The circuit can be calibrated over UART using a very basic, lightweight interface. The user just needs
to send a three character command over the UART interface, which currently runs at 500k buad.

```
C00-C99: calibrate the voltage divider to account for resistor tolerance. C50 is for ideal resistors.
P00-P99: set the power output, where the two digit number is the output in watts (P15 = 15W output).
```
### Resistor Calibration Calculation
The resistor calibration is performed by measuring the true output voltage, reading the measured voltage over UART,
and performing the following calculation:

```c
resistor_divider = vcc_true / vcc_measured / 3
C_value = round(resistor_divider - 2.50, 2) * 100

calibration command = "C{C_value}"
```

#### Calibration Example:
```c
vcc_true = 13.993  // the voltage as measured by the multimeter
vcc_measured = 13.881  // the voltage as output over UART
resistor_divider = 13.993 / 13.881 / 3 = 3.024
C_value = round(3.024 - 2.50, 2) * 100 = 52

calibration command: "C52"
```
## Images
![The assembled v1.0 hardware.](https://i.imgur.com/zvXHNeN.jpg)
The assembled v1.0 hardware.

![A close up of the v1.0 hardware under test.](https://i.imgur.com/tFVCLMT.jpg)
A close up of the v1.0 hardware while testing.

![The four revisions of the hotwire controller project.](https://i.imgur.com/LIb4eDc.jpg)
The four revisions of the hotwire controller project between 2018 (top) and 2022 (bottom).

![The calibration station using a high power PCB resistor.](https://i.imgur.com/TFHVM7W.jpg)
The calibration station using a high power PCB resistor.

## References
[My original hotwire project](https://github.com/rleonard21/hotwire-controller)
