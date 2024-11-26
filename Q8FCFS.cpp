#include<iostream>
using namespace std;

struct Process {
    int pid; // Process ID
    int BT;  // Burst Time
    int WT;  // Waiting Time
    int TAT; // Turnaround Time
};

void findWT(Process proc[], int n) {
    proc[0].WT = 0; // Waiting time for the first process is 0
    for (int i = 1; i < n; i++) {
        proc[i].WT = proc[i - 1].WT + proc[i - 1].BT; // Waiting time is cumulative
    }
}

void findTAT(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].TAT = proc[i].BT + proc[i].WT; // Turnaround time = Burst Time + Waiting Time
    }
}

void findAvgTime(Process proc[], int n) {
    int totalWT = 0, totalTAT = 0;

    findWT(proc, n); // Calculate waiting times
    findTAT(proc, n); // Calculate turnaround times

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        totalWT += proc[i].WT;
        totalTAT += proc[i].TAT;

        cout << proc[i].pid << "\t"
             << proc[i].BT << "\t"
             << proc[i].WT << "\t"
             << proc[i].TAT << endl;
    }

    cout << "\nAverage WT: " << (float)totalWT / n << endl;
    cout << "Average TAT: " << (float)totalTAT / n << endl;
}

int main() {
    int n;

    // Prompt user for the number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    Process proc[n]; // Create an array of processes

    // Input burst times
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1; // Process ID starts from 1
        cout << "Enter Burst Time for Process " << proc[i].pid << ": ";
        cin >> proc[i].BT;
    }

    findAvgTime(proc, n); // Calculate and display average times

    return 0;
}