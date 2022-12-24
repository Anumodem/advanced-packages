#include <stdio.h>
        #include <stdlib.h>
     
        long long solve(int *aa, int *bb, int n, int m)
        {
        	long long *ss, *dp, *qq, max;
        	int i, j, k, a, b, p, q;
     
        	ss = calloc(n + 1, sizeof *ss);
        	for (i = 0; i < n; i++)
        		ss[i + 1] = ss[i] + aa[i];
        	dp = malloc(n * sizeof *dp);
        	for (k = m - 1, b = bb[k], i = 0; i < n; i++)
        		dp[i] = i + b <= n ? ss[i + b] - ss[i] : 0;
        	qq = malloc(n * sizeof *qq);
        	for (k = m - 2; k >= 0; k--)
                {
        		b = bb[k], a = bb[k] - bb[k + 1] - 1, p = 0, q = 0;
        		for (i = 0, j = 1; i < n; i++)
        			if (i + b <= n)
        			{
        				while (j <= i + a)
        				{
        					while (q > p && dp[j] > dp[qq[q - 1]])
        						q--;
        					qq[q++] = j++;
        				}
        				if (qq[p] == i)
        					p++;
        				dp[i] = ss[i + b] - ss[i] - dp[qq[p]];
        			} else
        				dp[i] = 0;
        	    }
        	max = 0;
        	for (i = 0; i < n; i++)
        		if (max < dp[i])
        			max = dp[i];
        	return max;
        }
     
    int main()
        {
        	int t;
     
        	scanf("%d", &t);
        	while (t-- > 0)
            {
        		static int *a, *b;
        		int n, m, i, k;
     
        		scanf("%d%d", &n, &m);
        	a=malloc(n*sizeof*a);
        		for (i = 0; i < n; i++)
        			scanf("%d", &a[i]);
        	b=malloc(m*sizeof*b);
        		for (k = 0; k < m; k++)
        			scanf("%d", &b[k]);
        		printf("%lld\n", solve(a, b, n, m));
        	}
        	return 0;
        }
