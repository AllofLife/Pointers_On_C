/*
 * 程序的输出
 * a[0]'s value 0 point value 0x7ffee12b38b0 
//a[1]'s value 0 point value 0x7ffee12b38b4 
//a[2]'s value 0 point value 0x7ffee12b38b8 
//a[3]'s value 0 point value 0x7ffee12b38bc 
//a[4]'s value 0 point value 0x7ffee12b38c0 
//a[5]'s value 0 point value 0x7ffee12b38c4 
//a[6]'s value 0 point value 0x7ffee12b38c8 
//a[7]'s value 0 point value 0x7ffee12b38cc 
//a[8]'s value 0 point value 0x7ffee12b38d0 
//a[9]'s value 0 point value 0x7ffee12b38d4 
//a[10]'s value 226675968 point value 0x7ffee12b38d8
 * 
 */
#include<stdio.h>
int main(){
	int a[10]={0};
	int i=0;
	for(i=0;i<10;i++)
	{
		printf("a[%d]'s value %d point value %p ",i,a[i],&a[i]);
		printf("\n");
		}
	printf("a[10]'s value %d point value %p",a[10],&a[10]);
	printf("\n");
	
	return 0;
	}
