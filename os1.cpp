#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void *average();
void *maximum();
void *minimum();
int main()
{
	pthread_t ave_th,max_th,min_th;
	pthread_create(&ave_th,NULL,average,NULL);
	pthread_join(ave_th,NULL);
	pthread_create(&max_th,NULL,maximum,NULL);
	pthread_join(max_th,NULL);
	pthread_create(&min_th,NULL,minimum,NULL);
	pthread_join(min_th,NULL);
	printf("The program execution ends here........");
}
void *average()
{
	int n,i;
	float num_arr[100],sum=0.0,average;
	printf("Please enter the number of elements:");
	scanf("%d",&n);
	while(n>100||n<=0)
	{
		printf("error!number is out of range............");
		printf("Enter the number again(correctly) :");
		scanf("%d",&n);
	}
	for(i=0;i<n;++i)
	{
		printf("Enter the number:%d",i+1);
		scanf("%f",&num_arr[i]);
		sum+=num_arr[i];
	}
	average=sum/n;
	printf("The Average Value is %.2f",average);
	return 0;
}
void *maximum()
{
	int i,n;
	float arr[100];
	printf("please enter the total number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		printf("enter the number %d:",i+1);
		scanf("%f",&arr[i]);
	}
	for(i=1;i<n;++i)
	{
		if(arr[0]<arr[i])
			arr[0]=arr[i];
	}
	printf("The Maximum Value is %.2f",arr[0]);
	return 0;
}
void *minimum()
{
	int arr_min[100],min,size,k,location=1;
	printf("enter the number of elements in array\n");
	scanf("%d",&size);
	printf("Please enter %d integers\n",size);
	for(k=0;k<size;k++)
		scanf("%d",&array[k]);
	min=array[0];
	for(k=1;k<size;k++)
	{
		if(array[k]<min)
		{
			min=array[k];
			location=k+1;
		}
	}
	printf("The Minimum value is ",minimum);
	return 0;
}

