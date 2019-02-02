#include<ctime> 
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
int map[12][12];    // Ϊ����߽�����⴦���ʽ���ά�������ܱ߽���չ1
int derection[3] = { 0, 1, -1 };  //���ڴ���������Χ8���������
int type;
class bombsweep
{
public:
    int calculate ( int x, int y )
    {
        int counter = 0;
        for ( int i = 0; i < 3; i++ )
            for ( int j = 0; j < 3; j++ )
                if ( map[ x+derection[i]][ y+derection[j] ] == 9 )
                    counter++;                 // ͳ����(x,y)Ϊ������Χ8����ĵ�����Ŀ
        return counter;
    }
    void game ( int x, int y )
    {
        if ( calculate ( x, y ) == 0 )
        {
            map[x][y] = 0;
            for ( int i = 0; i < 3; i++ )
            {
                // ���㵽һ���հף���ϵͳ�Զ�������չ
                for ( int j = 0; j < 3; j++ )
                    if ( x+derection[i] <= 9 && y+derection[j] <= 9 && x+derection[i] >= 1 && y+derection[j] >= 1
                            && !( derection[i] == 0 && derection[j] == 0 ) &&  map[x+derection[i]][y+derection[j]] == -1 )
                        game( x+derection[i], y+derection[j] ); // һ�ǲ�������������������ͬʱΪ0������ݹ���ñ���
            }                                                      //���ǵݹ鲻�ܳ���.����Ҫ��֤�����ص��á�
        }
        else
            map[x][y] = calculate(x,y);
    }
 
    void print (int x,int y)
    {
        cout << "  |";
        for (int i=1; i<10; i++)
            cout << " " << i;
        cout << endl;
        cout << "__|__________________Y" ;
        cout << endl;
        for ( int i = 1; i < 10; i++ )
        {
            cout << i << " |";
            for ( int j = 1; j < 10; j++ )
            {
                if(map[i][j]==-2)
                    cout <<" B";
                else if ( map[i][j] == -1 || map[i][j] == 9 )
                    cout << " #";
                else
                    cout << " "<< map[i][j];
 
            }
            cout << "\n";
        }
        cout << "  X\n";
    }
    bool check ()
    {
        int counter = 0;
        for ( int i = 1; i < 10; i++ )
            for ( int j = 1; j < 10; j++ )
                if ( map[i][j] != -1 )
                    counter++;
        if ( counter == 10 )
            return true;
        else
            return false;
    }
};
 
int main ()
{
 
    int i, j, x, y;
    char ch;
    srand ( time ( 0 ) );
 
    do
    {
        //��ʼ������
        memset ( map, -1, sizeof(map) );
 
        for ( i = 0; i < 10;  )
        {
            x = rand()%9 + 1;
            y = rand()%9 + 1;
            if ( map[x][y] != 9 )
            {
                map[x][y] = 9;
                i++;
            }
        }
 
        cout << "  |";
        for (i=1; i<10; i++)
            cout << " " << i;
        cout << endl;
        cout << "__|__________________Y" ;
        cout << endl;
        for ( i = 1; i < 10; i++ )
        {
            cout << i << " |";
            for ( j = 1; j < 10; j++ )
                cout << " "<< "#";
            cout << "\n";
        }
        cout << "  X\n";
        cout << "Please input location x,press enter then input location y: \n";
        while ( cin >> x >> y )
        {
            cout << "Please select:1.dig, 2.sign, 3.cancel sign, 4.restart, 5.exit: \n";
            cin >>type;
            switch(type)
            {
            case 1:
            {
                if ( map[x][y] == 9 || map[x][y]==-2)
                {
                    cout << "YOU LOSE!" << endl;
                    cout << "  |";
                    for (i=1; i<10; i++)
                        cout << " " << i;
                    cout << endl;
                    cout << "__|__________________Y"<<endl ;
                    for ( i = 1; i < 10; i++ )
                    {
                        cout << i << " |";
                        for ( j = 1; j < 10; j++ )
                        {
                            if ( map[i][j] == 9 || map[i][j]==-2)
                                cout << " @";
                            else
                                cout << " #";
                        }
                        cout << "\n";
                    }
                    cout << "  X\n";
                    exit(0);
                }
 
                bombsweep bs;
                bs.game(x,y);
                bs.print(x,y);
                cout << "Please input location x,press enter then input location y: \n";
 
                if ( bs.check())
                {
                    cout << "YOU WIN" << endl;
                    break;
                }
                continue;
            }
 
            case 2:
            {
                bombsweep bs;
                map[x][y]=-2;
                bs.print(x,y);
                cout << "Please input location x,press enter then input location y: \n";
                continue;
            }
 
            case 3:
            {
                bombsweep bs;
                map[x][y]=-1;
                bs.print(x,y);
                cout << "Please input location x,press enter then input location y: \n";
                continue;
            }
 
            case 4:
            {
                memset ( map, -1, sizeof(map) );
 
                for ( i = 0; i < 10;  )
                {
                    x = rand()%9 + 1;
                    y = rand()%9 + 1;
                    if ( map[x][y] != 9 )
                    {
                        map[x][y] = 9;
                        i++;
                    }
                }
 
                cout << "  |";
                for (i=1; i<10; i++)
                    cout << " " << i;
                cout << endl;
                cout << "__|__________________Y" ;
                cout << endl;
                for ( i = 1; i < 10; i++ )
                {
                    cout << i << " |";
                    for ( j = 1; j < 10; j++ )
                        cout << " "<< "#";
                    cout << "\n";
                }
                cout << "  X\n";
                cout << "Please input location x,press enter then input location y: \n";
                continue;
            }
            case 5:
                cout << "Game Ended\n";
                exit(0);
                break;
            default:
                cout<< "Invalid input, try again: \n";
                continue;
            }//end switch
 
        }//end while(cin >> x >>y)
        cout << "Do you want to play again?(y/n):" << endl;
        cin >> ch;
    }//end do
    while ( ch == 'y' );
    return 0;
}//end main()

