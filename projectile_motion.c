#include <stdio.h>
#include <math.h>

void findRange(float launchSpeed, float launchAngle, float initialHeight) {
    const float G = 9.81;
    const float PI = 4.0 * atan(1.0);

    float launchAngle_radians = PI * launchAngle / 180.0;

    float launchSpeed_x = launchSpeed * cos(launchAngle_radians);
    float launchSpeed_y = launchSpeed * sin(launchAngle_radians);

    float airTime = ( launchSpeed_y + sqrt( pow(launchSpeed_y, 2) + 2 * G * initialHeight ) ) / G;

    float range = airTime * launchSpeed_x;

    printf("Horizontal projectile range is %.2f metres.\n", range);
}

int main() {
    float launchSpeed, launchAngle, initialHeight;

    printf("Enter the launch angle (degrees): ");
    scanf("%f", &launchAngle);
    if(launchAngle < 0 || launchAngle > 180) {
        printf("Invalid launch angle.\n");
        return 1;
    }

    printf("Enter the initial height (m): ");
    scanf("%f", &initialHeight);
    if(initialHeight < 0) {
        printf("Invalid initial height.\n");
        return 1;
    }

    printf("Enter the launch speed (m/s): ");
    scanf("%f", &launchSpeed);
    if(launchSpeed < 0) {
        printf("Invalid launch speed.\n");
        return 1;
    }


    printf("\n");

    findRange(launchSpeed, launchAngle, initialHeight);


    return 0;
}