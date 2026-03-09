#include <stdio.h>
#define MAX 10
struct process {
 int at, bt, ct, wt, tat, prt;
};
void input(struct process p[], int n) {
 for(int i=0; i<n; i++) {
 printf("Enter AT, BT, Priority for Process %d: ", i+1);
 scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].prt);
 }
}
void priorityScheduling(struct process p[], int n) {
 int time = 0;
 float avgTat = 0, avgWt = 0;
 for(int i=0; i<n-1; i++) {
 for(int j=i+1; j<n; j++) {
 if(p[i].at > p[j].at ||
 (p[i].at == p[j].at && p[i].prt > p[j].prt)) {
 struct process temp = p[i];
 p[i] = p[j];
 p[j] = temp;
 }
 }
 }
 for(int i=0; i<n; i++) {
 if(time < p[i].at) {
 time = p[i].at;
 }
 time += p[i].bt;
 p[i].ct = time;
 p[i].tat = p[i].ct - p[i].at;
 p[i].wt = p[i].tat - p[i].bt;
 avgTat += p[i].tat;
 avgWt += p[i].wt;
 }
 printf("\nProcess\tAT\tBT\tPRT\tCT\tTAT\tWT\n");
 for(int i=0; i<n; i++) {
 printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
 i+1, p[i].at, p[i].bt, p[i].prt,
 p[i].ct, p[i].tat, p[i].wt);
 }
 printf("\nAverage TAT: %.2f\n", avgTat/n);
 printf("Average WT: %.2f\n", avgWt/n);
}
int main() {
 struct process p[MAX];
 int n;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 input(p, n);
 priorityScheduling(p, n);
 return 0;
}