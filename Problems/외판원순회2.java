import java.util.*;
public class 외판원순회2 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int d[][]=new int[n][n];
		int ans=100000000;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				d[i][j]=sc.nextInt();
			}
		}
		int a[]=new int[n-1];
		for(int i=0;i<n-1;i++) {
			a[i]=i+1;
		}
		
		do {
			boolean p=false;
			int x=d[0][a[0]];
			if(x==0) p=true;
			for(int i=0;i<n-2;i++) {
				int c=d[a[i]][a[i+1]];
				if(c==0) {
					p=true;
				}
				x+=c;
			}
			if(d[a[n-2]][0]==0) {
				p=true;
			}
			x+=d[a[n-2]][0];
			if(p==true) {
				continue;
			}
			ans =Math.min(x, ans);
		}while(next_permutation(a));
		System.out.println(ans);
	}
	public static boolean next_permutation(int a[]) {
		for(int i=a.length-1;i>0;i--) {
			int index=-1;
			if(a[i-1]<a[i]) {
				for(int j=i;j<a.length;j++) {
					if(a[i-1]<a[j])
						index=j;
				}
				int temp=a[i-1];
				a[i-1]=a[index];
				a[index]=temp;
				
				index=a.length-1;
				while(i<index) {
					temp=a[i];
					a[i]=a[index];
					a[index]=temp;
					i++;index--;
				}
				return true;
			}
		}
		return false;
	}
}
