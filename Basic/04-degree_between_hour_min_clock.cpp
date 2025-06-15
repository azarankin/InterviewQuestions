#include <stdio.h>
#include <stdlib.h>
#include <cmath>

float calculate_angle(int hour, int minute) {
    if (hour < 0 || hour > 24 || minute < 0 || minute >= 59) {
        printf("שעה או דקות לא חוקיים\n");
        return -1.0f;
    }

    // הפוך שעה לפורמט 12
    hour = hour % 12;

    float minute_angle = minute * 6 /*360/60*/;                 // 6 מעלות לדקה
    float hour_angle = (hour * 30) /*360/12*/ + (minute * 0.5) /*30/60*/;  // 30 מעלות לשעה + 0.5 לכל דקה
    

    float angle = std::abs(hour_angle - minute_angle);
    if (angle > 180) {
        angle = 360 - angle;
    }

    return angle;
}

int main() {
    int hour, minute;
    printf("הכנס שעה (0-12): ");
    scanf("%d", &hour);
    printf("הכנס דקות (0-59): ");
    scanf("%d", &minute);

    float angle = calculate_angle(hour, minute);
    if (angle >= 0) {
        printf("הזווית בין המחוגים היא: %.2f מעלות\n", angle);
    }

    return 0;
}
