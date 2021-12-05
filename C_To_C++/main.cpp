#include <iostream>

using namespace std;


class Array
{
private:
    int *A;
    int _size;
    int length;
    void Swap(int *x, int *y);
public:
    Array() {
        _size = 10;
        length = 0;
        A = new int[_size];
    }
    Array(int sz) {
        _size = sz;
        length = 0;
        A = new int[_size];
    }
    ~Array() {
        delete []A;
    }

    void DisplayArray();
    void Add(int num);
    void Insert(int num, int index);
    int LinearSearch(int key);
    int Delete(int index);
    int BinarySearch(int key);
    //    int RBinSearch(int A[], int l, int h, int key);
    int Get(int index);
    int Set(int index, int x);
    int Sum();
    float Avg();
    int Max();
    int Min();
    void Reverse1();
    void Reverse2();
    void LeftShift();
    void RightShift();
    void InsertInSorted(int num);
    int IsSorted();
    void Rearrange();
    Array* MergeArrays(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* LeftJoin(Array *arr2);
};

void Array::DisplayArray()
{

    printf("Elements in array is: \n");

    for (int i = 0; i < length; i++)
        printf("%d ", A[i]);

};

void Array::Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Array::Add(int num)
{
    if (length < _size)
        A[length++] = num;
}

void Array::Insert(int num, int index)
{
    if (index >= 0 && index <= length)
    {

        for (int i = length; i > index; i--)
            A[i] = A[i - 1];

        A[index] = num;

        length++;

    }
}

int Array::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            Swap(&A[i], &A[0]);
            return i;
        }
    }

    return -1;
}

int Array::Delete(int index)
{
    int x = 0;

    if (index >= 0 && index < length)
    {

        x = A[index];

        for (int i = index; i < length - 1; i++)
        {

            A[i] = A[i + 1];

        }

        length--;

        return x;

    }

    return 0;

}

int Array::BinarySearch(int key)
{
    int l, mid, h;

    l = 0;
    h = length - 1;

    while (l <= h)
    {

        mid = (l + h) / 2;

        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;

}

//int RBinSearch(int A[], int l, int h, int key)
//{
//
//    int mid = 0;
//
//    if (l <= h)
//    {
//
//        mid = (l + h) / 2;
//
//        if (key == A[mid])
//            return mid;
//        else if (key < A[mid])
//            return RBinSearch(A, l, mid - 1, key);
//        else
//            return RBinSearch(A, mid + 1, h, key);
//    }
//
//    return -1;
//
//}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }

    return -1;
}

int Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
        return 1;
    }

    return -1;
}

int Array::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }

    return sum;
}

float Array::Avg()
{
    return (float)Sum() / length;
}

int Array::Max()
{
    int maxNum = A[0];

    for (int i = 0; i < length; i++)
    {
        if (maxNum < A[i])
        {
            maxNum = A[i];
        }
    }

    return maxNum;
}

int Array::Min()
{
    int minNum = A[0];

    for (int i = 0; i < length; i++)
    {
        if (minNum > A[i])
        {
            minNum = A[i];
        }
    }

    return minNum;
}

void Array::Reverse1()
{
    int *B;

    B = (int*)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        B[i] = A[length - 1 - i];
    }

    for (int i = 0; i < length; i++)
    {
        A[i] = B[i];
    }

}

void Array::Reverse2()
{
    for (int i = 0; i < length / 2; i++)
    {
        int temp;

        temp = A[i];

        A[i] = A[length - i - 1];

        A[length - i - 1] = temp;

    }
}

void Array::LeftShift()
{
    int temp = A[0];

    for (int i = 0; i < length - 1; i++)
    {
        A[i] = A[i + 1];
    }

    A[length - 1] = temp;

}

void Array::RightShift()
{
    int temp = A[length - 1];

    for (int i = length - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }

    A[0] = temp;

}

void Array::InsertInSorted(int num)
{
    int index = 0;

    while (num > A[index] && index < length)
    {
        index++;
    }

    ++length;

    for (int i = length - 1; i > index; i--)
    {
        A[i] = A[i - 1];
    }

    A[index] = num;

}

int Array::IsSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

void Array::Rearrange()
{
    int i, j;

    i = 0;

    j = length - 1;

    while (i < j)
    {
        while (A[i] < 0) i++;

        while (A[j] > 0) j--;

        if (i < j)
        {
            Swap(&A[i], &A[j]);
        }
    }
}

struct Array* Array::MergeArrays( Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = length + arr2->length;

    arr3->_size = 20;

    return arr3;
}

struct Array* Array::Union( Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (arr2->A[j] < A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;

    arr3->_size = 20;

    return arr3;

};

struct Array* Array::Intersection(Array *arr2)
{

    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < A[i])
            j++;
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;

    arr3->_size = 20;

    return arr3;

};

struct Array* Array::LeftJoin(struct Array *arr2)
{

    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (arr2->A[j] < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    arr3->length = k;

    arr3->_size = 20;

    return arr3;

};

int main()
{
    Array *arr1;
    int ch;
    int x, sz, index;
    printf("Enter Size of Array: ");
    scanf("%d", &sz);

    arr1 = new Array(sz);

    do
    {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");
        printf("enter you choice ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter an element and index ");
                scanf("%d%d", &x, &index);
                arr1->Insert(x, index );
                break;

            case 2:
                printf("Enter index ");
                scanf("%d", &index);
                x = arr1->Delete(index);
                printf("Deleted Element is %d\n", x);
                break;

            case 3:
                printf("Enter element to search ");
                scanf("%d", &x);
                index = arr1->LinearSearch( x);
                printf("Element index %d", index);
                break;

            case 4:
                printf("Sum is %d", arr1->Sum());
                break;

            case 5:
                arr1->DisplayArray( );
        }
    }
    while ( ch < 6 );

    return 0;
}





















