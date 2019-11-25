#include<stdio.h>
#include<conio.h>
bubblesort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	printf("SORTED ARRAY BY BUBBLE SORT IS\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void insertsort(int a[],int n)
{
	int i,j,iv;
	for(i=1;i<n;i++)
	{
		iv=a[i];
		for(j=i-1;j>=0 && a[j]>iv;j--)
			a[j+1]=a[j];
		a[j+1]=iv;
	}
	printf("\nSORTED ARRAY BY INSERTION SORT IS\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void selecsort(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{  if(a[i]>a[j])
		   {
			int t=a[j];
			a[j]=a[i];
			a[i]=t;
		   }
		}
	}
	printf("\nSORTED ARRAY BY SELECTION SORT\n");
		for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void combine(int a[],int l,int m,int h,int n)
{
	int i=l,j=m+1,k=l;
	int c[200];
	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			i++;k++;
		}
		else
		{
			c[k]=a[j];
			k++;j++;
		}
	}
	while(i<=m)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<=h)
	{
		c[k]=a[j];
		k++;
		j++;
	}
	for(i=l;i<=h;i++)
		a[i]=c[i];
	printf("\nSORTED ARRAY BY MERGE SORT\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void merge(int a[],int l,int h,int n)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		merge(a,l,m,n);
		merge(a,m+1,h,n);
		combine(a,l,m,h,n);
	}
}
int split(int a[],int l, int h,int n)
{
	int pivot;
	int i,j,t;
	pivot=a[l];
	i=l+1;
	j=h;
	while(i<j)
	{
		while(a[i]<pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[l]=a[j];
	a[j]=pivot;
	return j;
}

void quick(int a[],int l,int h,int n)
{
	int i;
	if(l<h)
	{
		i=split(a,l,h,n);
		quick(a,l,i-1,n);
		quick(a,i+1,h,n);
	}
	printf("\nSORTED ARRAY BY QUICK SORT\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	
}
	
void main()
{
 int a[100],i,j,n;
clrscr();
printf("HOW MANY NO ?\n");
scanf("%d",&n);
printf("ENTER ARRAY ELEMENTS\n");
for (i=0;i<n;i++)
	scanf("%d",&a[i]);
bubblesort(a,n);
insertsort(a,n);
selecsort(a,n);
merge(a,0,n-1,n);
quick(a,0,n-1,n);
getch();
}