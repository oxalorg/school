#include<stdlib.h>
#include<stdio.h>

void shlSort(int [], int, int);
void qckSort(int [], int, int);
int part(int [], int, int);
void mrgSort(int [], int, int);
void merge(int [], int, int, int);

int main(){
	
	int a[10], n, i, sortChoice;
	
	system("clear"); //clrscr() in Windows
	
	printf("Enter Number of Elements in the array, followed by the elements\n");
	scanf("%d",&n);
	
	i = 0;
	while( i < n )
		scanf("%d",&a[i++]);
	
	printf("\n1.InsertionSort\n2.ShellSort\n3.QuickSort\n4.MergeSort\n5.HeapSort\n6.RadixSort\n");
	scanf("%d",&sortChoice);
	switch(sortChoice){
	
	//case 1: insSort();break; //Skipped for Now
	case 2: shlSort(a,n,4);break;
	case 3: qckSort(a,0,n-1);break;
	case 4: mrgSort(a,0,n-1);break;
	//case 5: hipSort();break;
	//case 6: rdxSort();break;
	default: break;
	
	}

	i = 0;
	while ( i < n )
		printf(" %d ",a[i++]);
		
	printf("\nEnter an Integer to ClearScreen --> EXIT, anything else to simply EXIT.");
	if( scanf("%d",&i) == 1 ) system("clear");

	return 0;
}

//	**** SHELL SORT ****

void shlSort(int a[10], int n,int incr){
	int i, j, c, k;
	while(incr > 0){
		for(i = incr; i<n; i++){
			k = a[i];
			for(j = i; j >= incr && k < a[j - incr] ; j -= incr)
				a[j] = a[j - incr];
			
			a[j] = k;
			
		}
		printf("\nPass %d:",incr%4);
		for( c = 0; c < n; c++ )
			printf(" %d ",a[c]);
		
		incr = incr/2;
	}
}

//	**** QUICK SORT ****

void qckSort(int a[10], int first, int last){
	int loc;
	if( first < last){
		loc = part(a, first, last);
		qckSort(a, first, loc);
		qckSort(a, loc+1, last);
		
	}
}
			
int part(int a[10], int first, int last){
	int left = first;
	int right = last;
	int pivot = a[first];
	int temp;
	while(left < right){
		while((a[left] <= pivot) && left < last)
			left++;
		
		while(a[right] > pivot)
			right--;
		
		if( left < right ){
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}
	
	a[first] = a[right];
	a[right] = pivot;
	
	return right;
}	

//	**** MERGE SORT ****

void mrgSort(int a[10], int first, int last){
	int mid;
	if( first < last ){
		mid = (first + last)/2;
		mrgSort(a, first, mid);
		mrgSort(a, mid+1, last);
		merge(a, first, mid, last);
	}
}

void merge(int a[10], int first, int mid, int last){
	int first1 = first;
	int last1 = mid;
	int first2 = mid+1;
	int last2 = last;
	int temp[10];
	int im = first;
	int k;
	
	while( (first1 <= last1) && (first2 <= last2) ){
		if( first1 < first2 ){
			temp[im++] = a[first1++];
		} else if( first1 > first2 ){
			temp[im++] = a[first2++];
		} else if( first1 == first2 ){
			temp[im++] = a[first1++];
			temp[im++] = a[first2++];
		}
	}
	while( first2 < last2 )
		temp[im++] = a[first2++];
	
	while( first1 < last1 )
		temp[im++] = a[first1++];
	
	for( k = first; k < last; k++)
		a[k] = temp[k];
	
}
		
