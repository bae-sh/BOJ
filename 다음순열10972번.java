import java.util.*;
public class 다음순열10972번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		int p=0;
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		
		for(int i=n-1;i>0;i--) {
			if(i<=p) break;
			if(a[i]<a[i-1]) continue;
			int index=i;
			
			for(int j=i;j<=n-1;j++) {
				if(a[i-1]<a[j]) {
					index=j;
				}
			}
			int temp=a[i-1];
			a[i-1]=a[index];
			a[index]=temp;
			index=n-1;
			
			while(i<index) {
				temp=a[index];
				a[index]=a[i];
				a[i]=temp;
				i++; index--;
			}
			for(int k:a) {
				System.out.print(k+" ");
			}
			System.exit(0);
		}
		System.out.println(-1);
		
	}

}
