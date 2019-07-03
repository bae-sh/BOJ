import java.util.*;
import java.io.*;
public class 패션왕신해빈 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0) {
			int n=Integer.parseInt(br.readLine());
			int ans=1;
			String a[]=new String[n];
			int b[]=new int[n];
			for(int i=0;i<n;i++) {
				a[i]="";
			}
			for(int j=0;j<n;j++) {
				String []s=br.readLine().split(" ");
				for(int i=0;i<n;i++) {
					if(a[i].equals(s[1])) {
						b[i]++;
						break;
					}else if(a[i].equals("")) {
						a[i]=s[1];
						b[i]=2;
						break;
					}
				}
			}
			for(int i=0;i<n;i++) {
				if(a[i].equals("")) {
					break;
				}else {
					ans*=b[i];
				}
			}
			System.out.println(ans-1);
			
		}
	}

}
