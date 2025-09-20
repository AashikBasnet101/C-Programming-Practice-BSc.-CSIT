//Find majority element (Boyer–Moore)
#include <stdio.h>

int majority(int a[], int n) {
    int cand = -1, cnt = 0;
    for (int i=0;i<n;i++) {
        if (cnt==0) { cand = a[i]; cnt=1; }
        else if (a[i]==cand) cnt++;
        else cnt--;
    }
    // verify
    cnt = 0;
    for (int i=0;i<n;i++) if (a[i]==cand) cnt++;
    return cnt > n/2 ? cand : -1;
}

int main() {
    int n; if (scanf("%d", &n)!=1) return 0;
    int a[n]; for (int i=0;i<n;i++) scanf("%d", &a[i]);
    int m = majority(a,n);
    if (m == -1) printf("No majority\n"); else printf("Majority = %d\n", m);
    return 0;
}
