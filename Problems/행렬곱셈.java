import java.util.*;
import java.io.*;
public class 행렬곱셈 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s[]=br.readLine().split(" ");
		int a[][]=new int[Integer.parseInt(s[0])][Integer.parseInt(s[1])];
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<a.length;i++) {
			s=br.readLine().split(" ");
			for(int j=0;j<a[0].length;j++) {
				a[i][j]=Integer.parseInt(s[j]);
			}
		}
		s=br.readLine().split(" ");
		int b[][]=new int[Integer.parseInt(s[0])][Integer.parseInt(s[1])];
		for(int i=0;i<b.length;i++) {
			s=br.readLine().split(" ");
			for(int j=0;j<b[0].length;j++) {
				b[i][j]=Integer.parseInt(s[j]);
			}
		}
		for(int i=0;i<a.length;i++) {
			for(int j=0;j<b[0].length;j++) {
				int temp=0;
				for(int k=0;k<a[0].length;k++) {
					temp+=a[i][k]*b[k][j];
				}
				sb.append(temp+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
		
	}

}
