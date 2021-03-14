#include <iostream>
#include <vector>

using namespace std;

int total = 0;

void swap(vector<int>& A, int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void sortFirstElement(vector<int>& A, int start, int finish) {
    if (finish - start < 2) {
        return;
    }

    int l = start;
    int r = finish;
    int P = A[l];
    int i = l + 1;
    for (int j = l + 1; j < r; j++) {
        total++;
        if (A[j] < P) {
            swap(A, j, i);
            i++;
        }
    }
    swap(A, l, i - 1);


    sortFirstElement(A, start, i);
    sortFirstElement(A, i, finish);
}

void sortLastElement(vector<int>& A, int start, int finish) {
    if (finish - start < 2) {
        return;
    }

    int l = start;
    int r = finish;
    int P = A[finish - 1];
    int i = l + 1;
    for (int j = l + 1; j < r; j++) {
        total++;
        if (A[j] < P) {
            swap(A, j, i);
            i++;
        }
    }
    swap(A, l, i - 1);

    sortFirstElement(A, start, i);
    sortFirstElement(A, i, finish);
}

int indexOfMedian(vector<int>& A, int start, int finish) {
    int middleIndex;
    if (finish % 2 == 0) {
        middleIndex = (finish + start) / 2 + 1;
    } else {
        middleIndex = (finish + start) / 2;
    }
    cout << "middleIndex: " << middleIndex << "; Value: " << A[middleIndex] << endl;
    if ((A[finish] > A[start] && A[start] > A[middleIndex]) || (A[finish] < A[start] && A[start] < A[middleIndex])) {
        return start;
    }
    if ((A[start] > A[finish] && A[finish] > A[middleIndex]) || (A[start] < A[finish] && A[finish] < A[middleIndex])) {
        return finish;
    }
    return middleIndex;
}

void sortMedianElement(vector<int>& A, int start, int finish) {
    if (finish - start < 2) {
        return;
    }

    int l = start;
    int r = finish;

    cout << "Before sort" << endl;
    for (int k = start; k < finish; k++)
        cout << "Index: " << k << "; K: " << A[k] << endl;

    int P = A[indexOfMedian(A, start, finish - 1)];
    int i = l;
    for (int j = l; j < r; j++) {
        total++;
        if (A[j] < P) {
            swap(A, j, i);
            i++;
        }
    }
//    swap(A, l, i - 1);

    cout << "After sort" << endl;
    for (int k = start; k < finish; k++)
        cout << "Index: " << k << "; K: " << A[k] << endl;

    cout << "-----" << endl;
    cout << "| Start: " << start << "; Finish: " << i << endl;
    cout << "| Start: " << i + 1 << "; Finish: " << finish << endl;
    cout << "-----" << endl;

    sortMedianElement(A, start, i);
    sortMedianElement(A, i + 1, finish);
}

void quickSort(vector<int>& A, int start, int finish) {
    cout << "Recursion" << endl;
    if (finish - start < 2) return;

    int medianIndex = indexOfMedian(A, start, finish - 1);
    int i = start;
    int j = medianIndex + 1;
    bool isMore = false;
    bool isLess = false;
    bool iFinish = false;
    bool jFinish = false;
    while (i < medianIndex || j < finish) {
        cout << "I: " << i << "; J: " << j << endl;
        if (A[i] > A[medianIndex]) {
            isMore = true;
        } else {
            i++;
            if (i + 1 >= medianIndex) iFinish = true;
        }

        if (A[j] < A[medianIndex]) {
            isLess = true;
        } else {
            j++;
            if (j + 1 >= finish) jFinish = true;
        }

        if (isMore && isLess) {
            swap(A, j, i);
            isMore = false;
            isLess = false;
        }

        if (isMore && jFinish) {
            swap(A, medianIndex, medianIndex - 1);
            swap(A, i, medianIndex);
            medianIndex--;
            isMore = false;
        }

        if (isLess && iFinish) {
            swap(A, medianIndex, medianIndex + 1);
            swap(A, j, medianIndex);
            medianIndex++;
            isLess = false;
        }
    }

    for (int k = start; k < finish; k++)
        cout << "Index: " << k << "; K: " << A[k] << endl;

    cout << "medianIndex: " << medianIndex << endl;

    if (medianIndex == 9) quickSort(A, 0, medianIndex);
//    quickSort(A, medianIndex + 1, A.size());
}

int main() {
//    vector<int> A{2, 20, 1, 15, 3, 11, 13, 6, 16, 10, 19, 5, 4, 9, 8, 14, 18, 17, 7, 12};
//    sortFirstElement(A, 0, A.size());

//    for (int k : A)
//        cout << "K: " << k << endl;

//    cout << "Total: " << total << endl << endl;
//
//    total = 0;
//
//    vector<int> B{2, 20, 1, 15, 3, 11, 13, 6, 16, 10, 19, 5, 4, 9, 8, 14, 18, 17, 7, 12};
//    sortLastElement(B, 0, B.size());

//    for (int k : B)
//        cout << "K: " << k << endl;

//    cout << "Total: " << total << endl << endl;
//
//    total = 0;

    vector<int> C{2, 20, 1, 15, 3, 11, 13, 6, 16, 10, 19, 5, 4, 9, 8, 14, 18, 17, 7, 12};
//    sortMedianElement(C, 0, C.size());
    quickSort(C, 0, C.size());
    cout << "Finish: " << endl;
    for (int k : C)
        cout << "K: " << k << endl;
    cout << "Total: " << total;

    return 0;
}
