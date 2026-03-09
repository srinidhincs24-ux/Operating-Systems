#include <stdio.h>
#define MAX 10
struct process {
int at, bt, rt, ct, wt, tat;
};
void input(struct process p[], int n) {
for(int i=0; i<n; i++) {
printf("Enter arrival time and burst time of process %d: ", i+1);
scanf("%d%d", &p[i].at, &p[i].bt);
p[i].rt = p[i].bt;
}
}
void srtf(struct process p[], int n) {
int time = 0, completed = 0;
float avgTat = 0, avgWt = 0;
while(completed < n) {
int idx = -1;
int minRt = 9999;
for(int i=0; i<n; i++) {
if(p[i].at <= time && p[i].rt > 0) {
if(p[i].rt < minRt) {
minRt = p[i].rt;
idx = i;
}
}
}
if(idx == -1) {
time++;
continue;
}
p[idx].rt--;
time++;
if(p[idx].rt == 0) {
p[idx].ct = time;
p[idx].tat = p[idx].ct - p[idx].at;
p[idx].wt = p[idx].tat - p[idx].bt;
completed++;
printf("Process %d -> CT: %d, TAT: %d, WT: %d\n", idx+1, p[idx].ct, p[idx].tat,
p[idx].wt);
}
}
for(int i=0; i<n; i++) {
avgTat += p[i].tat;
avgWt += p[i].wt;
}
printf("\nAverage TAT: %.2f ms\n", avgTat/n);
printf("Average WT: %.2f ms\n", avgWt/n);
}
int main() {
struct process p[MAX];
int n;
printf("Enter number of processes: ");
scanf("%d", &n);
input(p, n);
srtf(p, n);
return 0;
}