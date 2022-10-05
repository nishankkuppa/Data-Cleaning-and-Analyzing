# Data-Cleaning-and-Analyzing
### Nishank Kuppa, Ryan Kutney, Aravind Prakash

Generate test data on Arduino; Convert test data to comma separated values in C; graph and analyze data in MatLab.
This project was completed as part of our Computer Applications final project at San Jose State University.

DEFINE THE PROBLEM
 Have the Arduino read the state of the four switches, the temperature sensor, the potentiometer,
and the light sensor 100 times with a 40-millisecond delay between readings. Have these values
recorded on the Serial Monitor. Paste the data into a file and create a C program which takes the
data from the file and writes it into a CSV (comma separated values) file for easy transfer into
MatLab. Using MatLab, compute the following values:
 - The mean, median, mode, and standard deviation for the Potentiometer readings
 - The mean, median, mode, and standard deviation for the Temperature readings
 - The mean, median, mode, and standard deviation for the Light sensor readings
 - A count of how many times each button was read as depressed
 - A line graph containing the pot, temp, and light readings over time with the linear approximation of
each data set and a bar graph comparing the number of times each button was pressed. All graphs
should be properly labeled.
LIST INPUTS AND OUTPUTS
 Arduino
 Inputs
 Switch 0, Switch 1, Switch 2, Switch 3, Temperature Sensor, Potentiometer, Light
Sensor
 Outputs
 Delay time, whether switch 0, 1, 2, 3 is pressed, pot value from 0 to 100% (0 to 1.0),
temperature value from 0 to 100% (0 to 1.0), light sensor value from 0 to 100% (0 to
1.0)
 Visual Studio
 Inputs
 Data from the Arduino in a text document
 Outputs
 Cleaned up data into a CSV file

 Matlab
 Inputs
 Cleaned up data from visual studio in a CSV file
 Outputs
 The mean, median, mode, and standard deviation for the Potentiometer readings
 - The mean, median, mode, and standard deviation for the Temperature readings
 - The mean, median, mode, and standard deviation for the Light sensor readings
 - A count of how many times each button was read as depressed
 - A line graph containing the pot, temp, and light readings over time with the linear
approximation of each data set and a bar graph comparing the number of times each
button was pressed

