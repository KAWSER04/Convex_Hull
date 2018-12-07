#include <iostream>
using namespace std;

int tree[400005], a[100005];

void build(int node, int start, int end)
{
    if (start == end)
        tree[node] = a[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node+1, start, mid);
        build(2 * node + 2, mid + 1, end);
        if (tree[2 * node+1] < tree[2 * node + 2])
            tree[node] = tree[2 * node+1];
        else
            tree[node] = tree[2 * node + 2];
    }
}


int query(int node, int start, int end, int l, int r)
{
    if (l > end || start > r)
        return 10000009;
    if (l <= start && r >= end)
        return tree[node];
    int p1, p2;
    int mid = (start + end) / 2;
    p1 = query(2 * node+1, start, mid, l, r);
    p2 = query(2 * node +2, mid + 1, end, l, r);

    return min(p1,p2);

}
int main()
{

    int n, q,t,j=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        for (int i = 1; i <= n; i++)
            scanf("%d",&a[i]);

        build(0, 1, n);
        printf("Case %d:\n",j);
        while (q--)
        {

            int x, y;
            scanf("%d %d",&x,&y);
            int z=query(0,1,n,x,y);
            printf("%d\n",z);
        }
        j++;
    }

    return 0;
}

