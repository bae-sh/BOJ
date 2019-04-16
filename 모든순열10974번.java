import java.util.*;
public class 모든순열10974번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<n;i++) {
			a[i]=i+1;
			sb.append(a[i]+" ");
		}
		sb.append("\n");
		
		for(int i=n-1;i>0;i--) {
			if(a[i-1]>=a[i]) continue;
			int index=-1;
			
			for(int j=i;j<n;j++) {
				if(a[i-1]<a[j]) {
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
			for(int j=0;j<a.length;j++) {
				sb.append(a[j]+" ");
			}
			sb.append("\n");
			i=n;
		}
		System.out.println(sb.toString());
	}

}
