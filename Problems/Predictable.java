import java.util.*;
public class Predictable {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		long a[]=new long[n];
		StringBuilder sb=new StringBuilder();
		a[0]=sc.nextLong();
		for(int i=1;i<n;i++) {
			a[i]=a[i-1]+sc.nextLong();
		}
		
		while(m-->0) {
			long time=sc.nextLong();
			if(a[0]>time) {
				sb.append(0+"\n");
				continue;
			}else if(a[n-1]<=time) {
				sb.append(n+"\n");
				continue;
			}
			int left=0;
			int right=n-1;
			int mid=(left+right)/2;
			while(left<=right) {
				mid=(left+right)/2;
				if(a[mid]<time) {
					left=mid+1;
				}else if(a[mid]>time) {
					if(mid-1>=0&&a[mid-1]<=time) {
						sb.append(mid+"\n");
						break;
					}else {
						right=mid-1;
					}
				}else {
					sb.append(mid+1+"\n");
					break;
				}
			}
		}
		System.out.println(sb.toString());
	}

}
