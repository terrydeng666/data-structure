#include <bits/stdc++.h>
int main(void) {
    int a[]={30,5,3,7,4,8,10,20,11,25,13};
    for(int i=1;i<11;i++) {
        int temp=a[i];
        for(int j=i-1;j>=0;j--) {
            if(a[j]<temp) {
               break; 
            }
            else if(temp<a[j]) {
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<11;i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}