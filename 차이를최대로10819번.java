import java.util.*;
public class 차이를최대로10819번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		int ans=0;
		do {
			int temp=0;
			for(int i=0;i<a.length-1;i++) {
					temp+=Math.abs(a[i]-a[i+1]);
			}
			ans=Math.max(ans, temp);
		}while(next_permutation(a));
		System.out.println(ans);
	}
	public static boolean next_permutation(int a[]) {
		int k=-1;
		for(int i=a.length-1;i>0;i--) {
			if(a[i-1]<a[i]) {
				for(int j=i;j<=a.length-1;j++) {
					if(a[i-1]<a[j]) {
						k=j;
					}
				}
				int temp=a[k];
				a[k]=a[i-1];
				a[i-1]=temp;
				k=a.length-1;
				while(i<k) {
					temp=a[i];
					a[i]=a[k];
					a[k]=temp;
					i++;k--;
				}
				return true;
			}
		}
		return false;
	}
}
