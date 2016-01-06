// -----------------------------------text book version ------------------------------//

template <class>   
void Merge(T* initList, T* mergedList, const int l,const int m, const int n)
{
	// initList[l:m]  + initList[ m+1:n]  ---------> mergedList[l:n]
	
	for(int i1 = l, iResult =l, i2= m+1 ; i1<=m && i2<=n;  iResult++)
	// i1 = the index for initList[l:m]
	// i2 = the index for initList[m+1:n]
	// iResult = index for mergedList[l:n]
	// when i1 >m   or i2 >n ---------> one of them is done
	// then no need to compare,  go out of loop and do the rest
	{
		if(initList[i1]<= initList[i2])
		{
			mergedList[iResult] = initList[i1];
			i1++;
		}
		else
		{
			mergedList[iResult] = initList[i2];
			i2++
		}
	}

	// the doing the rest of the mergeList[:n]
	copy(initList + i1, initList + m +1 , mergedList + iResult);
		// copy initList[i1:m]  to mergedList[]  from mergedList[iResult]
	copy(initList + i2, initList + n +1 , mergedList+ iResult);
		// copy initList[i2:n]  to mergedList[]  from mergedList[iResult]

}

// ---------------- MergePass  :  Merge the initList to resultList
template <class T>
void MergePass( T* initList, T* resultList, const int n , const int s)
//   s:   # of sublist
//   n:   size of initList
//   initList  ---  source of all sublist 
//   resultList  ------  stored the merged list
{
	for(int i=1; i<= n-2*s+1; i+=2*s)
	// i=1  ---------   i is first element of first sublist being merged
	// n-2*s+1   ------ preserve 2 sublists for last compare and out of loop
	// i+= 2*s  ------- i jump to next two sublist to merge
	{
		Merge(initList,resultList,i,i+s-1,i+2*s-1);
		//   Merging initList[i:i+s-1]  and initList[i+s: i+2*s-1]

	}

	// doing the last merging with smaller size

		if( (i+s-1)<n ) Merge(initList, resultList, i, i+s-1, n);
		//   Merge initList[i:i+s-1] and initList[i+s: n]

		////////////////
		/////QQQQQQ/////
		///Q/////Q//////
		//Q///////Q/////
		///////QQ///////
		//////Q/////////
		////////////////
		//////Q/////////
		////////////////
		// why merge the rest of the unMerge element to the resultList ???
		else copy(initList+i, initList+n+1, resultList +i);
}

template <class T>
void MergeSort (T * a, const int n)// Sort a[1:n] into nondecreasing order.
{
	T* tempList = new T[n+1];// tempList[0] is not used

	//     'l' is the length of the sublist currently being merged
	//     
	for(int l=1;l<n ; l*=2)
	{
		MergePass(a,tempList,n,l); 

		////////////////
		/////QQQQQQ/////
		///Q/////Q//////
		//Q///////Q/////
		///////QQ///////
		//////Q/////////
		////////////////
		//////Q/////////
		////////////////
		// why interchange role of a and tempList
		l*=2;
		
		MergePass(tempList, a, n, l);// interchange role of a and temmpList
	}
	delete [] tempList;
}
