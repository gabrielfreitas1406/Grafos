#include <iostream>
#include <vector> 

using namespace std;
int m,n,x,y,z; 

int main() {
    cin >> m >> n;
    while (m != 0 && n != 0){
        while (n > 0){
            cin >> x >> y >> z;
            n --;
            //cout << n;
        }
        cout << "saiu!\n";
        cin >> m >> n;
    }
    
    return 0;
}
