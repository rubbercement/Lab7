#include <stdio.h>
#include <string.h>
#include <stdbool.h>

float celsius_to_fahrenheit (float celsius) { 
    celsius = ((9.0/5.0)*celsius + 32);
    // printf("value: %f", celsius);
    return celsius;
}

float fahrenheit_to_celsius (float fahrenheit) { 
    fahrenheit = ((5.0/9.0)*(fahrenheit - 32));
    // printf("value: %f", fahrenheit);
    return fahrenheit;
}

float celsius_to_kelvin (float celsius) {
    celsius = (celsius + 273.15);
    // printf("value: %f", celsius);
    return celsius;
}

float kelvin_to_celsius (float kelvin) {
    kelvin = (kelvin - 273.15);
    // printf("value: %f", kelvin);
    return kelvin;
}

int getTempScale (char* myString) {
    if (strstr(myString, "Fahrenheit") != NULL)
    {
        return 0;
    }
    else if (strstr(myString, "Celsius") != NULL)
    {
        return 1;
    }
    else if (strstr(myString, "Kelvin") != NULL)
    {
        return 2;
    }
    else
    {
        return -1;
    }
} 

void categorize_temperature(float celsius)
{
    char status[15];
    char advice[30]; 
    if (celsius > 35.0)
    {
        printf("Status: Extreme Heat\nAdvice: Don't stay out for long!\n");
    }
    else if (celsius > 25.0)
    {
        printf("Status: Hot\nAdvice: Drink water!\n");
    }
    else if (celsius > 10.0)
    {
        printf("Status: Comfortable\nAdvice: Pleasant weather!\n");
    }
    else if (celsius >= 0)
    {
        printf("Status: Cold\nAdvice: Wear a coat!\n");
    }
    else
    {
        printf("Status: Freezing\nAdvice: Stay indoors!\n");
    }
}

int main() {
    float temperature;
    char originalTempScale[10]; 
    char newTempScale[10];
    bool loop = true;
    bool fail = false;
    int oTS = -1;
    int nTS = -1;
    while (loop) {
        printf("Enter temperature: ");
        int floatCheck = scanf("%f", &temperature);
        printf("Enter temperature scale (Fahrenheit, Celsius, or Kelvin): ");
        scanf("%s", originalTempScale);
        oTS = getTempScale(originalTempScale);
        printf("Enter conversion target (Fahrenheit, Celsius, or Kelvin): ");
        scanf("%s", newTempScale);
        nTS = getTempScale(newTempScale);
        printf("OTS: %d, NTS: %d\n", oTS, nTS);
        if ((temperature < 0 && oTS == 2) || (oTS == -1 || nTS == -1 || floatCheck == 0))
        {
            fail = true;
        }
        if (fail)
        {
            printf("Invalid Input, please reenter data\n");
            fail = false;
        }
        else 
        {
            loop = false;
        }
    }
    float temperatureC = 0;
    switch (oTS)
    {
        case 0:
            temperatureC = fahrenheit_to_celsius(temperature);
            break;
        case 1:
            temperatureC = temperature;
            break;
        case 2:
            temperatureC = kelvin_to_celsius(temperature);
            break;
    }
    if (strcmp(originalTempScale, newTempScale) != 0)
    {
        switch (nTS)
        {
            case 0:
                temperature = celsius_to_fahrenheit(temperatureC);
                break;
            case 1:
                temperature = temperatureC;
                break;
            case 2:
                temperature = celsius_to_kelvin(temperatureC);
                break;
        }
    }
    printf("Converted temperature: %f\n", temperature);
    categorize_temperature(temperatureC);
    return 0;
}