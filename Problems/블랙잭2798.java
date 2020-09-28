import java.util.*;
public class 블랙잭2798 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		int m=sc.nextInt();
		int d[]=new int[n];
		int cnt[]=new int[n];
		
		for(int i=0;i<n;i++) {
			d[i]=sc.nextInt();
		}
		cnt[n-1]=1;cnt[n-2]=1;cnt[n-3]=1;
		 int Max=m>=d[n-1]+d[n-2]+d[n-3] ? d[n-1]+d[n-2]+d[n-3] : 0;
		do {
			int plus=0;
			for(int i=0;i<n;i++) {
				if(cnt[i]==1) {
					plus+=d[i];
				}
			}
			if(plus<=m&&Max<plus) {
				Max=plus;
			}
		}
		while(next_permutation(cnt)) ;
		System.out.println(Max);
		
	}
	public static boolean next_permutation(int[] a) {
        int i = a.length-1;
        while (i > 0 && a[i-1] >= a[i]) {
            i -= 1;
        }

        // 마지막 순열
        if (i <= 0) {
            return false;
        }

        int j = a.length-1;
        while (a[j] <= a[i-1]) {
            j -= 1;
        }

        int temp = a[i-1];
        a[i-1] = a[j];
        a[j] = temp;

        j = a.length-1;
        while (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i += 1;
            j -= 1;
        }
        return true;
    }
}
