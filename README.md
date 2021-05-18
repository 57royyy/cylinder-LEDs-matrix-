# cylinder-LEDs-matrix-

This is the code of the project. Everything is done on Arduino. This code enables to :
- form a matrix of numbers
- spin it around the cylinder at the desired speed
- set time manually using buttons (it isn't connected to any other devices to calculate the time)
- switch from on color to another of the desired list, also with a button


So in the code, in order we have:
- all the libraries that we need
- the definition of all the pins 
- a function 'Colors' to switch between the colors of a list, depending of C, the variable. The colors are defined in RGB 
- a function 'Values' to put the time in the right format (24hours) : add a 0 if necessary and make sure the time stays in the range; and also put the resulting time in a string
- the initialisation of the matrix : adjusting Top/Bottom Right/Left Columns/Rows ZigZag/Progressive, according to the arrangement of the LED's strips
- In the setup : 
     - the matrix start, it automaticaly starts at ' 00 : 00 '
     - each button is connected to a input pullout pin, to avoid short circuit without using resistors
- In the loop : 
     - a while loop to set the time and color while the 'parameter button' is pressed
     - each press adds 1 to the desired variable: 'hournbr' for hours, 'minutenbr' for minutes, 'C' for colors
     - delays to ensure each press is counted individually 
     - Out of the while loop, the desired time is then put in string using the 'Values' function
     - the time is sent to the matrix
     - the matrix is put in spinning motion

