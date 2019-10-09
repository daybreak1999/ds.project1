#include<iostream>
#include<fstream>

using namespace std;

class map {
    public:

        map(int r, int c) {
            row = r;
            col = c;
            dot = new bool*[row + 4];
            for (int i = 0; i < row + 4; i++)
                dot[i] = new bool[col];
            
            for (int i = 0; i < row + 4; i++)
                for (int j = 0; j < col; j++)
                    dot[i][j] = 0;
        }

        void out() {

            for (int i = row - 1; i >= 0; i--) {
                for (int j = 0; j < col; j++)
                    cout << dot[i][j];
                cout << endl;
            }
        }

        void drop(char type[], int line);
        void t1(int line);

    private:

        int row;
        int col;
        bool **dot;
};


int main(void)
{
    int row, col;
    char type[3] = "";
    int line = 0;    

    cin >> row >> col;
    map A(row, col);
    
    cin >> type >> line;

    // A.drop(type, line);
    A.out();

    return 0;
}

void map::drop(char type[], int line)
{
    switch(type) {
        case "T1":
            t1(line);
            break;
        default:        
    }
}

void map::t1(int line) 
{
    map[row + 1][line] = 1;
    
}