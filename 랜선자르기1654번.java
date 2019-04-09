import java.util.*;

public class 랜선자르기1654번 {
    public static boolean check(long[] a, int m, long x) {
        int cnt = 0;
        for (int i=0; i<a.length; i++) {
            cnt += a[i]/x;
        }
        return cnt >= m;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[n];
        long max = 0;
        for (int i=0; i<n; i++) {
            a[i] = sc.nextLong();
            max = Math.max(max, a[i]);
        }
        long ans = 0;
        long l = 1;
        long r = max;
        while (l <= r) {
            long mid = (l+r)/2;
            if (check(a, m, mid)) {
                ans = Math.max(ans,mid);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        System.out.println(ans);
    }
}