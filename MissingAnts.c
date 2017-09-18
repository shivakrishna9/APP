#include <stdio.h>
 
void merge(int A[],int D[],int start,int mid, int end)
{
    int p=start,q=mid+1,k=0,Arr[end-start+1],Arr2[end-start+1];
    for(int i=start;i<=end;i++)
    {
    if(p>mid)
    {
        Arr[k]=A[q];
        Arr2[k]=D[q];
        k++;
        q++;
    }
    else if(q>end)
    {
        Arr[k]=A[p];
        Arr2[k]=D[p];
        k++;
        p++;
    }
    else if(A[p]<A[q])
    {
        Arr[k]=A[p];
        Arr2[k]=D[p];
        k++;
        p++;
    }
    else
    {
        Arr[k]=A[q];
        Arr2[k]=D[q];
        k++;
        q++;
    }
    }
    for(int i=0;i<k;i++)
    {
        A[start]=Arr[i];
        D[start]=Arr2[i];
        start++;
    }
    
}
void mergesort(int A[],int D[],int start,int end)
{
    if(start<end)
    {
        int mid =(start + end)/2;
        mergesort(A,D,start,mid);
        mergesort(A,D,mid+1,end);
        merge(A,D,start,mid,end);
    }
}
int main()
{
    int n,count=0,start,end;
    scanf("%d",&n);
    int x[n],d[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&x[i],&d[i],&d[i]);
    }
    mergesort(x,d,0,n-1);
    end = x[0]-1;
    for(int i=0;i<n;i++)
    {
        start=x[i];
        if(end<start)
        {
            count = count +(d[i]+1);
            end = x[i]+d[i]-1;
        }
        else if(end<(x[i]+d[i]-1))
        {
            count = count + d[i] - (end - start+1);
            end = x[i]+d[i]-1;
        }
    }
    printf("%d",count);
}
