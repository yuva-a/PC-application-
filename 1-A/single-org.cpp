//*YUVA*
    #include<bits/stdc++.h>
    using namespace std;

const int n = 100;

void move(int &x,int &y,int r,int a[n][n])
{
    //m = rand()%4;
    // 0 - right // 1 - left // 2 - up // 3 - down

    int dis=0;
    for(;dis<=r;dis++)
    {
        for(int i=0;i<=dis;i++)
        {
            if(x+i<n && y+dis-i<n && a[x+i][y+dis-i]==2)
            {
                if(i!=0){x++; return;}
                y++; return;
            }
        }

        for(int i=0;i<=dis;i++)
        {
            if(x-(i)>=0 && y-(dis-i)>=0 && a[x-(i)][y-(dis-i)]==2)
            {
                if(i!=0){x--; return;}
                y--; return;
            }
        }

        for(int i=0;i<=dis;i++)
        {
            if(x+(i)<n && y-(dis-i)>=0 && a[x+(i)][y-(dis-i)]==2)
            {
                if(i!=0){x++; return;}
                y--; return;
            }
        }

        for(int i=0;i<=dis;i++)
        {
            if(x-(i)>=0 && y+(dis-i)<n && a[x-(i)][y+(dis-i)]==2)
            {
                if(i!=0){x--; return;}
                y++; return;
            }
        }
    }

    int X = x, Y = y;
    do
    {
        int m = rand()%4;

        if(m==0){X=x; Y=y+1;}
        if(m==1){X=x; Y=y-1;}
        if(m==2){X=x-1; Y=y;}
        if(m==3){X=x+1; Y=y;}

    }while(X<0 ||  X>=n || Y<0 || Y>=n);

    x=X; y=Y;
}

void get()
{
    int k,r; cin>>k>>r;

    int xo,yo; cin>>xo>>yo;

    int a[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;

    a[0][0]=1;

    //placing food
    for(int i=0;i<k;i++)
    {
        int x = rand()%n;
        int y = rand()%n;

        while(a[x][y]!=0)
        {
            x = rand()%n;
            y = rand()%n;
        }

        a[x][y]=2;
    }

    cout<<"("<<xo<<","<<yo<<") -> start"<<endl;

    int x = xo,y = yo;
    int noof_eaten=0;

    for(int j=0;j<10000;j++)
    {
        a[x][y]=0;
        move(x,y,r,a);

        cout<<"("<<x<<","<<y<<") -> ";
        if(a[x][y]==2)
        {
            cout<<"eaten";
            noof_eaten++;
        }
        else
        {
            cout<<"-";
        }
        a[x][y] = 1;
        cout<<endl;
    }

    cout<<noof_eaten<<" eaten out of "<<k;
}



int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    get();
}