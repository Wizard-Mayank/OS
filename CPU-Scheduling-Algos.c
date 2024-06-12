#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int a[], int b[], int n){
	
	for(int i=0; i<n-1; ++i){
		for(int j=0; j<n-1-i; ++j){
			if(a[i]>a[i+1]){
				
				swap(&a[i], &a[i+1]);
				swap(&b[i], &b[i+1]);
				
			}
		}
	}
}

void fcfs(int pid[], int at[], int  bt[], int st[], int ct[], int wt[], int tat[], int n){
	
	bubbleSort(pid, bt, n);
	
	st[0]=0;
	ct[0]=bt[0];
	wt[0]=0;
	tat[0]=ct[0]-0;
	
	for (int i=1; i<n; ++i){
		st[i]=st[i-1]+bt[i-1];
		ct[i]=st[i]+bt[i];
		wt[i]=st[i]-0;
		tat[i]=ct[i]-0;
	}
}

void sjf(int pid[], int at[], int  bt[], int st[], int ct[], int wt[], int tat[], int n){
	
	bubbleSort(bt, pid, n);
	
	st[0]=0;
	ct[0]=bt[0];
	wt[0]=0;
	tat[0]=ct[0]-0;
	
	for (int i=1; i<n; ++i){
		st[i]=st[i-1]+bt[i-1];
		ct[i]=st[i]+bt[i];
		wt[i]=st[i]-0;
		tat[i]=ct[i]-0;
	}
}

void priority(int pid[], int at[], int  bt[], int st[], int ct[], int wt[], int tat[], int prior[], int n){
	
	bubbleSort(prior, pid, n);
	
	st[0]=0;
	ct[0]=bt[0];
	wt[0]=0;
	tat[0]=ct[0]-0;
	
	for (int i=1; i<n; ++i){
		st[i]=st[i-1]+bt[i-1];
		ct[i]=st[i]+bt[i];
		wt[i]=st[i]-0;
		tat[i]=ct[i]-0;
	}
}

int main(){
	int n;
	
	printf("Enter number of process IDs: ");
	scanf("%d", &n);
	
	int PID[n], AT[n], BT[n], ST[n], CT[n], WT[n], TAT[n];
	
	printf("\nEnter PID and BT respectively:\n");
	
	for(int i=0; i<n; ++i){
		scanf("%d %d", &PID[i], &BT[i]);
		AT[i]=0;
	}
	
	int prior[n];
	
	printf("\nEnter priority respectively(lower the number, higher the priority, all 0's for no priority):\n");
	
	for(int i=0; i<n; ++i)
		scanf("%d", &prior[i]);
	
	printf("\nEntered data:\n------------------------\nPID\tAT\tBT\tPriority\n");
	
	for(int i=0; i<n; ++i){
		printf("%d\t%d\t%d\t%d\n", PID[i], AT[i], BT[i], prior[i]);
	}
	
	
	priority(PID, AT, BT, ST, CT, WT, TAT, prior, n);
	
	printf("\nAfter Scheduling:\n------------------------\nPID\tAT\tBT\tPriority\tST\tCT\tWT\tTAT\n");
	
	for(int i=0; i<n; ++i){
		printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n", PID[i], AT[i], BT[i], prior[i], ST[i], CT[i], WT[i], TAT[i]);
	}

    return 0;
}