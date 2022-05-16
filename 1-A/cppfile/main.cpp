//*YUVA*
    #include<bits/stdc++.h>
    using namespace std;

class person
{
public:
    char race;
    int money;
};

void initialise(person p[],int x,int y,int z)
{
    int i=0;
    for(int j=0;j<x;j++,i++)
    {
        p[i].race='A';
        p[i].money=0;
    }

    for(int j=0;j<y;j++,i++)
    {
        p[i].race='B';
        p[i].money=0;
    }

    for(int j=0;j<z;j++,i++)
    {
        p[i].race='C';
        p[i].money=0;
    }
}

void play(person &p1,person &p2)
{
    if(p1.race=='A' && p2.race=='B')
    {
        p1.money+=30;
        p2.money-=10;
    }

    if(p1.race=='B' && p2.race=='A')
    {
        p1.money-=10;
        p2.money+=30;
    }

    if(p1.race=='C' && p2.race=='A')
    {
        p1.money--;
        p2.money+=3;
    }

    if(p1.race=='A' && p2.race=='C')
    {
        p2.money--;
        p1.money+=3;
    }

    if((p1.race=='C' || p1.race=='B') && (p2.race=='B' || p2.race=='C'))
    {
        p1.money+=20;
        p2.money+=20;
    }
}

void eliminate(person p[])
{
    for(int i=24;i>=0;i--)
    {
        for(int j=i;j<24;j++)
        {
            if(p[j+1].money<p[j].money)
            {
                int inttemp = p[j+1].money;
                char chartemp = p[j+1].race;

                p[j+1].money = p[j].money;
                p[j+1].race = p[j].race;

                p[j].money = inttemp;
                p[j].race = chartemp;
            }
            else break;
        }
    }

    int a[25]={0};

    int del[5];
    int x=0;
    int i=24;
    int j;

    while(x<5)
    {
        j=i;
        while(j>=0 && p[i].money==p[j].money)
        {
            j--;
        }

        j++;

        if(5-x > i-j+1)
        {
            for(int r=i;r<=j;r++)
            {
                if(a[r]==1)continue;
                del[x]=r;
                x++;
            }
        }
        else
        {
            while(x<5)
            {
                int index;
                int check;
                do
                {
                    index = j + rand()%(i-j+1);

                    check=0;
                    for(int h=0;h<x;h++)
                    {
                        if(del[h]==index)check++;
                    }
                } while (check!=0);

                del[x]=index;
                x++;
            }
        }
        i=j-1;
    }

    for(int r=0;r<5;r++){a[del[r]]=1; cout<<p[del[r]].race<<" ";}
    cout<<endl;

////////////////////////////////////////////////////////
    int reproduce[5];
    x=0;
    i=0;

    while(x<5)
    {
        int cnt=0;
        j=i;
        while(j<25 && p[i].money==p[j].money)
        {
            if(a[j]==1)cnt++;
            j++;
        }

        j--;

        if(5-x > j-i+1 - cnt)
        {
            for(int r=i;r<=j;r++)
            {
                if(a[r]==1)continue;
                reproduce[x]=r;
                x++;
            }
        }
        else
        {
            while(x<5)
            {
                int index;
                int check;
                do
                {
                    index = i + rand()%(j-i+1);

                    check=0;
                    for(int h=0;h<x;h++)
                    {
                        if(reproduce[h]==index)check++;
                    }
                } while (check!=0);

                reproduce[x]=index;
                x++;
            }
        }
        i=j+1;
    }

    for(int r=0;r<5;r++)cout<<p[reproduce[r]].race<<" ";
    cout<<endl;

    for(i=0;i<5;i++)
    {
        p[del[i]].race=p[reproduce[i]].race;
        p[del[i]].money=p[reproduce[i]].money;
    }
}

void money0(person p[25])
{
    for(int i=0;i<25;i++)p[i].money = 0;
}

void get()
{
    int num=0; // number of people that have existed till now
    int x,y,z; cin>>x>>y>>z;

    person p[25];

    initialise(p,x,y,z);

    while(1)
    {
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<25;j++)
            {
                play(p[i],p[j]);
            }
        }

        eliminate(p);

        money0(p);

        int a=0,b=0,c=0;
        for(int i=0;i<25;i++)
        {
            if(p[i].race=='A')a++;
            else if(p[i].race=='C')c++;
            else b++;
        }

        cout<<"A = "<<a<<",B = "<<b<<", C = "<<c<<endl;

        if(a==25)
        {
            cout<<"A won the race";
            break;
        }
        if(b==25)
        {
            cout<<"B won the race";
            break;
        }
        if(c==25)
        {
            cout<<"C won the race";
            break;
        }
    }

}


int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get();
}
