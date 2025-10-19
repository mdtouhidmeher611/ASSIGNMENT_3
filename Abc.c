#include<stdio.h>
int main(){int a[3][3]={{50,60,70},{80,90,100},{30,40,50}};char
n[3][10]={"Ali","Bob","Cat"};int i,j,s;float avg;
for(i=0;i<3;i++){s=0;for(j=0;j<3;j++){s+=a[i][j];}avg=s/3.0;if(avg>=80)p
rintf("%s Grade A avg=%.2f\n",n[i],avg);else if(avg>=60)printf("%s Grade
B avg=%.2f\n",n[i],avg);else if(avg>=40)printf("%s Grade C
avg=%.2f\n",n[i],avg);else printf("%s Fail avg=%.2f\n",n[i],avg);}int
max=0,pos=0;for(i=0;i<3;i++){s=0;for(j=0;j<3;j++){s+=a[i][j];}if(s>max){
max=s;pos=i;}}printf("Topper: %s with total %d\n",n[pos],max);return 0;}