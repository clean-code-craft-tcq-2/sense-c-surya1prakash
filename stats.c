#include "stats.h"
#include "math.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = NAN;
    s.min = NAN;
    s.max = NAN;

	if (setlength==0)
	{
		return s;
	}
    else
    {
        int i;
        float sum;
        s.average = 0;
        s.min = numberset[0];
        s.max = numberset[0];
        for(i = 0; i < setlength; i++)
        {
            sum += numberset[i];
            s.min = ((numberset[i] < s.min)? numberset[i] : s.min);
            s.max = ((numberset[i] > s.min)? numberset[i] : s.max);
        }
        s.average = sum / setlength;
    }
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	if (computedStats.max > maxThreshold)
	{
		alerters[0]();
		alerters[1]();
	}
}
