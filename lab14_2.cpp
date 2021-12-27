#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool R[][M],int s,int x,int y){
    int S;
    if(s >= 1){
        S = s;
    }
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 70; j++){
            double b = sqrt(pow(i-x,2)+pow(j-y,2));
            if(b <= S-1){
                R[i][j] = 1;
            }
        }
    }
}

void showImage(const bool R[][M]){
    for(int e = 0; e < 72 ; e++){
        cout << "-";
    }
    cout << "\n";
    for(int i = 0; i < 30; i++){
        cout << "|";
        for(int j = 0; j < 70; j++){
            if(R[i][j] == 1){
                cout << "*";
            }
            if(R[i][j] == 0){
                cout << " ";
            }
        }
        cout << "|\n";
    }
    for(int f = 0; f < 72 ; f++){
        cout << "-";
    }
    cout << "\n";
}