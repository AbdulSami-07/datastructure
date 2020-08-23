def selectionSort(list):

    for i in range(len(list)):
        minpos=i
        for j in range(minpos,len(list)):

            if list[j]<list[minpos]:
               minpos=j
        list[i],list[minpos]=list[minpos],list[i]

    return list

if __name__='__main__':

    arr=[3,5,12,4,2,3]
    arr=selectionSort(arr)
    print (arr)
