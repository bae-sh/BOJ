import java.util.*;
public class 이전순열10973번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		
		for(int i=n-1;i>0;i--) {
			if(a[i-1]<a[i]) continue;
			int index=-1;
			for(int j=i;j<n;j++) {
				if(a[i-1]>a[j]) {
					index=j;
				}
			}
			int temp=a[i-1];
			a[i-1]=a[index];
			a[index]=temp;
			index=n-1;
			while(i<index) {
				temp=a[i];
				a[i]=a[index];
				a[index]=temp;
				i++;index--;
			}
			
			for(int k=0;k<a.length;k++) {
				System.out.print(a[k]+" ");
			}
			System.exit(0);
		}
		System.out.println(-1);
	}

}
