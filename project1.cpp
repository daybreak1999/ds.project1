#include <iostream>
#include <fstream>

using namespace std;

class map 
{

    friend class inputer;

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
            ofstream outFile("Tetris.final",ios::out);
            for (int i = row - 1; i >= 0; i--) {
                for (int j = 0; j < col; j++)
                    outFile << dot[i][j];
                outFile << endl;
            }
            outFile.close();
        }

        int drop(char type,int t_n, int line);
        bool clear(int row1);

    private:

        int row;
        int col;
        bool **dot;
};

int main(void)
{
    int row, col;
    char type = ' ';
    int type_n = 0;
    int line = 0;
    int dead = 0;

    ifstream inFile("Tetris.data", ios::in);
    
    inFile >> row >> col;
    map A(row, col);    
    
    inFile >> type;
    while (type != 'E' && ! inFile.eof()) {
        if (type != 'O')
            inFile >> type_n >> line;
        else
            inFile >> line;
        int x = A.drop(type, type_n, line);
        if(A.clear(x)) {
            A.out();
            dead = 1;
            break;
        }
        inFile >> type;
    } 
    inFile.close();
    if(!dead)
        A.out();

    return 0;
}

int map::drop(char type,int t_n, int line)
{
    int row1, row2, row3, row4; // row1 should be the lowest row in tetris
    int col1, col2, col3, col4;

    switch(type) {
        case 'T':
            if (t_n == 1) {
                row1 = row; col1 = line; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 1; col3 = line;
                row4 = row + 1; col4 = line + 1;     
            }
            else if (t_n == 2) {
                row1 = row; col1 = line; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 1; col3 = line;
                row4 = row + 2; col4 = line;               
            }
            else if (t_n == 3) {
                row1 = row; col1 = line - 1; 
                row2 = row; col2 = line;
                row3 = row; col3 = line + 1;
                row4 = row + 1; col4 = line;
            }
            else {
                row1 = row; col1 = line - 1; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 1; col3 = line;
                row4 = row + 2; col4 = line - 1;
            }
            break;
        case 'L':
            if (t_n == 1) {
                row1 = row; col1 = line - 1; 
                row2 = row; col2 = line;
                row3 = row + 1; col3 = line - 1;
                row4 = row + 2; col4 = line - 1;     
            }
            else if (t_n == 2) {
                row1 = row; col1 = line - 1; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 1; col3 = line;
                row4 = row + 1; col4 = line + 1;               
            }
            else if (t_n == 3) {
                row1 = row; col1 = line; 
                row2 = row + 1; col2 = line;
                row3 = row + 2; col3 = line - 1;
                row4 = row + 2; col4 = line;
            }
            else {
                row1 = row; col1 = line - 1; 
                row2 = row; col2 = line;
                row3 = row; col3 = line + 1;
                row4 = row + 1; col4 = line + 1;
            }
            break;
        case 'J':
            if (t_n == 1) {
                row1 = row; col1 = line - 1; 
                row2 = row; col2 = line;
                row3 = row + 1; col3 = line;
                row4 = row + 2; col4 = line;     
            }
            else if (t_n == 2) {
                row1 = row; col1 = line - 1; 
                row2 = row; col2 = line;
                row3 = row; col3 = line + 1;
                row4 = row + 1; col4 = line - 1;               
            }
            else if (t_n == 3) {
                row1 = row; col1 = line - 1; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 2; col3 = line - 1;
                row4 = row + 2; col4 = line;
            }
            else {
                row1 = row; col1 = line + 1; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 1; col3 = line;
                row4 = row + 1; col4 = line + 1;
            }
            break;
        case 'S':
            if (t_n == 1) {
                row1 = row; col1 = line - 1; 
                row2 = row; col2 = line;
                row3 = row + 1; col3 = line;
                row4 = row + 1; col4 = line + 1;     
            }
            else {
                row1 = row; col1 = line; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 1; col3 = line;
                row4 = row + 2; col4 = line - 1;               
            }
            break;
        case 'Z':
            if (t_n == 1) {
                row1 = row; col1 = line; 
                row2 = row; col2 = line + 1;
                row3 = row + 1; col3 = line - 1;
                row4 = row + 1; col4 = line;
            }
            else {
                row1 = row; col1 = line - 1; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 1; col3 = line;
                row4 = row + 2; col4 = line;
            }
            break;
        case 'I':
            if (t_n == 1) {
                row1 = row; col1 = line - 1; 
                row2 = row + 1; col2 = line - 1;
                row3 = row + 2; col3 = line - 1;
                row4 = row + 3; col4 = line - 1;
            }
            else {
                row1 = row; col1 = line - 1; 
                row2 = row; col2 = line;
                row3 = row; col3 = line + 1;
                row4 = row; col4 = line + 2;
            }
            break;
        case 'O':
            row1 = row; col1 = line - 1; 
            row2 = row; col2 = line;
            row3 = row + 1; col3 = line - 1;
            row4 = row + 1; col4 = line; 
        default: ;
    }

    bool stop = 0;
    for (int i = 0; i < row && !stop; i++) {
        if (dot[row1 - 1][col1] == 0 &&
            dot[row2 - 1][col2] == 0 &&
            dot[row3 - 1][col3] == 0 &&
            dot[row4 - 1][col4] == 0) {
        row1--; row2--; row3--; row4--;
        }
        else
            stop = 1;
    }

    dot[row1][col1] = 1;
    dot[row2][col2] = 1;
    dot[row3][col3] = 1;                
    dot[row4][col4] = 1;

    return row1;
}

bool map::clear(int row1)
{
    int clearline[4] = {0};
    int clear_n = 0;
    int ifclear = 0;
    int seconddrop = 0;

    // very special case: the case we need to clear more than second times (always need to clear)
    if (col == 1) {
        for (int i = 0; i < row + 4; i++)
            dot[i][0] = 0;
        return 0;
    }

    // find line to clear
    for (int i = 0; i < 4 && row1 + i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dot[row1 + i][j] == 0)
                break;
            if (j == col - 1) {
                for (int k = 0; k < col; k++) 
                    dot[row1 + i][k] = 0;
                clearline[clear_n] = row1 + i;
                clear_n++;
                ifclear = 1;
            }
        }
    }

    for (; clear_n > 0; clear_n--) {
        for (int i = clearline[clear_n - 1] + 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(dot[i][j] == 1) {
                    dot[i][j] = 0;
                    dot[i - 1][j] = 1;
                }
            }
        }
    }

    int row2[3] = {0};
    int col2[3] = {0};
    int k = 0;

    // check dead
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < col; j++) {
            if (dot[row + i][j] == 1) {
                if (ifclear) {
                    seconddrop = 1;
                    row2[k] = row + i;
                    col2[k] = j;
                    k++;
                    dot[row + i][j] = 0;
                }
                else
                    return 1;
            }
        }
    }

    // second drop
    int stop = 0;
    if (seconddrop) {
        for (int i = 0; i < row && !stop; i++) {
            for (int m = 0; m < k; m++) {
                if (dot[row2[m] - 1][col2[m]] != 0)
                    stop = 1;
            }
            if (!stop) {
                for (int m = 0; m < k; m++)
                    row2[m]--;
            }
        }
        for (int m = 0; m < k; m++)
            dot[row2[m]][col2[m]] = 1;
    }
    else 
        return 0;   


    clearline[4] = {0};
    clear_n = 0;

    // second find line to clear
    for (int i = 0; i < 3 && row2[0] + i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dot[row2[0] + i][j] == 0)
                break;
            if (j == col - 1) {
                for (int k = 0; k < col; k++) 
                    dot[row2[0] + i][k] = 0;
                clearline[clear_n] = row2[0] + i;
                clear_n++;
            }
        }
    }

    // second clear
    for (; clear_n > 0; clear_n--) {
        for (int i = clearline[clear_n - 1] + 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(dot[i][j] == 1) {
                    dot[i][j] = 0;
                    dot[i - 1][j] = 1;
                }
            }
        }
    }



    // second check dead
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < col; j++) {
            if (dot[row + i][j] == 1) {
                return 1;
            }
        }
    }

    return 0;
}