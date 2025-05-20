    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define bieo cin.tie(0)->sync_with_stdio(0)
    #define endl '\n'

    signed main()
    {
        bieo;
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (auto &x : a)
            cin >> x;

        vector<int> dist;
        int bestSeq = 1, last = 1e9, seq = 1, initI = 0, l = 0, r = n, pa = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int cur = a[i + 1] - a[i];
            dist.push_back(cur);

            if (last == cur && i + 1 != n - 1)
                seq++;
            else
            {
                if (last == cur)
                    seq++;
                if (bestSeq < seq)
                {
                    pa = cur;
                    bestSeq = seq;
                    l = initI;
                    r = i-1;
                }
                initI = i;
            }
            last = cur;
        }
        
        set<int> del;
        int cur = 0, indexL = l-1, sum = 0;
        while (l > 0 && indexL >= 0)
        {   
            if (dist[l] != dist[indexL]+sum)
            {
                if (indexL >= 0)
                {
                    sum += dist[indexL];
                    del.insert(indexL);
                    cur++;
                } else
                {
                    cur++;
                    del.insert(indexL);
                }
                indexL--;
            }
            else {
                l = indexL;
                indexL--;
                sum = 0;
            }
        }

        int ans = cur, indexR = r+1;
        cur = 0, sum = 0;

        while (r < n-2 && indexR < n-1)
        {
            if (dist[r] != dist[indexR]+sum)
            {
                if (indexR < n-1)
                {
                    sum += dist[indexR];
                    del.insert(indexR);
                    cur++;
                } else
                {
                    cur++;
                    del.insert(indexR);
                }
                indexR++;
            }
            else {
                r = indexR;
                indexR++;
                sum = 0;
            }  
        }

        if(ans+cur > k) cout << -1 << endl;
        else{
            cout << del.size() << endl;
            for(auto &x : del) cout << x + 1 << " ";
            cout << endl;
        }
        
        return 0;
    }
