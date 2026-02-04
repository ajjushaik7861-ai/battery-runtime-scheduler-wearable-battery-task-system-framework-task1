#include <stdio.h>
#include <math.h>

/*
 Function to calculate minimum runtime
 Returns -1 if impossible
*/
double minRuntime(double capacity,
                  double initialBattery,
                  int n,
                  double tasks[][2],
                  double chargeRate)
{
    double battery = initialBattery;
    double totalTime = 0.0;

    for (int i = 0; i < n; i++)
    {
        double duration = tasks[i][0];
        double drainRate = tasks[i][1];

        // Energy needed
        double needed = duration * drainRate;

        // Impossible case
        if (needed > capacity)
        {
            return -1.0;
        }

        // Charge if needed
        if (battery < needed)
        {
            double missing = needed - battery;
            double chargeTime = missing / chargeRate;

            totalTime += chargeTime;
            battery += chargeTime * chargeRate;

            // Cap to capacity
            if (battery > capacity)
            {
                battery = capacity;
            }
        }

        // Run task
        battery -= needed;
        totalTime += duration;
    }

    // Round to 1 decimal
    return round(totalTime * 10.0) / 10.0;
}

int main()
{
    double capacity, initialBattery, chargeRate;
    int n;

    // Input battery capacity
    printf("Enter battery capacity (mAh): ");
    scanf("%lf", &capacity);

    // Input initial battery
    printf("Enter initial battery (mAh): ");
    scanf("%lf", &initialBattery);

    // Input charging rate
    printf("Enter charging rate (mAh/sec): ");
    scanf("%lf", &chargeRate);

    // Input number of tasks
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    double tasks[n][2];

    // Input tasks
    printf("Enter each task as: duration drainRate\n");

    for (int i = 0; i < n; i++)
    {
        printf("Task %d: ", i + 1);
        scanf("%lf %lf", &tasks[i][0], &tasks[i][1]);
    }

    double result = minRuntime(capacity,
                               initialBattery,
                               n,
                               tasks,
                               chargeRate);

    if (result < 0)
    {
        printf("\nResult: -1 (Impossible to execute all tasks)\n");
    }
    else
    {
        printf("\nMinimum Runtime: %.1f seconds\n", result);
    }

    return 0;
}
