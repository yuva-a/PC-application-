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

void eliminate(person p[25])
{

    // sorting in to increasing order

    for(int i=0;i<25;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(p[j].money<p[j-1].money)
            {
                int m = p[j].money;
                char r = p[j].race;

                p[j].money = p[j-1].money;
                p[j].race = p[j-1].race;

                p[j-1].money = m;
                p[j-1].race = r;
            }
        }
    }
    
    // for(int i=0;i<25;i++)
    //     cout<<p[i].race<<" ="<<p.money<<" ";
    
    cout<<endl;

    int rem[5];
    {
        int x=4;
        while(x<25 && p[x].money==p[4].money)x++;
        int a[x]={0};

        int dtn=0;
        while(dtn!=5)
        {
            int temp = rand()%x;
            if(a[temp]==0)
            {
                rem[dtn]=temp;
                a[temp]=1;
                dtn++;
            }
        }
    }

    int populate[5];
    {
        int x=20;
        while(x>0 && p[x].money == p[20].money)x--;

        int a[25-x]={0};

        int dtn=0;
        while(dtn!=5)
        {
            int temp = x + rand()%(25-x);
            if(a[temp]==0)
            {
                populate[dtn]=temp;
                a[temp]=1;
                dtn++;
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        p[rem[i]].race = p[populate[i]].race;
    }

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
        // make them play
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<25;j++)
            {
                play(p[i],p[j]);
            }
        }

        //eliminate
        eliminate(p);

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    get();
}