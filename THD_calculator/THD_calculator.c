#include<stdio.h>
#include<math.h>
//Snippet calculates THD, and THD % for both 50 and 60 Hz, the input of current
//must be entered either manually, or via another type of mapping to the arrays listed below
//The snippet can calculate 0 - 50 n harmonic acc. to IEC 509
// the frequency range of the calculation will be calculated via number of desired harmonics
// you can calculate overall harmonics (Power System Analysis)

int main ()
{
 //variables
int NetF=0, nharmonic=0; //Netfrequency (Fundamental), isodd / iseven (for n components), number of harmonic to be entered.
float harmonic [50];
float IF=0.0, IF_sqrt=0.0, sum=0.0, THDi_percent;
int frange; // should have 3.f precision, float and 3 decimals

 //User display
printf("--Harmonica--Calculates Total Harmonic Distortion in current and percentage in Power System--\n");

printf ("Insert the fundamental Frequency in Hz:");
scanf ("%d", &NetF);
if (NetF != 50 && NetF !=60) //input validation
    {
        printf("Not valid frequency range");
        return 0;
     }
else
        {
        printf("Insert the n harmonic range [2-50]:");
        scanf ("%d", &nharmonic);
        }

if (nharmonic < 2 || nharmonic >50) // input validation
    {
    printf ("The number of harmonic is invalid");
    return 0;
    }
else
    {
    frange = nharmonic * NetF;
    printf ("The frequency range is %d Hz\n", frange);
    }

    printf ("Enter the n samples of current:\n");

    for (int i = 0; i < nharmonic; i++) // array of n harmonics
    {
    printf ("Current RMS - harmonic n = %u>", i+1);
    scanf ("%f", &harmonic[i]);
    }

    IF = harmonic[0]; // IF = fundamental, sum and square all the other harmonics
    for (int i =0; i < nharmonic; i++)
        {
        harmonic[i] = harmonic[i]*harmonic[i];
        sum += harmonic[i];
        }

IF_sqrt =IF * IF; // squares Fundamental frequency
float THDi = sqrt (sum/IF_sqrt);

printf ("The THDi (Total Harmonic Distortion in current is: %.3f\n", THDi);
THDi_percent = (THDi / IF) * 100;
printf ("The THDi in percetage is: %.2f%%\n", THDi_percent);


return 0;
}
