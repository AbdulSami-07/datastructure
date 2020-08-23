import random

def QuickSort(A,l,r):
	if l >= r:
		return
	m = partition(A,l,r)
	QuickSort(A,l,m-1)
	QuickSort(A,m+1,r)

def partition(A,l,r):
	i,j = 1,1
	pivot = 0 #pivot element is 1st element.
	for k in range(1,r):
		if A[k] <= A[pivot] and i < j :
			A[j] , A[k] = A[k] , A[j]
		elif A[k] <= A[pivot]:
			i = k
		elif A[k] > A[pivot]:
			j = k
	A[pivot] , A[i] = A[i] , A[pivot]
	return i

if __name__ == '__main__':
	a = [random.randint(1,100) for i in range(10)]
	print(a)
	QuickSort(a,0 , 9)
	print(a)
