import java.util.*;
import java.io.*;
public class 숫자카드2 {

	public static void main(String[] args) throws IOException{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int a[]=new int[n];
		StringBuilder sb=new StringBuilder();
		String s[]=br.readLine().split(" ");
		for(int i=0;i<n;i++) {
			a[i]=Integer.parseInt(s[i]);
		}
		Arrays.sort(a);
		int m=Integer.parseInt(br.readLine());
		String[] s2=br.readLine().split(" ");
		for(int i=0;i<m;i++) {
			int k=Integer.parseInt(s2[i]);
			find(a,a.length-1,0,k,sb);
		}
		System.out.println(sb.toString());
		
	}
	public static void find(int a[],int right,int left,int x,StringBuilder sb) {
		while(left<=right) {
			int mid=(left+right)/2;
			if(a[mid]==x) {
				int n=1;
				left=mid-1;
				right=mid+1;
				while(left!=-1) {
					if(a[left]!=x)
						break;
					n++;
					left--;
				}
				while(right!=a.length) {
					if(a[right]!=x)
						break;
					n++;
					right++;
				}
				sb.append(n+" ");
				return;
			}else if(a[mid]>x) {
				right=mid-1;
			}else {
				left=mid+1;
			}
		}
		sb.append(0+" ");
	}
}
