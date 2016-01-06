//------------------- Handout Version -------------------------//

template <class T>
int rMergeSort(T* a, int* link, const int left, const int right)
// a[left:right] is to be sorted.
// link[i] is initially 0 for all i
// rMergeSort returns the index of the first element in the sorted chain
{
	if(left >= right) return left;
	int mid = (left + right)/2;
	// it would keep calling ListMerge  exponentially untill left >= right
	// which means that it break all a[] into single elements !!!!

	return ListMerge(a  ,link  , rMergeSort(a,link,left,mid),//  sort the leftside
							  	 rMergeSort(a,link,mid+1,right)// sort the rightside);
}

template <class T>
int ListMerge(T*a, int* link, const int start1, const int start2)
{
	int iResult =0;// link[0] is a register
	for(int i1=start1,i2 = start2 ; i1 && i2; )
	{
		if(a[i1] <= a[i2])
		{
			link[iResult] = i1;   // link[iResult] point to the smaller one

			iResult = i1;		 // iResult tempory store i1
			i1 = link[i1];		 // update i1 to the next position of link[i1]
		}
		else
		{
			link[iResult] = i2;  // link[iResult] point to the smaller one i2

			iResult = i2;		 // iResult tempory store i2
			i2 = link[i2];       // update i2 to the next position of link[i2]
		}

		//----------   why we need to store the iResult ????? ------------
		// Ans :  because link[iResult] would point to the next sorted link index
	}

	//  out of for loop  either i1 or i2 has no data
	//  link[iResult] should point to the rest of the sorted data
	if(i1 == 0) link[iResult]= i2;
	else link[iResult] =i1; 


	return link[0];  
//    amazing one !!!!   link[0] would always store the smallest one of the first comparison
//    link[0]  store the smallest element of this sorted sublist
}
