#include <bits/stdc++.h>
int main(void) {
    int a[]={30,5,3,7,4,8,10,20,11,25,13};
    for(int i=0;i<10;i++) {
        int min=a[i];
        for(int j=i+1;j<11;j++) {
            if(a[j]<min) {
                int temp=min;
                min=a[j];
                a[j]=temp;
            }
        }
        a[i]=min;
    }
    for(int i=0;i<11;i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}