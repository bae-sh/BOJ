import java.util.*;
import java.io.*;
public class 로또6603번 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		while(true) {
			String[] s=br.readLine().split(" ");
			int n=Integer.parseInt(s[0]);
			if(n==0) break;
			
			int a[]=new int[n];
			int b[]=new int[n];
			for(int i=0;i<n;i++) {
				a[i]=Integer.parseInt(s[i+1]);
			}
			for(int i=0;i<6;i++) {
				b[i]=1;
			}
			do {
				for(int i=0;i<n;i++) {
					if(b[i]==1)
						sb.append(a[i]+" ");
				}
				sb.append("\n");
			}while(next_permutation(b));
			sb.append("\n");
			
		}
		System.out.println(sb.toString());
	}
	public static boolean next_permutation(int a[]) {
		for(int i=a.length-1;i>0;i--) {
			int index=-1;
			if(a[i-1]>a[i]) {
				for(int j=i;j<a.length;j++) {
					if(a[i-1]>a[j])
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
