#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

#define INF 1000000000
void merge(int array[],int start,int mid_point,int end)
{
    int n1,n2;
    n1=mid_point-start+1;
    n2=end-mid_point;
    int left[n1+1],right[n2+1];

    for(int i=1;i<=n1;i++)
    {
        left[i]=array[start+i-1];
    }

    for(int j=1;j<=n2;j++)
    {
        right[j]=array[mid_point+j];
    }
    left[n1+1]=INF;
    right[n2+1]=INF;
    int i=1,j=1;
    for(int k=start;k<=end;k++)
    {
        if(left[i]<=right[j])
        {
            array[k]=left[i];
            i++;
        }
        else
        {
            array[k]=right[j];
            j++;
        }
    }
}

void merge_sort(int array[],int start,int end)
{
    int mid_point;
    if(start<end)
    {
        mid_point=(start+end)/2;
        merge_sort(array,start,mid_point);
        merge_sort(array,mid_point+1,end);
        merge(array,start,mid_point,end);
    }
}
int main()
{
    cout << "How many numbers you want to sort ? :";
    int number;
    int array_storage[100];
    while(cin>>number)
    {
        for(int i=1;i<=number;i++)
        {
            cin>>array_storage[i];
        }
        merge_sort(array_storage,1,number);
        for(int i=1;i<=number;i++)
        {
            cout<<array_storage[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

