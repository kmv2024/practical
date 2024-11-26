#include<stdlib.h>
#include<stdio.h>
void main(){
    printf("Mem Info from /proc/meminfo:\n");
    system("grep 'MemTotal' /proc/meminfo");
    system("grep 'MemFree' /proc/meminfo");
    system("grep 'MemAvailable' /proc/meminfo");
    system("grep 'KernelStack' /proc/meminfo");
    return;
}