#include <stdio.h>
#include <stdlib.h>

struct Edata // create Electrical Data Structure
{
 int voltage;
 int current;
};

int CalculatePower (struct Edata *p) // function takes struct Edata with a pointer as argument
{
 printf ("Values are %d Vdc,  %d A", p->voltage, p->current); // deferences p to voltage and current, to present the values
 return  p->voltage *p->current; // returns the product of voltage and current (dereferenced into values) not mememory addresses
}


int main()
{
int nreadings=0;
int power=0;

printf ("\nEnter the number of readings: ");
scanf ("%d", &nreadings);

struct Edata readings[nreadings]; // creates a an array of readings
int totpower=0;

for (int i =0; i < nreadings; i++)
{
printf ("\nEnter the Voltage reading for set the %d: ", i + 1);
scanf ("%d", &readings[i].voltage);

printf ("\nEnter the Current reading for the set %d: ", i + 1);
scanf ("%d", &readings[i].current);

power = CalculatePower(&readings[i]);
printf ("\nThe Calculated Power is %d Watts\n", power);

totpower += power;
}

printf ("\n\nThe total power of all sets is %d\n\n", totpower);

getchar();

//old example, I thought it was better to make it with a structure of arrays, instead of many samples
/*struct Edata n1; // calls Edata structure with index n1

printf("\nVoltage Reading: "); // read the first set of n1 parameter
scanf("%d", &n1.voltage);
printf("\nCurrent Reading: ");
scanf("%d", &n1.current);

int power = CalculatePower(&n1); // calls Calculate Power functions with giving the address of n1 to the function power, which takes a pointer as argument
printf ("\nThe calculated power for number 1 set is %d Watts\n\n", power); // displays power

//second element
struct Edata n2; // calls Edata structure with index n2

printf("\nVoltage Reading: "); // read the first set of n1 parameter
scanf("%d", &n2.voltage);
printf("\nCurrent Reading: ");
scanf("%d", &n2.current);

int power2 = CalculatePower(&n2); // calls Calculate Power functions with giving the address of n1 to the function power, which takes a pointer as argument
printf ("\nThe calculated power for number 2 set is %d Watts\n\n", power2); // displays power


*/
    return 0;
}

