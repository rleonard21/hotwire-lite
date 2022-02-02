EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny402-SS MCU1
U 1 1 61F8B5AA
P 5150 2950
F 0 "MCU1" H 4621 2996 50  0000 R CNN
F 1 "ATtiny402-SS" H 4621 2905 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5150 2950 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny202-402-AVR-MCU-with-Core-Independent-Peripherals_and-picoPower-40001969A.pdf" H 5150 2950 50  0001 C CNN
	1    5150 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 61F8D340
P 3300 2250
F 0 "C2" H 3392 2296 50  0000 L CNN
F 1 "1uF" H 3392 2205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3300 2250 50  0001 C CNN
F 3 "~" H 3300 2250 50  0001 C CNN
	1    3300 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR01
U 1 1 61F90ED0
P 2800 2550
F 0 "#PWR01" H 2800 2300 50  0001 C CNN
F 1 "GNDREF" H 2805 2377 50  0000 C CNN
F 2 "" H 2800 2550 50  0001 C CNN
F 3 "" H 2800 2550 50  0001 C CNN
	1    2800 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 61F9D699
P 2300 2250
F 0 "C1" H 2392 2296 50  0000 L CNN
F 1 "1uF" H 2392 2205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2300 2250 50  0001 C CNN
F 3 "~" H 2300 2250 50  0001 C CNN
	1    2300 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2050 5150 2350
$Comp
L power:GNDREF #PWR04
U 1 1 61FA36CC
P 5150 3700
F 0 "#PWR04" H 5150 3450 50  0001 C CNN
F 1 "GNDREF" H 5155 3527 50  0000 C CNN
F 2 "" H 5150 3700 50  0001 C CNN
F 3 "" H 5150 3700 50  0001 C CNN
	1    5150 3700
	1    0    0    -1  
$EndComp
Connection ~ 4400 2050
Wire Wire Line
	4400 2050 5150 2050
Wire Wire Line
	5150 3550 5150 3700
Wire Wire Line
	5150 2050 5900 2050
Connection ~ 5150 2050
Wire Wire Line
	5900 2350 5900 2650
Wire Wire Line
	5900 2650 5750 2650
Wire Wire Line
	5900 2050 5900 2150
$Comp
L Device:R_Small_US R3
U 1 1 61FA97A8
P 5900 2250
F 0 "R3" H 5968 2296 50  0000 L CNN
F 1 "10k" H 5968 2205 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 5900 2250 50  0001 C CNN
F 3 "~" H 5900 2250 50  0001 C CNN
	1    5900 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Barrel_Jack J1
U 1 1 61FAFD02
P 1450 2150
F 0 "J1" H 1507 2475 50  0000 C CNN
F 1 "Barrel_Jack" H 1507 2384 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_CLIFF_FC681465S_SMT_Horizontal" H 1500 2110 50  0001 C CNN
F 3 "~" H 1500 2110 50  0001 C CNN
	1    1450 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2250 1950 2250
Wire Wire Line
	1950 2250 1950 2450
$Comp
L Transistor_FET:Si4162DY Q1
U 1 1 61FBC2EA
P 7400 3000
F 0 "Q1" H 7605 3046 50  0000 L CNN
F 1 "Si4162DY" H 7605 2955 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7600 2900 50  0001 L CNN
F 3 "http://www.vishay.com/docs/68967/si4162dy.pdf" H 7400 3000 50  0001 L CNN
	1    7400 3000
	1    0    0    -1  
$EndComp
Text Label 1850 2050 0    50   ~ 0
vin
$Comp
L power:GNDREF #PWR05
U 1 1 61FC14D4
P 7500 3450
F 0 "#PWR05" H 7500 3200 50  0001 C CNN
F 1 "GNDREF" H 7505 3277 50  0000 C CNN
F 2 "" H 7500 3450 50  0001 C CNN
F 3 "" H 7500 3450 50  0001 C CNN
	1    7500 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 3450 7500 3200
$Comp
L Device:R_Small_US R4
U 1 1 61FC5936
P 7500 1850
F 0 "R4" H 7568 1896 50  0000 L CNN
F 1 "R_Small_US" H 7568 1805 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric" H 7500 1850 50  0001 C CNN
F 3 "~" H 7500 1850 50  0001 C CNN
	1    7500 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1950 7500 2000
$Comp
L Amplifier_Current:INA181 U2
U 1 1 61FC6B9C
P 8850 1850
F 0 "U2" H 9194 1896 50  0000 L CNN
F 1 "INA181" H 9194 1805 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 8900 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ina181.pdf" H 9000 2000 50  0001 C CNN
	1    8850 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2000 8350 2000
Wire Wire Line
	8350 2000 8350 1950
Wire Wire Line
	8350 1950 8550 1950
Connection ~ 7500 2000
Wire Wire Line
	8550 1750 8350 1750
Wire Wire Line
	8350 1750 8350 1700
Wire Wire Line
	8350 1700 7500 1700
Wire Wire Line
	7500 1700 7500 1750
Text Label 7500 1600 0    50   ~ 0
vin
Wire Wire Line
	7500 1600 7500 1700
Connection ~ 7500 1700
$Comp
L power:GNDREF #PWR06
U 1 1 61FCC653
P 8750 2250
F 0 "#PWR06" H 8750 2000 50  0001 C CNN
F 1 "GNDREF" H 8755 2077 50  0000 C CNN
F 2 "" H 8750 2250 50  0001 C CNN
F 3 "" H 8750 2250 50  0001 C CNN
	1    8750 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR07
U 1 1 61FCCE96
P 8950 2250
F 0 "#PWR07" H 8950 2000 50  0001 C CNN
F 1 "GNDREF" H 8955 2077 50  0000 C CNN
F 2 "" H 8950 2250 50  0001 C CNN
F 3 "" H 8950 2250 50  0001 C CNN
	1    8950 2250
	1    0    0    -1  
$EndComp
Text Label 3350 2050 0    50   ~ 0
vcc
Text Label 8750 1400 0    50   ~ 0
vcc
Wire Wire Line
	8750 1400 8750 1500
$Comp
L Device:C_Small C4
U 1 1 61FD6570
P 9200 1500
F 0 "C4" H 9292 1546 50  0000 L CNN
F 1 "0.1uF" H 9292 1455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9200 1500 50  0001 C CNN
F 3 "~" H 9200 1500 50  0001 C CNN
	1    9200 1500
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDREF #PWR08
U 1 1 61FD6576
P 9450 1500
F 0 "#PWR08" H 9450 1250 50  0001 C CNN
F 1 "GNDREF" H 9455 1327 50  0000 C CNN
F 2 "" H 9450 1500 50  0001 C CNN
F 3 "" H 9450 1500 50  0001 C CNN
	1    9450 1500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9300 1500 9450 1500
Wire Wire Line
	8750 1500 9100 1500
Connection ~ 8750 1500
Wire Wire Line
	8750 1500 8750 1550
Text Label 7100 3000 2    50   ~ 0
pwm_output
Wire Wire Line
	7100 3000 7150 3000
Text Label 9500 1850 0    50   ~ 0
current_sense
Wire Wire Line
	9500 1850 9400 1850
Wire Wire Line
	2300 3200 2300 3300
$Comp
L Device:R_Small_US R1
U 1 1 61FE23AA
P 2300 3400
F 0 "R1" H 2368 3446 50  0000 L CNN
F 1 "10k" H 2368 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 2300 3400 50  0001 C CNN
F 3 "~" H 2300 3400 50  0001 C CNN
	1    2300 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R2
U 1 1 61FE42C4
P 2300 3700
F 0 "R2" H 2368 3746 50  0000 L CNN
F 1 "10k" H 2368 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 2300 3700 50  0001 C CNN
F 3 "~" H 2300 3700 50  0001 C CNN
	1    2300 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR02
U 1 1 61FEB60F
P 2300 3900
F 0 "#PWR02" H 2300 3650 50  0001 C CNN
F 1 "GNDREF" H 2305 3727 50  0000 C CNN
F 2 "" H 2300 3900 50  0001 C CNN
F 3 "" H 2300 3900 50  0001 C CNN
	1    2300 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3500 2300 3550
Wire Wire Line
	2300 3800 2300 3900
Text Label 2400 3550 0    50   ~ 0
voltage_sense
Wire Wire Line
	2400 3550 2300 3550
Connection ~ 2300 3550
Wire Wire Line
	2300 3550 2300 3600
Text Label 2300 3200 0    50   ~ 0
vin
Text Label 5900 3050 0    50   ~ 0
tx_led
Wire Wire Line
	5900 3050 5750 3050
Wire Wire Line
	5750 3150 5900 3150
Text Label 5900 2650 0    50   ~ 0
UPDI
Wire Notes Line
	2000 3000 2000 4300
Wire Notes Line
	2000 4300 3100 4300
Wire Notes Line
	3100 4300 3100 3000
Wire Notes Line
	3100 3000 2000 3000
$Comp
L power:GNDREF #PWR03
U 1 1 61FA3228
P 4400 2500
F 0 "#PWR03" H 4400 2250 50  0001 C CNN
F 1 "GNDREF" H 4405 2327 50  0000 C CNN
F 2 "" H 4400 2500 50  0001 C CNN
F 3 "" H 4400 2500 50  0001 C CNN
	1    4400 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 62065050
P 4400 2300
F 0 "C3" H 4492 2346 50  0000 L CNN
F 1 "1uF" H 4492 2255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4400 2300 50  0001 C CNN
F 3 "~" H 4400 2300 50  0001 C CNN
	1    4400 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2050 4400 2200
Wire Wire Line
	4400 2400 4400 2500
Wire Wire Line
	2800 2550 2800 2450
Connection ~ 2800 2450
Wire Wire Line
	2800 2350 2800 2450
Wire Wire Line
	8750 2150 8750 2250
Wire Wire Line
	8950 2150 8950 2250
Text Label 5900 2750 0    50   ~ 0
pwm_output
Wire Wire Line
	5900 2750 5750 2750
Text Label 5900 2950 0    50   ~ 0
current_sense
Text Label 5900 2850 0    50   ~ 0
voltage_sense
Wire Wire Line
	5750 2850 5900 2850
Wire Wire Line
	5750 2950 5900 2950
$Comp
L Connector:TestPoint vin1
U 1 1 61FA1C8A
P 2300 1900
F 0 "vin1" H 2358 2018 50  0000 L CNN
F 1 "TestPoint" H 2358 1927 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 2500 1900 50  0001 C CNN
F 3 "~" H 2500 1900 50  0001 C CNN
	1    2300 1900
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint reg1
U 1 1 61FA2EC8
P 3300 1900
F 0 "reg1" H 3358 2018 50  0000 L CNN
F 1 "TestPoint" H 3358 1927 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 3500 1900 50  0001 C CNN
F 3 "~" H 3500 1900 50  0001 C CNN
	1    3300 1900
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint amp1
U 1 1 61FA4F98
P 9400 2050
F 0 "amp1" H 9342 2076 50  0000 R CNN
F 1 "TestPoint" H 9342 2167 50  0000 R CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 9600 2050 50  0001 C CNN
F 3 "~" H 9600 2050 50  0001 C CNN
	1    9400 2050
	-1   0    0    1   
$EndComp
$Comp
L Connector:TestPoint pwm1
U 1 1 61FA6F0F
P 7150 2850
F 0 "pwm1" H 7208 2968 50  0000 L CNN
F 1 "TestPoin" H 7208 2877 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 7350 2850 50  0001 C CNN
F 3 "~" H 7350 2850 50  0001 C CNN
	1    7150 2850
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint volt1
U 1 1 61FA928F
P 2250 3550
F 0 "volt1" V 2445 3622 50  0000 C CNN
F 1 "TestPoint" V 2354 3622 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 2450 3550 50  0001 C CNN
F 3 "~" H 2450 3550 50  0001 C CNN
	1    2250 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9400 2050 9400 1850
Connection ~ 9400 1850
Wire Wire Line
	9400 1850 9150 1850
Wire Wire Line
	7150 2850 7150 3000
Connection ~ 7150 3000
Wire Wire Line
	7150 3000 7200 3000
Wire Wire Line
	2250 3550 2300 3550
$Comp
L Device:LED D1
U 1 1 61FA3AE9
P 4600 4350
F 0 "D1" V 4639 4232 50  0000 R CNN
F 1 "LED" V 4548 4232 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 4600 4350 50  0001 C CNN
F 3 "~" H 4600 4350 50  0001 C CNN
	1    4600 4350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R5
U 1 1 61FA52F2
P 4600 4750
F 0 "R5" H 4668 4796 50  0000 L CNN
F 1 "220" H 4668 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 4600 4750 50  0001 C CNN
F 3 "~" H 4600 4750 50  0001 C CNN
	1    4600 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0101
U 1 1 61FB209B
P 7050 4850
F 0 "#PWR0101" H 7050 4600 50  0001 C CNN
F 1 "GNDREF" H 7055 4677 50  0000 C CNN
F 2 "" H 7050 4850 50  0001 C CNN
F 3 "" H 7050 4850 50  0001 C CNN
	1    7050 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0102
U 1 1 61FB3571
P 4600 4950
F 0 "#PWR0102" H 4600 4700 50  0001 C CNN
F 1 "GNDREF" H 4605 4777 50  0000 C CNN
F 2 "" H 4600 4950 50  0001 C CNN
F 3 "" H 4600 4950 50  0001 C CNN
	1    4600 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 4650 7050 4650
Text Label 6100 4650 2    50   ~ 0
rx_button
Text Label 5900 3150 0    50   ~ 0
rx_button
Wire Wire Line
	4600 4950 4600 4850
Text Label 4600 4100 2    50   ~ 0
tx_led
Wire Wire Line
	4600 4500 4600 4650
Wire Wire Line
	4600 4100 4600 4200
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 61FE84AE
P 6250 5700
F 0 "J4" H 6330 5692 50  0000 L CNN
F 1 "Conn_01x04" H 6330 5601 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6250 5700 50  0001 C CNN
F 3 "~" H 6250 5700 50  0001 C CNN
	1    6250 5700
	1    0    0    -1  
$EndComp
Text Label 5750 5600 2    50   ~ 0
UPDI
Text Label 5750 5700 2    50   ~ 0
rx_button
Text Label 5750 5800 2    50   ~ 0
tx_led
$Comp
L power:GNDREF #PWR0103
U 1 1 61FEB83F
P 5750 5950
F 0 "#PWR0103" H 5750 5700 50  0001 C CNN
F 1 "GNDREF" H 5755 5777 50  0000 C CNN
F 2 "" H 5750 5950 50  0001 C CNN
F 3 "" H 5750 5950 50  0001 C CNN
	1    5750 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 5600 6050 5600
Wire Wire Line
	5750 5700 6050 5700
Wire Wire Line
	5750 5800 6050 5800
Wire Wire Line
	6050 5900 5750 5900
Wire Wire Line
	5750 5900 5750 5950
$Comp
L Connector:Screw_Terminal_01x02 J5
U 1 1 61FF9D1B
P 1600 2650
F 0 "J5" H 1518 2325 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 1518 2416 50  0000 C CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x02_P3.50mm_Horizontal" H 1600 2650 50  0001 C CNN
F 3 "~" H 1600 2650 50  0001 C CNN
	1    1600 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	1800 2550 1850 2550
Wire Wire Line
	1850 2550 1850 2050
Connection ~ 1850 2050
Wire Wire Line
	1850 2050 1750 2050
Wire Wire Line
	1800 2650 1950 2650
Wire Wire Line
	1950 2650 1950 2450
Connection ~ 1950 2450
Wire Wire Line
	1850 2050 2300 2050
Wire Wire Line
	1950 2450 2300 2450
Wire Wire Line
	2300 2350 2300 2450
Connection ~ 2300 2450
Wire Wire Line
	2300 2450 2800 2450
Wire Wire Line
	2300 2050 2300 1900
Connection ~ 2300 2050
Wire Wire Line
	2300 2050 2500 2050
Wire Wire Line
	2300 2150 2300 2050
Wire Wire Line
	3100 2050 3300 2050
Wire Wire Line
	3300 2450 3300 2350
Wire Wire Line
	2800 2450 3300 2450
Wire Wire Line
	3300 2150 3300 2050
Connection ~ 3300 2050
Wire Wire Line
	3300 2050 4400 2050
Wire Wire Line
	3300 2050 3300 1900
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 6204FD0C
P 7750 2500
F 0 "J2" H 7830 2492 50  0000 L CNN
F 1 "Conn_01x02" H 7830 2401 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7750 2500 50  0001 C CNN
F 3 "~" H 7750 2500 50  0001 C CNN
	1    7750 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2500 7500 2500
Wire Wire Line
	7500 2000 7500 2500
Wire Wire Line
	7550 2600 7500 2600
Wire Wire Line
	7500 2600 7500 2800
$Comp
L Regulator_Linear:AP1117-50 U1
U 1 1 62085323
P 2800 2050
F 0 "U1" H 2800 2292 50  0000 C CNN
F 1 "AP1117-50" H 2800 2201 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2800 2250 50  0001 C CNN
F 3 "http://www.diodes.com/datasheets/AP1117.pdf" H 2900 1800 50  0001 C CNN
	1    2800 2050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 6208A8D0
P 6600 4650
F 0 "SW1" H 6600 4935 50  0000 C CNN
F 1 "SW_Push" H 6600 4844 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_PTS645" H 6600 4850 50  0001 C CNN
F 3 "~" H 6600 4850 50  0001 C CNN
	1    6600 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4650 6400 4650
Wire Wire Line
	7050 4650 7050 4850
Text Label 7500 2750 0    50   ~ 0
output_return
$EndSCHEMATC
