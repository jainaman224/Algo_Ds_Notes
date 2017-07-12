#include <iostream>

using namespace std;

int main()
{
    int a[100][100];
    int N;
    cout << "Enter the size of the chakravyuha: ";
    cin >> N;
    int top=0,bottom=N-1,left=0,right=N-1;
//for keeping tabs on which direction we are moving
    int k=1;
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            a[top][i] = k;
            k++;
        }
        top++;
        for(int i = top; i <= bottom; i++){
            a[i][right] = k;
            k++;
        }
        right--;
        for(int i = right; i >= left; i--){
            a[bottom][i] = k;
            k++;
        }
        bottom--;
        for(int i = bottom; i >= top; i--){
            a[i][left] = k;
            k++;
        }
        left++;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
