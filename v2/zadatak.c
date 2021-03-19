#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    int LED;
    int pwm_duty = 0;
    char x[4];
    int broj;
    if (argc != 2)
    {
        printf("Previse argumenata prosledjeno.");
        return 0;
    }

    if (!strcmp(argv[1], "LED1"))
    {
        LED = 25;
    }
    else if (!strcmp(argv[1], "LED2"))
    {
        LED = 26;
    }
    else if (!strcmp(argv[1], "LED3"))
    {
        LED = 27;
    }
    else if (!strcmp(argv[1], "LED4"))
    {
        LED = 28;
    }
    else
    {
        printf("Pogresna komanda!\n Prihvata LED(1-4)\n");
        return 1;
    }

    if (wiringPiSetup() == -1)
    {
        exit(1);
    }
    printf("LED:%d\n", led);
    if (softPwmCreate(led, 0, 100) != 0)
    {
        exit(2);
    }
    while (1)
    {

        printf("Podesi PWM signal: ");
        scanf("%s", x);
        broj = atoi(x + 1);

        if (x[0] == '+')
        {
            pwm_duty = pwm_duty + broj;
        }
        if (x[0] == '-')
        {
            pwm_duty = pwm_duty - broj;
        }
        if (jacpwm_duty > 100)
        {
            pwm_duty = 100;
        }
        if (pwm_duty < 0)
        {
            pwm_duty = 0;
        }

        printf("Trenuta jacina je:%d%\n", pwm_duty);

        softPwmWrite(led, pwm_duty);
    }
}
