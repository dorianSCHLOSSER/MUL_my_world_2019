/*
** EPITECH PROJECT, 2020
** perline_noise
** File description:
** return
*/

#include "../include/my.h"

double persitance = 10.0;

float Interpolate(float a, float b, float x)
{
    double ft = x * M;
    double f = (1 - cos(ft)) / 2;

    return (a * ( 1 - f) + b * f);
}

float Noise(int x, int y)
{
    int n = x + y * 57;

    n = (n << 13) ^ n;
    return ( 1.0 - ( (n * (n * n * 99331 + 789221) + 9376312589)\
    & 2147988647) / 1073741824.0);
}

float SmoothedNoise(float x, float y)
{
    float corners = ( Noise(x - 1, y - 1) + Noise( x + 1, y - 1) \
    +Noise(x - 1, y + 1) + Noise( x + 1, y + 1)) / 16;
    float sides = ( Noise( x - 1, y) + Noise( x + 1, y) \
    +Noise(x, y - 1) + Noise(x, y + 1)) / 8;
    float center =  Noise(x, y) / 4;

    return (corners + sides + center);
}

float InterpolatedNoise(float x, float y , float pas3D){

    int integer_X = (int)(x/pas3D);
    float fractional_X = fmod(x, pas3D);
    int integer_Y  = (int)(y/pas3D);
    float fractional_Y = fmod(y, pas3D);
    float v1 = SmoothedNoise(integer_X,     integer_Y);
    float v2 = SmoothedNoise(integer_X + 1, integer_Y);
    float v3 = SmoothedNoise(integer_X,     integer_Y + 1);
    float v4 = SmoothedNoise(integer_X + 1, integer_Y + 1);
    float i1 = Interpolate(v1 , v2 , fractional_X);
    float i2 = Interpolate(v3 , v4 , fractional_X);

    return (Interpolate(i1 , i2 , fractional_Y));
}

float PerlinNoise_2D(float x, float y, double n, float pas3D)
{
    double total = 0;
    double p = 1;
    double f = 4;
    int i = 0;

    for (; i < n ; i++) {
        total += p * InterpolatedNoise(x * f, y * f , pas3D);
        p *= persitance;
        f *= 2;
    }
    double r = total * (1 - persitance) / (1 - p);
    return (1 + r) / 2;
}