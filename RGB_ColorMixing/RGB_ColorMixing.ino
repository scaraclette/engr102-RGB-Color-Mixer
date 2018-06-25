1.  /* 
2.   * -Name: Gusti S. Halima 
3.   * -class: ENGR 102, Fall 2017 
4.   * -Project #1: Manual RGB LED Color Mixing 
5.   * -What it does: The RGB LED main color LEDs (red, green, blue) are seperated 
6.   * by individual buttons. Pressing the buttons simultaneously will mix the colors 
7.   */  
8.    
9.  //Creating arrays to store buttonPins and led pin values  
10. int buttonPins[] = {11, 12, 13}; //blue, green, red  
11. int led[] ={3, 4, 5}; //blue, green, red  
12.   
13. //variables to check the state of the buttons assigned for each led  
14. int redState, greenState, blueState;  
15.   
16. void setup() {  
17.   //individually assigned pins  
18.   pinMode(buttonPins[0], INPUT);  
19.   pinMode(buttonPins[1], INPUT);  
20.   pinMode(buttonPins[2], INPUT);  
21.   pinMode(led[0], OUTPUT);  
22.   pinMode(led[1], OUTPUT);  
23.   pinMode(led[2], OUTPUT);  
24.   
25.   /* 
26.    * Creating a loop to assign the LED outputs 
27.    * resulted a dim red LED, problem solved by 
28.    * individually assigning the LEDs 
29.    */  
30. }  
31.   
32. void loop() {  
33.   blueState = digitalRead(buttonPins[0]);  
34.   greenState = digitalRead(buttonPins[1]);  
35.   redState = digitalRead(buttonPins[2]);  
36.   
37. /* 
38.  * note that when a button's state is HIGH / 1 it actually turns 
39.  * off the LED (buttons are inverted by default, search web for more 
40.  * info). Either remeber this or change the buttons' pinMode from 
41.  * output to INPUT_PULLUP will turn LED on if buttons are HIGH / 1. 
42.  */  
43.   
44.   //if-else statement for default colors  
45.   if ((blueState == 0) && (greenState == 1) && (redState == 1)) {  
46.     lightLED(HIGH, LOW, LOW);  
47.   }  
48.   
49.   else if ((blueState == 1) && (greenState == 0) && (redState == 1)) {  
50.     lightLED(LOW, HIGH, LOW);  
51.   }  
52.   
53.   else if ((blueState == 1) && (greenState == 1) && (redState == 0)) {  
54.     lightLED(LOW, LOW, HIGH);  
55.   }  
56.     
57. //if- else conditionals to mix the colors  
58. /* 
59.  * Initially couldn't mix the colors inside the RGB LED from using a single 220 ohm 
60.  * resistor connected to the GND. Fixed by giving each LED their own reistor. 
61.  */  
62.   else if (blueState == 0 && redState == 0 && greenState == 1) { //red + blue  
63.     lightLED(1, 0, 1);  
64.   }  
65.   
66.   else if (blueState == 1 && redState == 0 && greenState == 0) { //red + green  
67.     lightLED(0, 1, 1);  
68.   }  
69.   
70.   else if (blueState == 0 && redState == 1 && greenState == 0) { //green + blue  
71.     lightLED(1, 0, 1);  
72.   }  
73.   
74.   else if (blueState == 0 && redState == 0 && greenState == 0) { //all  
75.     lightLED(1, 1, 1);  
76.   }  
77.   
78. //When all buttons are high (not pressed), the RGB LED is turned off by default  
79.   else {  
80.     lightLED(0, 0, 0);  
81.   }  
82. }  
83.   
84. /* 
85.  the following method reduces the redundancy 
86.  of typing digitalWrite() for each combinations. 
87.  */  
88. void lightLED(int b, int g, int r)   
89.   digitalWrite(led[0], b);  
90.   digitalWrite(led[1], g);  
91.   digitalWrite(led[2], r);  
92. }  

