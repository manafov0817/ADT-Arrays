#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void DisplayArray(struct Array arr)
{

    printf("Elements in array is: \n");

    for(int i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);

};

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Add(struct Array *arr, int num)
{
    if(arr->length<arr->size)
        arr->A[arr->length++] = num;
}

void Insert(struct Array *arr, int num, int index)
{
    if(arr->length<arr->size)
    {

        if(index>0 && index <= arr->length)
        {

            for(int i = arr->length; i>index; i--)
                arr->A[i] = arr->A[i-1];

            arr->A[index] = num;

            arr->length++;

        }
    }
}

int LinearSearch(struct Array * arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(arr->A[i]==key)
        {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int Delete(struct Array *arr, int index)
{
    int x = 0;

    if(index>=0 && index<arr->length)
    {

        x = arr->A[index];

        for(int i = index; i < arr->length-1; i++)
        {

            arr->A[i] = arr-> A[i+1];

        }

        arr->length--;

        return x;

    }

    return 0;

}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;

    l = 0;
    h = arr.length-1;

    while(l <= h)
    {

        mid = (l + h)/2;

        if(arr.A[mid] == key)
            return mid;
        else if(key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;

}

int RBinSearch(int A[], int l, int h, int key)
{

    int mid = 0;

    if(l <= h)
    {

        mid = (l + h)/2;

        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return RBinSearch(A, l, mid - 1, key);
        else
            return RBinSearch(A, mid+1, h, key);
    }

    return -1;

}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

int Set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
        return 1;
    }
    return -1;
}

int Sum(struct Array arr)
{
    int sum = 0;
    for(int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

int Max(struct Array arr)
{
    int maxNum = arr.A[0];
    for(int i = 0; i < arr.length; i++)
    {
        if(maxNum < arr.A[i])
        {
            maxNum = arr.A[i];
        }
    }
    return maxNum;
}

int Min(struct Array arr)
{
    int minNum = arr.A[0];
    for(int i = 0; i < arr.length; i++)
    {
        if(minNum > arr.A[i])
        {
            minNum = arr.A[i];
        }
    }
    return minNum;
}

void Reverse1(struct Array *arr)
{
    int *B;

    B = (int*)malloc(arr->length*sizeof(int));

    for(int i = 0; i < arr->length; i++)
    {
        B[i] = arr->A[arr->length-1-i];
    }
    for(int i= 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }

}

void Reverse2(struct Array *arr)
{
    for(int i = 0; i < arr->length/2; i++)
    {
        int temp;

        temp = arr->A[i];

        arr->A[i] = arr->A[arr->length-i-1];

        arr->A[arr->length-i-1] = temp;

    }
}

void LeftShift(struct Array *arr){
    int temp = arr->A[0];

    for(int i = 0; i < arr->length-1; i++){
        arr->A[i] = arr->A[i+1];
    }

    arr->A[arr->length-1] = temp;

}

void RightShift(struct Array *arr){
    int temp = arr->A[arr->length-1];

    for(int i = arr->length-1; i > 0; i--){
        arr->A[i] = arr->A[i-1];
    }

    arr->A[0] = temp;

}

int main()
{

    struct Array arr= {{2,3,5,8,9,15,335,542},10,5};
    //int n;

    //printf("Please enter size of an array: ");

    //scanf("%d",&arr.size);

    //arr.A = (int*) malloc(arr.size*sizeof(int));

    //arr.length = 0;

    //printf("Please enter number of an numbers: ");

    //scanf("%d",&n);

    //arr.length = n;

    //printf("Please enter all elements: \n");

    //for(int i=0; i<n; i++){
    //printf("Number in array with index %d is: ", i);
    //scanf("%d", &arr.A[i]);

    //Insert(&arr, 111, 2);

    //Delete(&arr, 0);
    RightShift(&arr);

    //printf("%f \n", );

    DisplayArray(arr);

    return 0;
}





















