//All sorting algorithms of Piyush Chandra Chandra

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//bubble sort
void bubblesort(int arr[],int n)
{
 int i,j,temp;
 for(i=0;i<n;i++)
 {
  for(j=1;j<n-i;j++)
  {
   if(arr[j-1]>arr[j])
   {
    temp=arr[j];
    arr[j]=arr[j-1];
    arr[j-1]=temp;
   }
  }
 }
}

//selection sort
void selectionsort(int arr[],int n)
{
 int temp,min,i,j;
 
 for(i=0;i<n;i++)
 { min=i;
  for(j=i+1;j<n;j++)
  {
   if(arr[j]<arr[i])
   {
    min=j;
   }
  }

  temp=arr[min];
  arr[min]=arr[i];
  arr[i]=temp;  
 }
}


//insertion sort
void insertionsort(int arr[],int n)
{
 int i,j,temp;
 
 for( i=0;i<n;i++)
 {
  temp=arr[i];
  for(j=i-1;j>=0;j--)
  {
   if(arr[j]>temp)
   {
    arr[j+1]=arr[j];
   }
   else
   break;
  }
  arr[j+1]=temp;
 }
}


//merge sort
void merge(int arr[],int l,int m,int r)
{
 int len,i,j,k,*c;
 len=r-l+1;
 c=(int*)malloc(sizeof(int)*len);
 i=0;
 j=l;
 k=m+1;
 while(j<=m && k<=r)
 {
  if(arr[j]<arr[k])
  {
   c[i++]=arr[j++];
   
  }
  else
  {
   c[i++]=arr[k++];
   
  }
  
 }
 
 while(j<=m)
 {
  c[i++]=arr[j++];
 }
 
 while(k<=r)
 {
  c[i++]=arr[k++];
 }
 i=0;
 while(l<=r)
 {
  arr[l++]=c[i++];
 }
}


//mergesort
void mergesort(int arr[],int l,int r)
{
 int m=(l+r)/2;
 if(l<r)
 {
  mergesort(arr,l,m);
  mergesort(arr,m+1,r);
  merge(arr,l,m,r);
 }
}

int partition(int arr[],int l,int r)
{
 int j=l+1,k=r,temp;
 int num=arr[l];
 while(k>=j)
 {
  while(arr[j]<num)
  j++;
  while(arr[k]>num)
  k--;
  
  if(k>j)
  {
   temp=arr[j];
   arr[j]=arr[k];
   arr[k]=temp;
   
  }
 }
 temp=arr[k];
 arr[k]=arr[l];
 arr[l]=temp;
 return k;
}

//quicksort
void quicksort(int arr[],int l,int r)
{ int m;
 if(r>l)
 {
  m=partition(arr,l,r);
  quicksort(arr,l,m-1);
  quicksort(arr,m+1,r);
 }
}

//raddixsort
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
void countSort(int arr[], int n, int exp) 
{ 
    int output[n];
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 

    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    }  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

void radixsort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
}

//heapsort
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
  
  void heapify(int arr[], int n, int i) {
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;
  
    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;
  
    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
  }
  
  void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify(arr, i, 0);
    }
  }

//timsort
#define min(a,b) (a)<(b)?(a):(b)
const int RUN = 32;

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merging(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 
void timsort(int arr[], int n)
{
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+31), (n-1)));
    for (int size = RUN; size < n; size = 2*size)
    {
        for (int left = 0; left < n; left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));
            merging(arr, left, mid, right);
        }
    }
}

//shellsort
void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}

//countingsort

void countingsort(int arr[], int size) {
  int output[10];
  int min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min)
      min = arr[i];
  }
  int count[10];
  for (int i = 0; i <= min; ++i) {
    count[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    count[arr[i]]++;
  }
  for (int i = 1; i <= min; i++) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
}

//Bucketsort
struct bucket 
{
    int count;
    int* value;
};
 
int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y =  *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
 
void bucketsort(int arr[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            buckets[0].value[buckets[0].count++] = arr[i];
        }
        else if (arr[i] > 10)
        {
            buckets[2].value[buckets[2].count++] = arr[i];
        }
        else
        {
            buckets[1].value[buckets[1].count++] = arr[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            arr[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}

//execution logic
void main()
{
 int i,n,*arr,choice;
 int no = sizeof(arr)/sizeof(arr[0]);
 printf("Enter No. of elements:");
 scanf("%d",&n);
 printf("\nEnter %d elements:",n);
 arr=(int*)malloc(sizeof(int)*n);
 for(i=0;i<n;i++)
 scanf("%d",&arr[i]);
 printf("\n\tMenu\n---------------------------");
 printf("\n1 : to apply bubble sort!");
 printf("\n2 : to apply selection sort!");
 printf("\n3 : to apply insertion sort!");
 printf("\n4 : to apply mergesort");
 printf("\n5 : to apply quicksort!");
 printf("\n6 : to apply radixsort!");
 printf("\n7 : to apply heapsort!"); 
 printf("\n8 : to apply timsort!"); 
 printf("\n9 : to apply shellsort!"); 
 printf("\n10 : to apply countingsort!");
 printf("\n11 : to apply Bucketsort!");
 printf("\n12 : to apply any sorting algorithm!");
 printf("\nAny other number to exit!");
 printf("\nEnter your choice:");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1: bubblesort(arr,n);
    break;
  case 2: selectionsort(arr,n);
    break;
  case 3: insertionsort(arr,n);
    break;
  case 4: mergesort(arr,0,n-1);
    break;
  case 5: quicksort(arr,0,n-1);
    break;
  case 6: radixsort(arr,n);
    break;
  case 7: heapsort(arr,n);
    break;  
  case 8: timsort(arr,n);
    break;
  case 9: shellsort(arr,n);
    break;  
  case 10: countingsort(arr,no);
    break;
  case 11: bucketsort(arr,n);
    break;    
  case 12: quicksort(arr,0,n-1);
    break;
  default: exit(0);
    
 }
 
 printf("\n\tSorted Numbers:\n-----------------------------------------\n");
 for(i=0;i<n;i++)
 printf("%d\t",arr[i]);
}//main
