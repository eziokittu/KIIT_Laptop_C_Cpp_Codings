#include <stdio.h>
#include <stdlib.h>

// Define the Process structure
typedef struct Process {
    int id;
    int bt;
    int at;
    int ct;
    int tat;
    int wt;
} Process;

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum element in an array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum completion time using the MaxMin algorithm
int maxmin(Process p[], int n, char sequence[]) {
    // Sort p based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].bt > p[j + 1].bt) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int max_ct = findMax(p[0].at + p[0].bt, n);
    int min_ct = findMin(p[0].at + p[0].bt, n);
    int result = max_ct;

    // Finding the maximum of the minimum completion times
    while (min_ct < max_ct) {
        int mid = (min_ct + max_ct) / 2;
        int workers = 1;
        int sum = 0;
        int current_process = 0;

        for (int i = 0; i < n; i++) {
            sum += p[i].bt;
            if (sum > mid) {
                workers++;
                sum = p[i].bt;
                sequence[current_process++] = '-';
            }
            sequence[current_process++] = 'p';
            sequence[current_process++] = '0' + p[i].id;
            sequence[current_process] = '\0';
        }

        if (workers <= 2) {
            result = mid;
            max_ct = mid;
        } else {
            min_ct = mid + 1;
        }
    }
    return result;
}

// Function to calculate turnaround time and waiting time
void calculateTimes(Process p[], int n) {
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = 0;

    for (int i = 1; i < n; i++) {
        int ct = p[i - 1].ct + p[i].bt;
        p[i].ct = ct;

        int tat = p[i].ct - p[i].at;
        p[i].tat = tat;

        int wt = tat - p[i].bt;
        p[i].wt = wt;
    }
}

int main() {
    int n;
    printf("Enter the number of p: ");
    scanf("%d", &n);

    Process p[n];
    char sequence[2 * n];
    
    printf("Enter burst times and arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        p[i].id = i + 1;
    }

    calculateTimes(p, n);

    int result = maxmin(p, n, sequence);
    printf("Minimum maximum completion time: %d\n", result);
    printf("MaxMin sequence of execution: %s\n", sequence);

    // Calculate average waiting time and average turnaround time
    double total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    double average_wt = total_wt / n;
    double average_tat = total_tat / n;
    printf("Average waiting time: %.2f\n", average_wt);
    printf("Average turnaround time: %.2f\n", average_tat);

    return 0;
}
