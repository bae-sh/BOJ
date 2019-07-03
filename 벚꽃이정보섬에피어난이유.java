import java.util.*;
public class 벚꽃이정보섬에피어난이유 {
	static int ans=0;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		int d[]=new int[n-1];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		for(int i=3;i<n-1;i++) {
			d[i]=1;
		}
		do {
			int answer=0;
			int temp=1;
			for(int i=0;i<n-1;i++) {
				if(d[i]==0) {
					temp*=a[i];
					answer+=temp;
					temp=1;
					if(i==n-2) {
						answer+=a[n-1];
					}
				}else {
					temp*=a[i];
					if(i==n-2) {
						temp*=a[i+1];
						answer+=temp;
					}
				}
			}
			ans=Math.max(ans, answer);
		}while(next_permutation(d));
		System.out.println(ans);
		
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
