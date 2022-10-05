#include <stdio.h>

int main(void)
{
	FILE *data = fopen("C:/Users/email_000/Desktop/data.txt", "r");
	FILE *outfile = fopen("C:/Users/email_000/Desktop/newdata.csv", "w");

	if (data == NULL || outfile == NULL) // If the file doesn't open, print an error message
	{
		fprintf(stderr, "Error opening files\n");
		return 1;
	}

	fprintf(outfile, "time,switch0,switch1,switch2,switch3,potentiometer,temperature,light\n"); // Title bar on output file

	char time[15] = { 0 }; //Sets up arrays for each type of data
	char sw0[15] = { 0 };
	char sw1[15] = { 0 };
	char sw2[15] = { 0 };
	char sw3[15] = { 0 };
	char pot[15] = { 0 };
	char temp[15] = { 0 };
	char light[15] = { 0 };

	int samplesize = 100;
	char extra[30]; //Stuff that isnt the necessary numbers 
	fscanf(data, "%s", &extra); //Gets rids of the lines where it asks to press sw0
	fscanf(data, "%s", &extra);
	fscanf(data, "%s", &extra);
	fscanf(data, "%s", &extra);
	fscanf(data, "%s", &extra);
	fscanf(data, "%s", &extra);
	fscanf(data, "%s", &extra);
	fscanf(data, "%s", &extra);

	for (int w = 0; w < 100; w++) //For loop which first takes the lines from the txt doc, and then prints it to the CSV file
	{
		fscanf(data, "%s", &extra); //Takes "time:" away
		fscanf(data, "%s", &time); //Takes delay time from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "ms" away
		fscanf(data, "%s", &extra); //Takes "switch0:" away
		fscanf(data, "%s", &sw0); //Takes sw0 value from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "switch1:" away
		fscanf(data, "%s", &sw1); //Takes sw1 value from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "switch2:" away
		fscanf(data, "%s", &sw2); //Takes sw2 from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "switch:" away
		fscanf(data, "%s", &sw3); //Takes sw3 from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "potentiometer:" away
		fscanf(data, "%s", &pot); //Takes pot value from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "temperature:" away
		fscanf(data, "%s", &temp); //Takes temp value from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "light:" away
		fscanf(data, "%s", &light); //Takes light value from txt doc, and put its in to an array
		fscanf(data, "%s", &extra); //Takes "--------" away

		fprintf(outfile, "%s,", time); //Prints the respective data values in order to the CSV file
		fprintf(outfile, "%s,", sw0);
		fprintf(outfile, "%s,", sw1);
		fprintf(outfile, "%s,", sw2);
		fprintf(outfile, "%s,", sw3);
		fprintf(outfile, "%s,", pot);
		fprintf(outfile, "%s,", temp);
		fprintf(outfile, "%s\n", light);

	}


	if (fclose(data) == EOF) //Closes the files, and makes sure they can be closed
	{
		fprintf(stderr, "Error closing data file\n");
		return 2;
	}

	if (fclose(outfile) == EOF)
	{
		return 3;
	}

	return 0;
}