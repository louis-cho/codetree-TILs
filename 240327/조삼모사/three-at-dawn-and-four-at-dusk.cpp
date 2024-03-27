#include <iostream>
using namespace std;

int n, half;
int P[20][20];
bool isMorning[20];
int answer = 1e9;

int calculation();

void initSelected() {
    for(int i=0; i<20; i++)
    {
        isMorning[i] = false;
    }
}

void selectMorning(int cnt, int lastIndex) {
    if(cnt == half) {
        answer = min(answer, calculation());
        return;
    }

    if(cnt > half)
        return;

    for(int i=lastIndex+1; i<n; i++)
    {
        isMorning[i] = true;
        selectMorning(cnt+1, i);
        isMorning[i] = false;
    }
}

int calculation() {
    int morning = 0;
    int aftermorning = 0;

    for(int i=0; i<n; i++) {
        if(isMorning[i]) {
            for(int j=i+1; j<n; j++) {
                if(isMorning[j]) {
                    morning += P[i][j];
                    morning += P[j][i];
                }
            }
        } else {
            for(int j=i+1; j<n; j++) {
                if(!isMorning[j]) {
                    aftermorning += P[i][j];
                    aftermorning += P[j][i];
                }
            }
        }
    }

    return morning - aftermorning < 0 ? aftermorning - morning : morning - aftermorning;
}

int main() {
    cin >> n;
    half = n / 2;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> P[i][j];
        }
    }

    selectMorning(0, -1);

    cout << answer;
    return 0;
}