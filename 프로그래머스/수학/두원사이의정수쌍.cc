#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;

    long long r11 = (long long)r1 * r1;
    long long r22 = (long long)r2 * r2;

    for (int x = 1; x <= r2; x++) // 특정 x값에 대한 가능한 y값들을 구함
    {
        // X^2 + Y^2 >= r1^2 && X^2 + Y^2 <= r2^2
        // Y^2 >= r1^2 -X^2 -> 만족하는 정수 y의 최소값
        //  Y^2 <= r2^2 -X^2 -> 만족하는 정수 y의 최대값
        int minY = ceil(sqrt(r11 - (long long)x * x));  // 올림 내림은 부등호에 의해 결정
        int maxY = floor(sqrt(r22 - (long long)x * x)); // r22 > r11에 의해 maxY minY 결정 (x와 y는 두 경우 모두 동일하니까)

        if (r1 < x)
            minY = 0;

        answer += maxY - minY + 1;
    }

    // 사분면중 한면만 계산한거이니까 4곱함
    return answer * 4;
}