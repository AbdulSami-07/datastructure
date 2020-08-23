def merge_sorted(left=[],right=[]):
    (list,l,r)= ([],len(left),len(right))
    (i,j)=(0,0) #i for left and j for right

    while i+j<l+r:
        if i==l:
            list.append(right[j])
            j=j+1

        elif j==r:
            list.append(left[i])
            i=i+1

        elif left[i]<=right[j]:
            list.append(left[i])
            i=i+1

        elif left[i]>right[j]:
            list.append(right[j])
            j=j+1

    return list

def mergeSort(list=[]):
    if len(list)<2:
        return list

    mid=len(list)//2

    left=mergeSort(list[:mid])
    right=mergeSort(list[mid:])

    return merge_sorted(left,right)



