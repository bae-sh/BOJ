package 백준;
import java.util.*;
import java.io.*;
public class 전화번호목록5052번 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0) {
			int n=Integer.parseInt(br.readLine());
			long d[]=new long[n];
			boolean b=true;
			for(int i=0;i<n;i++) {
				d[i]=Long.parseLong(br.readLine());
			}
			Arrays.sort(d);
			outloop:
			for(int i=0;i<n;i++) {
				StringBuilder sb=new StringBuilder();
				sb.append(d[i]);
				for(int j=i+1;j<n;j++) {
					StringBuilder sr=new StringBuilder();
					sr.append(d[j]);
					String s=sr.substring(0, sb.length());
					if(sb.toString().equals(s)) {
						b=false;
						break outloop ;
					}
				}
			}
			System.out.println(b==true? "YES":"NO");
			
		}
	}

}
